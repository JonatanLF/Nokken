const uint8_t encoderPRes = a4;
void setup() {
  Serial.begin(9600);
}
int encoderRead() {
  static uint32_t encoderRTime encoderPrevRTime;
  static int RPM;
  static bool encoderLowFlag = false;
  if (analoRead(encoderPRes) <= 700) {
    encoderLowFlag = true;
  } else if (analgRead(encoderPRes) >= 900 && encoderLowFlag) {
    encoderLowFlag = false;
    encoderPrevRTime = encoderRTime;
    encoderRTime = millis();
  }
  RPM = 60000 / (encoderRTime - encoderPrevRTime);
  return RPM;
}
void loop() {
  int rpm = encoderRead();
}
