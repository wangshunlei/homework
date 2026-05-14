// ex03: SOS信号 - 使用millis()
const int ledPin = 2;

const int DOT = 200;
const int DASH = 600;
const int GAP = 200;
const int LETTER_GAP = 500;
const int SOS_GAP = 2000;

int step = 0;
unsigned long lastTime = 0;

int pattern[] = {1,0,1,0,1,0,0, 2,0,2,0,2,0,0, 1,0,1,0,1,0,0};
int patternLen = 21;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  unsigned long now = millis();
  
  int waitTime;
  if (pattern[step] == 1) waitTime = DOT;
  else if (pattern[step] == 2) waitTime = DASH;
  else {
    int zeroCount = 1;
    for (int i = step+1; i < patternLen && pattern[i]==0; i++) zeroCount++;
    if (zeroCount == 1) waitTime = GAP;
    else if (zeroCount == 2) waitTime = LETTER_GAP;
    else waitTime = SOS_GAP;
  }
  
  if (now - lastTime >= waitTime) {
    lastTime = now;
    
    if (pattern[step] == 1 || pattern[step] == 2) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
    
    step++;
    if (step >= patternLen) step = 0;
  }
}