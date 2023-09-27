
int distanceTreshold = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
   for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
   sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  distanceTreshold = 300;
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  if (cm > distanceTreshold) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    noTone(6);
  }
  if (cm <= distanceTreshold && cm > distanceTreshold - 75) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    noTone(6);
    delay(1000); 
 millisecond(s)
    digitalWrite(2, HIGH);
  }
  if (cm <= distanceTreshold - 75 && cm > distanceTreshold - 150) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    noTone(6);
    delay(1000);
 millisecond(s)
    digitalWrite(3, HIGH);
  }
  if (cm <= distanceTreshold - 150 && cm > distanceTreshold - 225) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    noTone(6);
    delay(1000); 
 millisecond(s)
    digitalWrite(4, HIGH);
  }
  if (cm <= distanceTreshold - 225 && cm > distanceTreshold - 285) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    delay(1000);
 millisecond(s)
    digitalWrite(5, HIGH);
  }
  if (cm <= distanceTreshold - 285) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(8, LOW);
    tone(6, 523, 1000); // play tone 60 (C5 = 523 Hz)
  }
}