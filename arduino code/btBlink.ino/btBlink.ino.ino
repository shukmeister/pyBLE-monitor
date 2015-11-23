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
}
