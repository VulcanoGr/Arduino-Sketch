/* 
KIT 06 Sonido, calibracion de un buffer y contrucion de un theremin

*/

// definimos valores de los sensores

int valorsensor;
int sensorLow = 1023;
int sensorHigh =0;

// usa el pin 13 como LED fin de calibracion

const int LEDRef = 13;

// calibracion

void setup() {
  // LED encendido
  pinMode (LEDRef, OUTPUT);
  digitalWrite(LEDRef, HIGH);
  
  //calibramos con while
  
  while(millis() < 5000){
  
    valorsensor = analogRead(A0); // lee el valor del sensor pin A0
    
    if(valorsensor > sensorHigh){
    
      sensorHigh = valorsensor;
    
    }
  
    if(valorsensor < sensorLow){
    
      sensorLow = valorsensor;
    
    }
  }
  
  //Apagamos el LED
  
  digitalWrite(LEDRef, LOW);

}

void loop() {
  
  valorsensor = analogRead(A0); // lee el valor del sensor pin A0
  
  // creamos una variable y esa se mapea con el valor del sensor y los valores extremos
  
  int pitido = map(valorsensor, sensorLow, sensorHigh, 50, 4000);
  
  // lo mandamos al buzzer
  
  tone(8,pitido,20);
  
  delay(10);

}
