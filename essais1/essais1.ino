#include <MinimumSerial.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SdFatmainpage.h>
#include <SdFatUtil.h>
#include <SdInfo.h>
#include <SdSpi.h>
#include <SdSpiCard.h>

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
//#include <SD.h>

SdFat SD;
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

  if (!SD.exists("/DOSSIER")){ // Création du dossier "DOSSIER" s'il n'éxiste pas.
    SD.mkdir("DOSSIER");
  }
  if (!SD.exists("/OUT")){ // Création du dossier "OUT" s'il n'éxiste pas.
    SD.mkdir("OUT");
  }
  String chemin = "/DOSSIER/"; // Création de la chaîne de caractère "chemin"
  String chemin2 = "/OUT/";    // Création de la chaîne de caractère "chemin2"
  
  File myFile2 = SD.open(chemin + "example2.txt", FILE_WRITE); // Simple test d'écriture dans le dossier
  myFile2.println("YOLO");
  myFile2.close();
  
  effacerLigne(chemin, "EXAMPLE1.TXT", 5); // Appel de la méthode effacerLigne
  effacerLigneVers(chemin, "example.txt", chemin2, "out.txt", 1, true);

  Serial.println("done!");
}


void loop() {
  // nothing happens after setup finishes.
}


/**
 * Efface une ligne d'un fichier.
 * 
 * @param chemin        Le chemin du fichier
 * @param nomFichier    Le nom du fichier à modifier
 * @param numeroLigne   La ligne à effacer.
 * @return              La ligne a été effacée et le fichier temporaire a ete supprime
 */

boolean effacerLigne(String chemin, String nomFichier, uint8_t numeroLigne){
  boolean ligneParcourue = false;
  boolean bufSuppr = false;
  File fichier = SD.open(chemin + nomFichier, FILE_READ);
  if(SD.exists(chemin + "buffer.txt")){
    SD.remove(chemin + "buffer.txt"); 
  }
  File buf = SD.open(chemin + "buffer.txt", FILE_WRITE);
  String ligne = ""; uint8_t numLigne = 0; uint8_t i;
  while(fichier.available()){             // Lecture du fichier ligne par ligne
    ligne += fichier.readStringUntil('\n');
    if (numLigne != numeroLigne-1){           
      buf.println(""+ligne);
    } else {
      ligneParcourue = true;
    }
    ligne = "";                           // Réinitialisation de la chaîne de caractère "ligne"
    numLigne++;
  }
  fichier.close(); buf.close();           // Fermeture du fichier
  SD.remove(chemin + nomFichier);
  SD.rename(chemin + "buffer.txt", chemin + nomFichier);
  /*if (SD.exists(chemin + "buffer.txt")) { // Suppressin du fichier "buffer.txt" si restant
    SD.remove(chemin + "buffer.txt"); 
  }*/
  bufSuppr = !SD.exists(chemin + "buffer.txt");
  
  return (ligneParcourue && bufSuppr);
}


/**
 * Créée une copie du fichier d'entree, la ligne indiquée étant supprimee.
 * 
 * @param cheminIN        Le chemin du fichier
 * @param nomFichierIN    Le nom du fichier à modifier
 * @param cheminOUT       Le chemin du fichier
 * @param nomFichierOUT   Le nom du fichier à modifier
 * @param numeroLigne     La ligne à effacer.
 * @param suppr           Si le fichier de sortie existe deja, donne l'autorisation ou non d'écraser le fichier de sortie existant
 * @return                Si une erreur s'est produite.
 */
boolean effacerLigneVers(String cheminIN, String nomFichierIN, String cheminOUT, String nomFichierOUT, uint8_t numeroLigne, boolean suppr){
  boolean ligneParcourue = false;
  boolean ok = true;
  File fIn = SD.open(cheminIN + nomFichierIN, FILE_READ);
  if(SD.exists(cheminOUT)){
    if(SD.exists(cheminOUT + nomFichierOUT)){
      if (suppr){                             // Autorisation d'ecrasement accordee.
        SD.remove(cheminOUT + nomFichierOUT); 
      } else {                                // Autorisation d'ecrasement non accordee.
        ok = false; // Le fichier de sortie existe deja, et il n'est pasautorise de le supprimer.
      }
    }
  } else {
    ok = false; // Le chemin specifie n'existe pas.
  }
  if (ok){  // Si toutes les conditions nécessaires sont valides, on procède alors.
    File fOut = SD.open(cheminOUT + nomFichierOUT, FILE_WRITE);
    String ligne = ""; uint8_t numLigne = 0; uint8_t i;
    while(fIn.available()){             // Lecture du fichier ligne par ligne
      ligne += fIn.readStringUntil('\n');
      if (numLigne != numeroLigne-1){           
        fOut.println(""+ligne);
      } else {
        ligneParcourue = true;
      }
      ligne = "";                           // Réinitialisation de la chaîne de caractère "ligne"
      numLigne++;
    }
    fIn.close(); fOut.close();           // Fermeture des fichiers
  }
  return (ok && ligneParcourue) ;
}



