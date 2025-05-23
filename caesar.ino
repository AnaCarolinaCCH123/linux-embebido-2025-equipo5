const int shift = 3; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Connected:");
}

String message = "";

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    char c = Serial.read();
    message += c;
    delay(3);
  }
  if(message != ""){
    String encrypted = caesar(message, shift);
    Serial.print("Original: ");
    Serial.println(message);
    Serial.print("Encriptado: ");
    Serial.println(encrypted);
    message = "";
  }
}

String caesar(String text, int shift) {
  shift = shift % 26;  
  if (shift < 0) shift += 26;  
  
  for(int i = 0; i < text.length(); i++) {
    char c = text[i];
    
    if(isAlpha(c)) {
      char base = minus(c) ? 'a' : 'A';
      text[i] = (c - base + shift + 26) % 26 + base;
    }
  }
  return text;
}

bool isAlpha(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool minus(char c) {
  return (c >= 'a' && c <= 'z');
}
