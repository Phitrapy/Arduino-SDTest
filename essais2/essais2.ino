/*
  Listfiles

 This example shows how print out the files in a
 directory on a SD card

 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 2 Feb 2014
 by Scott Fitzgerald

 This example code is in the public domain.

 */
#include <SPI.h>
#include <SD.h>
#include "SysSD.h"

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  SD.remove("error.txt");
  SysSD sysSD;
  sysSD.init();
  delay(1000);
  SysSD::removePeople("Colas", "Pe", "CARDID1");
  //SysSD::editPeople("Hennin", "Matthieu", "CARDID4");
  //SysSD::addPeople("Cesari", "Matthieu", "CARDIDGG");
  //SysSD::renommer("/", "test.txt", "/", "yolo.txt");
  
  Serial.println("All done!");

  
}

void loop() {
  
}
