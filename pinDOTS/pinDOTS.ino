#include "SD.h"
#define SD_ChipSelectPin 53
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

String getString, str;
char getChar, mode;
boolean btn1, btn2, btn3, btn4, btn5, btn6;
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
  //pinMode(22,LOW); //relay
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

//Do While loop for checking if btn 1 was pressed
void checkbtnn1() {
  do {
    tmrpcm.play("TN1.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn1);
  } while(btn1 == HIGH);
  btn1Pressed = true;
  tmrpcm.play("FRB.wav");
}

//Do While loop for checking if btn 2 was pressed
void checkbtnn2() {
  do {
    tmrpcm.play("TN2.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn2);
  } while(btn2 == HIGH);
  btn2Pressed = true;
  tmrpcm.play("SCB.wav");
}

//Do While loop for checking if btn 3 was pressed
void checkbtnn3() {
  do {
    tmrpcm.play("TN3.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn3);
  } while(btn3 == HIGH);
  btn3Pressed = true;
  tmrpcm.play("THB.wav");
}

//Do While loop for checking if btn 4 was pressed
void checkbtnn4() {
  do {
    tmrpcm.play("TN4.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn4);
  } while(btn4 == HIGH);
  btn4Pressed = true;
  tmrpcm.play("FOB.wav");
}

//Do While loop for checking if btn 5 was pressed
void checkbtnn5() {
  do {
    tmrpcm.play("TN5.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn5);
  } while(btn5 == HIGH);
  btn5Pressed = true;
  tmrpcm.play("FFB.wav");
}

//Do While loop for checking if btn 6 was pressed
void checkbtnn6() {
  do {
    tmrpcm.play("TN6.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn6);
  } while(btn6 == HIGH);
  btn6Pressed = true;
  tmrpcm.play("SXB.wav");
}

//Do While loop for checking if btn 1 was pressed
void checkAlpha1() {
  do {
    tmrpcm.play("TN1.wav");
    while(tmrpcm.isPlaying() == 1){}
   pause5();
    readInput();
    Serial.println(btn1);
  } while(btn1 == HIGH);
  btn1Pressed = true;
}

//Do While loop for checking if btn 2 was pressed
void checkAlpha2() {
  do {
    tmrpcm.play("TN2.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn2);
  } while(btn2 == HIGH);
  btn2Pressed = true;
}

//Do While loop for checking if btn 3 was pressed
void checkAlpha3() {
  do {
    tmrpcm.play("TN3.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn3);
  } while(btn3 == HIGH);
  btn3Pressed = true;
}

//Do While loop for checking if btn 4 was pressed
void checkAlpha4() {
  do {
    tmrpcm.play("TN4.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn4);
  } while(btn4 == HIGH);
  btn4Pressed = true;
}

//Do While loop for checking if btn 5 was pressed
void checkAlpha5() {
  do {
    tmrpcm.play("TN5.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
    Serial.println(btn5);
  } while(btn5 == HIGH);
  btn5Pressed = true;
}

//Do While loop for checking if btn 6 was pressed
void checkAlpha6() {
  do {
    tmrpcm.play("TN6.wav");
    while(tmrpcm.isPlaying() == 1){}
    pause5();
    readInput();
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
  boolean ans = false;
  
  switch(receive)
  {
    case 'A':
    do{
      tmrpcm.play("DRA.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("Press A");
      pause10();
      readInput();
      
      if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LA.wav");
        while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed A!");
    break;

    case 'B':
    do{
      tmrpcm.play("DRB.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("Press B");
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LB.wav");
        while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed B!");
    break;

    case 'C':
    do{
      tmrpcm.play("DRC.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("Press C");
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LC.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed C!");
    break;

    case 'D':
    do{
      Serial.println("Press D");
      tmrpcm.play("DRD.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LD.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed D!");
    break;

    case 'E':
    do{
      Serial.println("Press E");
      tmrpcm.play("DRE.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LE.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed E!");
    break;

    case 'F':
    do{
      Serial.println("Press F");
      tmrpcm.play("DRF.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LF.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed F!");
    break;

    case 'G':
    do{
      Serial.println("Press G");
      tmrpcm.play("DRG.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LG.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed G!");
    break;

    case 'H':
    do{
      Serial.println("Press H");
      tmrpcm.play("DRH.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LH.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed H!");
    break;

    case 'I':
    do{
      Serial.println("Press I");
      tmrpcm.play("DRI.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LI.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed I!");
    break;

    case 'J':
    do{
      Serial.println("Press J");
      tmrpcm.play("DRJ.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LJ.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed J!");
    break;

    case 'K':
    do{
      Serial.println("Press K");
      tmrpcm.play("DRK.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LK.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed K!");
    break;

    case 'L':
    do{
      Serial.println("Press L");
      tmrpcm.play("DRL.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LL.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }

    }while(ans == false);
    Serial.println("Well done! You have pressed L!");
    break;

    case 'M':
    do{
      Serial.println("Press M");
      tmrpcm.play("DRM.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LM.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed M!");
    break;

    case 'N':
    do{
      Serial.println("Press N");
      tmrpcm.play("DRN.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LN.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed N!");
    break;

    case 'O':
    do{
      Serial.println("Press O");
      tmrpcm.play("DRO.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LO.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed O!");
    break;

    case 'P':
    do{
      Serial.println("Press P");
      tmrpcm.play("DRP.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LP.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed P!");
    break;

    case 'Q':
    do{
      Serial.println("Press Q");
      tmrpcm.play("DRQ.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LQ.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed Q!");
    break;

    case 'R':
    do{
      Serial.println("Press R");
      tmrpcm.play("DRR.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LR.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed R!");
    break;

    case 'S':
    do{
      Serial.println("Press S");
      tmrpcm.play("DRS.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LS.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed S!");
    break;

    case 'T':
    do{
      Serial.println("Press T");
      tmrpcm.play("DRT.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
        ans = true;
        tmrpcm.play("LT.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed T!");
    break;

    case 'U':
    do{
      Serial.println("Press U");
      tmrpcm.play("DRU.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW){
        ans = true;
        tmrpcm.play("LU.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed U!");
    break;

    case 'V':
    do{
      Serial.println("Press V");
      tmrpcm.play("DRV.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW){
        ans = true;
        tmrpcm.play("LV.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed V!");
    break;

    case 'W':
    do{
      Serial.println("Press W");
      tmrpcm.play("DRW.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == LOW){
        ans = true;
        tmrpcm.play("LW.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed W!");
    break;

    case 'X':
    do{
      Serial.println("Press X");
      tmrpcm.play("DRX.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == LOW){
        ans = true;
        tmrpcm.play("LW.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed X!");
    break;

    case 'Y':
    do{
      Serial.println("Press Y");
      tmrpcm.play("DRY.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW){
        ans = true;
        tmrpcm.play("LY.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed Y!");
    break;

    case 'Z':
    do{
      Serial.println("Press Z");
      tmrpcm.play("DRZ.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause10();
      readInput();

      if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == LOW){
        ans = true;
        tmrpcm.play("LZ.wav");
      while(tmrpcm.isPlaying() == 1){}
      }
      else{
        ans = false;
      }
      
    }while(ans == false);
    Serial.println("Well done! You have pressed Z!");
    break;
  }
}

void checkPressedButton(int pressedBtn) {
  TMRpcm tmrpcm;
  tmrpcm.setVolume(6);
  
  switch(pressedBtn){
    case 1:
    do{
      Serial.println("Turn off the first button!");
      tmrpcm.play("TO1.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause5();
      readInput();
      pauseHalf();
    }while(btn1 == LOW);
    Serial.println("You have turned off the first button!");
    break;
    
    case 2:
    do{
      Serial.println("Turn off the second button!");
      tmrpcm.play("TO2.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause5();
      readInput();
      pauseHalf();
    }while(btn2 == LOW);
    Serial.println("You have turned off the second button!");
    break;
    
    case 3:
    do{
      Serial.println("Turn off the third button!");
      tmrpcm.play("TO3.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause5();
      readInput();
      pauseHalf();
    }while(btn3 == LOW);
    Serial.println("You have turned off the third button!");
    break;

    case 4:
    do{
      Serial.println("Turn off the fourth button!");
      tmrpcm.play("TO4.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause5();
      readInput();
      pauseHalf();
    }while(btn4 == LOW);
    Serial.println("You have turned off the fourth button!");
    break;

    case 5:
    do{
      Serial.println("Turn off the fifth button!");
      tmrpcm.play("TO5.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause5();
      readInput();
      pauseHalf();
    }while(btn5 == LOW);
    Serial.println("You have turned off the fifth button!");
    break;

    case 6:
    do{
      Serial.println("Turn off the sixth button!");
      tmrpcm.play("TO6.wav");
      while(tmrpcm.isPlaying() == 1){}
      pause5();
      readInput();
      pauseHalf();
    }while(btn6 == LOW);
    Serial.println("You have turned off the sixth button!");
    break;
  }
}

void checkIfClicked() {
  TMRpcm tmrpcm;
  tmrpcm.setVolume(6);
  do {
    readInput();
    
    if(btn1 == LOW) {
      digitalWrite(28, HIGH);
      tmrpcm.play("FRB.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("You have pressed the first button!"); 
      pause3();
      btn1Pressed = true;
      checkPressedButton(1);
    }
    else if(btn2 == LOW) {
      digitalWrite(29, HIGH);
      tmrpcm.play("SCB.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("You have pressed the second button!");
      pause3();
      btn2Pressed = true;
      checkPressedButton(2);
    }
    else if(btn3 == LOW) {
      digitalWrite(30, HIGH);
      tmrpcm.play("THB.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("You have pressed the third button!");
      pause3();
      btn3Pressed = true;
      checkPressedButton(3);
    }
    else if(btn4 == LOW) {
      digitalWrite(31, HIGH);
      tmrpcm.play("FOB.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("You have pressed the fourth button!");
      pause3();
      btn4Pressed = true;
      checkPressedButton(4);
    }
    else if(btn5 == LOW) {
      digitalWrite(32, HIGH);
      tmrpcm.play("FFB.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("You have pressed the fifth button!");
      pause3();
      btn5Pressed = true;
      checkPressedButton(5);
    }
    else if(btn6 == LOW) {
      digitalWrite(33, HIGH);
      tmrpcm.play("SXB.wav");
      while(tmrpcm.isPlaying() == 1){}
      Serial.println("You have pressed the sixth button!");
      pause3();
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
    while(tmrpcm.isPlaying() == 1){}
  }
  
  //B
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    changeDotState("110000");
    tmrpcm.play("LB.wav");
    Serial.println("B");
    while(tmrpcm.isPlaying() == 1){}
  }

  //C
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("100100");
    tmrpcm.play("LC.wav");
    Serial.println("C");
    while(tmrpcm.isPlaying() == 1){}
  }
  
  //D
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("100110");
    tmrpcm.play("LD.wav");
    Serial.println("D");
    while(tmrpcm.isPlaying() == 1){}
  }
  //E
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    changeDotState("100010");
    tmrpcm.play("LE.wav");
    Serial.println("E");
    while(tmrpcm.isPlaying() == 1){}
  }
  //F
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("110100");
    tmrpcm.play("LF.wav");
    Serial.println("F");
    while(tmrpcm.isPlaying() == 1){}
  }
  //G
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("110110");
    tmrpcm.play("LG.wav");
    Serial.println("G");
    while(tmrpcm.isPlaying() == 1){}
  }
  //H
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    changeDotState("110010");
    tmrpcm.play("LH.wav");
    Serial.println("H");
    while(tmrpcm.isPlaying() == 1){}
  }
  //I
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("010100");
    tmrpcm.play("LI.wav");
    Serial.println("I");
    while(tmrpcm.isPlaying() == 1){}
  }
  //J
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("010110");
    tmrpcm.play("LJ.wav");
    Serial.println("J");
    while(tmrpcm.isPlaying() == 1){}
  }
  //K
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    changeDotState("101000");
    tmrpcm.play("LK.wav");
    Serial.println("K");
    while(tmrpcm.isPlaying() == 1){}
  }
  //L
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    changeDotState("111000");
    tmrpcm.play("LL.wav");
    Serial.println("L");
    while(tmrpcm.isPlaying() == 1){}
  }
  //M
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("101100");
    tmrpcm.play("LM.wav");
    Serial.println("M");
    while(tmrpcm.isPlaying() == 1){}
  }
  //N
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("101110");
    tmrpcm.play("LN.wav");
    Serial.println("N");
    while(tmrpcm.isPlaying() == 1){}
  }
  //O
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    changeDotState("101010");
    tmrpcm.play("LO.wav");
    Serial.println("O");
    while(tmrpcm.isPlaying() == 1){}
  }
  //P
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("111100");
    tmrpcm.play("LP.wav");
    Serial.println("P");
    while(tmrpcm.isPlaying() == 1){}
  }
  //Q
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("111110");
    tmrpcm.play("LQ.wav");
    Serial.println("Q");
    while(tmrpcm.isPlaying() == 1){}
  }
  //R
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    changeDotState("111010");
    tmrpcm.play("LR.wav");
    Serial.println("R");
    while(tmrpcm.isPlaying() == 1){}
  }
  //S
  else if(btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    changeDotState("011100");
    tmrpcm.play("LS.wav");
    Serial.println("S");
    while(tmrpcm.isPlaying() == 1){}
  }
  //T
  else if(btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    changeDotState("011110");
    tmrpcm.play("LT.wav");
    Serial.println("T");
    while(tmrpcm.isPlaying() == 1){}
  }
  //U
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW){
    changeDotState("101001");
    tmrpcm.play("LU.wav");
    Serial.println("U");
    while(tmrpcm.isPlaying() == 1){}
  }
  //V
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW){
    changeDotState("111001");
    tmrpcm.play("LV.wav");
    Serial.println("V");
    while(tmrpcm.isPlaying() == 1){}
  }
  //W
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == LOW){
    changeDotState("010111");
    tmrpcm.play("LW.wav");
    Serial.println("W");
    while(tmrpcm.isPlaying() == 1){}
  }
  //X
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == LOW){
    changeDotState("101101");
    tmrpcm.play("LX.wav");
    Serial.println("X");
    while(tmrpcm.isPlaying() == 1){}
  }
  //Y
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW){
    changeDotState("101111");
    tmrpcm.play("LY.wav");
    Serial.println("Y");
    while(tmrpcm.isPlaying() == 1){}
  }
  //Z
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == LOW){
    changeDotState("101011");
    tmrpcm.play("LZ.wav");
    Serial.println("Z");
    while(tmrpcm.isPlaying() == 1){}
  }
  else{
    Serial.println("Wrong");
  }
}

//Free mode
void freeMode() {
  delay(3000);
  readInput();
  //on();
  //off();
  Check();
}

//Tutorial mode
void tutorial() {

  tmrpcm.setVolume(6);
  //btns
  tmrpcm.play("A0.wav");
  Serial.println("Welcome to pinDOTS!");
  while(tmrpcm.isPlaying() == 1){}
  tmrpcm.play("B0.wav");
  Serial.println("On your left you have 6 btns. On your right you have 6 dots. Can you feel the buttons on your left? Try pressing any button.");
  while(tmrpcm.isPlaying() == 1){}
  //Check if any buttons were pressed!
  checkIfClicked();
  tmrpcm.play("C0.wav");
  Serial.println("Very Good!");
  while(tmrpcm.isPlaying() == 1){}
  tmrpcm.play("D0.wav");
  while(tmrpcm.isPlaying() == 1){}
  Serial.println("You can press these btns to push down and pop up the dots! If you press the first btn, the first dot will pop up,if you press the first btn again, the first dot will push down! So let us start our tutorial! ");
  
  Serial.println("Try pressing the first btn!");
  //test();
  checkbtnn1();
  Serial.println("Great! You were able to press the first btn! Now try to feel the first dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("F0.wav");
  changeDotState("100000");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  
  Serial.println("Now try pressing the second btn!");
  checkbtnn2();
  Serial.println("Great! You were able to press the second btn! Now try to feel the second dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("H0.wav");
  changeDotState("010000");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(2);
  
  Serial.println("Now try pressing the third btn!");
  checkbtnn3();
  Serial.println("Great! You were able to press the third btn! Now try to feel the third dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("J0.wav");
  changeDotState("001000");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(3);
  
  Serial.println("Now try pressing the fourth btn!");
  checkbtnn4();
  Serial.println("Great! You were able to press the fourth btn! Now try to feel the fourth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("L0.wav");
  changeDotState("000100");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(4);

  Serial.println("Now try pressing the fifth btn!");
  checkbtnn5();
  Serial.println("Great! You were able to press the fifth btn! Now try to feel the fifth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("N0.wav");
  changeDotState("000010");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(5);

  Serial.println("Try pressing the sixth btn!");
  checkbtnn6();
  Serial.println("Great! You were able to press the sixth btn! Now try to feel the sixth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("P0.wav");
  changeDotState("000001");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(6);

  tmrpcm.play("Q0.wav");
  Serial.println("Great! You were able to press all the btns! Very good!");
  while(tmrpcm.isPlaying() == 1){}
  tmrpcm.play("R.wav");
  Serial.println("Now let us practice the braille alphabets from A - Z!");
  while(tmrpcm.isPlaying() == 1){}
  
  //Alphabets

  //A
  Serial.println("Press the first btn!");
  checkAlpha1();
  tmrpcm.play("A2.wav");
  Serial.println("Great! You have pressed A! You have 10 seconds to feel the dot!");
  pause10();
  changeDotState("100000");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  
  //B
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  //changeDotState("010000");
  //tmrpcm.play("B3.wav");
  //Serial.println("Great! You have pressed B! You have 10 seconds to feel the dot!");
  //while(tmrpcm.isPlaying() == 1){}
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(5);
  checkPressedButton(6);
  
  /*
  //Numbers

  //1
  Serial.println("Press the first btn!");
  checkAlpha1();
  Serial.println("Great! You have pressed 1! You have 10 seconds to feel the dot!");
  changeDotState("100000");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  
  //2
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Great! You have pressed 2! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  
  //3
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 3! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  resetOutputPin();

  //5
  Serial.println("Press the first btn!");
  checkAlpha1();
  changeDotState("100000");
  Serial.println("Press the fifth btn!");
  checkAlpha5();
  changeDotState("000010");
  Serial.println("Great! You have pressed 5! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  resetOutputPin();

  //9
  Serial.println("Press the second btn!");
  checkAlpha2();
  changeDotState("010000");
  Serial.println("Press the fourth btn!");
  checkAlpha4();
  changeDotState("000100");
  Serial.println("Great! You have pressed 9! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  resetOutputPin();
  */
  
  Serial.println("Congratulations! You have completed the tutorial!");

  checkMode();
}

void playAudio(String words){

  Serial.println("Word: " + words);
  
  if(words == "BEE"){
    tmrpcm.play("Bee.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "CAT"){
    tmrpcm.play("Cat.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "DOG"){
    tmrpcm.play("Dog.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "PET"){
    tmrpcm.play("Pet.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "RAT"){
    tmrpcm.play("Rat.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "FLY"){
    tmrpcm.play("Fly.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "PIG"){
    tmrpcm.play("Pig.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "SUN"){
    tmrpcm.play("Sun.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "FIT"){
    tmrpcm.play("Fit.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "FAT"){
    tmrpcm.play("Fat.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
}

//Drill mode
void drill() {
  
  tmrpcm.play("WDR.wav");
  while(tmrpcm.isPlaying() == 1){}
  Serial.println("Welcome to drill mode");
  tmrpcm.play("WDR1.wav");
  while(tmrpcm.isPlaying() == 1){}
  
  String data = str;
  Serial.println("String : " + str);

  //Counting the number of words from the string
  int wordCount = 1;
  for(int i = 0; i < data.length(); i++)
  {
    if(data[i] == '-')
      wordCount++;
  }
  
  char drillWordArray[4];
  String words[wordCount];
  char * pch;
  char str[data.length() + 1];
  data.toCharArray(str, data.length() + 1);
  pch = strtok (str, "-");

  //Separating the words from the string
  for(int x = 0; x < wordCount; x++)
  {
    if(x == (wordCount - 1))
    {
      words[x] = pch;
    }
    else
    {
      words[x] = pch;
      pch = strtok (NULL, "-");
    }
  }

  //Separating letters from words
  for(int x = 0; x < wordCount; x++)
  {
    Serial.println(words[x]);
    playAudio(words[x]);
    String drillWord = words[x];
    drillWord.toCharArray(drillWordArray, 4); //Convert String to Array
    
    for (int i = 0; i < sizeof(drillWordArray) - 1; i++){ //
        Serial.println(drillWordArray[i]);
        checkAlpha(drillWordArray[i]);
        tmrpcm.play("C0.wav");
        while(tmrpcm.isPlaying() == 1){}
        delay(1000);
    }
  }
  
  tmrpcm.play("WDR2.wav");
  while(tmrpcm.isPlaying() == 1){}
  checkMode();
}

int ctr=0;

void getMode(){
  //str = "freemode";
  //str = "tutorial";
  //str = "CAT-DOG-ANT";
  
  str = Serial.readString();
  str.trim();
  
  Serial.println("Mode : " + str);
  
  if(str == "freemode"){
    //mode = 'f';
    Serial.println("Free Mode");
    freeMode();
  }
  else if(str == "tutorial"){
    //mode = 't';
    Serial.println("Tutorial");
    tutorial();
  }
  else if(str.indexOf("-") > 0){
    //mode ='d';
    Serial.println("Drill Mode");
    drill();
  }
}

void checkMode(){
  getMode();
}

void loop() {
  // put your main code here, to run repeatedly:
  checkMode();
}
