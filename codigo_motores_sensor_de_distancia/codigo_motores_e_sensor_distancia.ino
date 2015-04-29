#include <Ultrasonic.h>
#define PINO_TRIG 7 //DEFINE O PINO 7 DO ARDUINO COMO TRIG
#define PINO_ECHO 6 //DEFINE O PINO 6 DO ARDUINO COMO ECHO
Ultrasonic ultrasonic(PINO_TRIG,PINO_ECHO);
int IN1 = 13; //PINO MOTOR1
int IN2 = 12; //PINO MOTOR1
int IN3 = 9; //PINO MOTOR2
int IN4 = 8; //PINO MOTOR2
int DISTANCIA; //VARIVEL QUE GUARDA A DISTANCIA 

//FUNCAO PARA PARAR OS MOTORES (PONTO MORTO)
void pararmotor(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
} 
//FUNCAO QUE DIRECIONA OS MOTORES PARA FRENTE
void prafrente(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}
//FUNCAO QUE DIRECIONA OS MOTORES PARA TRAS
void pratras(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
}
//FUNCAO RESPONSAVEL PELA MANOBRA
void manobra(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
}

void setup (){
//INICIALIZA O MONITOR SERIAL
Serial.begin(9600);
//DEFINE OS PINOS COMO SAIDA
pinMode(IN1,OUTPUT); 
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
}

void loop(){
DISTANCIA = ultrasonic.Ranging(CM);

Serial.print("Distance CM: ");

Serial.println(ultrasonic.Ranging(CM));

delay(100);

prafrente(); 

if (DISTANCIA < 15){
  
	pararmotor(); delay(1000);
	pratras(); delay(1000);
	manobra(); delay(1000);

}
else{
  
	prafrente();	

}
}


