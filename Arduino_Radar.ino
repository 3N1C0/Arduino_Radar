#include <Servo.h>


Servo myservo;

const int trigPin = 5;
const int echoPin = 4;

const int butt = 8;

long duration;
int distance;

void setup() {
  myservo.attach(2);
  myservo.write(90);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(butt, INPUT);

  Serial.begin(9600);

}

void loop() {
  if (digitalRead(butt) == HIGH){
    for(int i = 15; i < 165; i++){
      myservo.write(i);
      delay(25);

    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    }

    for (int i = 165; i > 15; i--){
      myservo.write(i);
      delay(25);

    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    } 
  }
  else{
    myservo.write(90);
  }
}
  int calculateDistance(){

  digitalWrite(trigPin, LOW); 

  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin, HIGH); 

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds

  distance= duration*0.034/2;

  return distance;
  }
