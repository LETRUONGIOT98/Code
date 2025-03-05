
int dong = 3; // Nối với chân OUT 1 của module RF
int mo = 4; // Nối vào chân OUT 2 của module RF
int dung = 6;
int ledPin = 7; //Led báo trạng thái
int hanhtrinhmo = 9; // Nối công tắc hành trình phía trong khi mở hết cửa sẽ dừng lại
int hanhtrinhdong = 10; // Nối công tắc hành trình phía ngoài khi đóng hết cửa sẽ dừng lại
 //Khai báo chân điều khiển động cơ
const int stepPin = 5; //clk+ 
const int dirPin = 2; //cw+ 
const int enPin = 8;

void setup() {
  pinMode(dong, INPUT);
  pinMode(mo, INPUT);
  pinMode(dung, INPUT);
  pinMode(hanhtrinhdong, INPUT_PULLUP);
  pinMode(hanhtrinhmo, INPUT_PULLUP);
  pinMode(hanhtrinhmo, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
    pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
}
 
void loop() {
  set:
  //ĐÓNG
    
  if (digitalRead(dong) == HIGH && digitalRead(dung) == LOW){
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  digitalWrite(ledPin,HIGH);
  // Makes 200 pulses for making one full cycle rotation
 dong:  for(int x = 0; x >= 0; x++) {
  digitalWrite(ledPin,HIGH);
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  if (digitalRead(mo) == HIGH){
    delay(300);
  goto mo;}
  if(digitalRead(hanhtrinhdong) == LOW || digitalRead(dung) == HIGH){
    digitalWrite(ledPin,LOW);
    goto set;
  }
  }
  }
  
 //mở
if (digitalRead(mo) == HIGH && digitalRead(dung) == LOW){
  digitalWrite(ledPin,HIGH);
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
mo: for(int x = 0; x >= 0; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
      if (digitalRead(dong) == HIGH ){
        delay(300);
  goto dong;  
  }
  if(digitalRead(hanhtrinhmo) == LOW || digitalRead(dung) == HIGH){
    digitalWrite(ledPin,LOW);
    goto set;
  }
  }
}
}
