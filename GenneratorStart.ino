int PowerOnPin = 7;  // Relay for Powerbutton
int AutoStartOnPin = 8;  // Relay for AutoStart

int inStartGenneratorPin = 4;    // Start signal
int inGenneratorStatePin = 3;    // Gennerator State

int Restart = 0;      // variable to store the read value
int RestartCount = 0;      // variable to store the read value


void setup() {
  Serial.begin(9600);  // Initializes serial port
  pinMode(PowerOnPin, OUTPUT);  // sets the digital pin 2 as output
  pinMode(AutoStartOnPin, OUTPUT);  // sets the digital pin 4 as output

  digitalWrite(PowerOnPin,HIGH);
  digitalWrite(AutoStartOnPin,HIGH);
  
  pinMode(inStartGenneratorPin, INPUT_PULLUP);    // sets the digital pin 4 as input
  pinMode(inGenneratorStatePin, INPUT_PULLUP);    // sets the digital pin 2 as input
}

void loop() {


  
if ((digitalRead(inStartGenneratorPin)==LOW) && RestartCount<=3){
  Serial.println("Gennerator start aktivert og restart er ikke over X");

if (digitalRead(inGenneratorStatePin)==HIGH){
  //Serial.println("Gennerator ikke startet");
  
  if (Restart==1){
   Serial.print("Gennerator restart sequens nr: ");
   Serial.println(RestartCount);
   digitalWrite(PowerOnPin,HIGH);
   delay(20000);
   RestartCount=RestartCount+1;
  }

digitalWrite(PowerOnPin,LOW);
Serial.println("Power ON");
delay(2000);
if (digitalRead(inStartGenneratorPin)==LOW){
  Serial.println("Autostart Aktivert kontroll 1");
  delay(2000);
  digitalWrite(AutoStartOnPin,LOW);
  Serial.println("Autostart aktivert ON");
  }
  else{
    Serial.println("Autostart ikke Aktivert kontroll 1");
    digitalWrite(PowerOnPin,HIGH);
    digitalWrite(AutoStartOnPin,HIGH);
    Serial.println("Power OFF");
  }
  if (digitalRead(inStartGenneratorPin)==LOW){
    Serial.println("Autostart Aktivert kontroll 2");
    delay(5000);
     digitalWrite(AutoStartOnPin,HIGH);
     Serial.println("Autostart aktivert OFF");
     delay(40000);
      if (digitalRead(inGenneratorStatePin)==HIGH){
        Serial.println("Gennerator ikke startet restart");
        Restart=1; 
        }
        }
    else{
     Serial.println("Autostart ikke Aktivert kontroll 2");
      digitalWrite(PowerOnPin,HIGH);
      digitalWrite(AutoStartOnPin,HIGH);
      Serial.println("Power OFF");
   } 
}
else{
  Serial.println("Gennerator startet");
  RestartCount=0;
}
}
else
{
  digitalWrite(PowerOnPin,HIGH);  
  Restart=0;
  if (digitalRead(inStartGenneratorPin)==HIGH){
      RestartCount=0;
  }
}
}
