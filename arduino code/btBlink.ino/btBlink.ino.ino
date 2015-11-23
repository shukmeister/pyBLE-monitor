String message; //string that stores the incoming message

void setup() {
  Serial1.begin(9600); //set baud rate
  pinMode(13, OUTPUT);    //teensy LED 
}

void loop() {
//  while(Serial1.available())
//  {//while there is data available on the serial monitor
//    Serial1.println("sup");
//    message+=char(Serial1.read());//store string from serial command
//  }
//  if(!Serial1.available())
//  {
//    if(message!="")
//    {//if data is available
//      Serial1.println("hi");
//      Serial1.println(message); //show the data
//      message=""; //clear the data
//    }
//  }
  Serial1.println("hi");
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(1000); //delay
}

