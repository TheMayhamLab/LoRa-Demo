/* Name:     LoRa-Testing-RX_SoftwareSerial
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

#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String lora_band = "865000000"; //enter band as per your country
String lora_networkid = "4";    //enter Lora Network ID
String lora_address = "2";      //enter Lora address
String lora_RX_address = "1";   //enter Lora RX address
String incomingString;

SoftwareSerial mySerial(10, 11); // RX, TX


// ------------------------------------------------------
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.display();

  // display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("LoRa Test v1.0");
  display.display();
  delay(1000);
  
  //Serial.begin(115200);
  mySerial.begin(115200);
  delay(500);
  mySerial.println("AT+BAND=" + lora_band);
  delay(500);
  mySerial.println("AT+ADDRESS=" + lora_address);
  delay(500);
  mySerial.println("AT+NETWORKID=" + lora_networkid);
  delay(1500);
}
// ------------------------------------------------------
void loop() {
  if(mySerial.available()) {
    incomingString = mySerial.readString();
    //Print to the OLED
    display.clearDisplay();
    display.setCursor(0,0);
    //display.println(" ");
    display.println(incomingString);
    display.display();

    if(incomingString.indexOf("On") >0) {
      digitalWrite(LED_BUILTIN, HIGH); // LED on
    }
    if(incomingString.indexOf("Off") >0) {
      digitalWrite(LED_BUILTIN, LOW); // LED off
    }
  }
}
