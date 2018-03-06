#include "SD.h"
#define SD_ChipSelectPin 53
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

String getString;
char getChar, mode;
int btn1, btn2, btn3, btn4, btn5, btn6;
boolean btn1Pressed, btn2Pressed, btn3Pressed, btn4Pressed, btn5Pressed, btn6Pressed;

void setup() {
  // put your setup code here, to run once:

  initializeInputPin();
  initializeOutputPin();
  initializeStaticPin();

  Serial.begin(9600);

  tmrpcm.speakerPin = 11;
  
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
  }
  return;
}

//Initialize Input Pin
void initializeInputPin() {
  pinMode(22,INPUT); //btn
  pinMode(23,INPUT); //btn
  pinMode(24,INPUT); //btn
  pinMode(25,INPUT); //btn
  pinMode(26,INPUT); //btn
  pinMode(27,INPUT); //btn
}

//Initialize Output Pin
void initializeOutputPin() {
  pinMode(28,OUTPUT); //relay
  pinMode(29,OUTPUT); //relay
  pinMode(30,OUTPUT); //relay
  pinMode(31,OUTPUT); //relay
  pinMode(32,OUTPUT); //relay
  pinMode(33,OUTPUT); //relay
}

//Initialize Static Pin
void initializeStaticPin() {
  pinMode(35,OUTPUT); //static
  pinMode(37,OUTPUT); //static
  pinMode(38,OUTPUT); //static
  pinMode(39,OUTPUT); //static
  pinMode(40,OUTPUT); //static
  pinMode(41,OUTPUT); //static

  digitalWrite(35, HIGH);
  digitalWrite(37, HIGH);
  digitalWrite(38, HIGH);
  digitalWrite(39, HIGH);
  digitalWrite(40, HIGH);
  digitalWrite(41, HIGH);
}

//Changing the solenoid (output pin) status (either on or off used during tutorial mainly)
void changeDotState(String parameter) {
  int pins[] = {28, 29, 30, 31, 32, 33};
  for(int i = 0; i < parameter.length(); i++)
  {
    if(parameter[i] == '1')
    {
      digitalWrite(pins[i], LOW);
      Serial.println(pins[i]);
    }
    else
    {
      digitalWrite(pins[i], HIGH);
    }
  }
}

//Reset Output Pin
void resetOutputPin() {
  pinMode(22,LOW); //relay
  //pinMode(23,LOW); //relay
  //pinMode(24,LOW); //relay
  //pinMode(25,LOW); //relay
  //pinMode(26,LOW); //relay
  //pinMode(27,LOW); //relay
}

//Read Input Pin
void readInput() {
  btn1 = digitalRead(22);
  btn2 = digitalRead(23);
  btn3 = digitalRead(24);
  btn4 = digitalRead(25);
  btn5 = digitalRead(26);
  btn6 = digitalRead(27);
}

void pauseHalf() {
  delay(500);
}

void pause1() {
  delay(1000);
}

//Pause for 3 sec
void pause3() {
  //3 seconds for reading
  delay(3000);
}

//Pause for 5 sec
void pause5() {
  //5 seconds for reading
  delay(5000);
}

//Pause for 10 sec
void pause10() {
  //10 seconds for reading
  delay(10000);
}

//Pause for 30 sec
void pause30() {
  //30 seconds for reading
  delay(30000);
}

void resetBool() {
  btn1Pressed = false;
  btn2Pressed = false;
  btn3Pressed = false;
  btn4Pressed = false;
  btn5Pressed = false;
  btn6Pressed = false;
}

/*
//Do While loop for checking if btn was pressed while btn is LOW
void checkbtn1() {
  tmrpcm.play("pressFirstButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn1);
  } while(btn1 == LOW);
  btn1Pressed = true;
  tmrpcm.play("firstButtonPressed.wav");
}

void checkbtn2() {
  tmrpcm.play("pressSecondButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn2);
  } while(btn2 == LOW);
  btn2Pressed = true;
  tmrpcm.play("secondButtonPressed.wav");
}

void checkbtn3() {
  tmrpcm.play("pressThirdButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn3);
  } while(btn3 == LOW);
  btn3Pressed = true;
  tmrpcm.play("thirdButtonPressed.wav");
}

void checkbtn4() {
  tmrpcm.play("pressFourthButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn4);
  } while(btn4 == LOW);
  btn4Pressed = true;
  tmrpcm.play("fourthButtonPressed.wav");
}

void checkbtn5() {
  tmrpcm.play("pressFifthButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn5);
  } while(btn5 == LOW);
  btn5Pressed = true;
  tmrpcm.play("fifthButtonPressed.wav");
}

void checkbtn6() {
  tmrpcm.play("pressSixthButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn6);
  } while(btn6 == LOW);
  btn6Pressed = true;
  tmrpcm.play("sixthButtonPressed.wav");
}

//Do While loop for checking if btn was pressed while btn is HIGH
void checkbtnH1() {
  tmrpcm.play("pressFirstButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn1);
  } while(btn1 == HIGH);
  btn1Pressed = true;
  tmrpcm.play("firstButtonPressed.wav");
}

void checkbtnH2() {
  tmrpcm.play("pressSecondButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn2);
  } while(btn2 == HIGH);
  btn2Pressed = true;
  tmrpcm.play("secondButtonPressed.wav");
}

void checkbtnH3() {
  tmrpcm.play("pressThirdButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn3);
  } while(btn3 == HIGH);
  btn3Pressed = true;
  tmrpcm.play("thirdButtonPressed.wav");
}

void checkbtnH4() {
  tmrpcm.play("pressFourthButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn4);
  } while(btn4 == HIGH);
  btn4Pressed = true;
  tmrpcm.play("fourthButtonPressed.wav");
}

void checkbtnH5() {
  tmrpcm.play("pressFifthButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn5);
  } while(btn5 == HIGH);
  btn5Pressed = true;
  tmrpcm.play("fifthButtonPressed.wav");
}

void checkbtnH6() {
  tmrpcm.play("pressSixthButton.wav");
  do {
    readInput();
    pause1();
    Serial.println(btn6);
  } while(btn6 == HIGH);
  btn6Pressed = true;
  tmrpcm.play("sixthButtonPressed.wav");
}

//Do While loop for checking if btn 1 was pressed
void checkAlpha1() {
  tmrpcm.play("pressFirstButton.wav");
  do {
    readInput();
    pauseHalf();
    Serial.println(btn1);
  } while(btn1 == LOW);
}

//Do While loop for checking if btn 2 was pressed
void checkAlpha2() {
  tmrpcm.play("pressSecondButton.wav");
  do {
    readInput();
    pauseHalf();
    Serial.println(btn2);
  } while(btn2 == LOW);
}

//Do While loop for checking if btn 3 was pressed
void checkAlpha3() {
  tmrpcm.play("pressThirdButton.wav");
  do {
    readInput();
    pauseHalf();
    Serial.println(btn3);
  } while(btn3 == LOW);
}

//Do While loop for checking if btn 4 was pressed
void checkAlpha4() {
  tmrpcm.play("pressFourthButton.wav");
  do {
    readInput();
    pauseHalf();
    Serial.println(btn4);
  } while(btn4 == LOW);
}

//Do While loop for checking if btn 5 was pressed
void checkAlpha5() {
  tmrpcm.play("pressFifthButton.wav");
  do {
    readInput();
    pauseHalf();
    Serial.println(btn5);
  } while(btn5 == LOW);
}

//Do While loop for checking if btn 6 was pressed
void checkAlpha6() {
  tmrpcm.play("pressSixthButton.wav");
  do {
    readInput();
    pauseHalf();
    Serial.println(btn6);
  } while(btn6 == LOW);
}
*/

//Do While loop for checking if btn 1 was pressed
void checkbtn1() {
  TMRpcm tmrpcm11;
  tmrpcm11.setVolume(6);
  do {
    tmrpcm11.play("PFR.wav");
    readInput();
    pause5();
    Serial.println(btn1);
  } while(btn1 == LOW);
  btn1Pressed = true;
  tmrpcm11.play("FRB.wav");
}

//Do While loop for checking if btn 2 was pressed
void checkbtn2() {
  TMRpcm tmrpcm12;
  tmrpcm12.setVolume(6);
  do {
    tmrpcm12.play("PSC.wav");
    readInput();
    pause5();
    Serial.println(btn2);
  } while(btn2 == LOW);
  btn2Pressed = true;
  tmrpcm12.play("SCB.wav");
}

//Do While loop for checking if btn 3 was pressed
void checkbtn3() {
  TMRpcm tmrpcm13;
  tmrpcm13.setVolume(6);
  do {
    tmrpcm13.play("PTH.wav");
    readInput();
    pause5();
    Serial.println(btn3);
  } while(btn3 == LOW);
  btn3Pressed = true;
  tmrpcm13.play("THB.wav");
}

//Do While loop for checking if btn 4 was pressed
void checkbtn4() {
  TMRpcm tmrpcm14;
  tmrpcm14.setVolume(6);
  do {
    tmrpcm14.play("PFO.wav");
    readInput();
    pause5();
    Serial.println(btn4);
  } while(btn4 == LOW);
  btn4Pressed = true;
  tmrpcm14.play("FOB.wav");
}

//Do While loop for checking if btn 5 was pressed
void checkbtn5() {
  TMRpcm tmrpcm15;
  tmrpcm15.setVolume(6);
  do {
    tmrpcm15.play("PFF.wav");
    readInput();
    pause5();
    Serial.println(btn5);
  } while(btn5 == LOW);
  btn5Pressed = true;
  tmrpcm15.play("FFB.wav");
}

//Do While loop for checking if btn 6 was pressed
void checkbtn6() {
  TMRpcm tmrpcm16;
  tmrpcm16.setVolume(6);
  do {
    tmrpcm16.play("PSX.wav");
    readInput();
    pause5();
    Serial.println(btn6);
  } while(btn6 == LOW);
  btn6Pressed = true;
  tmrpcm16.play("SXB.wav");
}

//Do While loop for checking if btn 1 was pressed
void checkbtnn1() {
  TMRpcm tmrpcm11;
  tmrpcm11.setVolume(6);
  do {
    tmrpcm11.play("PFR.wav");
    readInput();
    pause5();
    Serial.println(btn1);
  } while(btn1 == HIGH);
  btn1Pressed = true;
  tmrpcm11.play("FRB.wav");
}

//Do While loop for checking if btn 2 was pressed
void checkbtnn2() {
  TMRpcm tmrpcm12;
  tmrpcm12.setVolume(6);
  do {
    tmrpcm12.play("PSC.wav");
    readInput();
    pause5();
    Serial.println(btn2);
  } while(btn2 == HIGH);
  btn2Pressed = true;
  tmrpcm12.play("SCB.wav");
}

//Do While loop for checking if btn 3 was pressed
void checkbtnn3() {
  TMRpcm tmrpcm13;
  tmrpcm13.setVolume(6);
  do {
    tmrpcm13.play("PTH.wav");
    readInput();
    pause5();
    Serial.println(btn3);
  } while(btn3 == HIGH);
  btn3Pressed = true;
  tmrpcm13.play("THB.wav");
}

//Do While loop for checking if btn 4 was pressed
void checkbtnn4() {
  TMRpcm tmrpcm14;
  tmrpcm14.setVolume(6);
  do {
    tmrpcm14.play("PFO.wav");
    readInput();
    pause5();
    Serial.println(btn4);
  } while(btn4 == HIGH);
  btn4Pressed = true;
  tmrpcm14.play("FOB.wav");
}

//Do While loop for checking if btn 5 was pressed
void checkbtnn5() {
  TMRpcm tmrpcm15;
  tmrpcm15.setVolume(6);
  do {
    tmrpcm15.play("PFF.wav");
    readInput();
    pause5();
    Serial.println(btn5);
  } while(btn5 == HIGH);
  btn5Pressed = true;
  tmrpcm15.play("FFB.wav");
}

//Do While loop for checking if btn 6 was pressed
void checkbtnn6() {
  TMRpcm tmrpcm16;
  tmrpcm16.setVolume(6);
  do {
    tmrpcm16.play("PSX.wav");
    readInput();
    pause5();
    Serial.println(btn6);
  } while(btn6 == HIGH);
  btn6Pressed = true;
  tmrpcm16.play("SXB.wav");
}

//Do While loop for checking if btn 1 was pressed
void checkAlpha1() {
  TMRpcm tmrpcm11;
  tmrpcm11.setVolume(6);
  do {
    tmrpcm.play("pressFirstButton.wav");
    readInput();
    pause5();
    Serial.println(btn1);
  } while(btn1 == HIGH);
  btn1Pressed = true;
}

//Do While loop for checking if btn 2 was pressed
void checkAlpha2() {
  TMRpcm tmrpcm12;
  tmrpcm12.setVolume(6);
  do {
    tmrpcm.play("pressSecondButton.wav");
    readInput();
    pause5();
    Serial.println(btn2);
  } while(btn2 == HIGH);
  btn2Pressed = true;
}

//Do While loop for checking if btn 3 was pressed
void checkAlpha3() {
  TMRpcm tmrpcm13;
  tmrpcm13.setVolume(6);
  do {
    tmrpcm.play("pressThirdButton.wav");
    readInput();
    pause5();
    Serial.println(btn3);
  } while(btn3 == HIGH);
  btn3Pressed = true;
}

//Do While loop for checking if btn 4 was pressed
void checkAlpha4() {
  TMRpcm tmrpcm14;
  tmrpcm14.setVolume(6);
  do {
    tmrpcm.play("pressFourthButton.wav");
    readInput();
    pause5();
    Serial.println(btn4);
  } while(btn4 == HIGH);
  btn4Pressed = true;
}

//Do While loop for checking if btn 5 was pressed
void checkAlpha5() {
  TMRpcm tmrpcm15;
  tmrpcm15.setVolume(6);
  do {
    tmrpcm.play("pressFifthButton.wav");
    readInput();
    pause5();
    Serial.println(btn5);
  } while(btn5 == HIGH);
  btn5Pressed = true;
}

//Do While loop for checking if btn 6 was pressed
void checkAlpha6() {
  TMRpcm tmrpcm16;
  tmrpcm16.setVolume(6);
  do {
    tmrpcm.play("pressSixthButton.wav");
    readInput();
    pause5();
    Serial.println(btn6);
  } while(btn6 == HIGH);
  btn6Pressed = true;
}

void callAlpha(char receive) {

  
  switch(receive)
  {
    case 'A':
    changeDotState("100000");
    Serial.println("A");
    break;

    case 'B':
    changeDotState("110000");
    Serial.println("B");
    break;

    case 'C':
    changeDotState("100100");
    Serial.println("C");
    break;

    case 'D':
    changeDotState("100110");
    Serial.println("D");
    break;

    case 'E':
    changeDotState("100010");
    Serial.println("E");
    break;

    case 'F':
    changeDotState("110100");
    Serial.println("F");
    break;

    case 'G':
    changeDotState("110110");
    Serial.println("G");
    break;

    case 'H':
    changeDotState("110010");
    Serial.println("H");
    break;

    case 'I':
    changeDotState("010100");
    Serial.println("I");
    break;

    case 'J':
    changeDotState("010110");
    Serial.println("J");
    break;

    case 'K':
    changeDotState("101000");
    Serial.println("K");
    break;

    case 'L':
    changeDotState("111000");
    Serial.println("L");
    break;

    case 'M':
    changeDotState("101100");
    Serial.println("M");
    break;

    case 'N':
    changeDotState("101110");
    Serial.println("N");
    break;

    case 'O':
    changeDotState("101010");
    Serial.println("O");
    break;

    case 'P':
    changeDotState("111100");
    Serial.println("P");
    break;

    case 'Q':
    changeDotState("111110");
    Serial.println("Q");
    break;

    case 'R':
    changeDotState("111010");
    Serial.println("R");
    break;

    case 'S':
    changeDotState("011100");
    Serial.println("S");
    break;

    case 'T':
    changeDotState("011110");
    Serial.println("T");
    break;

    case 'U':
    changeDotState("101001");
    Serial.println("U");
    break;

    case 'V':
    changeDotState("111001");
    Serial.println("V");
    break;

    case 'W':
    changeDotState("010111");
    Serial.println("W");
    break;

    case 'X':
    changeDotState("101101");
    Serial.println("X");
    break;

    case 'Y':
    changeDotState("101111");
    Serial.println("Y");
    break;

    case 'Z':
    changeDotState("101011");
    Serial.println("Z");
    break;
  }
}

void checkAlpha(char receive) {
  
  switch(receive)
  {
    case 'A':
    Serial.println("A");
    break;

    case 'B':
    Serial.println("B");
    break;

    case 'C':
    Serial.println("C");
    break;

    case 'D':
    Serial.println("D");
    break;

    case 'E':
    Serial.println("E");
    break;

    case 'F':
    Serial.println("F");
    break;

    case 'G':
    Serial.println("G");
    break;

    case 'H':
    Serial.println("H");
    break;

    case 'I':
    Serial.println("I");
    break;

    case 'J':
    Serial.println("J");
    break;

    case 'K':
    Serial.println("K");
    break;

    case 'L':
    Serial.println("L");
    break;

    case 'M':
    Serial.println("M");
    break;

    case 'N':
    Serial.println("N");
    break;

    case 'O':
    Serial.println("O");
    break;

    case 'P':
    Serial.println("P");
    break;

    case 'Q':
    Serial.println("Q");
    break;

    case 'R':
    Serial.println("R");
    break;

    case 'S':
    Serial.println("S");
    break;

    case 'T':
    Serial.println("T");
    break;

    case 'U':
    Serial.println("U");
    break;

    case 'V':
    Serial.println("V");
    break;

    case 'W':
    Serial.println("W");
    break;

    case 'X':
    Serial.println("X");
    break;

    case 'Y':
    Serial.println("Y");
    break;

    case 'Z':
    Serial.println("Z");
    break;
  }
}

/*
void checkBtnStatus(int intBtn) {
  
  switch(intBtn)
  {
    case 1:
    if(btn1 == HIGH){
      checkbtnH1();
    }
    else{
      checkbtn1();
    }
    break;
    
    case 2:
    if(btn2 == HIGH){
      checkbtnH2();
    }
    else{
      checkbtn2();
    }
    break;
    
    case 3:
    if(btn3 == HIGH){
      checkbtnH3();
    }
    else{
      checkbtn3();
    }
    break;

    case 4:
    if(btn4 == HIGH){
      checkbtnH4();
    }
    else{
      checkbtn4();
    }
    break;

    case 5:
    if(btn5 == HIGH){
      checkbtnH5();
    }
    else{
      checkbtn5();
    }
    break;

    case 6:
    if(btn6 == HIGH){
      checkbtnH6();
    }
    else{
      checkbtn6();
    }
    break;
  } 
}

void checkIfClicked() {

  do{
    readInput();
    
    if(btn1 == HIGH) {
      checkbtnH1();
    }
    if(btn1 == LOW) {
      checkbtn1();
    }
  
    if(btn2 == HIGH) {
      checkbtnH2();
    }
    if(btn2 == LOW) {
      checkbtn2();
    }
  
    if(btn3 == HIGH) {
      checkbtnH3();
    }
    if(btn3 == LOW) {
      checkbtn3();
    }
  
    if(btn4 == HIGH) {
      checkbtnH4();
    }
    if(btn4 == LOW) {
      checkbtn4();
    }
  
    if(btn5 == HIGH) {
      checkbtnH5();
    }
    if(btn5 == LOW) {
      checkbtn5();
    }
  
    if(btn6 == HIGH) {
      checkbtnH6();
    }
    if(btn6 == LOW) {
      checkbtn6();
    }
  }while(btn1Pressed == false && btn2Pressed == false && btn3Pressed == false && btn4Pressed == false && btn5Pressed == false && btn6Pressed == false);
}
*/

void checkPressedButton(int pressedBtn) {
  switch(pressedBtn){
    case 1:
    do{
      readInput();
      Serial.println("Turn off the first button!");
      pauseHalf();
    }while(btn1 == LOW);
    Serial.println("You have turned off the first button!");
    break;
    
    case 2:
    do{
      readInput();
      Serial.println("Turn off the second button!");
      pauseHalf();
    }while(btn2 == LOW);
    Serial.println("You have turned off the second button!");
    break;
    
    case 3:
    do{
      readInput();
      Serial.println("Turn off the third button!");
      pauseHalf();
    }while(btn3 == LOW);
    Serial.println("You have turned off the third button!");
    break;

    case 4:
    do{
      readInput();
      Serial.println("Turn off the fourth button!");
      pauseHalf();
    }while(btn4 == LOW);
    Serial.println("You have turned off the fourth button!");
    break;

    case 5:
    do{
      readInput();
      Serial.println("Turn off the fifth button!");
      pauseHalf();
    }while(btn5 == LOW);
    Serial.println("You have turned off the fifth button!");
    break;

    case 6:
    do{
      readInput();
      Serial.println("Turn off the sixth button!");
      pauseHalf();
    }while(btn6 == LOW);
    Serial.println("You have turned off the sixth button!");
    break;
  }
}

void checkIfClicked() {
  TMRpcm tmrpcm1;
  tmrpcm1.setVolume(6);
  do {
    readInput();
    
    if(btn1 == LOW) {
      digitalWrite(28, HIGH);
      tmrpcm1.play("FRB.wav");
      pause5();
      Serial.println("You have pressed the first button!"); 
      btn1Pressed = true;
      checkPressedButton(1);
    }
    else if(btn2 == LOW) {
      digitalWrite(29, HIGH);
      tmrpcm1.play("SCB.wav");
      pause5();
      Serial.println("You have pressed the second button!");
      btn2Pressed = true;
      checkPressedButton(2);
    }
    else if(btn3 == LOW) {
      digitalWrite(30, HIGH);
      tmrpcm1.play("THB.wav");
      pause5();
      Serial.println("You have pressed the third button!");
      btn3Pressed = true;
      checkPressedButton(3);
    }
    else if(btn4 == LOW) {
      digitalWrite(31, HIGH);
      tmrpcm1.play("FOB.wav");
      pause5();
      Serial.println("You have pressed the fourth button!");
      btn4Pressed = true;
      checkPressedButton(4);
    }
    else if(btn5 == LOW) {
      digitalWrite(32, HIGH);
      tmrpcm1.play("FFB.wav");
      pause5();
      Serial.println("You have pressed the fifth button!");
      btn5Pressed = true;
      checkPressedButton(5);
    }
    else if(btn6 == LOW) {
      digitalWrite(33, HIGH);
      tmrpcm1.play("SXB.wav");
      pause5();
      Serial.println("You have pressed the sixth button!");
      btn6Pressed = true;
      checkPressedButton(6);
    } 
  } while(btn1Pressed == false && btn2Pressed == false && btn3Pressed == false && btn4Pressed == false && btn5Pressed == false && btn6Pressed == false);
}

//Embosing the solenoid
void on() {
  if(btn1 == HIGH) {
    digitalWrite(28, LOW);
    tmrpcm.play("firstButtonPressed.wav");
  }
  if(btn2 == HIGH) {
    digitalWrite(29, LOW);
    tmrpcm.play("secondButtonPressed.wav");
  }
  if(btn3 == HIGH) {
    digitalWrite(30, LOW);
    tmrpcm.play("thirdButtonPressed.wav");
  }
  if(btn4 == HIGH) {
    digitalWrite(31, LOW);
    tmrpcm.play("fourthButtonPressed.wav");
  }
  if(btn5 == HIGH) {
    digitalWrite(32, LOW);
    tmrpcm.play("fifthButtonPresed.wav");
  }
  if(btn6 == HIGH) {
    digitalWrite(33, LOW);
    tmrpcm.play("sixthButtonPressed.wav");
  }
  Check();
  pauseHalf();
}

//Engraving the solenoid
void off() {
  if(btn1 == LOW) {
    digitalWrite(28, HIGH);
    tmrpcm.play("firstButtonPressed.wav");
  }
  if(btn2 == LOW) {
    digitalWrite(29, HIGH);
    tmrpcm.play("secondButtonPressed.wav");
  }
  if(btn3 == LOW) {
    digitalWrite(30, HIGH);
    tmrpcm.play("thirdButtonPressed.wav");
  }
  if(btn4 == LOW) {
    digitalWrite(31, HIGH);
    tmrpcm.play("fourthButtonPressed.wav");
  }
  if(btn5 == LOW) {
    digitalWrite(32, HIGH);
    tmrpcm.play("fifthButtonPressed.wav");
  }
  if(btn6 == LOW) {
    digitalWrite(33, HIGH);
    tmrpcm.play("sixthButtonPressed.wav");
  }
  Check();
  pauseHalf();
}

//Checking the alphabet combinations
void Check() {
  
  //A
  if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LA.wav");
    changeDotState("100000");
    Serial.println("A");
    pause3();
  }
  
  //B
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    changeDotState("110000");
    tmrpcm.play("LB.wav");
    Serial.println("B");
    pause3();
  }

  //C
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("100100");
    tmrpcm.play("LC.wav");
    Serial.println("C");
    pause3();
  }
  
  //D
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("100110");
    tmrpcm.play("LD.wav");
    Serial.println("D");
    pause3();
  }
  //E
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    changeDotState("100010");
    tmrpcm.play("LE.wav");
    Serial.println("E");
    pause3();
  }
  //F
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("110100");
    tmrpcm.play("LF.wav");
    Serial.println("F");
    pause3();
  }
  //G
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("110110");
    tmrpcm.play("LG.wav");
    Serial.println("G");
    pause3();
  }
  //H
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    changeDotState("110010");
    tmrpcm.play("LH.wav");
    Serial.println("H");
    pause3();
  }
  //I
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("010100");
    tmrpcm.play("LI.wav");
    Serial.println("I");
    pause3();
  }
  //J
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("010110");
    tmrpcm.play("LJ.wav");
    Serial.println("J");
    pause3();
  }
  //K
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    changeDotState("101000");
    tmrpcm.play("LK.wav");
    Serial.println("K");
    pause3();
  }
  //L
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    changeDotState("111000");
    tmrpcm.play("LL.wav");
    Serial.println("L");
    pause3();
  }
  //M
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("101100");
    tmrpcm.play("LM.wav");
    Serial.println("M");
    pause3();
  }
  //N
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("101110");
    tmrpcm.play("LN.wav");
    Serial.println("N");
    pause3();
  }
  //O
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    changeDotState("101010");
    tmrpcm.play("LO.wav");
    Serial.println("O");
    pause3();
  }
  //P
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("111100");
    tmrpcm.play("LP.wav");
    Serial.println("P");
    pause3();
  }
  //Q
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("111110");
    tmrpcm.play("LQ.wav");
    Serial.println("Q");
    pause3();
  }
  //R
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    changeDotState("111010");
    tmrpcm.play("LR.wav");
    Serial.println("R");
    pause3();
  }
  //S
  else if(btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("011100");
    tmrpcm.play("LS.wav");
    Serial.println("S");
    pause3();
  }
  //T
  else if(btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("011110");
    tmrpcm.play("LT.wav");
    Serial.println("T");
    pause3();
  }
  //U
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW){
    changeDotState("101001");
    tmrpcm.play("LU.wav");
    Serial.println("U");
    pause3();
  }
  //V
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW){
    changeDotState("111001");
    tmrpcm.play("LV.wav");
    Serial.println("V");
    pause3();
  }
  //W
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == LOW){
    changeDotState("010111");
    tmrpcm.play("LW.wav");
    Serial.println("W");
    pause3();
  }
  //X
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == LOW){
    changeDotState("101101");
    tmrpcm.play("LX.wav");
    Serial.println("X");
    pause3();
  }
  //Y
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW){
    changeDotState("101111");
    tmrpcm.play("LY.wav");
    Serial.println("Y");
    pause3();
  }
  //Z
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == LOW){
    changeDotState("101011");
    tmrpcm.play("LZ.wav");
    Serial.println("Z");
    pause3();
  }
  else{
    Serial.println("Wrong");
  }
}

/*
//Checking the alphabet combinations
void Check() {
  
  //A
  if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == false && btn4Pressed == false && btn5Pressed == false && btn6Pressed == false){
    changeDotState("100000");
    Serial.println("A");
  }
  
  //B
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == false && btn4Pressed == false && btn5Pressed == false && btn6Pressed == false){
    changeDotState("110000");
    Serial.println("B");
  }
  //C
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == false && btn4Pressed == true && btn5Pressed == false && btn6Pressed == false){
    changeDotState("100100");
    Serial.println("C");
  }
  
  //D
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == false && btn4Pressed == true && btn5Pressed == true && btn6Pressed == false){
    changeDotState("100110");
    Serial.println("D");
  }
  //E
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == false && btn4Pressed == false && btn5Pressed == true && btn6Pressed == false){
    changeDotState("100010");
    Serial.println("E");
  }
  //F
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == false && btn4Pressed == true && btn5Pressed == false && btn6Pressed == false){
    changeDotState("110100");
    Serial.println("F");
  }
  //G
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == false && btn4Pressed == true && btn5Pressed == true && btn6Pressed == false){
    changeDotState("110110");
    Serial.println("G");
  }
  //H
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == false && btn4Pressed == false && btn5Pressed == true && btn6Pressed == false){
    changeDotState("110010");
    Serial.println("H");
  }
  //I
  else if(btn1Pressed == false && btn2Pressed == true && btn3Pressed == false && btn4Pressed == true && btn5Pressed == false && btn6Pressed == false){
    changeDotState("010100");
    Serial.println("I");
  }
  //J
  else if(btn1Pressed == false && btn2Pressed == true && btn3Pressed == false && btn4Pressed == true && btn5Pressed == true && btn6Pressed == false){
    changeDotState("010110");
    Serial.println("J");
  }
  //K
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == true && btn4Pressed == false && btn5Pressed == false && btn6Pressed == false){
    changeDotState("101000");
    Serial.println("K");
  }
  //L
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == true && btn4Pressed == false && btn5Pressed == false && btn6Pressed == false){
    changeDotState("111000");
    Serial.println("L");
  }
  //M
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == true && btn4Pressed == true && btn5Pressed == false && btn6Pressed == false){
    changeDotState("101100");
    Serial.println("M");
  }
  //N
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == true && btn4Pressed == true && btn5Pressed == true && btn6Pressed == false){
    changeDotState("101110");
    Serial.println("N");
  }
  //O
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == true && btn4Pressed == false && btn5Pressed == true && btn6Pressed == false){
    changeDotState("101010");
    Serial.println("O");
  }
  //P
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == true && btn4Pressed == true && btn5Pressed == false && btn6Pressed == false){
    changeDotState("111100");
    Serial.println("P");
  }
  //Q
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == true && btn4Pressed == true && btn5Pressed == true && btn6Pressed == false){
    changeDotState("111110");
    Serial.println("Q");
  }
  //R
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == true && btn4Pressed == false && btn5Pressed == true && btn6Pressed == false){
    changeDotState("111010");
    Serial.println("R");
  }
  //S
  else if(btn1Pressed == false && btn2Pressed == true && btn3Pressed == true && btn4Pressed == true && btn5Pressed == false && btn6Pressed == false){
    changeDotState("011100");
    Serial.println("S");
  }
  //T
  else if(btn1Pressed == false && btn2Pressed == true && btn3Pressed == true && btn4Pressed == true && btn5Pressed == true && btn6Pressed == false){
    changeDotState("011110");
    Serial.println("T");
  }
  //U
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == true && btn4Pressed == false && btn5Pressed == false && btn6Pressed == true){
    changeDotState("101001");
    Serial.println("U");
  }
  //V
  else if(btn1Pressed == true && btn2Pressed == true && btn3Pressed == true && btn4Pressed == false && btn5Pressed == false && btn6Pressed == true){
    changeDotState("111001");
    Serial.println("V");
  }
  //W
  else if(btn1Pressed == false && btn2Pressed == false && btn3Pressed == false && btn4Pressed == false && btn5Pressed == false && btn6Pressed == false){
    changeDotState("010111");
    Serial.println("W");
  }
  //X
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == true && btn4Pressed == true && btn5Pressed == false && btn6Pressed == true){
    changeDotState("101101");
    Serial.println("X");
  }
  //Y
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == true && btn4Pressed == true && btn5Pressed == true && btn6Pressed == true){
    changeDotState("101111");
    Serial.println("Y");
  }
  //Z
  else if(btn1Pressed == true && btn2Pressed == false && btn3Pressed == true && btn4Pressed == false && btn5Pressed == true && btn6Pressed == true){
    changeDotState("101011");
    Serial.println("Z");
  }
  else{
    Serial.println("Wrong");
  }
}
*/

//Free mode
void freeMode() {
  readInput();
  //on();
  //off();
  Check();
  //checkMode();
}

//Tutorial mode
void tutorial() {
  
  //btns
  tmrpcm.play("A0.wav");
  Serial.println("Welcome to pinDOTS!");
  pause5();
  tmrpcm.play("B0.wav");
  Serial.println("On your left you have 6 btns. On your right you have 6 dots. Can you feel the buttons on your left? Try pressing any button.");
  //pause5();
  //Check if any buttons were pressed!
  checkIfClicked();
  tmrpcm.play("C0.wav");
  Serial.println("Very Good!");
  pause5();
  tmrpcm.play("D0.wav");
  delay(6000);
  Serial.println("You can press these btns to push down and pop up the dots! If you press the first btn, the first dot will pop up,if you press the first btn again, the first dot will push down! So let us start our tutorial! ");
  pause10();

  pause3();
  tmrpcm.play("E0.wav");
  delay(2000);
  Serial.println("Try pressing the first btn!");
  checkbtnn1();
  Serial.println("Great! You were able to press the first btn! Now try to feel the first dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("F0.wav");
  delay(10000);
  changeDotState("100000");
  pause5();
  checkPressedButton(1);
  
  tmrpcm.play("G0.wav");
  delay(4000);
  Serial.println("Now try pressing the second btn!");
  checkbtnn2();
  Serial.println("Great! You were able to press the second btn! Now try to feel the second dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("H0.wav");
  delay(9000);
  changeDotState("010000");
  pause5();
  checkPressedButton(2);
  
  tmrpcm.play("I0.wav");
  delay(3000);
  Serial.println("Now try pressing the third btn!");
  checkbtnn3();
  Serial.println("Great! You were able to press the third btn! Now try to feel the third dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("J0.wav");
  delay(9000);
  changeDotState("001000");
  pause5();
  resetOutputPin();
  checkPressedButton(3);
  
  tmrpcm.play("K0.wav");
  delay(3000);
  Serial.println("Now try pressing the fourth btn!");
  checkbtnn4();
  Serial.println("Great! You were able to press the fourth btn! Now try to feel the fourth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("L0.wav");
  delay(9000);
  changeDotState("000100");
  pause5();
  checkPressedButton(4);

  tmrpcm.play("M0.wav");
  delay(3000);
  Serial.println("Now try pressing the fifth btn!");
  checkbtnn5();
  Serial.println("Great! You were able to press the fifth btn! Now try to feel the fifth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("N0.wav");
  delay(9000);
  changeDotState("000010");
  pause5();
  checkPressedButton(5);


  tmrpcm.play("O0.wav");
  delay(3000);
  Serial.println("Try pressing the sixth btn!");
  checkbtnn6();
  Serial.println("Great! You were able to press the sixth btn! Now try to feel the sixth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("P0.wav");
  delay(10000);
  changeDotState("000001");
  pause5();
  checkPressedButton(6);


  tmrpcm.play("Q0.wav");
  Serial.println("Great! You were able to press all the btns! Very good!");
  pause5();
  tmrpcm.play("R.wav");
  Serial.println("Now let us practice the braille alphabets from A - Z!");
  pause5();
  
  //Alphabets

  //A
  tmrpcm.play("A1.wav");
  delay(2000);
  Serial.println("Press the first btn!");
  checkAlpha1();
  tmrpcm.play("A2.wav");
  delay(6000);
  Serial.println("Great! You have pressed A! You have 10 seconds to feel the dot!");
  changeDotState("100000");
  pause5();
  checkPressedButton(1);

  //B
  tmrpcm.play("B1.wav");
  delay(2000);
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  tmrpcm.play("B3.wav");
  Serial.println("Great! You have pressed B! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  
  //C
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("C3.wav");
  Serial.println("Great! You have pressed C! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(4);
  
  //D
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("D4.wav");
  Serial.println("Great! You have pressed D! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(4);
  checkPressedButton(5);
  
  //E
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("E3.wav");
  Serial.println("Great! You have pressed E! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(5);
  
  //F
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("F4.wav");
  Serial.println("Great! You have pressed F! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(4);
  
  //G
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("G5.wav");
  Serial.println("Great! You have pressed G! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(3);
  checkPressedButton(4);
  
  //H
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("H4.wav");
  Serial.println("Great! You have pressed H! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(5);
  
  //I
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("I3.wav");
  Serial.println("Great! You have pressed I! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(2);
  checkPressedButton(4);
  
  //J
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("J4.wav");
  Serial.println("Great! You have pressed J! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(2);
  checkPressedButton(4);
  checkPressedButton(5);
  
  //K
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  tmrpcm.play("K3.wav");
  Serial.println("Great! You have pressed K! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(3);
  
  //L
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  tmrpcm.play("L4.wav");
  Serial.println("Great! You have pressed L! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(3);
  
  //M
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("M4.wav");
  Serial.println("Great! You have pressed M! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(4);
  
  //N
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("N5.wav");
  Serial.println("Great! You have pressed N! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(4);
  checkPressedButton(5);

  //O
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("O4.wav");
  Serial.println("Great! You have pressed O! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(5);
  
  //P
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("0100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("P5.wav");
  Serial.println("Great! You have pressed P! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(3);
  checkPressedButton(4);
  
  //Q
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("Q6.wav");
  Serial.println("Great! You have pressed Q! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(3);
  checkPressedButton(4);
  checkPressedButton(5);
  
  //R
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("R5.wav");
  Serial.println("Great! You have pressed R! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(3);
  checkPressedButton(5);
  
  //S
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("S4.wav");
  Serial.println("Great! You have pressed S! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(2);
  checkPressedButton(3);
  checkPressedButton(4);
  
  //T
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("T5.wav");
  Serial.println("Great! You have pressed T! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(2);
  checkPressedButton(3);
  checkPressedButton(4);
  checkPressedButton(5);
  
  //U
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("U4.wav");
  Serial.println("Great! You have pressed U! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(6);
  
  //V
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("V5.wav");
  Serial.println("Great! You have pressed V! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(3);
  checkPressedButton(6);
  
  //W
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("W5.wav");
  Serial.println("Great! You have pressed W! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(2);
  checkPressedButton(4);
  checkPressedButton(5);
  checkPressedButton(6);
  
  //X
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("X5.wav");
  Serial.println("Great! You have pressed X! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(4);
  checkPressedButton(6);
  
  //Y
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("Y6.wav");
  Serial.println("Great! You have pressed Y! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(4);
  checkPressedButton(5);
  checkPressedButton(6);
  
  //Z
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("Z5.wav");
  Serial.println("Great! You have pressed Z! You have 10 seconds to feel the dot!");
  pause5();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(5);
  checkPressedButton(6);
  
  //Numbers

  //1
  Serial.println("Press the first btn!");
  checkAlpha1();
  Serial.println("Great! You have pressed 1! You have 10 seconds to feel the dot!");
  changeDotState("100000");
  pause5();
  resetOutputPin();

  //2
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Great! You have pressed 2! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //3
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 3! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //4
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 4! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //5
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 5! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //6
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 6! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //7
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 7! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //8
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 8! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //9
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 9! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //0
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Press the six btn!");
  checkAlpha6();
  changeDotState("000001");
  Serial.println("Great! You have pressed 0! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  Serial.println("Congratulations! You have completed the tutorial!");

  checkMode();
}

/*
//Tutorial mode
void tutorial() {

  resetOutputPin();
  
  //btns
  tmrpcm.play("A0.wav");
  Serial.println("Welcome to pinDOTS!");
  pause5();
  tmrpcm.play("B0.wav");
  Serial.println("On your left you have 6 btns. On your right you have 6 dots. Can you feel the buttons on your left? Try pressing any button.");
  //pause5();
  //Check if any buttons were pressed!
  checkIfClicked();
  tmrpcm.play("C0.wav");
  Serial.println("Very Good!");
  pause5();
  tmrpcm.play("D0.wav");
  delay(6000);
  Serial.println("You can press these btns to push down and pop up the dots! If you press the first btn, the first dot will pop up,if you press the first btn again, the first dot will push down! So let us start our tutorial! ");
  pause10();

  pause3();
  tmrpcm.play("E0.wav");
  delay(2000);
  Serial.println("Try pressing the first btn!");
  checkbtn1();
  Serial.println("Great! You were able to press the first btn! Now try to feel the first dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("F0.wav");
  delay(10000);
  changeDotState("100000");
  pause5();
  resetOutputPin();

  tmrpcm.play("G0.wav");
  delay(4000);
  Serial.println("Now try pressing the second btn!");
  checkbtn2();
  Serial.println("Great! You were able to press the second btn! Now try to feel the second dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("H0.wav");
  delay(9000);
  changeDotState("010000");
  pause5();
  resetOutputPin();

  tmrpcm.play("I0.wav");
  delay(3000);
  Serial.println("Now try pressing the third btn!");
  checkbtn3();
  Serial.println("Great! You were able to press the third btn! Now try to feel the third dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("J0.wav");
  delay(9000);
  changeDotState("001000");
  pause5();
  resetOutputPin();

  tmrpcm.play("K0.wav");
  delay(3000);
  Serial.println("Now try pressing the fourth btn!");
  checkbtn4();
  Serial.println("Great! You were able to press the fourth btn! Now try to feel the fourth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("L0.wav");
  delay(9000);
  changeDotState("000100");
  pause5();
  resetOutputPin();

  tmrpcm.play("M0.wav");
  delay(3000);
  Serial.println("Now try pressing the fifth btn!");
  checkbtn5();
  Serial.println("Great! You were able to press the fifth btn! Now try to feel the fifth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("N0.wav");
  delay(9000);
  changeDotState("000010");
  pause5();
  resetOutputPin();

  tmrpcm.play("O0.wav");
  delay(3000);
  Serial.println("Try pressing the sixth btn!");
  checkbtn6();
  Serial.println("Great! You were able to press the sixth btn! Now try to feel the sixth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("P0.wav");
  delay(10000);
  changeDotState("000001");
  pause5();
  resetOutputPin();

  tmrpcm.play("Q0.wav");
  Serial.println("Great! You were able to press all the btns! Very good!");
  pause5();
  tmrpcm.play("R.wav");
  Serial.println("Now let us practice the braille alphabets from A - Z!");
  pause5();
  
  //Alphabets

  //A
   tmrpcm.play("A1.wav");
   delay(2000);
  Serial.println("Press the first btn!");
  checkAlpha1();
  tmrpcm.play("A2.wav");
  delay(6000);
  Serial.println("Great! You have pressed A! You have 10 seconds to feel the dot!");
  changeDotState("100000");
  pause5();
  resetOutputPin();

  //B
  tmrpcm.play("B1.wav");
   delay(2000);
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  tmrpcm.play("B3.wav");
  Serial.println("Great! You have pressed B! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //C
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("C3.wav");
  Serial.println("Great! You have pressed C! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //D
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("D4.wav");
  Serial.println("Great! You have pressed D! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //E
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("E3.wav");
  Serial.println("Great! You have pressed E! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //F
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("F4.wav");
  Serial.println("Great! You have pressed F! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //G
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("G5.wav");
  Serial.println("Great! You have pressed G! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //H
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("H4.wav");
  Serial.println("Great! You have pressed H! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //I
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("I3.wav");
  Serial.println("Great! You have pressed I! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //J
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("J4.wav");
  Serial.println("Great! You have pressed J! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //K
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  tmrpcm.play("K3.wav");
  Serial.println("Great! You have pressed K! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //L
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  tmrpcm.play("L4.wav");
  Serial.println("Great! You have pressed L! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //M
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("M4.wav");
  Serial.println("Great! You have pressed M! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //N
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("N5.wav");
  Serial.println("Great! You have pressed N! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //O
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("O4.wav");
  Serial.println("Great! You have pressed O! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //P
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("0100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("P5.wav");
  Serial.println("Great! You have pressed P! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //Q
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("Q6.wav");
  Serial.println("Great! You have pressed Q! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //R
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("R5.wav");
  Serial.println("Great! You have pressed R! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //S
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  tmrpcm.play("S4.wav");
  Serial.println("Great! You have pressed S! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //T
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  tmrpcm.play("T5.wav");
  Serial.println("Great! You have pressed T! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //U
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("U4.wav");
  Serial.println("Great! You have pressed U! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //V
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("V5.wav");
  Serial.println("Great! You have pressed V! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //W
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("W5.wav");
  Serial.println("Great! You have pressed W! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //X
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("X5.wav");
  Serial.println("Great! You have pressed X! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //Y
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("Y6.wav");
  Serial.println("Great! You have pressed Y! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //Z
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkAlpha3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkAlpha6();
  changeDotState("000001");
  tmrpcm.play("Z5.wav");
  Serial.println("Great! You have pressed Z! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //Numbers

  //1
  Serial.println("Press the first btn!");
  checkAlpha1();
  Serial.println("Great! You have pressed 1! You have 10 seconds to feel the dot!");
  changeDotState("100000");
  pause5();
  resetOutputPin();

  //2
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Great! You have pressed 2! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //3
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 3! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //4
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 4! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //5
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 5! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //6
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 6! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //7
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 7! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //8
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 8! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //9
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 9! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  //0
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Press the six btn!");
  checkAlpha6();
  changeDotState("000001");
  Serial.println("Great! You have pressed 0! You have 10 seconds to feel the dot!");
  pause5();
  resetOutputPin();

  Serial.println("Congratulations! You have completed the tutorial!");

  checkMode();
}
*/

//Drill mode
void drill() {
  //printing 

  char drillWordArray[4];
  String drillWord = "CAT"; //get from DB //CAT
  drillWord.toCharArray(drillWordArray, 4); //Convert String to Array
  
  for (int i = 0; i < sizeof(drillWordArray) - 1; i++){ //
      callAlpha(drillWordArray[i]);
      pause1();
  }
  checkMode();
}

int ctr=0;

void getMode() {
  //get mode via wemos
  //mode= Serial.read();
  mode = 't';

  switch(mode)
  {

    case 't':
      ctr=1;
      break;

    case 'd':
      ctr=2;
      break;
    
    case 'f':
      ctr=3;
      break;

      default:
        break;
  }
}

void checkMode() {

  getMode();
  
  if(mode == 'd'){
    Serial.println(mode);
      if(ctr==1)
    {
      tmrpcm.play("");
      delay(1500);
      ctr=0;
    }
    
    pause5();
    drill();
  }
  else if(mode == 't') {
    Serial.println(mode);
    if(ctr==2)
    {
      tmrpcm.play("");
      delay(1500);
      ctr=0;
    }
    pause5();
    tutorial();
  }
  else if(mode == 'f') {
    if(ctr==3)
    {
      //tmrpcm.play("Welcome.wav");
      ctr=0;
    }
    Serial.println(mode);
    pause5();
    freeMode();
  }
  else {
    Serial.println("mode: " + mode);
    pause5();
  }
}

/*
void getMode() {
  //get mode via wemos
  //mode= Serial.read();
  mode = 'f';
}

void checkMode() {

  getMode();
  
  if(mode == 'd'){
    Serial.println(mode);
    drill();
  }
  else if(mode == 't') {
    Serial.println(mode);
    tutorial();
  }
  else if(mode == 'f') {
    //Serial.println(mode);
    freeMode();
  }
  else {
    Serial.println("mode: " + mode);
  }
}*/

void loop() {
  // put your main code here, to run repeatedly:
  checkMode();
  //1549
}
