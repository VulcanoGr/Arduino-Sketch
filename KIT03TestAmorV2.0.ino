/*
Arduino StarKIT 03 La pruebra del amor con la temperatura
V2.0 Mas LED, y ajuste de la temperatura mas fino
*/

const int sensorPIN = A0;
const float baselineTemp = 20.0;

void setup() {
  // Abre un puerto serie
  Serial.begin(9600);
  
  // Inicializamos los LED como salida y los apagamos
  
  for (int pinNumber = 2; pinNumber <8; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // leemos el valor del sensor de temperatura (analogico)
  int sensorVal = analogRead(sensorPIN);

  Serial.print("Valor del Sensor: "); 
  Serial.print(sensorVal);
  
  // convertimos el valor del sensor en voltios
  float voltaje = (sensorVal/1024.0)*5.0;
  
  Serial.print(" , Voltaje: "); 
  Serial.print(voltaje);
  
  // calculamos la tension en Temperatura
  float temperatura = (voltaje - .5)*100;
 
  Serial.print(" , Temperatura: ");  
  Serial.println(temperatura);
  
  // segun el valor encendemos LED
  if(temperatura < baselineTemp+1){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }else if(temperatura >= baselineTemp+1 && temperatura < baselineTemp+2){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }else if(temperatura >= baselineTemp+2 && temperatura < baselineTemp+3){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }else if(temperatura >= baselineTemp+3 && temperatura < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }else if(temperatura >= baselineTemp+4 && temperatura < baselineTemp+5){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }else if(temperatura >= baselineTemp+5 && temperatura < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }else if(temperatura >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }
  delay(10);
}
