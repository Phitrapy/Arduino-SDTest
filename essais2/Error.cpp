// Error Class - By Clément BEGNAUD

#include <String.h>
#include <WString.h>
//#include <iostream.h>
#include "Error.h"


using namespace std;

String Error::cannotOpen(String nomFichier){
	String error = "[Error] Le fichier \"" + nomFichier;
	error += "\" n'a pas pu être ouvert." ;
	return error;
}

String Error::peopleNotRemoved(String nom, String prenom, String cardID){
  String error = "[Error] L'utilisateur \""+ nom +" "+ prenom +" "+ cardID;
  error += "\" n'a pas pu être supprimé." ;
  return error;
}

String Error::bufNotRemoved(){
  String error = "[Error] Lors de l'opération le fichier buffer n'a pas été supprimé." ;
  return error;
}

String Error::renommerGeneric(){
  String error = "[Error] Impossible de renommer." ;
  return error;
  //return "";
}

/*
String Error::renommerInputFileDoesntExists(){
  String error = "[Error] Impossible de renommer : Le fichier d'entrée n'existe pas." ;
  return error;
  //return "";
}

String Error::renommerOutputFileAlreadyExists(){
  String error = "[Error] Impossible de renommer : Le fichier de sortie existe déjà." ;
  return error;
  //return "";
}

String Error::renommerOutputPathDoesntExist(){
  String error = "[Error] Impossible de renommer : Le répertoire de sortie n'existe pas." ;
  return error;
  //return "";
}
*/

