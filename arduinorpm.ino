/* Constante pour la broche de mesure */ 
 const byte PIN_SIGNAL = 2; 
 float speed; /* variable pour stocker la mesure de vitesse*/ 
 float S; /* variable pour stocker la lecture analogique*/

 /** Fonction setup() */
 void setup() {

  /* Initialise le port série */ 
  Serial.begin(115200);

  /* Met la broche en entrée */ 
  pinMode(PIN_SIGNAL, INPUT_PULLUP);
  pinMode(S,4);
 }
 /** Fonction loop() */
 void loop() {

  /* Mesure la durée de la demi période */
  unsigned long periode = pulseIn(PIN_SIGNAL, LOW, 1000000) * 2;

  /* Affiche le résultat de la mesure en RPM */
  speed=1000000 / periode * 60;
  S=analogRead(speed);
  delay(1000);
 }
