#define PIN_TEMP_SENSOR A1
#define FAN 3

int setPoint = 50;
int upGraphLimit = setPoint + 10, lowGraphLimit = setPoint - 10;
float temperature, lowerLimit = setPoint - 2, upperLimit = setPoint + 2;

void setup() {
  Serial.begin(9600);
  //Serial.println("Conection started");
  pinMode(FAN, OUTPUT);
}

void loop() {
  temperature = ((float(analogRead(PIN_TEMP_SENSOR)) * 5 / 1023) / 0.01) - 9;
  Serial.print("Up limit: ");
  Serial.print(upGraphLimit);
  Serial.print(",");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(",");
  Serial.print("Low limit: ");
  Serial.println(lowGraphLimit);

  if (temperature > upperLimit) {
    digitalWrite(FAN,HIGH);
  } else if (temperature < lowerLimit) {
    digitalWrite(FAN,LOW);
  }

  delay(100);
}
