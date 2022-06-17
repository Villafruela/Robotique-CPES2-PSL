//Pour Hasheur moteur alimenté en 12V

// Définition des pins
const byte moteurA_1 = A6, // prend moins de place en RAM que int
  moteurA_2 = A7,
  moteurB_1 = A4,
  moteurB_2 = A5,
  encodeurAA = 2, //D2
  encodeurAB = 3; //D3

// Définition des variables
int vitesse = 50; // (Tension) entre 50 et 255
int encA = 0;
int encB = 0;
int encPosA = 0;
int encPosB = 0;
int encPos = 0;
int vitEchantillonage = 1; // En millisecondes

// Initialisations
void setup() {
    // Configuration des ports en mode "sortie"
  Serial.begin(230400);
  pinMode (encodeurAA, INPUT);
  pinMode (encodeurAB, INPUT);
  pinMode(moteurA_1, OUTPUT);
  pinMode(moteurA_2, OUTPUT);
  pinMode(moteurB_1, OUTPUT);
  pinMode(moteurB_2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encodeurAA), readEncoderA, RISING);// Triger sur les fronts montants de capteur A
  attachInterrupt(digitalPinToInterrupt(encodeurAB), readEncoderB, RISING);// Triger les fronts montants de capteur B
  delay(5000);
}

// Récupération de la position de l'encodeur A
void readEncoderA(){
  int encA = digitalRead(encodeurAA);
  if (encA>0){
    encPosA++;
    encPos++; // positions cumulées : A+B
  }
}

// Récupération de position de l'encodeur B
void readEncoderB(){
  int encB = digitalRead(encodeurAB);
  if (encB>0){
    encPosB++;
    encPos++;
  }
}

// Pour faire avancer le robot (Les 2 moteurs en même temps)
void setMotor (int Tension) {
  analogWrite(moteurA_1, -Tension);
  analogWrite(moteurB_1, Tension);
}

// Si on ne teste que l'encodeur d'un des moteurs, pour savoir dans quel sens le moteur tourne :
// On lit la position de l'encodeur B, à chaque fois que l'encodeur A est sur un front montant (attachInterrupt Rising).
// On détermine le sens et l'incrément en fonction de la position de phase :
// Par exemple : quand l'encodeur A est Montant, si B est déjà à 1 cela veut dire qu'on avance
// Si B est à 0 cela signifie qu'on recule (évidement les sens "avancer" ou "reculer" sont dépendant de la position des
// moteurs sur le robot. 
void readEncoder (){
  int encB = digitalRead(encodeurAB);
  if (encB>0){
    encPos++;
  } else {
    encPos--;
  }
}
// Fonction pour faire avancer le robot
void forward(int voltage){
  analogWrite(moteurA_1, 0);
  analogWrite(moteurA_2, voltage);
  analogWrite(moteurB_1, 0);
  analogWrite(moteurB_2, voltage);
}

void loop() {
  if (encPosA==0){
    Serial.print("//Vitesse d'echantillonage ms : ");
    Serial.println(vitEchantillonage);
    Serial.println("Tension (0-255) de 12V;Pos Encodeur A ;Pos encodeur B");
  }
  if (encPos <=20000){
    vitesse = 50;
  } else if ((encPos > 20000) && (encPos <= 40000)){
    vitesse = 80;
  } else if ((encPos > 40000) && (encPos <= 60000)){
    vitesse = 110;
  } else if ((encPos > 60000) && (encPos <= 80000)){
    vitesse = 140;
  }  else if ((encPos > 80000) && (encPos <= 100000)){
    vitesse = 170;
  }  else if ((encPos > 100000) && (encPos <= 120000)){
    vitesse = 200;
  }  else if ((encPos > 120000) && (encPos <= 140000)){
    vitesse = 230;
  } else {
    vitesse = 0;
    Serial.print("Fin");
    Serial.print("; ");
  }

  forward(vitesse);
  Serial.print(vitesse);

  Serial.print("; ");
  //Serial.print("Pos Enc A : ");
  Serial.print(encPosA);
  Serial.print("; ");
  //Serial.print("Pos Enc B : ");
  Serial.println(encPosB);

  delay(vitEchantillonage);

  // int encPosApres = encPos;
  // Serial.print("encPosApres:");
  // Serial.print(encPosApres);
  // Serial.print("; ");
  // float delta = encPosApres - encPosAvant;
  // float tourMin = delta/(16*50)*600; //x 4 lorsqu'on prend la mesure sur un seul détecteur
  // (Avec attachInterrupt ici on ne mesure que les fronts montants de A) :
  // 16 fronts descendant pour A + 16 montants pour A + 16 descendants pour B et 16 montants pour B
  // Serial.print("delta pos:");
  // Serial.print(delta);
  // Serial.print("; ");
  // Serial.print ("tour/min : ");
  // Serial.println(tourMin);
  
}