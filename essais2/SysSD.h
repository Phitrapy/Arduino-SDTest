// SD Class Header - By Clément BEGNAUD


#ifndef SYSSD_H
#define SYSSD_H

#include <String.h>
#include <SPI.h>
//#include <iostream>
#include "Error.h"
#include "Warning.h"



class SysSD {
	
	public:
	//Constructeur par défaut
	void init();
	static bool createLog_Nodes();
	static bool createLog_Users();
	static bool createLog_Admins();
	static bool createLog_Settings();
	static bool createLog_Actions();
	static bool createLog_Errors();
	static bool createLog_Stats();
	static bool addAction(String titre, String message);
	static bool addPeople(String nom, String prenom, String cardID);
	static bool editPeople(String nom, String prenom, String cardID);
	static bool removePeople(String nom, String prenom, String cardID);
  static bool cleanCardID(String cardID);
  static bool cleanCardID(String oldCardID, String newCardID);
	static bool addNode(String titre, uint8_t nodeID, String type, uint8_t settings[]);
	static bool editNode(String titre, uint8_t nodeID, String type, uint8_t settings[]);
	static bool removeNode(String titre, uint8_t nodeID, String type, uint8_t settings[]);
	static bool editSetting();
	static String readSettings();
	static bool addError(String error);
	static bool addWarning(String warning);
	static bool findUserCardID(String match, uint8_t* line);
  static bool findUserCardID(String nom, String prenom, uint8_t* line);
 	static bool findUserCardID(String match, uint8_t* line, String userStr[]);
  static boolean effacerLigne(String chemin, String nomFichier, uint8_t numeroLigne);
  static boolean effacerLigneVers(String cheminIN, String nomFichierIN, String cheminOUT, String nomFichierOUT, uint8_t numeroLigne, boolean suppr);
  static boolean renommer(String cheminIN, String nomFichierIN, String cheminOUT, String nomFichierOUT);
  static void splitCardID(String str, char tok, String* cardID);
	static String glandouillHeure();
	
	
	
	private:
	//Attributs
	
};

#endif
