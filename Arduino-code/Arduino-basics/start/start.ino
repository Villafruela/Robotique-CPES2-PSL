// Chargement de librairies
//#include <Servo.h>

// Définition des entrées/sorties & `constantes
#define PIN1  1


// Définition de variables globales
int a = 25;
int b = 7;
float reel = 123.453;

// Initialisation & setup
void setup() {
  Serial.begin(9600);
}

// La boucle d'exécution
void loop() {
  int c = a+b;
  Serial.println (a+b);                 
}




