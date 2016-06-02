// Warning Class Header - By Clément BEGNAUD


#ifndef WARNING_H
#define WARNING_H

#include <string.h>
#include <SPI.h>
//#include <iostream>


class Warning{

public:
	static String logDoesNotExist(String nomFichier);
	static String folderDoesNotExist(String nomDossier);
  static String userCardIDNotFound(String cardID);
private:

};

#endif
