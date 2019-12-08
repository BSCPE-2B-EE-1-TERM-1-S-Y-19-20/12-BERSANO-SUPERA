const int sPin1 = A1; 
const int sPin2 = A2;
const int sPin3 = A3;

int sValue1 = 0;   
int sValue2 = 0;
int sValue3 = 0;

float VIn = 5;
float VOut1 = 0;  
float VOut2 = 0;
float VOut3 = 0;
float Rknown1 = 960; 
float Rknown2 = 850;
float Rknown3 = 1185;
float r1 = 0; 
float r2 = 0;  
float r3 = 0;
float Ra=0,Rb=0,Rc=0;

void setup ()
{
  Serial.begin(9600);     
}
  void getR1(){
  sValue1 = analogRead(sPin1);
  VOut1 = (VIn * sValue1) / 1023;    
  r1 = Rknown1 * (1 / ((VIn / VOut1) - 1));  
  Serial.print("Resistor 1: ");                  
  Serial.println(r1);                
  delay(1000);
  }
  void getR2(){
  sValue2 = analogRead(sPin2);
  VOut2 = (VIn * sValue2) / 1023;    
  r2 = Rknown2 * (1 / ((VIn / VOut2) - 1));  
  Serial.print("Resistor 2: ");                  
  Serial.println(r2);                    
  delay(1000);
  }
  void getR3(){
  sValue3 = analogRead(sPin3);
  VOut3 = (VIn * sValue3) / 1023;    
  r3 = Rknown3 * (1 / ((VIn / VOut3) - 1));  
  Serial.print("Resistor 3: ");                  
  Serial.println(r3);                    
    delay(1000);
  }
void loop ()
{
  Serial.println("------------------------------------------");
  Serial.println("Delta to Wye");
  Serial.println("Initializing Resistors. . . . ");
  getR1();
  getR2();
  getR3();
  Serial.println("Estimating.....");
  delay(2000);

   Ra=(r2*r3)/(r1+r2+r3);
   Rb=(r3*r1)/(r1+r2+r3);
   Rc=(r1*r2)/(r1+r2+r3);

    Serial.print("Resistor A:");
    Serial.println(Ra);
    Serial.print("Resistor B:");
    Serial.println(Rb);
    Serial.print("Resistor C:");
    Serial.println(Rc);
    Serial.println("------------------------------------------");
delay(2000);
}