int number =0;

String stringValue[]={"number : ", "Binary : ", "Hexadecimal : "};

void setup() {
  Serial.begin(9600);
}

void loop(){

  Serial.print("Number = ");
  Serial.print(number);
  Serial.print(", ");
  Serial.print(stringValue[0]);
  Serial.print(number,BIN);
  Serial.print(", ");
  Serial.print(stringValue[1]);
  Serial.print(number,HEX);
  Serial.println();

  number++;

if(number > 15) { 
Serial.println("mission complete");
delay(1000);
exit(0);}


  delay(1000);
}
