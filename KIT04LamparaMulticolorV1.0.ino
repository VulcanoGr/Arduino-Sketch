/*
KIT 04 Lampara multicolor

CONSEJO: USAR el skecth con la luz apagada
*/

//Definir constantes y variables

const int verdeLEDPin = 9; 
const int rojoLEDPin = 10;
const int azulLEDPin = 11;

const int rojoSensorPin = A0;
const int verdeSensorPin = A1;
const int azulSensorPin = A2;

int rojoValor = 0;
int verdeValor = 0;
int azulValor = 0;

int rojoSensorValor = 0;
int verdeSensorValor = 0;
int azulSensorValor = 0;

void setup() {
  // se abre el monitor y se definen los pin de salida
  
  Serial.begin(9600);
  
  pinMode(verdeLEDPin,OUTPUT);
  pinMode(rojoLEDPin,OUTPUT);
  pinMode(azulLEDPin,OUTPUT);
  
}

void loop() {
  // lee los valores analogicos, y los representa por el monitor
  rojoSensorValor = analogRead (rojoLEDPin);
  delay(5);
  verdeSensorValor = analogRead (verdeLEDPin);
  delay(5);
  azulSensorValor = analogRead (azulLEDPin);
  delay(5);
  
  Serial.print ("Valor del Sensor \t Rojo: ");
  Serial.print (rojoSensorValor);
  Serial.print ("\t Verde: ");
  Serial.print (verdeSensorValor);
  Serial.print ("\t Azul: ");
  Serial.println (azulSensorValor);
  
  // pasamos los datos de analogico a digital
  
  rojoValor = rojoSensorValor/4;
  verdeValor = verdeSensorValor/4;
  azulValor = azulSensorValor/4;
  
  Serial.print ("Valor Sigital \t Rojo: ");
  Serial.print (rojoValor);
  Serial.print ("\t Verde: ");
  Serial.print (verdeValor);
  Serial.print ("\t Azul: ");
  Serial.println (azulValor);
  
  //Mandamos valor al LED
  
  analogWrite(rojoLEDPin,rojoValor);
  analogWrite(verdeLEDPin,verdeValor);
  analogWrite(azulLEDPin,azulValor);
  
}
