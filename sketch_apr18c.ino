
int sensorPin = A0;
int sensorThreshold = 600;
unsigned long detectionTime = 0;
boolean detectState = false;
int countRat = 0;
int countSnake = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  Serial.println("Starting traffic monitoring");
}

void loop() {
  unsigned int sensorValue = analogRead(sensorPin);
  
  if (sensorValue > sensorThreshold && !detectState) {
    Serial.println("--------------------------");
    Serial.println("Movement detected!");
    detectionTime = millis();
    detectState = true;
  } 
  else if (sensorValue < sensorThreshold && detectState) {
    unsigned long duration = millis() - detectionTime;
    detectState = false;
    
    if (duration < 500) {
      return;
    } 
    else if (duration < 1000) {
      countRat++;
      Serial.println("Rat left area. Current Rat count:");
      Serial.println(countRat);
    } 
    else if (duration < 3000) {
      countSnake++;
      Serial.println("Snake left area. Current Snake count:");
      Serial.println(countSnake);
    }
    else {
      Serial.println("Object left area, but type undetermined.");
    }
  }
}
