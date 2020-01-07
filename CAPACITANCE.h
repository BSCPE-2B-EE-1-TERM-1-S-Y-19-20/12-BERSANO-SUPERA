int analogPin = 0;
int chargePin = 13;
int dischargePin = 11;
int resistorValue = 10000;
unsigned long startTime;
unsigned long elapsedTime;
float microFarads;                
float nanoFarads;
class CapacitanceRay{
	public:
	void CAP(){
				digitalWrite(chargePin, HIGH); 
				startTime = millis();  
		  while(analogRead(analogPin) < 645)
		  {       
			
		  }
		  elapsedTime= millis() - startTime; // Determines how much time it took to charge capacitor
		  microFarads = ((float)elapsedTime / resistorValue) * 1000;
		  Serial.print(elapsedTime);       
		  Serial.print(" mS    ");         
		  if (microFarads > 1) // Determines if units should be micro or nano and prints accordingly
		  {
			Serial.print((long)microFarads);       
			Serial.println(" microFarads");         
		  }

		  else
		  {
			nanoFarads = microFarads * 1000.0;      
			Serial.print((long)nanoFarads);         
			Serial.println(" nanoFarads");          
			delay(500); 
		  }
		  digitalWrite(chargePin, LOW); // Stops charging capacitor
		  pinMode(dischargePin, OUTPUT); 
		  digitalWrite(dischargePin, LOW); // Allows capacitor to discharge    
		  while(analogRead(analogPin) > 0)
		  {
			// Do nothing until capacitor is discharged      
		  }

		  pinMode(dischargePin, INPUT); // Prevents capacitor from discharging  
				
			}
			
			
};
