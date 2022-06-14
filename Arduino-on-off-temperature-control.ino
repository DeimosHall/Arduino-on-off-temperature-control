#define TEMP_SENSOR_PIN A1
#define FAN_PIN 3
#define LIGHT_BULB_PIN 4

int setPoint = 60;
int upGraphLimit = setPoint + 10, lowGraphLimit = setPoint - 10;
float temperature, lowerLimit = setPoint - 1, upperLimit = setPoint + 1;

void setup() {
  Serial.begin(9600);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LIGHT_BULB_PIN, OUTPUT);
}

void loop() {
  temperature = ((float(analogRead(TEMP_SENSOR_PIN)) * 5 / 1023) / 0.01) - 5;
  
  Serial.print("Up limit: ");
  Serial.print(upGraphLimit);
  Serial.print(",");
  Serial.print("SetPoint: ");
  Serial.print(setPoint);
  Serial.print(","); 
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  
  Serial.print(",");
  Serial.print("Low limit: ");
  Serial.println(lowGraphLimit);

  //digitalWrite(FAN_PIN, HIGH);
  //digitalWrite(LIGHT_BULB_PIN, HIGH);
  
  if (temperature > upperLimit + 1.5) {
    digitalWrite(LIGHT_BULB_PIN, LOW);
  } else if (temperature > upperLimit) {
    digitalWrite(FAN_PIN, HIGH);
  } else if (temperature < lowerLimit) {
    digitalWrite(FAN_PIN, LOW);
    digitalWrite(LIGHT_BULB_PIN, HIGH);
  }

  delay(1000);
}
