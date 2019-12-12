/// Boulay Alexis ///
/// Last entry 12 December 2019

/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/
#define LED 7

#include <SPI.h>
#include <SD.h>
#include <string.h>

File myFile;

// Permet d'inscrire une donnée sur la carte SD
//// Impossibilité de récuperer plusieurs données en même temps
template <class D> void writeonSD(File cartesd, const char* monfichier, D data) 
{
  cartesd=SD.open(monfichier, FILE_WRITE);
  if (cartesd)
  {
    cartesd.println(data);
    cartesd.close();
  }
}


void setup() {

  // En cas de bug, la LED reste allumée
  pinMode(LED,OUTPUT);
  digitalWrite(LED, HIGH);
  
  if (!SD.begin(10)) {
   // Indiquer que la carte est mal configurer (LED/Signal sonore tres agacant/serial pour les test)
    while (1);
  }
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  writeonSD(myFile,"test.txt","J'écris donc je suis !"); //Attention ne fonction pas avec des tabs
  writeonSD(myFile,"test.txt",6546);

  digitalWrite(LED,LOW);
}

void loop() {
  // nothing happens after setup
}