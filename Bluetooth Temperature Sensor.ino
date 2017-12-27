// Determines the temperature within the shoe and then send the input reading to the an Android Device.
// Requires ArduDroid Application 

int sensorPin = 0; // intialize variable which will hold temp. sensor data
int ledPin = 13; // create the Red LED value
int state = 0;
int flag = 0; 

void setup() 
{
  Serial.begin(9600);  //Start the serial connection with the computer
  pinMode(ledPin, OUTPUT); // initialize the red LED
  digitalWrite(ledPin, LOW);
  pinMode(12, OUTPUT); // initialize the green LED

}

void loop() {
  int reading = analogRead(sensorPin);  //getting the voltage reading from the temperature sensor
 
 float voltage = reading * 5.0;// converting that reading to voltage, for 3.3v arduino use 3.3
 voltage /= 1024.0; 
 
 float celcius = ((voltage - 0.5) * 100) * -1 ;  

 Serial.print(celcius); Serial.println(" degrees C"); // print temp. in celcius to serial monitor

if(Serial.available() > 0){
 state = Serial.read();
 flag=0;
 }

 if (state == '0') {
 digitalWrite(ledPin, LOW);
 if(flag == 0){
 Serial.println(celcius); // show temperature in textbox
 flag = 1;
 }
 }

 else if (state == '1') {
 digitalWrite(ledPin, HIGH);
 if(flag == 0){
 Serial.println(celcius); // show temperature in textbox
 flag = 1;
 }  
 }
   if (celcius > 0) // comparison statement to check whether stored data is greater than melting point
  {
    digitalWrite(13, HIGH); // if temp reading is above 0 degrees
    digitalWrite(12, LOW); 
  }
  else 
  {
    digitalWrite(12, HIGH); // if temp reading is below 0 degrees
    digitalWrite(13, LOW); 
  }
    delay(4000); // wait 4 seconds between each reading
}
