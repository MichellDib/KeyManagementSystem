/* Read RFID Tag with RC522 RFID Reader
    Made by miliohm.com
*/
#include <SPI.h>
#include <MFRC522.h>
constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;     // Configurable, see typical pin layout above
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;



String tag;
void setup() {
  Serial.begin(115200);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  pinMode(D1, OUTPUT);
}
void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);
    if (tag == "24213714427") {
      Serial.println("Access Granted!");
      digitalWrite(D1, HIGH);
      delay(100);
      digitalWrite(D1, LOW);
      delay(100);
      digitalWrite(D1, HIGH);
      delay(100);
      digitalWrite(D1, LOW);
      delay(100);
      digitalWrite(D1, HIGH);
      delay(100);
      digitalWrite(D1, LOW);
      delay(100);
    } else {
      Serial.println("Access Denied!");
      digitalWrite(D1, HIGH);
      delay(2000);
      digitalWrite(D1, LOW);
    }
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}
