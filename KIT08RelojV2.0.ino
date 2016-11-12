/*
  KIT 08 Reloj de arena V2.0
  
  Con el sensor de inclinacion y LED 
  
  Menos tiempo y cuando se encienden todos los LED estos se encienden y se apagan uno por uno

*/


//definimos variables
const int senincpin = 8;

unsigned long tiempoprevio = 0;

int estadoseninc = 0;
int preestadoseninc = 0;

int led = 2;

// intervalo de 6 seg
long intervalo = 6000;


void setup() {
  // definimos los pin de los LED
  for(int x = 2;x<8;x++){
    pinMode(x, OUTPUT);
  }
  
  // Y el del sensor 
  pinMode(senincpin,INPUT);
  
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  // lee el tiempo transcurrido
  unsigned long tiempo = millis();
  
  //calcula el tiempo para ver si se ha de encender un LED
  if(tiempo - tiempoprevio > intervalo){
    tiempoprevio = tiempo;
    
    //enciende un LED
    digitalWrite(led,HIGH);
    // aumenta el nuevo pin del LED
    led++;
    
    if(led == 7){
      // enciende el LED 7
      digitalWrite(led,HIGH);
      delay(1000);
      
      for(int x = 2;x<7;x++){
        digitalWrite(x, LOW);
        delay(1000);
      }
      
      for(int x = 2;x<7;x++){
        digitalWrite(x, HIGH);
        delay(1000);
      }
    }
  }
  
  // leemos de nuevo el valor del sensor
  estadoseninc = digitalRead(senincpin);
  
  // si ha cambiado volvemos a la posicion inicial
  if(estadoseninc != preestadoseninc){
  
    // apagamos LED
    for(int x = 2;x<8;x++){
      digitalWrite(x, LOW);
    }
    
    led = 2;
    tiempoprevio = tiempo;
  }
  
  preestadoseninc = estadoseninc;
}
