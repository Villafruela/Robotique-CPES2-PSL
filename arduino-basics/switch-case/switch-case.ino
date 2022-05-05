int valeur =1;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // initialise l'entrée/sortie de la led sur la carte
}

void loop() {
    valeur = random (1,5);

    switch (valeur) {
      case 1:
        digitalWrite(LED_BUILTIN, HIGH); // on allume la led
        Serial.print("Led allumée et la valeur est ");
        Serial.println (valeur); // on log l'action sur le moniteur Série
        delay(500);
        break;
      case 2:
        digitalWrite(LED_BUILTIN, LOW);  // on éteint la led
        Serial.print("Led allumée et la valeur est ");
        Serial.println (valeur); // on log l'action sur le moniteur Série
        delay(500);
        break;
      case 3:
        digitalWrite(LED_BUILTIN, HIGH); // on allume la led
        Serial.print("Led allumée et la valeur est ");
        Serial.println (valeur); // on log l'action sur le moniteur Série
        delay(500);
        break;
      case 4:
        digitalWrite(LED_BUILTIN, LOW);  // on éteint la led
        Serial.print("Led allumée et la valeur est ");
        Serial.println (valeur); // on log l'action sur le moniteur Série
        delay(500);
        break;
    }

}