int v = 13;
int si = 2;
int rck = 4;
int srck = 8;

int numbers[] = {
  0b11111100,
  0b01100000,
  0b11011010,
  0b11110010,
  0b01100110,
  0b10110110,
  0b10111110,
  0b11100100,
  0b11111110,
  0b11100110
};

void setup() {
  // put your setup code here, to run once:
  pinMode(v, OUTPUT);
  pinMode(si, OUTPUT);
  pinMode(srck, OUTPUT);
  pinMode(rck, OUTPUT);
  Serial.begin(9600);
}

void reset(int pin){
  on(pin);
  off(pin);
}

void input(int input) {
  for(int k = 0; k < 8; k++) {
    digitalWrite(si, input >> (7 - k) & 1);
    Serial.println(input >> (7 - k) & 1);
    shift();
  }
}
void shift() {
  reset(srck);
}
void sends() {
  reset(rck);
}

void on(int pin) {
  digitalWrite(pin, HIGH);
}

void off(int pin) {
  digitalWrite(pin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  on(v);
  for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
    Serial.println(numbers[i]);
    input(numbers[i]);
    sends();
    delay(1000);
  }
}
