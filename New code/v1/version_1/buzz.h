
byte speakerPin = 23;

void playTone(int period, int duration)
{
  //period is one cycle of tone
  //how long the pulsing should last in milliseconds
  int pulse = period / 2;
  for(long i = 0; i < duration * 1000L; i += period)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(pulse);  
  }  

}
