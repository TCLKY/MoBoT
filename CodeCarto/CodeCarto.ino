int sensorPin = A0; // Définit la broche analogique à laquelle le capteur est connecté
int sensorValue; // Stocke la valeur de tension lue sur la broche du capteur
float distance; // Stocke la distance calculée en fonction de la valeur de tension


void setup() {
  Serial.begin(9600); 
}

void loop() {
  sensorValue = analogRead(sensorPin); // Lit la valeur de tension du capteur
distance = -3.5241e-06 * pow(sensorValue, 3) + 0.0036398 * pow(sensorValue, 2) -  1.2264 * sensorValue + 153.18; // Calcule la distance en centimètres 
  Serial.print("Distance : "); 
  Serial.print(distance); // Affiche la distance calculée 
  Serial.println(" cm"); 
  Serial.println(sensorValue);
  
  delay(100); 
}
