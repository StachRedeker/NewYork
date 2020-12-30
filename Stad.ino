/// Stach Redeker ///
/// The city that never sleeps ///
/// (c) 2021 ///


// nummers waar de LED-circuits aanzitten
const int WitPin = 10;     
const int BlauwPin =  9;     
const int GeelPin =  8;      
const int PaarsPin =  7;      
const int GrijsPin =  6;      
const int GroenPin =  5;      
const int OranjePin =  4;      
const int BruinPin =  3;      

// en aan deze pin zit het doorbrandmechanisme voor de pot met verf
const int VerfPin =  2;       

// en nu de kansen op succes (lichtcircuit gaat uit)
// het getal staat voor 1/kans
// voorbeeld: uit 2 volgt -> kans = 1/2 = 50%
int WitOdd = 32;
int BlauwOdd = 16;
int GeelOdd = 8;
int PaarsOdd = 8;
int GrijsOdd = 4;
int GroenOdd = 4;
int OranjeOdd = 2;
int BruinOdd = 2;

// en nu de randomnummervariabelen
int WitRandNumber;
int BlauwRandNumber;
int GeelRandNumber;
int PaarsRandNumber;
int GrijsRandNumber;
int GroenRandNumber;
int OranjeRandNumber;
int BruinRandNumber;

// tot slot nog een optelvariable
// deze gebruiken we later
int VerfNumber;


void setup() {
  
// uncomment de regel hieronder als je de getallen via een computer wil monitoren 
// Serial.begin(9600);
  
// leest de lege pin A0 af. Hier zit geen component aan, dus de Arduino krijgt gibberish terug
// dat gebruikt hij om een RandomSeed te genereren
  randomSeed(analogRead(0));

// alle pins waar de relais/lampjes/lichtcircuits aanzitten, defineren als outputs
pinMode(WitPin, OUTPUT);
pinMode(BlauwPin, OUTPUT);
pinMode(GeelPin, OUTPUT);
pinMode(PaarsPin, OUTPUT);
pinMode(GrijsPin, OUTPUT);
pinMode(GroenPin, OUTPUT);
pinMode(OranjePin, OUTPUT);
pinMode(BruinPin, OUTPUT);

// alle lampjes testen
digitalWrite(WitPin, LOW);
digitalWrite(BlauwPin, LOW);
digitalWrite(GeelPin, LOW);
digitalWrite(PaarsPin, LOW);
digitalWrite(GrijsPin, LOW);
digitalWrite(GroenPin, LOW);
digitalWrite(OranjePin, LOW);
digitalWrite(BruinPin, LOW);

delay(2000);

}


void loop() {
  
// m.b.v. de randomSeed genereren we 8 pseudorandom nummers
// de Arduino kiest een nummer van 0 tot en met ([Kleur]Odd - 1)
// en slaat dit getal op in de variabele [Kleur]RandNumber
WitRandNumber = random(WitOdd);
BlauwRandNumber = random(BlauwOdd);
GeelRandNumber = random(GeelOdd);
PaarsRandNumber = random(PaarsOdd);
GrijsRandNumber = random(GrijsOdd);
GroenRandNumber = random(GroenOdd);
OranjeRandNumber = random(OranjeOdd);
BruinRandNumber = random(BruinOdd);


// dan passen we nu wat logic toe
// als [Kleur]RandNumber gelijk is aan 0, moet het lichtcircuit uitgaan
// als [Kleur]RandNumber niet gelijk is aan 0, moet het lichtcircuit aangaan
 if (WitRandNumber == 0) {
    // lamp moet uit:
    digitalWrite(WitPin, HIGH);
  } else {
    // lamp moet aan:
    digitalWrite(WitPin, LOW);
  }
delay(1000);

 if (BlauwRandNumber == 0) {
    // lamp moet uit:
    digitalWrite(BlauwPin, HIGH);
  } else {
    // lamp moet aan:
    digitalWrite(BlauwPin, LOW);
  }
delay(1000);

 if (GeelRandNumber == 0) {
    // lamp moet uit:
    digitalWrite(GeelPin, HIGH);
  } else {
    // lamp moet aan:
    digitalWrite(GeelPin, LOW);
  }
delay(1000);

 if (PaarsRandNumber == 0) {
    // lamp moet uit:
    digitalWrite(PaarsPin, HIGH);
  } else {
    // lamp moet aan:
    digitalWrite(PaarsPin, LOW);
  }
delay(1000);

 if (GrijsRandNumber == 0) {
    // lamp moet uit:
    digitalWrite(GrijsPin, HIGH);
  } else {
    // lamp moet aan:
    digitalWrite(GrijsPin, LOW);
  }
delay(1000);

 if (GroenRandNumber == 0) {
    // lamp moet uit:
    digitalWrite(GroenPin, HIGH);
  } else {
    // lamp moet aan:
    digitalWrite(GroenPin, LOW);
  }
delay(1000);

 if (OranjeRandNumber == 0) {
    // lamp moet uit:
    digitalWrite(OranjePin, HIGH);
  } else {
    // lamp moet aan:
    digitalWrite(OranjePin, LOW);
  }
delay(1000);

 if (BruinRandNumber == 0) {
    // lamp moet uit:
    digitalWrite(BruinPin, HIGH);
  } else {
    // lamp moet aan:
    digitalWrite(BruinPin, LOW);
  }
delay(1000);


// dan berekenen we nu het VerfNumber 
// dat is een optelsom van alle pseudo-randomgegenereerde nummers
VerfNumber = (WitRandNumber + BlauwRandNumber + GeelRandNumber + PaarsRandNumber + GrijsRandNumber + GroenRandNumber + OranjeRandNumber + BruinRandNumber);

// uncomment de regel hieronder als je de getallen via een computer wil monitoren 
// Serial.println(VerfNumber);

// en als dat VerfNumber gelijk is aan 0, zijn dus alle lichtcircuits uit
// daaruit volgt:
 if (VerfNumber == 0) {
    // verf moet vallen:
    delay(5000);
    digitalWrite(VerfPin, LOW);
  } else {
    // verf moet niet vallen:
    digitalWrite(VerfPin, HIGH);
  }


// tot slot nog heel even wachten voordat we aan een nieuwe loop beginnen
delay(2000);

}
