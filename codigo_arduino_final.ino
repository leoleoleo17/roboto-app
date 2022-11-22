#include <SoftwareSerial.h>
#include <Servo.h>
#include <LedControl.h>
#define demora 1000

int pin_pulgar = 5;
int pin_indice = 6;
int pin_corazon = 9;
int pin_anular = 11;
int pin_menique = 10;

LedControl lc=LedControl(8,7,4,1);
LedControl led = LedControl(DIN, CLK, CS, 1);
SoftwareSerial BTSerial(2,3);

Servo pulgar;
Servo indice;
Servo corazon;
Servo anular;
Servo menique;

byte arriba[8]= {B00011000, B00111100, B01111110, B11111111, B00011000, B00011000, B00011000, B00011000};

byte abajo[8] = {B00011000, B00011000, B00011000, B00011000, B11111111, B01111110, B00111100, B00011000};

byte izquierda[8] = {B00011000, B00011100, B00011110, B11111111, B11111111, B00011110, B00011100, B00011000};

byte derecha[8] = {B00011000, B00111000, B01111000, B11111111, B11111111, B01111000, B00111000, B00011000};

void cerrar_todo(Servo dedo){
  for(int i=0; i<180; i++){
    dedo.write(i);
    delay(5); //ms
  } 
}

void cerrar_parcial(Servo dedo){
    for(int i=0; i<90; i++){
    dedo.write(i);
    delay(5); //ms
  }
}

void abrir_todo (Servo dedo){
   for(int i=180; i>0; i--){
    dedo.write(i);
    delay(5); //ms 
  }   
}

void abrir_toda_la_mano(){
    abrir_todo(pulgar);
    abrir_todo(indice);
    abrir_todo(corazon);
    abrir_todo(anular);
    abrir_todo(menique);
}

void f_arriba () {
  for (int i = 0; i < 8; i++){
    led.setRow(0, i, arriba[i]);
  }
}

void f_abajo () {
  for (int i = 0; i < 8; i++){
    led.setRow(0, i, abajo[i]);
  }
}

void f_izq () {
  for (int i = 0; i < 8; i++){
    led.setRow(0, i, izquierda[i]);
  }
}

void f_der () {
  for (int i = 0; i < 8; i++){
    led.setRow(0, i, derecha[i]);
  }
}

void a(){
  abrir_toda_la_mano();
  
  byte A[8]={0b00000000,0b00111100,0b01100110,0b01100110,0b01111110,0b01100110,0b01100110,0b01100110};
  lc.setRow(0,0,A[0]);
  lc.setRow(0,1,A[1]);
  lc.setRow(0,2,A[2]);
  lc.setRow(0,3,A[3]);
  lc.setRow(0,4,A[4]);
  lc.setRow(0,5,A[5]);
  lc.setRow(0,6,A[6]);
  lc.setRow(0,7,A[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);

  delay(5000);
}

void b(){
  abrir_toda_la_mano();
  
  byte B[8]={0b00000000,0b01111100,0b01100110,0b01100110,0b01111100,0b01100110,0b01100110,0b01111100};
  lc.setRow(0,0,B[0]);
  lc.setRow(0,1,B[1]);
  lc.setRow(0,2,B[2]);
  lc.setRow(0,3,B[3]);
  lc.setRow(0,4,B[4]);
  lc.setRow(0,5,B[5]);
  lc.setRow(0,6,B[6]);
  lc.setRow(0,7,B[7]);
  f_arriba();
  
  cerrar_todo(pulgar);
  
  delay(5000);
}
 
void c(){
  abrir_toda_la_mano();
  
  byte C[8]={0b00000000,0b00111100,0b01100110,0b01100000,0b01100000,0b01100000,0b01100110,0b00111100};
  lc.setRow(0,0,C[0]);
  lc.setRow(0,1,C[1]);
  lc.setRow(0,2,C[2]);
  lc.setRow(0,3,C[3]);
  lc.setRow(0,4,C[4]);
  lc.setRow(0,5,C[5]);
  lc.setRow(0,6,C[6]);
  lc.setRow(0,7,C[7]);
  f_arriba();
  
  cerrar_parcial(menique);
  cerrar_parcial(anular);
  cerrar_parcial(corazon);
  cerrar_parcial(indice);
  cerrar_parcial(pulgar);

  delay(5000);
}

void d(){
  abrir_toda_la_mano();
  
  byte D[8]={0b00000000,0b01111100,0b01100110,0b01100110,0b01100110,0b01100110,0b01100110,0b01111100};
  lc.setRow(0,0,D[0]);
  lc.setRow(0,1,D[1]);
  lc.setRow(0,2,D[2]);
  lc.setRow(0,3,D[3]);
  lc.setRow(0,4,D[4]);
  lc.setRow(0,5,D[5]);
  lc.setRow(0,6,D[6]);
  lc.setRow(0,7,D[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_parcial(pulgar);

  delay(5000);
}

void e(){
  abrir_toda_la_mano();
  
  byte E[8]={0b00000000,0b01111110,0b01100000,0b01100000,0b01111100,0b01100000,0b01100000,0b01111110};
  lc.setRow(0,0,E[0]);
  lc.setRow(0,1,E[1]);
  lc.setRow(0,2,E[2]);
  lc.setRow(0,3,E[3]);
  lc.setRow(0,4,E[4]);
  lc.setRow(0,5,E[5]);
  lc.setRow(0,6,E[6]);
  lc.setRow(0,7,E[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
  cerrar_parcial(pulgar);

  delay(5000);
}

void f(){
  abrir_toda_la_mano();
  
  byte f[8]={0b00000000,0b01111110,0b01100000,0b01100000,0b01111100,0b01100000,0b01100000,0b01100000};
  lc.setRow(0,0,f[0]);
  lc.setRow(0,1,f[1]);
  lc.setRow(0,2,f[2]);
  lc.setRow(0,3,f[3]);
  lc.setRow(0,4,f[4]);
  lc.setRow(0,5,f[5]);
  lc.setRow(0,6,f[6]);
  lc.setRow(0,7,f[7]);
  f_arriba();
  
  cerrar_parcial(indice);
  cerrar_parcial(pulgar);

  delay(5000);
}

void g(){
  abrir_toda_la_mano();
  
  byte G[8]={0b00000000,0b00111100,0b01100110,0b01100000,0b01100000,0b01101110,0b01100110,0b00111100};
  lc.setRow(0,0,G[0]);
  lc.setRow(0,1,G[1]);
  lc.setRow(0,2,G[2]);
  lc.setRow(0,3,G[3]);
  lc.setRow(0,4,G[4]);
  lc.setRow(0,5,G[5]);
  lc.setRow(0,6,G[6]);
  lc.setRow(0,7,G[7]);
  f_abajo();
  delay(demora);
  f_der();
  delay(demora);
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);

  delay(5000);
}

void h(){
  abrir_toda_la_mano();
  
  byte H[8]={0b00000000,0b01100110,0b01100110,0b01100110,0b01111110,0b01100110,0b01100110,0b01100110};
  lc.setRow(0,0,H[0]);
  lc.setRow(0,1,H[1]);
  lc.setRow(0,2,H[2]);
  lc.setRow(0,3,H[3]);
  lc.setRow(0,4,H[4]);
  lc.setRow(0,5,H[5]);
  lc.setRow(0,6,H[6]);
  lc.setRow(0,7,H[7]);
  f_der();
  delay(demora);
  
  cerrar_todo(menique);
  cerrar_todo(anular);

  delay(5000);
}

void I(){
  abrir_toda_la_mano();
  
  byte I[8]={0b00000000,0b00111100,0b00011000,0b00011000,0b00011000,0b00011000,0b00011000,0b00111100};
  lc.setRow(0,0,I[0]);
  lc.setRow(0,1,I[1]);
  lc.setRow(0,2,I[2]);
  lc.setRow(0,3,I[3]);
  lc.setRow(0,4,I[4]);
  lc.setRow(0,5,I[5]);
  lc.setRow(0,6,I[6]);
  lc.setRow(0,7,I[7]);
  f_arriba();
  
  cerrar_todo(indice);
  cerrar_todo(corazon);
  cerrar_todo(anular);
  cerrar_parcial(pulgar);

  delay(5000);
}

void j(){
  abrir_toda_la_mano();
  
  byte J[8]={0b00000000,0b00011110,0b00001100,0b00001100,0b00001100,0b01101100,0b01101100,0b00111000};
  lc.setRow(0,0,J[0]);
  lc.setRow(0,1,J[1]);
  lc.setRow(0,2,J[2]);
  lc.setRow(0,3,J[3]);
  lc.setRow(0,4,J[4]);
  lc.setRow(0,5,J[5]);
  lc.setRow(0,6,J[6]);
  lc.setRow(0,7,J[7]);
  f_abajo();
  
  cerrar_todo(indice);
  cerrar_todo(corazon);
  cerrar_todo(anular);
  cerrar_todo(pulgar);

  delay(5000);
}

void k(){
  abrir_toda_la_mano();
  
  byte K[8]={0b00000000,0b01100110,0b01101100,0b01111000,0b01110000,0b01111000,0b01101100,0b01100110};
  lc.setRow(0,0,K[0]);
  lc.setRow(0,1,K[1]);
  lc.setRow(0,2,K[2]);
  lc.setRow(0,3,K[3]);
  lc.setRow(0,4,K[4]);
  lc.setRow(0,5,K[5]);
  lc.setRow(0,6,K[6]);
  lc.setRow(0,7,K[7]);
  f_der();
  
  cerrar_parcial(pulgar);
  cerrar_todo(menique);
  cerrar_todo(anular);

  delay(5000);
}

void l(){
  abrir_toda_la_mano();
  
  byte L[8]={0b00000000,0b01100000,0b01100000,0b01100000,0b01100000,0b01100000,0b01100000,0b01111110};
  lc.setRow(0,0,L[0]);
  lc.setRow(0,1,L[1]);
  lc.setRow(0,2,L[2]);
  lc.setRow(0,3,L[3]);
  lc.setRow(0,4,L[4]);
  lc.setRow(0,5,L[5]);
  lc.setRow(0,6,L[6]);
  lc.setRow(0,7,L[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);

  delay(5000);
}

void m(){ //hay que tener en cuenta que el pulgar en teoría debe estar entre meñique y anular
  abrir_toda_la_mano();
  
  byte M[8]={0b00000000,0b01100011,0b01110111,0b01111111,0b01101011,0b01100011,0b01100011,0b01100011};
  lc.setRow(0,0,M[0]);
  lc.setRow(0,1,M[1]);
  lc.setRow(0,2,M[2]);
  lc.setRow(0,3,M[3]);
  lc.setRow(0,4,M[4]);
  lc.setRow(0,5,M[5]);
  lc.setRow(0,6,M[6]);
  lc.setRow(0,7,M[7]);
  f_abajo();

  cerrar_todo(pulgar);
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);

  delay(5000);
}

void n(){ //hay que tener en cuenta que el pulgar en teoría debe estar entre anular y corazón
  abrir_toda_la_mano();
  
  byte N[8]={0b00000000,0b01100011,0b01110011,0b01111011,0b01101111,0b01100111,0b01100011,0b01100011};
  lc.setRow(0,0,N[0]);
  lc.setRow(0,1,N[1]);
  lc.setRow(0,2,N[2]);
  lc.setRow(0,3,N[3]);
  lc.setRow(0,4,N[4]);
  lc.setRow(0,5,N[5]);
  lc.setRow(0,6,N[6]);
  lc.setRow(0,7,N[7]);
  f_abajo();
  
  cerrar_todo(pulgar);
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);

  delay(5000);
}

void o(){ //no sé como hacer para diferenciar de la c
  abrir_toda_la_mano();
  
  byte O[8]={0b00000000,0b00111100,0b01100110,0b01100110,0b01100110,0b01100110,0b01100110,0b00111100};
  lc.setRow(0,0,O[0]);
  lc.setRow(0,1,O[1]);
  lc.setRow(0,2,O[2]);
  lc.setRow(0,3,O[3]);
  lc.setRow(0,4,O[4]);
  lc.setRow(0,5,O[5]);
  lc.setRow(0,6,O[6]);
  lc.setRow(0,7,O[7]);
  f_arriba();
  
  cerrar_parcial(menique);
  cerrar_parcial(anular);
  cerrar_parcial(corazon);
  cerrar_parcial(indice);
  cerrar_parcial(pulgar);

  delay(5000);
}

void p(){
  abrir_toda_la_mano();
  
  byte P[8]={0b00000000,0b01111100,0b01100110,0b01100110,0b01100110,0b01111100,0b01100000,0b01100000};
  lc.setRow(0,0,P[0]);
  lc.setRow(0,1,P[1]);
  lc.setRow(0,2,P[2]);
  lc.setRow(0,3,P[3]);
  lc.setRow(0,4,P[4]);
  lc.setRow(0,5,P[5]);
  lc.setRow(0,6,P[6]);
  lc.setRow(0,7,P[7]);
  f_abajo();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_parcial(corazon);
  cerrar_parcial(pulgar);

  delay(5000);
}

void q(){
  abrir_toda_la_mano();
  
  byte Q[8]={0b00000000,0b00111100,0b01100110,0b01100110,0b01100110,0b01101110,0b00111100,0b00000110};
  lc.setRow(0,0,Q[0]);
  lc.setRow(0,1,Q[1]);
  lc.setRow(0,2,Q[2]);
  lc.setRow(0,3,Q[3]);
  lc.setRow(0,4,Q[4]);
  lc.setRow(0,5,Q[5]);
  lc.setRow(0,6,Q[6]);
  lc.setRow(0,7,Q[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_parcial(pulgar);

  delay(5000);
}

void r(){
  abrir_toda_la_mano();
  
 byte R[8]={0b00000000,0b01111100,0b01100110,0b01100110,0b01111100,0b01111000,0b01101100,0b01100110};
  lc.setRow(0,0,R[0]);
  lc.setRow(0,1,R[1]);
  lc.setRow(0,2,R[2]);
  lc.setRow(0,3,R[3]);
  lc.setRow(0,4,R[4]);
  lc.setRow(0,5,R[5]);
  lc.setRow(0,6,R[6]);
  lc.setRow(0,7,R[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(pulgar);
  cerrar_parcial(indice);

  delay(5000);
}

void s(){
  abrir_toda_la_mano();
  
  byte S[8]={0b00000000,0b00111100,0b01100110,0b01100000,0b00111100,0b00000110,0b01100110,0b00111100};
  lc.setRow(0,0,S[0]);
  lc.setRow(0,1,S[1]);
  lc.setRow(0,2,S[2]);
  lc.setRow(0,3,S[3]);
  lc.setRow(0,4,S[4]);
  lc.setRow(0,5,S[5]);
  lc.setRow(0,6,S[6]);
  lc.setRow(0,7,S[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);
  cerrar_parcial(pulgar); 
  
  delay(5000);
}

void t(){
  abrir_toda_la_mano();
  
  byte T[8]={0b00000000,0b01111110,0b01011010,0b00011000,0b00011000,0b00011000,0b00011000,0b00011000};
  lc.setRow(0,0,T[0]);
  lc.setRow(0,1,T[1]);
  lc.setRow(0,2,T[2]);
  lc.setRow(0,3,T[3]);
  lc.setRow(0,4,T[4]);
  lc.setRow(0,5,T[5]);
  lc.setRow(0,6,T[6]);
  lc.setRow(0,7,T[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);

  delay(5000);
}

void u(){ //los dedos que no se extienden van pegados
  abrir_toda_la_mano();
  
  byte U[8]={0b00000000,0b01100110,0b01100110,0b01100110,0b01100110,0b01100110,0b01100110,0b00111110};
  lc.setRow(0,0,U[0]);
  lc.setRow(0,1,U[1]);
  lc.setRow(0,2,U[2]);
  lc.setRow(0,3,U[3]);
  lc.setRow(0,4,U[4]);
  lc.setRow(0,5,U[5]);
  lc.setRow(0,6,U[6]);
  lc.setRow(0,7,U[7]);
  f_arriba();

  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(pulgar);

  delay(5000);
}

void v(){ //los dedos que no se extienden van despegados
  abrir_toda_la_mano();
  
  byte V[8]={0b00000000,0b01100110,0b01100110,0b01100110,0b01100110,0b01100110,0b00111100,0b00011000};
  lc.setRow(0,0,V[0]);
  lc.setRow(0,1,V[1]);
  lc.setRow(0,2,V[2]);
  lc.setRow(0,3,V[3]);
  lc.setRow(0,4,V[4]);
  lc.setRow(0,5,V[5]);
  lc.setRow(0,6,V[6]);
  lc.setRow(0,7,V[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(pulgar);

  delay(5000);
}

void w(){
  abrir_toda_la_mano();
  
  byte W[8]={0b00000000,0b01100011,0b01100011,0b01100011,0b01101011,0b01111111,0b01110111,0b01100011};
  lc.setRow(0,0,W[0]);
  lc.setRow(0,1,W[1]);
  lc.setRow(0,2,W[2]);
  lc.setRow(0,3,W[3]);
  lc.setRow(0,4,W[4]);
  lc.setRow(0,5,W[5]);
  lc.setRow(0,6,W[6]);
  lc.setRow(0,7,W[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(pulgar);  

  delay(5000);
}

void x(){
  abrir_toda_la_mano();
  
  byte X[8]={0b00000000,0b01100011,0b01100011,0b00110110,0b00011100,0b00110110,0b01100011,0b01100011};
  lc.setRow(0,0,X[0]);
  lc.setRow(0,1,X[1]);
  lc.setRow(0,2,X[2]);
  lc.setRow(0,3,X[3]);
  lc.setRow(0,4,X[4]);
  lc.setRow(0,5,X[5]);
  lc.setRow(0,6,X[6]);
  lc.setRow(0,7,X[7]);
  f_arriba();
  
  cerrar_todo(pulgar);
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_parcial(indice);
  
  delay(5000);
}

void y(){
  abrir_toda_la_mano();
  
  byte Y[8]={0b00000000,0b01100110,0b01100110,0b01100110,0b00111100,0b00011000,0b00011000,0b00011000};
  lc.setRow(0,0,Y[0]);
  lc.setRow(0,1,Y[1]);
  lc.setRow(0,2,Y[2]);
  lc.setRow(0,3,Y[3]);
  lc.setRow(0,4,Y[4]);
  lc.setRow(0,5,Y[5]);
  lc.setRow(0,6,Y[6]);
  lc.setRow(0,7,Y[7]);
  f_arriba();
  
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(indice);

  delay(5000);
}

void z(){
  abrir_toda_la_mano();
  
  byte Z[8]={0b00000000,0b01111110,0b00000110,0b00001100,0b00011000,0b00110000,0b01100000,0b01111110};
  lc.setRow(0,0,Z[0]);
  lc.setRow(0,1,Z[1]);
  lc.setRow(0,2,Z[2]);
  lc.setRow(0,3,Z[3]);
  lc.setRow(0,4,Z[4]);
  lc.setRow(0,5,Z[5]);
  lc.setRow(0,6,Z[6]);
  lc.setRow(0,7,Z[7]);
  f_arriba();
  
  cerrar_todo(menique);
  cerrar_todo(anular);
  cerrar_todo(corazon);
  cerrar_todo(pulgar);

  delay(5000);
}

void setup() {
  pulgar.attach(pin_pulgar);
  indice.attach(pin_indice);
  corazon.attach(pin_corazon);
  anular.attach(pin_anular);
  menique.attach(pin_menique);
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  led.shutdown(0, false);
  led.setIntensity(0,8);
  led.clearDisplay(0);
  Serial.begin(9600);
  BTSerial.begin(9600);
  abrir_toda_la_mano();
}

void loop() {
  while(BTSerial.available()){
    for(int i = 0; i < 160; i++){
      char letra = BTSerial.read();
       if(letra == 'a'){
          a();
      }else if(letra == 'b'){
          b();
      }else if(letra == 'c'){
          c();
      }else if(letra == 'd'){
          d();
      }else if(letra == 'e'){
          e();
      }else if(letra == 'f'){
          f();
      }else if(letra == 'g'){
          g();
      }else if(letra == 'h'){
          h();
      }else if(letra == 'i'){
          I();
      }else if(letra == 'j'){
          j();
      }else if(letra == 'k'){
          k();
      }else if(letra == 'l'){
          l();
      }else if(letra == 'm'){
          m();
      }else if(letra == 'n'){
          n();
      }else if(letra == 'o'){
          o();
      }else if(letra == 'p'){
          p();
      }else if(letra == 'q'){
          q();
      }else if(letra == 'r'){
          r();
      }else if(letra == 's'){
          s();
      }else if(letra == 't'){
          t();
      }else if(letra == 'u'){
          u();
      }else if(letra == 'v'){
          v();
      }else if(letra == 'w'){
          w();
      }else if(letra == 'x'){
          x();
      }else if(letra == 'y'){
          y();
      }else if(letra == 'z'){
          z();
      }
    }
  }
}
