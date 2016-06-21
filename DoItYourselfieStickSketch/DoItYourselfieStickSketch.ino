/*
  Do It Yourselfie Stick 
  2016
  
  This code is in the public domain
*/

int previousButtonReading = HIGH;

void setup() {
  BeanHid.enable();

  pinMode(0, INPUT_PULLUP);
}

void loop() {
  int buttonReading = digitalRead(0);

  // pullup inverts the logic
  // HIGH = open, LOW = button pressed
  if (buttonReading == LOW && previousButtonReading == HIGH) {
    BeanHid.holdKey(KEY_LEFT_CTRL);
    BeanHid.holdKey("P");
    BeanHid.releaseAllKeys();
  }

  previousButtonReading = buttonReading;
}
