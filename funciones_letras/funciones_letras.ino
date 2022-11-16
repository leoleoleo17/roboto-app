#include <Servo.h>
int pin_pulgar = 3;
int pin_indice = 9;
int pin_corazon = 10;
int pin_anular = 11;
int pin_menique = 12;

Servo pulgar;
Servo indice;
Servo corazon;
Servo anular;
Servo menique;

void cerrar_todo(char dedo){
  for(int i=0; i<180; i++){
    dedo.write(i);
    delay(50); //ms
  } 
}
void cerrar_parcial(char dedo){
    for(int i=0; i<90; i++){
    dedo.write(i);
    delay(50); //ms
  }
}

void abrir_todo (char dedo){
   for(int i=180; i>0; i--){
    dedo.write(i);
    delay(50); //ms 
  }   
}

void a(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
  }
void b(){
  cerrar_parcial(pulgar);
  } 
void c(){
  cerrar_parcial(meñique);
  cerrar_parcial(anular);
  cerrar_parcial(corazon);
  cerrar_parcial(indice);
  cerrar_parcial(pulgar);
}
void d(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_parcial(pulgar);
}
void e(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
  cerrar_parcial(pulgar);
}
void f(){
  cerrar_parcial(indice);
  cerrar_parcial(pulgar);
}
void g(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
}
void h(){
  cerrar_todo(menique);
  cerrar_todo(anular);
}
void i(){
  cerrar_parcial(pulgar);
  cerrar_todo(indice);
  cerrar_todo(corazon);
  cerrar_todo(anular);
}
void j(){
  cerrar_todo(pulgar);
  cerrar_todo(indice);
  cerrar_todo(corazon);
  cerrar_todo(anular);
}
void k(){
  cerrar_parcial(pulgar);
  cerrar_todo(menique);
  cerrar_todo(anular);
}
void l (){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
}
void m(){ /hay que tener en cuenta que el pulgar en teoría debe estar entre meñique y anular
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
  cerrar_todo(pulgar);
}
void n(){ /hay que tener en cuenta que el pulgar en teoría debe estar entre anular y corazón
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
  cerrar_todo(pulgar);
}
void o(){ /no sé como hacer para diferenciar de la c
  cerrar_parcial(meñique);
  cerrar_parcial(anular);
  cerrar_parcial(corazon);
  cerrar_parcial(indice);
  cerrar_parcial(pulgar);
}
void p(){
  cerrar_parcial(meñique);
  cerrar_parcial(anular);
  cerrar_parcial(corazon);
  cerrar_parcial(pulgar);
}
void q(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
}
void r(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(pulgar);
}
void s(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
  cerrar_parcial(pulgar);
  
}
void t(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
}
void u(){ /los dedos que no se extienden van pegados
  cerrar_parcial(menique);
  cerrar_parcial(anular);
  cerrar_parcial(pulgar);
}
void v(){ /los dedos que no se extienden van despegados
  cerrar_parcial(menique);
  cerrar_parcial(anular);
  cerrar_parcial(pulgar);
}
void w(){
cerrar_parcial(menique);
cerrar_parcial(pulgar);  
}
void x(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_parcial(indice);
  cerrar_todo(pulgar);
}
void y(){
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
}
void z(){
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(pulgar);
}


void setup() {
  pulgar.attach(pin_pulgar);
  indice.attach(pin_indice);
  corazon.attach(pin_corazon);
  anular.attach(pin_anular);
  menique.attach(pin_menique);
}

void loop() {
  void setup() {
  
  Serial.begin(9600)

}

void loop() {

  if(Serial.available() >0){ //esa recibiendo datos
      char data = Serial.read(); // almacena lo que esta leyendo del puerto serial - el mensaje de python

      }

}
