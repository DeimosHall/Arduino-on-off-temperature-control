#define PIN_TEMP_SENSOR A1
#define PIN_FAN 3

int setPoint = 60;
int upGraphLimit = setPoint + 10, lowGraphLimit = setPoint - 10;
float temperature, lowerLimit = setPoint - 1, upperLimit = setPoint + 0;
float error;

void setup() {
  Serial.begin(9600);
  //Serial.println("Conection started");
  pinMode(PIN_FAN, OUTPUT);
}

void loop() {
  temperature = ((float(analogRead(PIN_TEMP_SENSOR)) * 5 / 1023) / 0.01) - 9;
  error = setPoint - temperature;
  
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
  

  if (temperature > upperLimit) {
    digitalWrite(PIN_FAN,HIGH);
  } else if (temperature < lowerLimit) {
    digitalWrite(PIN_FAN,LOW);
  }

  delay(1000);
}
