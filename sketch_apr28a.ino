int speedA = 2;
int speedB = 5;
int dirA = 3;
int dirB = 4;
//senosr
int trigPin = 11;
int echoPin = 12;
long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedA, OUTPUT);
  pinMode(speedB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  analogWrite(speedA, 200);
  analogWrite(speedB, 200);

  //sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

 //sensor
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.034)/2;
  Serial.print("Distance:" );
  Serial.println(distance);
  
  if(distance <= 20){
  delay(3000);
  analogWrite(speedA, 20);
  analogWrite(speedB, 20);
  delay(2000);
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
  delay(2000);
  digitalWrite(dirA, HIGH);
  delay(2000);
  analogWrite(speedA, 200);
  analogWrite(speedB, 200);
  
    }else{
        // put your main code here, to run repeatedly:
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
    }
  
}
