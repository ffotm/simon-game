
const int ledPins[5] = {2, 3, 4, 5, 6};
const int buttonPins[5] = {7, 8, 9, 10, 11};
const int buzzerPin = 12;

int gamePattern[100];
int userPattern[100];

int level = 0;
bool started = false;


void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  pinMode(buzzerPin, OUTPUT);

  randomSeed(analogRead(0)); 
}


void loop() {

  if (!started) {
    delay(1000);
    started = true;
    level = 0;
    nextSequence();
  }

  int step = 0;

  while (step < level) {
    if (checkButton(step)) {
      step++;
    }
  }

  delay(500);
  nextSequence();
}


void nextSequence() {
  level++;

  int randomNumber = random(0, 5); 
  gamePattern[level - 1] = randomNumber;

  delay(500);

  for (int i = 0; i < level; i++) {
    flashLED(gamePattern[i]);
    delay(300);
  }
}


void flashLED(int index) {
  digitalWrite(ledPins[index], HIGH);
  tone(buzzerPin, 500 + (index * 100), 200);
  delay(200);
  digitalWrite(ledPins[index], LOW);
}


bool checkButton(int step) {

  for (int i = 0; i < 5; i++) {

    if (digitalRead(buttonPins[i]) == LOW) {
      delay(200); 

      flashLED(i);

      if (i != gamePattern[step]) {
        gameOver();
        return false;
      }

      while (digitalRead(buttonPins[i]) == LOW);

      return true;
    }
  }

  return false;
}



void gameOver() {
  tone(buzzerPin, 200, 1000);

  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  delay(1000);

  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  level = 0;
  started = false;
}