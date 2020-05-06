void myPrint()
{
  int opt = random(1, 4);
  Serial.print("Warup my ");
  switch(opt){
    case 1: 
      Serial.println("Gs?!");
      break;
    case 2: 
      Serial.println("homies?!");
      break;
    case 3: 
      Serial.println("Bitchs?!");
      break;
    default:
      Serial.println("dumb ass?!");
  }
}
