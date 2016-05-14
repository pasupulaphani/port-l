int ledPin = 6;
int potPin = A0;
int val = 0;
int angleVal = 0;
int blinkVal = 0;
int counter = 0;
int countMax = 10;

void setup() {
 // put your setup code here, to run once:
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}

void loop() {
 val = analogRead(potPin);
 angleVal = map(val, 0, 1023, 0, 180);
 Serial.println(angleVal);
 analogWrite(ledPin, val/4);

}
