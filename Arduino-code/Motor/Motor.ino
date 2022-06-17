// Définitiion des pin de connexion
#define ENCMOTORAA 2 //Blanc
#define ENCMOTORAB 3 //Jaune
#define INAA 6
#define INAB 7
const byte PWM = A5;

// Initialisation
void setup() {
  Serial.begin(9600);
  pinMode (ENCMOTORAA,INPUT);
  pinMode (ENCMOTORAB,INPUT);
  pinMode (INAA,OUTPUT);
  pinMode (INAB,OUTPUT);
}

// Utilisation du moteur en analogique
// dir : direction : -1 ou 1
// pwmVal : intensité envoyé au moteur (0-11.1V) sur 0-255
// pwm : pin de contrôle du moteur
// IN1 : encodeur A
// IN2 : encodeur B
void setMotor (int dir, int pwmVal, int pwm, int IN1, int IN2) {
  analogWrite(pwm, pwmVal);
  //On règle la vitesse pour les 2 moteurs
  if (dir==1){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }else if (dir==-1){
    digitalWrite(IN1, LOW);    
    digitalWrite(IN2, HIGH);
  } else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}

void loop() {
  int pwr = 150; // entre 0 et 255
  int dir = 1; // 1 ou -1
  setMotor (dir, pwr, PWM, INAA, INAB);
}
