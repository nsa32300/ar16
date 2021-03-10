

int number = 0; 

void setup() {
 Serial.begin(9600);  
}

void loop() {
 Serial.print(number*200);   
 Serial.println(" msec");   
 delay(200);
 number++;
 
 if (number > 25) {
  number = 0;
 
 }
   
}
