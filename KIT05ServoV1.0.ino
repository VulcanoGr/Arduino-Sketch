/*
KIT 05 Sensor- Estado de animo
Problemas al sujetar el servo, sujetar con cables, NO CON LOS PINCHOS
*/

//Incluir la libreria Servo
#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  // definimos el servo y abrimos la comunicacion serial
  
  myServo.attach(9); // puerto PWM 9
  
  Serial.begin(9600);
}

void loop() {
  // leemos el valor del potenciometro y los escribimos en el monitor
  
  potVal = analogRead(potPin);
  
  Serial.print("Valor Potencial: ");
  Serial.print(potVal);
  
  // lo pasamos a angulos y lo mandamos al servo y al monitor
  
  angle = map (potVal, 0 , 1023, 0, 179);
  
  Serial.print(", Angulo: ");
  Serial.println(angle);
  
  myServo.write(angle);
  
  delay(15);
}
