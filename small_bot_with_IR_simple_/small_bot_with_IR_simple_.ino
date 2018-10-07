int Lm1 = 2;
int Lm2 = 3;
int Rm1 = 4;
int Rm2 = 5;
int ENLeft = 9;
int ENRight = 10;

int sensorPin = A0;
int sensorData;
boolean freeze = false;
int mainThreshold = 600;

void setup() {

  pinMode(Lm1, OUTPUT);
  pinMode(Lm2, OUTPUT);
  pinMode(Rm1, OUTPUT);
  pinMode(Rm2, OUTPUT);
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


  if (freeze == false) {
    sensorData = analogRead(sensorPin);
    if (sensorData >= mainThreshold) {
      freeze = true;
    }

    if (val == 'F') {
      digitalWrite(Lm1, HIGH);      digitalWrite(Rm1, HIGH);
      digitalWrite(Lm2, LOW);      digitalWrite(Rm2, LOW);
    }

    else if (val == 'B'){
      digitalWrite(Lm2, HIGH);   digitalWrite(Rm2, HIGH);
      digitalWrite(Lm1, LOW);  digitalWrite(Rm1, LOW);
    }
    
    else if (val == 'R'){
      digitalWrite(Lm1, HIGH);  digitalWrite(Rm2, HIGH);
      digitalWrite(Lm2, LOW);       digitalWrite(Rm1, LOW);
    }
    
    else if (val == 'L'){
      digitalWrite(Lm2, HIGH);  digitalWrite(Rm1, HIGH);
      digitalWrite(Lm1, LOW);       digitalWrite(Rm2, LOW);
    }

    else  {
      digitalWrite(Lm1, LOW);      digitalWrite(Rm1, LOW);
      digitalWrite(Lm2, LOW);       digitalWrite(Rm2, LOW);
    }

  }
}
