int incomingByte = 0; // for incoming serial data

const int word_len = 8;
char m_word[word_len];
int len = 0;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    Serial.print("received: ");
    while(Serial.available() > 0){
      len = read_word();
      Serial.print("received ");
      Serial.print(len);
      Serial.print(" chars : ");
      write_word(len + 1);
    }
  }
}

int read_word()
{
  int i=0;
  for(; (i<word_len) && (Serial.available() > 0); i++)
  {
    m_word[i] = Serial.read();
  }
  return i;
}

void write_word(int len)
{
  for(int i=0; i< len ; i++)
  {
     Serial.print((char)m_word[i]);
  }
}
