#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu1(0x68); // Sensor 1: Femur bone
MPU6050 mpu2(0x69); // Sensor 2: Tibia bone

//Provide the token generation process info.
#include <addons/TokenHelper.h>

//Provide the RTDB payload printing info 
#include <addons/RTDBHelper.h>

#define WIFI_SSID "Pratz"
#define WIFI_PASSWORD "7975089407"

/* Define the API Key */
#define API_KEY "***********************"

/* Define the RTDB URL */
#define DATABASE_URL "*************************"         


#define USER_EMAIL "****************"
#define USER_PASSWORD "********************"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
unsigned long count = 0;

int16_t ax1, ay1, az1, gx1, gy1, gz1;
int16_t ax2, ay2, az2, gx2, gy2, gz2;

#define vibmotor D5
 
void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  mpu1.initialize();
  mpu2.initialize();

  pinMode(vibmotor, OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL */
  config.database_url = DATABASE_URL;

  
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h


  Firebase.begin(&config, &auth);

  //Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);

}

void loop() {
  
  mpu1.getMotion6(&ax1, &ay1, &az1, &gx1, &gy1, &gz1);
  mpu2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);

  // Calculate the angle between the two sensors

  /* LOGIC FOR KNEE ANGLE CALCULATION */
  /* ----------------
   *  ------------------
   *    -----------------------
   */
  
  String SendKneeAngle = String(KneeAngle);

  Firebase.setString(fbdo, "KneeAngle", SendKneeAngle);

  if (Firebase.getString(fbdo,"PainPoint")){
    String  pain = fbdo.stringData();      
    Serial.println(pain);
    
    if(pain == "1"){
      digitalWrite(vibmotor, HIGH);
      delay(1000);
      digitalWrite(vibmotor, LOW);
      delay(1000);
    } 
  }
  delay(1000);
}
