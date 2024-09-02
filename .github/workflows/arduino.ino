const int led1 = 4;  // rood LED
const int led2 = 5;  // groen LED
const int led3 = 6;  // blauw LED
const int led4 = 7;  // geel LED
const int potPin = A0; // Potentiometer
const int buttonPause = 8; // Pushbutton K1
const int buttonResume = 9; // Pushbutton K2

const int delayTime = 500; // set delay

bool isPaused = false; // boolean waarde voor pause aan en uit 

void setup() {
  // leds zijn output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // knoppen omhoog als input
  pinMode(buttonPause, INPUT_PULLUP);
  pinMode(buttonResume, INPUT_PULLUP);

  // start serial console output
  Serial.begin(9600);
}

void loop() {
  // check pause button
  if (digitalRead(buttonPause) == LOW) {
    isPaused = true;
  }

  // check resumebutton
  if (digitalRead(buttonResume) == LOW) {
    isPaused = false;
  }

  // wanneer gepauzeerd is wacht 0.1 seconde tot isPaused weer false is
  if (isPaused) {
    delay(100); 
    return; 
  }

  // lees potentiometer
  int potValue = analogRead(potPin);

  // potentiometer value naar PMW value
  int brightness = map(potValue, 0, 1023, 0, 255);

  // Print de potentiometer value en brightness
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);

  // led cycle
  analogWrite(led1, brightness);
  analogWrite(led2, 0);
  analogWrite(led3, 0);
  analogWrite(led4, 0);
  delay(delayTime);

  analogWrite(led1, 0);
  analogWrite(led2, brightness);
  analogWrite(led3, 0);
  analogWrite(led4, 0);
  delay(delayTime);

  analogWrite(led1, 0);
  analogWrite(led2, 0);
  analogWrite(led3, brightness);
  analogWrite(led4, 0);
  delay(delayTime);

  analogWrite(led1, 0);
  analogWrite(led2, 0);
  analogWrite(led3, 0);
  analogWrite(led4, brightness);
  delay(delayTime);
}
