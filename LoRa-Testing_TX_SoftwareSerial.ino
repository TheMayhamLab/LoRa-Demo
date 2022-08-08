/* Name:     LoRa-Testing-TX_SoftwareSerial
 * Purpose:  To demo the LoRa RLYR998 board
 * By:       Michael Vieau
 * Created:  2022.07.20
 * Modified: 2022.08.07
 * Rev level 0.1
 * 
 * Resources Used:
 * https://www.youtube.com/watch?v=NMWipsalrr0
 * https://www.youtube.com/watch?v=JDvV-0sFpTQ
 */
 
String lora_band = "865000000"; //enter band as per your country
String lora_networkid = "4";    //enter Lora Network ID
String lora_address = "1";      //enter Lora address
String lora_RX_address = "2";   //enter Lora RX address

#include <SoftwareSerial.h>
String incomingString;

SoftwareSerial mySerial(10, 11); // RX, TX

// ------------------------------------------------------
void setup() {
  mySerial.begin(115200);
  delay(1500);
  mySerial.println("AT+BAND=" + lora_band);
  delay(500);
  mySerial.println("AT+ADDRESS=" + lora_address);
  delay(500);
  mySerial.println("AT+NETWORKID=" + lora_networkid);
  delay(1500);
}
// ------------------------------------------------------
void loop() {
  //Serial.println(mySerial.readString());
  if(mySerial.available()) {
    digitalWrite(LED_BUILTIN, HIGH); // LED on
    mySerial.println("AT+SEND="+ lora_RX_address +",2,On");
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);  // LED off
    mySerial.println("AT+SEND="+ lora_RX_address +",3,Off");
    delay(2000);
  }
}
