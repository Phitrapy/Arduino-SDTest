// Error Class Header - By Clément BEGNAUD
#ifndef ERROR_H
#define ERROR_H

#include <String.h>
//#include <iostream>

class Error{

public:
	static String cannotOpen(String nomFichier);
  static String peopleNotRemoved(String nom, String prenom, String cardID);
  static String bufNotRemoved();
  static String renommerGeneric();
  static String renommerInputFileDoesntExists();
  static String renommerOutputFileAlreadyExists();
  static String renommerOutputPathDoesntExist();

private: 

};

#endif
