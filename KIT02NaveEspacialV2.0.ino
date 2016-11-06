/*
Programa 02 Kit Iniciacion
La nave espacial.
Con 3 LED y un Pulsador
*/

const int LEDVerde = 3;
const int LEDRojo1 = 4;
const int LEDRojo2 = 5;
const int PULSADOR = 2;

int Estado = 0;

void setup() {
  // pines de los LED, definidos como salida
  pinMode(LEDVerde,OUTPUT);
  pinMode(LEDRojo1,OUTPUT);
  pinMode(LEDRojo2,OUTPUT);
  
  // pin del pulsador, definido como entrada
  pinMode(PULSADOR,OUTPUT);
}

void loop() {
  //leo lo que marca el pulsador
  Estado = digitalRead (PULSADOR);
  
  if(Estado == LOW) {
    // si el pulsador esta apagado
    
    digitalWrite(LEDVerde,HIGH); //LED Verde
    digitalWrite(LEDRojo1,LOW);  //LED Rojo
    digitalWrite(LEDRojo2,LOW);  //LED Rojo
    }
  else {
    // si el pulsador esta apagado
    digitalWrite(LEDVerde,LOW); //LED Verde
    digitalWrite(LEDRojo1,LOW);  //LED Rojo
    digitalWrite(LEDRojo2,HIGH);  //LED Rojo
    
    delay (250); //Retraso de 250ms
    //conmutamos LED
    digitalWrite(LEDRojo1,HIGH);  //LED Rojo
    digitalWrite(LEDRojo2,LOW);  //LED Rojo
    
    delay(250);
  }

}
