int Capteur_distance = A0;  // Broche analogique pour lire le capteur IR

void setup() {
  Serial.begin (9600);  // démarre le port série
}

void loop () {
  float volts = analogRead(Capteur_distance)  * 0.0048828125;  // valeur du capteur * (5/1024)
  int distance = 25 * pow (volts, -1);  // élaboré à partir du graphique 5 = distance théorique / (1 / Volts)
  Serial.print(volts);
  Serial.print(" V");
  Serial.print(" : ");
  Serial.print(distance);
  Serial.print(" cm"); // Distance dans le moniteur série
  Serial.println("");
  Serial.print(Capteur_distance);
  Serial.print(" ");
  delay(500);

}