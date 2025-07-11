
int sensorPin=A0;
int sensorThreshold=600;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  Serial.println("Starting traffic monitoring");
}

boolean detectState = false;
int count = 0;

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int sensorValue;
  sensorValue=analogRead(sensorPin);
  //  Serial.println(sensorValue);
  if(sensorValue>sensorThreshold && !detectState){
    Serial.println("--------------------------");
    Serial.println("Movement detected!");
    Serial.println("Rat entered area");
    detectState=true;
  }
  else if(sensorValue<sensorThreshold && detectState){
    count++;
    detectState=false;
    Serial.println("Rat left area. Current count:");
    Serial.println(count);
  }

}
