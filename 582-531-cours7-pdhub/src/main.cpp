#include <Arduino.h>
#include <FastLED.h> //importer biblio doit garder
CRGB monPixel; //Doit l'appeler pour donner la couleur
#define BROCHE_ATOM_BOUTON_ROUGE 32 //32 super important
#define ATOM_LIGHT 26 //Pour appeler la couleur du bouton

#define BROCHE_ATOM_BOUTON 39

#include <M5_PbHub.h>
M5_PbHub myPbHub;

#define KEY_CHANNEL 0 //num ou branché

//CRGB keyPixel; Pu besoin

void setup() {
  FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1); //Garder la couleur pixel
  //FastLED.addLeds<WS2812, 26, GRB>(&keyPixel, 1);

  //pinMode( BROCHE_ATOM_BOUTON_ROUGE , INPUT ); //S'assurer que la broche reliée au bouton est en mode entrée
  pinMode( BROCHE_ATOM_BOUTON , INPUT );

  Wire.begin();
  myPbHub.begin();

  myPbHub.setPixelCount( KEY_CHANNEL ,  1 ); //1 pixel
}

void loop() {
  //int maLectureAtomBoutonRouge = digitalRead( BROCHE_ATOM_BOUTON_ROUGE  ); //Chercher la lecture du bouton

  int maLectureKey = myPbHub.digitalRead( KEY_CHANNEL );

  int maLectureAtomBouton = digitalRead( BROCHE_ATOM_BOUTON  );

  if ( maLectureAtomBouton == 0) { //La lecture de mon bouton
    monPixel = CRGB(255,255,0); //Bouton couleur jaune au clic
  } else {
    monPixel = CRGB(0,0,0); //Si non bouton pas couleur
  }

  if ( maLectureKey == 0) { //La lecture de mon bouton rouge
    myPbHub.setPixelColor( KEY_CHANNEL , 0 , 255, 255,0 ); //Bouton couleur jaune au clic
  } else {
    myPbHub.setPixelColor( KEY_CHANNEL , 0 , 0, 0, 0 ); //Si non bouton pas couleur
  }

  FastLED.show(); //Le montre suite à l'envoie du code avec fleche

  delay(20); //Delais pour que sa marche sur l'ordi
}


