int readline(int readch, char *buffer, int len)
{
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
      case '\n': // Ignore new-lines
        break;
      case '\r': // Return on CR
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;
      default:
        if (pos < len-1) {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  // No end of line has been found, so return -1.
  return -1;
}

void setup()
{
  Serial1.begin(9600);
}

void loop()
{
  static char buffer[80];
  if (readline(Serial1.read(), buffer, 80) > 0) {
    Serial1.print("You entered: >");
    Serial1.print(buffer);
    Serial1.println("<");
  }
}
