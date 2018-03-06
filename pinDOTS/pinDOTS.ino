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
  pinMode(28,LOW); //relay
  pinMode(29,LOW); //relay
  pinMode(30,LOW); //relay
  pinMode(31,LOW); //relay
  pinMode(32,LOW); //relay
  pinMode(33,LOW); //relay
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

//Embosing the solenoid
void on() {
  if(btn1Pressed == true) {
    digitalWrite(28, LOW);
    tmrpcm.play("firstButtonPressed.wav");
    Serial.println("You have pressed the first button!"); 
  }
  if(btn2Pressed == true) {
    digitalWrite(29, LOW);
    tmrpcm.play("secondButtonPressed.wav");
    Serial.println("You have pressed the second button!");
  }
  if(btn3Pressed == true) {
    digitalWrite(30, LOW);
    tmrpcm.play("thirdButtonPressed.wav");
    Serial.println("You have pressed the third button!");
  }
  if(btn4Pressed == true) {
    digitalWrite(31, LOW);
    tmrpcm.play("fourthButtonPressed.wav");
    Serial.println("You have pressed the fourth button!");
  }
  if(btn5Pressed == true) {
    digitalWrite(32, LOW);
    tmrpcm.play("fifthButtonPresed.wav");
    Serial.println("You have pressed the fifth button!");
  }
  if(btn6Pressed == true) {
    digitalWrite(33, LOW);
    tmrpcm.play("sixthButtonPressed.wav");
    Serial.println("You have pressed the sixth button!");
  }
  Check();
}

//Engraving the solenoid
void off() {
  if(btn1Pressed == false) {
    digitalWrite(28, HIGH);
    tmrpcm.play("firstButtonPressed.wav");
    Serial.println("You have pressed the first button!");
  }
  if(btn2Pressed == false) {
    digitalWrite(29, HIGH);
    tmrpcm.play("secondButtonPressed.wav");
    Serial.println("You have pressed the second button!");
  }
  if(btn3Pressed == false) {
    tmrpcm.play("thirdButtonPressed.wav");
    digitalWrite(30, HIGH);
    Serial.println("You have pressed the third button!");
  }
  if(btn4Pressed == false) {
    tmrpcm.play("fourthButtonPressed.wav");
    digitalWrite(31, HIGH);
    Serial.println("You have pressed the fourth button!");
  }
  if(btn5Pressed == false) {
    tmrpcm.play("fifthButtonPressed.wav");
    digitalWrite(32, HIGH);
    Serial.println("You have pressed the fifth button!");
  }
  if(btn6Pressed == false) {
    tmrpcm.play("sixthButtonPressed.wav");
    digitalWrite(33, HIGH);
    Serial.println("You have pressed the sixth button!");
  }
  Check();
}

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

//Free mode
void freeMode() {
  readInput();
  on();
  off();
  checkMode();
}

//Tutorial mode
void tutorial() {

  int passedIntButton;
  
  //btns
  Serial.println("Welcome to pinDOTS!");
  pause1();
  Serial.println("On your left you have 6 btns. On your right you have 6 dots. Can you feel the buttons on your left? Try pressing any button.");
  pause1();
  //Check if any buttons were pressed!
  checkIfClicked();
  Serial.println("Very Good!");
  pause1();
  Serial.println("You can press these btns to push down and pop up the dots! If you press the first btn, the first dot will pop up,if you press the first btn again, the first dot will push down! So let us start our tutorial! ");
  pause1();
  
  Serial.println("Try pressing the first btn!");
  checkBtnStatus(1);
  Serial.println("Great! You were able to press the first btn! Now try to feel the first dot! You have 10 seconds to feel the dot!");
  changeDotState("100000");
  pause1();
  resetBool();
  resetOutputPin();
  
  Serial.println("Now try pressing the second btn!");
  checkBtnStatus(2);
  Serial.println("Great! You were able to press the second btn! Now try to feel the second dot! You have 10 seconds to feel the dot!");
  changeDotState("010000");
  pause1();
  resetBool();
  resetOutputPin();
  
  Serial.println("Now try pressing the third btn!");
  checkBtnStatus(3);
  Serial.println("Great! You were able to press the third btn! Now try to feel the third dot! You have 10 seconds to feel the dot!");
  changeDotState("001000");
  pause1();
  resetBool();
  resetOutputPin();
  
  Serial.println("Now try pressing the fourth btn!");
  checkBtnStatus(4);
  Serial.println("Great! You were able to press the fourth btn! Now try to feel the fourth dot! You have 10 seconds to feel the dot!");
  changeDotState("000100");
  pause1();
  resetBool();
  resetOutputPin();
  
  Serial.println("Now try pressing the fifth btn!");
  checkBtnStatus(5);
  Serial.println("Great! You were able to press the fifth btn! Now try to feel the fifth dot! You have 10 seconds to feel the dot!");
  changeDotState("000010");
  pause1();
  resetBool();
  resetOutputPin();
  
  Serial.println("Try pressing the sixth btn!");
  checkBtnStatus(6);
  Serial.println("Great! You were able to press the sixth btn! Now try to feel the sixth dot! You have 10 seconds to feel the dot!");
  changeDotState("000001");
  pause1();
  resetBool();
  resetOutputPin();
  
  Serial.println("Great! You were able to press all the btns! Very good!");
  pause1();
  
  Serial.println("Now let us practice the braille alphabets from A - Z!");
  pause1();
  
  //Alphabets

  //A
  Serial.println("Press the first btn!");
  checkbtn1();
  Serial.println("Great! You have pressed A! You have 10 seconds to feel the dot!");
  changeDotState("100000");
  pause1();
  resetOutputPin();

  //B
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Great! You have pressed B! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //C
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed C! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //D
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed D! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //E
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed E! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //F
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed F! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //G
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed G! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //H
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed H! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //I
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed I! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //J
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Press the six btn!");
  checkbtn6();
  changeDotState("000001");
  Serial.println("Great! You have pressed J! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //K
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Great! You have pressed K! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //L
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Great! You have pressed L! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //M
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed M! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //N
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed N! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //O
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed O! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //P
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("0100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed P! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //Q
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed Q! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //R
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed R! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //S
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed S! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //T
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed T! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //U
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the sixth btn!");
  checkbtn6();
  changeDotState("000001");
  Serial.println("Great! You have pressed U! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //V
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the sixth btn!");
  checkbtn6();
  changeDotState("000001");
  Serial.println("Great! You have pressed V! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //W
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkbtn6();
  changeDotState("000001");
  Serial.println("Great! You have pressed W! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //X
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the sixth btn!");
  checkbtn6();
  changeDotState("000001");
  Serial.println("Great! You have pressed X! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //Y
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkbtn6();
  changeDotState("000001");
  Serial.println("Great! You have pressed Y! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //Z
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the third btn!");
  checkbtn3();
  changeDotState("001000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Press the sixth btn!");
  checkbtn6();
  changeDotState("000001");
  Serial.println("Great! You have pressed Z! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //Numbers

  //1
  Serial.println("Press the first btn!");
  checkbtn1();
  Serial.println("Great! You have pressed 1! You have 10 seconds to feel the dot!");
  changeDotState("100000");
  pause1();
  resetOutputPin();

  //2
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Great! You have pressed 2! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //3
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 3! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //4
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 4! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //5
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 5! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //6
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 6! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //7
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 7! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //8
  Serial.println("Press the first btn!");
  checkbtn1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 8! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //9
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkbtn4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 9! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  //0
  Serial.println("Press the second btn!");
  checkbtn2();
  changeDotState("010000");
  Serial.println("Press the fifth btn!");
  checkbtn5();
  changeDotState("000010");
  Serial.println("Press the six btn!");
  checkbtn6();
  changeDotState("000001");
  Serial.println("Great! You have pressed 0! You have 10 seconds to feel the dot!");
  pause1();
  resetOutputPin();

  Serial.println("Congratulations! You have completed the tutorial!");

  checkMode();
}

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

void getMode() {
  //get mode via wemos
  //mode= Serial.read();
  mode = 't';
}

void checkMode() {

  getMode();
  
  if(mode == 'd'){
    Serial.println(mode);
    pause3();
    drill();
  }
  else if(mode == 't') {
    Serial.println(mode);
    pause3();
    tutorial();
  }
  else if(mode == 'f') {
    Serial.println(mode);
    pause3();
    freeMode();
  }
  else {
    Serial.println("mode: " + mode);
    pause3();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  checkMode();
  //1549
}
