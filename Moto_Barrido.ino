const int stepPin = 3; 
const int dirPin = 4; 
const int inputPin = 5;
const int inputPin1 = 6;
const int inputPin2 = 7;
char rotar = 0;
int value = 0;
int value1 = 0;
int value2 = 0;
int contador = 0;

void setup() {

  Serial.begin(9600);
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(inputPin,INPUT); 
  pinMode(inputPin1,INPUT);
  pinMode(inputPin2,INPUT);
}
void loop() {
  /*value = digitalRead(inputPin);
  value1 = digitalRead(inputPin1);
  value2 = digitalRead(inputPin2);

  if (value == HIGH){
    rotar = 1;
    digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction

  }
  if(value1 == HIGH){
    rotar = 2;
    digitalWrite(dirPin,LOW);
  }

  if(value2 == HIGH){
    rotar = 3;
  }*/

  if (Serial.available() > 0) {
    motor = Serial.read();

    if(motor == 'A'){
      rotar = 1;
    }else if(motor == 'B'){
      rotar = 2;
    }else if(motor == 'C'){
      rotar = 3;
    }
  }
  if(rotar == 1){
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500);
    contador++;
  }else if(rotar == 2){
    for(int x = 0; x < (contador - 1); x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    }
    contador = 0;
  }else if(rotar == 3){
    Serial.print(contador);
    rotar = 0;
  }
}
