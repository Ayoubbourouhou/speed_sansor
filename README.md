# Tachymètre Optique Sans Contact

Ce dépôt contient le code source pour un tachymètre optique sans contact, également connu sous le nom de tachymètre photo. L'instrument mesure la vitesse de rotation d'un moteur en utilisant un capteur optique.

## Principes de fonctionnement

Le tachymètre utilise un laser, une lumière infrarouge ou d'autres sources lumineuses pour prendre des mesures sans contact. Le faisceau lumineux est réfléchi chaque fois qu'une bande fait une rotation complète. Le récepteur compte ces réflexions pour mesurer la vitesse de rotation en RPM (tr/min). Le capteur est basé sur le principe suivant :

- Un objet à mesurer doit avoir 4 trous, permettant au faisceau infrarouge émis par la LED d'atteindre la photodiode.
- La photodiode détecte le signal lumineux réfléchi par les trous.
- Les impulsions générées par la photodiode sont comptées par le microcontrôleur pour calculer la vitesse moyenne du moteur.

## Matériels utilisés

1. **Photodiode:** Un composant semi-conducteur détectant le rayonnement optique et le transformant en signal électrique.

2. **LED infrarouge:** Un composant émettant de la lumière infrarouge lorsqu'il est parcouru par un courant électrique.

3. **NE555:** Un circuit intégré pour la temporisation, utilisé pour générer des impulsions précises.

4. **LM358:** Un amplificateur opérationnel double utilisé dans le traitement du signal.

5. **Moteur à courant continu:** Convertisseur électromécanique permettant la conversion bidirectionnelle d'énergie entre une installation électrique et un dispositif mécanique.

## Code Arduino

```cpp
const byte PIN_SIGNAL = 2;
float speed; /* variable pour stocker la mesure de vitesse*/ 
float S; /* variable pour stocker la lecture analogique*/

/** Fonction setup() */
void setup() {
  /* Initialise le port série */ 
  Serial.begin(115200);

  /* Met la broche en entrée */ 
  pinMode(PIN_SIGNAL, INPUT_PULLUP);
  pinMode(S, 4);
}

/** Fonction loop() */
void loop() {
  /* Mesure la durée de la demi période */
  unsigned long periode = pulseIn(PIN_SIGNAL, LOW, 1000000) * 2;

  /* Affiche le résultat de la mesure en RPM */
  speed = 1000000 / periode * 60;
  S = analogRead(speed);
  delay(1000);
}
