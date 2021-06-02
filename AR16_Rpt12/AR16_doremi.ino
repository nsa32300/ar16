int buzzerPin = 9;

const int DO = 3;
const int MI = 5;
const int SOL = 6;

void setup() {
  pinMode(buzzerPin,OUTPUT);
  pinMode(DO, INPUT_PULLUP);
  pinMode(MI, INPUT_PULLUP);
  pinMode(SOL, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(DO) == LOW){
    tone(buzzerPin,262,100);
  }
  if(digitalRead(MI) == LOW){
    tone(buzzerPin,330,100);
  }
  if(digitalRead(SOL) == LOW){
    tone(buzzerPin,392,100);
  }
}  
