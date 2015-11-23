String message; //string that stores the incoming message
bool newlineTest = 1;

void setup() {
  Serial1.begin(9600); //set baud rate
  pinMode(13, OUTPUT);    //teensy LED 
}

void loop() {

  if (Serial1.available() > 0) {
    Serial1.println("got it!");
    char received = char(Serial1.read()); //read string from serial command
    message += received; //store string from serial command
    if (received == '\n') {
      Serial1.print("Message received: ");
      Serial1.print(message);
      message = "";
    }
  }
//
//  // Process message when new line character is recieved
//  if (recieved == '\n') {
//    Serial.print("Arduino Received: ");
//    Serial.print(inData);
//
//    inData = ""; // Clear recieved buffer
//  }
////
//  if (Serial1.read() == "/") {
//    newlineTest = 1;
//  }
//
//  if (newlineTest == 1) {
//    Serial1.println(message);
//    newlineTest = 0;
//    message = "";
//  }
//  if (!Serial1.available() > 0) {
//    if (message != "") {
//      Serial1.println(message);
//      message = "";
//    }
//  }

//  digitalWrite(13, HIGH);
//  digitalWrite(13, LOW);
//  delay(1000); //delay
  
}

