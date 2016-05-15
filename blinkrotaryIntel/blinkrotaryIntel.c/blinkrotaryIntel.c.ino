int ledPin = 6;
int potPin = A0;
int notifier_pin   = 3;
int js_subscriber_pin   = 6;

FILE *fromarduino, *toarduino;

int val = 0;
int oldAngleVal = 0;
int newAngleVal = 0;
int blinkVal = 0;
int counter = 0;
int countMax = 10;

void setup() {
 // put your setup code here, to run once:
// pinMode(ledPin, OUTPUT);

 
  pinMode(notifier_pin, OUTPUT); //Notification pin     
  pinMode(js_subscriber_pin, INPUT_PULLUP); //interrupt pin for reading message from JS    
// Serial.begin(9600);
}

void loop() {
 val = analogRead(potPin);
 newAngleVal = map(val, 0, 1023, 0, 180);
// Serial.write(newAngleVal);

  if (newAngleVal > oldAngleVal + 2 || newAngleVal < oldAngleVal - 2) {
    publishData(newAngleVal);
    notifyWorld();  
    oldAngleVal = newAngleVal;
  }
//
// analogWrite(ledPin, val/4);
}


void publishData(int angle)
{
  fromarduino = fopen ("/arduino_notification_out.txt", "w+");
  fprintf(fromarduino, "%d", angle);
  fclose(fromarduino);  
}

//Nofity any body connected to this interrupt  (C++ program and NodeJS) program
void notifyWorld()
{
    digitalWrite(notifier_pin, HIGH);
    delay(200);
    digitalWrite(notifier_pin, LOW);
}
