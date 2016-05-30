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

File root;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  root = SD.open("/");
  
  SD.mkdir("DOSSIER");
  String nomDossier = "/DOSSIER/";
  //SD.open("/"+nomDossier);
  File myFile = SD.open(nomDossier+"example.txt", FILE_WRITE);
  myFile.close();
  
  printDirectory(root, 1);
  effacerLigne("EXAMPLE.TXT", 3);

  Serial.println("done!");
}

void loop() {
  // nothing happens after setup finishes.
}

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

void effacerLigne(String nomFichier, uint8_t n){
  File fichier = SD.open(nomFichier, FILE_READ);
  File buf = SD.open("buffer.txt", FILE_WRITE);
  buf.println("Ce fichier a été ouvert, on se fout aps de votre gueule");
  String ligne = ""; uint8_t numLigne = 0; uint8_t i;
  while(fichier.available()){
    ligne += fichier.readStringUntil('\n');
    /*while(fichier.peek()!= '\n'){
      ligne += fichier.read('\n');
    }
    fichier.read();*/
    if (numLigne != n){
      Serial.println("Ligne écrite! " + ligne);
      buf.println(""+ligne);
    }
//    Serial.println(ligne, strlen(ligne));
    ligne = "";
    numLigne++;
  }
  fichier.close(); buf.close();
  Serial.println("done!");
}

