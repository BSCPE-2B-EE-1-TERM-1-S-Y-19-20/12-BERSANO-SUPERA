double pulse=0, frequency, capacitance, inductance;
class Inductance{
public:
void getInductance(){
  digitalWrite(9, HIGH);
  delay(5);
  digitalWrite(9,LOW);
  delayMicroseconds(100); 
  pulse = pulseIn(8,HIGH);
  if(pulse > 0.1){ 
  capacitance = 2.E-6;
  
  frequency = 1.E6/(2*pulse);
  inductance = 1./(capacitance*frequency*frequency*4.*3.14159*3.14159);
  inductance *= 1E6; 

  //Serial print
  Serial.print("inductance uH:");
  Serial.println( inductance );
  delay(100);
  }
}
};
