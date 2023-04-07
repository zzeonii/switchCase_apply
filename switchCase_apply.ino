const int sensorMin = 0;    // sensor minimum, discovered through experiment
const int sensorMax = 600;  // sensor maximum, discovered through experiment

const int LED1 = 6;
const int LED2 = 9;
const int LED3 = 10;
const int BUZZER = 11;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // read the sensor:
  int sensorReading = analogRead(A0);
  // map the sensor range to a range of four options:
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  // do something different depending on the range value:
  switch (range) {
    case 0:  // your hand is on the sensor
      Serial.println("dark");
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      tone(BUZZER, 800);
      break;
    case 1:  // your hand is close to the sensor
      Serial.println("dim");
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      tone(BUZZER, 400);
      break;
    case 2:  // your hand is a few inches from the sensor
      Serial.println("medium");
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      tone(BUZZER, 200);
      break;
    case 3:  // your hand is nowhere near the sensor
      Serial.println("bright");
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      noTone(BUZZER);
      break;
  }
  delay(1);  // delay in between reads for stability
}
