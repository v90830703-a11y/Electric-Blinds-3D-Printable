int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;
int button5 = 6;

int left1 = 7;
int left2 = 8;

int right1 = 9;
int right2 = 10;

int mode = 1;
char calibrateWhich = "left";

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);

  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);

  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);

  digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
  digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);


  Serial.begin(9600);

}

bool checkButtonPressed(int which){
  if (digitalRead(which) == LOW){
    delay(25);
    if (digitalRead(which) == LOW){
      return true;
    }
  }else{return false;}
}

void normalMode(){
  
  if (digitalRead(button4) == LOW){
    digitalWrite(left1,LOW);
    digitalWrite(left2,HIGH);
    digitalWrite(right1,HIGH);
    digitalWrite(right2,LOW);
  }
  if (digitalRead(button5) == LOW){
    digitalWrite(left1,HIGH);
    digitalWrite(left2,LOW);
    digitalWrite(right1,LOW);
    digitalWrite(right2,HIGH);
  }
  else{
    digitalWrite(left1,LOW);
    digitalWrite(left2,LOW);
    digitalWrite(right1,LOW);
    digitalWrite(right2,LOW);
  }
}


void calibrationMode(char calibrateWhichSide){
  
  while (true){
    if (checkButtonPressed(button1) == true) {
      calibrateWhich = 'left';
      }
    if (checkButtonPressed(button2) == true) {
      calibrateWhich = 'right';
      }
    if (checkButtonPressed(button3) == true) {
      return;
      }
    digitalWrite(right1,LOW);
    digitalWrite(right2,LOW);
    if (calibrateWhichSide == 'left'){
      if (digitalRead(button4) == LOW){
        digitalWrite(left1,LOW);
        digitalWrite(left2,HIGH);
      }
      if (digitalRead(button5) == LOW){
        digitalWrite(left1,HIGH);
        digitalWrite(left2,LOW);
      }
      if (digitalRead(button4) == HIGH & digitalRead(button5)==HIGH){
        digitalWrite(left1,LOW);
        digitalWrite(left2,LOW);
      }

    }
    if (calibrateWhichSide == 'right'){
      if (digitalRead(button4) == LOW){
        digitalWrite(right1,HIGH);
        digitalWrite(right2,LOW);
      }
      if (digitalRead(button5) == LOW){
        digitalWrite(right1,LOW);
        digitalWrite(right2,HIGH);
      }
      if (digitalRead(button4) == HIGH & digitalRead(button5)==HIGH){
        digitalWrite(right1,LOW);
        digitalWrite(right2,LOW);
      }
    }
 
  }
}


void loop() {
  delay(100);
  checkButtonPressed(button3) == true? mode = 0: mode = 1;

  switch (mode){
    case 1:
      Serial.print(digitalRead(button1));
      Serial.print(digitalRead(button2));
      Serial.print(digitalRead(button3));
      Serial.print(digitalRead(button4));
      Serial.println(digitalRead(button5));
      normalMode();
      break;

    case 0:
      if (checkButtonPressed(button1) == true) calibrateWhich = "left";
      if (checkButtonPressed(button2) == true) calibrateWhich = "Right";
      calibrationMode(calibrateWhich);
      break;

  
  }


}
