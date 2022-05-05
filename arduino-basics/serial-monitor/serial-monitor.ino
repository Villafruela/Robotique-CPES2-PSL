void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // initialise l'entrée/sortie de la led sur la carte
}
//enum command {ON, OFF};

void loop() {
  if(Serial.available()) // si on reçoit des données
  {
    String command = Serial.readStringUntil('\n'); // on lit la chaine de caractère jusqu'au retour chariot

    switch (command) {
      case "O":
        digitalWrite(LED_BUILTIN, HIGH); // on allume la led
        Serial.println("LED is turned ON"); // on log l'action sur le moniteur Série
        break;
      case "F":
        digitalWrite(LED_BUILTIN, LOW);  // on éteint la led
        Serial.println("LED is turned OFF"); // on log l'action sur le moniteur Série
        break;
    }
  }
}