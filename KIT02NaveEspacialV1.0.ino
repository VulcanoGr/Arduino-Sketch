/*
Programa 02 Kit Iniciacion
La nave espacial.
Con 3 LED y un Pulsador
*/

int Estado = 0;

void setup() {
  // pines de los LED, definidos como salida
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  // pin del pulsador, definido como entrada
  pinMode(2,OUTPUT);
}

void loop() {
  //leo lo que marca el pulsador
  Estado = digitalRead (2);
  
  if(Estado == LOW) {
    // si el pulsador esta apagado
    
    digitalWrite(3,HIGH); //LED Verde
    digitalWrite(4,LOW);  //LED Rojo
    digitalWrite(5,LOW);  //LED Rojo
    }
  else {
    // si el pulsador esta apagado
    digitalWrite(3,LOW); //LED Verde
    digitalWrite(4,LOW);  //LED Rojo
    digitalWrite(5,HIGH);  //LED Rojo
    
    delay (250); //Retraso de 250ms
    //conmutamos LED
    digitalWrite(4,HIGH);  //LED Rojo
    digitalWrite(5,LOW);  //LED Rojo
    
    delay(250);
  }

}
