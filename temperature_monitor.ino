

// lcd pins
LiquidCrystal lcd(8,9,4,5,6,7); 

// init variables
int value=0;            
float volts=0.0;      
float temp=0.0;      
float tempF=0.0;

void setup()
{
// setting arduino pin3 as input
  pinMode(3,INPUT);  
// opens serial port, sets data rate to 9600 bps      
  Serial.begin(9600); 
// set up the LCD's number of columns and rows  
  lcd.begin(16,2);      
 
  
}

void loop()
{
//read from A0
  value=analogRead(A0);
//conversion to volts         
  volts=(value/1024.0)*5.0; 
//conversion to temp Celsius     
  temp= volts*100.0;   
//conversion to temp Fahrenheit          
  tempF=temp*9/5+32;             

//display temp no lcd
  Serial.print("temperature= "); 
  Serial.println(temp);
  lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  lcd.print(tempF);
  lcd.print(" F");
  
  delay(500);
}

