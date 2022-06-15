#define EncodeurA 2
#define EncodeurB 3

void setup() {
  //On ouvre le port Série
  Serial.begin(9600);
// On place les pin 2 et 3 en mode lecture
  pinMode(EncodeurA, INPUT);
  pinMode(EncodeurB, INPUT);
}

void loop() {
  // On lit les valeur de l'encodeur
  int A = digitalRead(EncodeurA);
  int B = digitalRead(EncodeurB);
  // On imprime sur le port Série
  Serial.print(A*5);
  Serial.print("; ");
  Serial.print(B*5);
  Serial.println();
  delay(500);
}
