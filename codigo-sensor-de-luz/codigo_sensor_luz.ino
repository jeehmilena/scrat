int led = 13;
int sensor = 0;
int valorsensor = 0;

void setup(){
Serial.begin (9600);
pinMode(led, OUTPUT);
}

void loop () {
valorsensor = analogRead(sensor);
Serial.println(valorsensor);
delay(10);
if (valorsensor < 420){
digitalWrite(led,HIGH);
}
else {
digitalWrite(led,LOW);
}
}
