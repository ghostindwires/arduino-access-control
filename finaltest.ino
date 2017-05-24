#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <DS3231.h>
#include <SD.h>

DS3231  rtc(SDA, SCL); // initialize RTC
#define RST_PIN 2
#define SS_PIN 3

MFRC522 mfrc522(SS_PIN, RST_PIN); //initialize RFID

String read_rfid;
String rfid1 = "e33e80f7";//toheeb
String rfid2 = "85687168";//kayode
String rfid3 = "6d32763";//chidinma
int buzzerpin =  6;
int ledred = 8;
int ledgreen = 9;
int servopin = 5;
Servo myservo; //initialize servo*/

int servo_angle = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//while(!Serial);
SPI.begin();
mfrc522.PCD_Init();
myservo.attach(5);
pinMode(ledred, OUTPUT);
pinMode(ledgreen, OUTPUT);
rtc.begin();
pinMode(buzzerpin, OUTPUT);
  // tweak to change current date
  //rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(05, 05, 40);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(12, 05, 2017);   // Set the date to May 8th, 2017
}

void rfid_database(byte *buffer, byte bufferSize){
    read_rfid ="";
  for (byte i = 0; i < bufferSize; i++){
        read_rfid = read_rfid + String(buffer[i], HEX);
      }
  }
void loop() {
  // put your main code here, to run repeatedly:
  if (! mfrc522.PICC_IsNewCardPresent()) 
  return;
  
  if  (! mfrc522.PICC_ReadCardSerial()) 
  return;
  
  rfid_database(mfrc522.uid.uidByte, mfrc522.uid.size);
  if (read_rfid == rfid1){
        Serial.println("Welcome DR. Jubril");
        Serial.println("Time of entrance: ");
       Serial.print(rtc.getDOWStr());
        Serial.print(" ");

        Serial.print(rtc.getDateStr());
        Serial.print(" -- ");

       Serial.println(rtc.getTimeStr());
       digitalWrite(ledgreen, HIGH);
  for ( int i =90; i <= 180; i++){
       myservo.write(i);
       delay(5);
       }
       delay(5000);
       for ( int i=180; i >= 90; i--){
       myservo.write(i);
       delay(5);
  }
       digitalWrite(ledgreen, LOW);
       digitalWrite(ledred, LOW);
  }
  else if (read_rfid == rfid2)
   {
       Serial.println("Welcome Kayode");
       Serial.println("Time of entrance: ");
       // Send Day-of-Week
      Serial.print(rtc.getDOWStr());
      Serial.print(" ");
      // Send date
       Serial.print(rtc.getDateStr());
        Serial.print(" -- ");
     // Send time
       Serial.println(rtc.getTimeStr());
       digitalWrite(ledgreen, HIGH);
  for ( int i =90; i <= 180; i++){
       myservo.write(i);
       delay(5);
       }
       delay(5000);
       for ( int i=180; i >= 90; i--){
       myservo.write(i);
       delay(5);
  }
         digitalWrite(ledgreen, LOW);
         digitalWrite(ledred, LOW);
  } 
   else if (read_rfid == rfid3)
   {
        Serial.println("Welcome Chidinma");
        Serial.println("Time of entrance: ");
       //Send Day-of-Week
        Serial.print(rtc.getDOWStr());
        Serial.print(" ");
  
      // Send date
        Serial.print(rtc.getDateStr());
        Serial.print(" -- ");

     // Send time
       Serial.println(rtc.getTimeStr());
       digitalWrite(ledgreen, HIGH);
        for ( int i =90; i <= 180; i++){
       myservo.write(i);
       delay(5);
       }
       delay(5000);
       for ( int i=180; i >= 90; i--){
       myservo.write(i);
       delay(5);
  }
          digitalWrite(ledgreen, LOW);
          digitalWrite(ledred, LOW);
   }
  else {
  Serial.println("invalid Card");
  digitalWrite(buzzerpin, HIGH);
  {
  tone(6, 3073,1000);
  noTone(10);
  delay(500);
 tone(6, 550,1800);
  delay(500);
  tone(6, 3073,1000);
  noTone(10);
   tone(6, 200,1800);
 } 
 digitalWrite(ledred,HIGH);
 delay(2000);
 digitalWrite(ledred,LOW);
digitalWrite(ledgreen,LOW);
}
}
