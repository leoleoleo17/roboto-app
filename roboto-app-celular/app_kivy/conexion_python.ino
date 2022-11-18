
void setup() {
  
  Serial.begin(9600)

}

void loop() {

  if(Serial.available() >0){ //esa recibiendo datos
      char data = Serial.read(); // almacena lo que esta leyendo del puerto serial - el mensaje de python

      }
  
        
