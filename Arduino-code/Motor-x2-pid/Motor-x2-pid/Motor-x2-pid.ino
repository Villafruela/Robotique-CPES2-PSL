// Encodeur Moteur A
#define ENCMOTEURAA 3 //Blanc
#define ENCMOTEURAB 4 //Jaune
// Encodeur Moteur B
#define ENCMOTEURBA 10
#define ENCMOTEURBB 9
// Controle du moteur A
#define INAA 6
#define INAB 5
// Controle du moteur B
#define INBA 7
#define INBB 8

#define SPEED 50 // Entre 50 et 255

int posMUN = 0;

// Gestion du PID
long prevT = 0;
float eprev = 0;
float eintegral = 0;

void setup() {
  Serial.begin(9600);
  pinMode (ENCMOTEURAA,INPUT);
  pinMode (ENCMOTEURAB,INPUT);
  pinMode (INAA,OUTPUT);
  pinMode (INAB,OUTPUT);
  pinMode (INBA,OUTPUT);
  pinMode (INBB,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCMOTEURAA), readEncoder, RISING);
}

void readEncoder(){
  int b = digitalRead(ENCMOTEURAB);
  if (b>0) {
    posMUN ++;
  } else {
    posMUN --;
  }
}

void setMotor(int dir, int Speed, int IN1, int IN2) {
  //On règle la vitesse pour les 2 moteurs
  if (dir==1){
    analogWrite(IN1, Speed);
    analogWrite(IN2, 0);
  }else if (dir==-1){
    analogWrite(IN1, 0);
    analogWrite(IN2, Speed);
  } else{
    analogWrite(IN2, 0);
    analogWrite(IN2, 0);
  }
}

void loop() {
  // On définit la consigne 64 impulsions 
  int consigne = 256;

  //les constantes du PID
  float Kp = 3;
  float Ki = 0.025;
  float Kd = 0;

  // DeltaT
  long currT = micros(); // le temps actuel en micro-secondes
  float deltaT = ((float)(currT-prevT))/1.0e6; // l'intervale de temps en secondes
  prevT = currT;

  //erreur
  int e = posMUN-consigne; // Attention, suivant le cablage il faut peut-être intervertir les valeurs

  // La dérivée
  float dedt = (e-eprev)/(deltaT);

  // L'intégrale
  eintegral = eintegral+e*deltaT;

  // Controle du signal
  float u = Kp*e + Kd*dedt + Ki*eintegral;

  // Conversion en puissance pour le moteur
  float power = fabs(u);
  if (power > 255) {
    power = 255;
  }

  // Conversion en direction pour le moteur
  int dir = 1;
  if (u<0) {
    dir = -1;
  } else if (u>0) {
    dir = 1;
  }

  // On actionne les moteurs :
  setMotor(-dir, power, INAA, INAB);
  setMotor(dir,power, INBA, INBB);
  
  
  // on enregistre l'érreur précédente
  eprev = e;

  // Debugage
  Serial.println (consigne);
  Serial.println (" ");
  Serial.println (posMUN);
  Serial.println (" ");
}
