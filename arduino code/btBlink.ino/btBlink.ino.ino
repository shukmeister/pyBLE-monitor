String message; //string that stores the incoming message

void setup()
{
  Serial1.begin(9600); //set baud rate
  pinMode(13, OUTPUT);    //teensy LED 
}

void loop()
{
  while(Serial.available())
  {//while there is data available on the serial monitor
    message+=char(Serial.read());//store string from serial command
  }
  if(!Serial.available())
  {
    if(message!="")
    {//if data is available
      Serial.println(message); //show the data
      message=""; //clear the data
    }
  }
//  Serial1.println("Hi!  I'm a robot!");
////  digitalWrite(13, HIGH);
////  delay(100);
////  digitalWrite(13, LOW);
//  delay(1000); //delay
}

