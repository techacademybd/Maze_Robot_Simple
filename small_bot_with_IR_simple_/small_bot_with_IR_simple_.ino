int lm1 = 2;
int lm2 = 3;
int rm1 = 4;
int rm2 = 5;
int ENLeft = 9;
int ENRight = 10;

int sensorPin = A0;
int sensorData;
boolean freeze = false;
int mainThreshold = 600;

void setup() {

  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(ENLeft, OUTPUT);
  pinMode(ENRight, OUTPUT);

  analogWrite(ENLeft, 100);
  analogWrite(ENRight, 100);

  
  Serial.begin(9600);
}

void loop() {

  while (Serial.available() == 0 ) {
  }
  
  char val = Serial.read() ;

 
 if(freeze==false){
    sensorData = analogRead(sensorPin);
    if (sensorData >= mainThreshold) {
    freeze = true;
  }

    if (val == 'F') {
      
      digitalWrite(lm1, HIGH);      digitalWrite(rm1, HIGH);
      digitalWrite(lm2, LOW);      digitalWrite(rm2, LOW);
    }

    else if (val == 'B')
    {
      digitalWrite(lm2, HIGH);   digitalWrite(rm2, HIGH);
      digitalWrite(lm1, LOW);  digitalWrite(rm1, LOW);

    }
    else if (val == 'R')
    {
      digitalWrite(lm1, HIGH);  digitalWrite(rm2, HIGH);
      digitalWrite(lm2, LOW);       digitalWrite(rm1, LOW);
    }
   
    else if (val == 'L')
    {
      digitalWrite(lm2, HIGH);  digitalWrite(rm1, HIGH);
      digitalWrite(lm1, LOW);       digitalWrite(rm2, LOW);
    }

    else  {
      digitalWrite(lm1, LOW);      digitalWrite(rm1, LOW);
      digitalWrite(lm2, LOW);       digitalWrite(rm2, LOW);

    }

 }
}
