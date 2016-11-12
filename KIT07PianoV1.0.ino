/*
  KIT 07 Piano
  
  Crear un piano con un buzzer y un pulsador

*/

// definimos variables

//definimos las notas, frecuencias
int notas[] = {262,294,330,349}; 

void setup() {
  // solamente abrimos el puero serie
  Serial.begin(9600);
}

void loop() {
  // variable local que lee A0
  int valor = analogRead(A0);
  
  //imprimimos por puert serie
  Serial.println(valor);
  
  if(valor == 1023){
    tone(8,notas[0]); 
  }
  else if(valor >= 990 && valor <= 1010){
    tone(8,notas[1]);    
  }
  else if(valor >= 505 && valor <= 515){
    tone(8,notas[2]);    
  }
  else if(valor >= 5 && valor <= 10){
    tone(8,notas[3]);    
  }
  else{
    noTone(8);
  }

}
