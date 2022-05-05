#define ENCMOTORAA 3 //Blanc
#define ENCMOTORAB 4 //Jaune
#define INAA 6
#define INAB 5
#define SPEED 50 // Entre 50 et 255

// Position Moteur 1
int posMUN = 0;
// Encodeur A du Moteur A
int MAA = 0;
// Encodeur B du Moteur A
int MAB = 0;

void setup() {
  Serial.begin(9600);
  pinMode (ENCMOTORAA,INPUT);
  pinMode (ENCMOTORAB,INPUT);
  pinMode (INAA,OUTPUT);
  pinMode (INAB,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCMOTORAA), readEncoder, RISING);
}

void readEncoder(){
  int b = digitalRead(ENCMOTORAB);
  if (b>0) {
    posMUN ++;
  } else {
    posMUN --;
  }
}

// Utilisation du moteur en digital (vitesse par défaut)
void setMotorD(int dir, int IN1, int IN2) {
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

// Utilisation du moteur en digital (vitesse par défaut)
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
  setMotorD(1, INAA, INAB);
  delay (3000);
  //setMotor(1, 100, INAA, INAB);
  //delay (3000);
  //setMotor(-1, 100, INAA, INAB);
  //delay (3000);
  //setMotor(1, 200, INAA, INAB);
  //delay (3000);
  //setMotor(-1, 200, INAA, INAB);
  //delay (3000);
  //setMotor(0,0,INAA, INAB);
  MAA = digitalRead(ENCMOTORAA);
  MAB = digitalRead(ENCMOTORAB);
  Serial.print("MAA : ");
  Serial.println(MAA);
  Serial.print("MAB : ");
  Serial.println(MAB);
  Serial.print("Pos Moteur 1 : ");
  Serial.println(posMUN);
}
