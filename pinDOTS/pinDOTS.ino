#include "SD.h"
#define SD_ChipSelectPin 53
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

String str;
boolean btn1, btn2, btn3, btn4, btn5, btn6;
boolean btn1Pressed = false, btn2Pressed = false, btn3Pressed = false, btn4Pressed = false, btn5Pressed = false, btn6Pressed = false, alpha = false;

void setup() {
  // put your setup code here, to run once:

  initializeInputPin();
  initializeOutputPin();
  initializeStaticPin();

  Serial.begin(9600);

  tmrpcm.speakerPin = 11;
  tmrpcm.setVolume(6);

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

//Read Input Pin
void readInput() {
  btn1 = digitalRead(22);
  btn2 = digitalRead(23);
  btn3 = digitalRead(24);
  btn4 = digitalRead(25);
  btn5 = digitalRead(26);
  btn6 = digitalRead(27);
}

void resetBool() {
  btn1Pressed = false;
  btn2Pressed = false;
  btn3Pressed = false;
  btn4Pressed = false;
  btn5Pressed = false;
  btn6Pressed = false;
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

void checkPressedButton(int pressedBtn) {

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

//Do While loop for checking if btn 1 was pressed
void checkbtn1() {

  readInput();

  if(btn1 == LOW){
    btn1Pressed = true;
    tmrpcm.play("FRB.wav");
    while(tmrpcm.isPlaying() == 1){}
    checkPressedButton(1);
  }
}

//Do While loop for checking if btn 2 was pressed
void checkbtn2() {

  readInput();

  if(btn2 == LOW){
    btn2Pressed = true;
    tmrpcm.play("SCB.wav");
    while(tmrpcm.isPlaying() == 1){}
    checkPressedButton(2);
  }
}

//Do While loop for checking if btn 3 was pressed
void checkbtn3() {

    readInput();

    if(btn3 == LOW){
      btn3Pressed = true;
      tmrpcm.play("THB.wav");
      while(tmrpcm.isPlaying() == 1){}
      checkPressedButton(3);
    }
}

//Do While loop for checking if btn 4 was pressed
void checkbtn4() {

  readInput();

  if(btn4 == LOW){
    btn4Pressed = true;
    tmrpcm.play("FOB.wav");
    while(tmrpcm.isPlaying() == 1){}
    checkPressedButton(4);
  }
}

//Do While loop for checking if btn 5 was pressed
void checkbtn5() {

  readInput();

  if(btn5 == LOW){
    btn5Pressed = true;
    tmrpcm.play("FFB.wav");
    while(tmrpcm.isPlaying() == 1){}
    checkPressedButton(5);
  }
}

//Do While loop for checking if btn 6 was pressed
void checkbtn6() {

  readInput();

  if(btn6 == LOW){
    btn6Pressed = true;
    tmrpcm.play("SXB.wav");
    while(tmrpcm.isPlaying() == 1){}
    checkPressedButton(6);
  }
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
  if(alpha == false){
    btn1Pressed = true;
    tmrpcm.play("FRB.wav");
  }
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
  if(alpha == false){
    btn2Pressed = true;
    tmrpcm.play("SCB.wav");
  }
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
  if(alpha == false){
    btn3Pressed = true;
    tmrpcm.play("THB.wav");
  }
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
  if(alpha == false){
    btn4Pressed = true;
    tmrpcm.play("FOB.wav");
  }
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
  if(alpha == false){
    btn5Pressed = true;
    tmrpcm.play("FFB.wav");
  }
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
  if(alpha == false){
    btn6Pressed = true;
    tmrpcm.play("SXB.wav");
  }
}

//Checking the alphabet combinations
void check() {

  //A
  if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LA.wav");
    Serial.println("A");
    while(tmrpcm.isPlaying() == 1){}
  }

  //B
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LB.wav");
    Serial.println("B");
    while(tmrpcm.isPlaying() == 1){}
  }

  //C
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH ){
    tmrpcm.play("LC.wav");
    Serial.println("C");
    while(tmrpcm.isPlaying() == 1){}
  }

  //D
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LD.wav");
    Serial.println("D");
    while(tmrpcm.isPlaying() == 1){}
  }
  //E
  else if(btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LE.wav");
    Serial.println("E");
    while(tmrpcm.isPlaying() == 1){}
  }
  //F
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LF.wav");
    Serial.println("F");
    while(tmrpcm.isPlaying() == 1){}
  }
  //G
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LG.wav");
    Serial.println("G");
    while(tmrpcm.isPlaying() == 1){}
  }
  //H
  else if(btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LH.wav");
    Serial.println("H");
    while(tmrpcm.isPlaying() == 1){}
  }
  //I
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LI.wav");
    Serial.println("I");
    while(tmrpcm.isPlaying() == 1){}
  }
  //J
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LJ.wav");
    Serial.println("J");
    while(tmrpcm.isPlaying() == 1){}
  }
  //K
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LK.wav");
    Serial.println("K");
    while(tmrpcm.isPlaying() == 1){}
  }
  //L
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LL.wav");
    Serial.println("L");
    while(tmrpcm.isPlaying() == 1){}
  }
  //M
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LM.wav");
    Serial.println("M");
    while(tmrpcm.isPlaying() == 1){}
  }
  //N
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LN.wav");
    Serial.println("N");
    while(tmrpcm.isPlaying() == 1){}
  }
  //O
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LO.wav");
    Serial.println("O");
    while(tmrpcm.isPlaying() == 1){}
  }
  //P
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LP.wav");
    Serial.println("P");
    while(tmrpcm.isPlaying() == 1){}
  }
  //Q
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LQ.wav");
    Serial.println("Q");
    while(tmrpcm.isPlaying() == 1){}
  }
  //R
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LR.wav");
    Serial.println("R");
    while(tmrpcm.isPlaying() == 1){}
  }
  //S
  else if(btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH){
    tmrpcm.play("LS.wav");
    Serial.println("S");
    while(tmrpcm.isPlaying() == 1){}
  }
  //T
  else if(btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH){
    tmrpcm.play("LT.wav");
    Serial.println("T");
    while(tmrpcm.isPlaying() == 1){}
  }
  //U
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW){
    tmrpcm.play("LU.wav");
    Serial.println("U");
    while(tmrpcm.isPlaying() == 1){}
  }
  //V
  else if(btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW){
    tmrpcm.play("LV.wav");
    Serial.println("V");
    while(tmrpcm.isPlaying() == 1){}
  }
  //W
  else if(btn1 == HIGH && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == LOW){
    tmrpcm.play("LW.wav");
    Serial.println("W");
    while(tmrpcm.isPlaying() == 1){}
  }
  //X
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == LOW){
    tmrpcm.play("LX.wav");
    Serial.println("X");
    while(tmrpcm.isPlaying() == 1){}
  }
  //Y
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW){
    tmrpcm.play("LY.wav");
    Serial.println("Y");
    while(tmrpcm.isPlaying() == 1){}
  }
  //Z
  else if(btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == LOW){
    tmrpcm.play("LZ.wav");
    Serial.println("Z");
    while(tmrpcm.isPlaying() == 1){}
  }
  else{
    Serial.println("Wrong");
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

void playAudio(String words){

  Serial.println("Word: " + words);

  if(words == "AIR"){
    tmrpcm.play("Air.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "ANT"){
    tmrpcm.play("Ant.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "ARM"){
    tmrpcm.play("Arm.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "ART"){
    tmrpcm.play("Art.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "BAD"){
    tmrpcm.play("Bad.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "BEE"){
    tmrpcm.play("Bee.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "CAP"){
    tmrpcm.play("Cap.wav");
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
  else if(words == "EGG"){
    tmrpcm.play("Egg.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "EYE"){
    tmrpcm.play("Eye.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "FAT"){
    tmrpcm.play("Fat.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "FIT"){
    tmrpcm.play("Fit.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "FLY"){
    tmrpcm.play("Fly.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
  else if(words == "FRY"){
    tmrpcm.play("Fry.wav");
    while(tmrpcm.isPlaying() == 1){}
  }
}

//Tutorial mode
void tutorial() {

  Serial.println("Tutorial Mode on");
  //btns
  Serial.println("Welcome to pinDOTS!");
  tmrpcm.play("A0.wav");
  while(tmrpcm.isPlaying() == 1){}
  tmrpcm.play("A0_1.wav");
  while(tmrpcm.isPlaying() == 1){}
  tmrpcm.play("B0.wav");
  Serial.println("On your left you have 6 btns. On your right you have 6 dots. Can you feel the buttons on your left? Try pressing any button.");
  while(tmrpcm.isPlaying() == 1){}

  //Check if any buttons were pressed!

  do{
    checkbtn1();
    pauseHalf();

    checkbtn2();
    pauseHalf();

    checkbtn3();
    pauseHalf();

    checkbtn4();
    pauseHalf();

    checkbtn5();
    pauseHalf();

    checkbtn6();
    pauseHalf();

  }while(btn1Pressed == false && btn2Pressed == false && btn3Pressed == false && btn4Pressed == false && btn5Pressed == false && btn6Pressed == false);

  pause10();

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
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);

  Serial.println("Now try pressing the second btn!");
  checkbtnn2();
  Serial.println("Great! You were able to press the second btn! Now try to feel the second dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("H0.wav");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(2);

  Serial.println("Now try pressing the third btn!");
  checkbtnn3();
  Serial.println("Great! You were able to press the third btn! Now try to feel the third dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("J0.wav");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(3);

  Serial.println("Now try pressing the fourth btn!");
  checkbtnn4();
  Serial.println("Great! You were able to press the fourth btn! Now try to feel the fourth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("L0.wav");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(4);

  Serial.println("Now try pressing the fifth btn!");
  checkbtnn5();
  Serial.println("Great! You were able to press the fifth btn! Now try to feel the fifth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("N0.wav");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(5);

  Serial.println("Try pressing the sixth btn!");
  checkbtnn6();
  Serial.println("Great! You were able to press the sixth btn! Now try to feel the sixth dot! You have 10 seconds to feel the dot!");
  tmrpcm.play("P0.wav");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(6);

  tmrpcm.play("Q0.wav");
  Serial.println("Great! You were able to press all the btns! Very good!");
  while(tmrpcm.isPlaying() == 1){}
  tmrpcm.play("R.wav");
  Serial.println("Now let us practice the braille alphabets from A - Z!");
  while(tmrpcm.isPlaying() == 1){}

  alpha = true;

  //Alphabets

  //A
  Serial.println("Press the first btn!");
  checkbtnn1();
  tmrpcm.play("A2.wav");
  Serial.println("Great! You have pressed A! You have 10 seconds to feel the dot!");
  pause10();
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);

  //B
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  tmrpcm.play("B3.wav");
  Serial.println("Great! You have pressed B! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  checkPressedButton(1);
  checkPressedButton(2);

  //C
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  tmrpcm.play("C3.wav");
  Serial.println("Great! You have pressed C! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(4);

  //D
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
  tmrpcm.play("D4.wav");
  Serial.println("Great! You have pressed D! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(4);
  checkPressedButton(5);

  //E
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
  tmrpcm.play("E3.wav");
  Serial.println("Great! You have pressed E! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(5);

  //F
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  tmrpcm.play("F4.wav");
  Serial.println("Great! You have pressed F! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(4);

  //G
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
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
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
  tmrpcm.play("H4.wav");
  Serial.println("Great! You have pressed H! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(5);

  //I
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  tmrpcm.play("I3.wav");
  Serial.println("Great! You have pressed I! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(2);
  checkPressedButton(4);

  //J
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
  tmrpcm.play("J4.wav");
  Serial.println("Great! You have pressed J! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(2);
  checkPressedButton(4);
  checkPressedButton(5);

  //K
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the third btn!");
  checkbtnn3();
  tmrpcm.play("K3.wav");
  Serial.println("Great! You have pressed K! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(3);

  //L
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the third btn!");
  checkbtnn3();
  tmrpcm.play("L4.wav");
  Serial.println("Great! You have pressed L! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(2);
  checkPressedButton(3);

  //M
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  tmrpcm.play("M4.wav");
  Serial.println("Great! You have pressed M! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(4);

  //N
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
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
  checkbtnn1();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
  tmrpcm.play("O4.wav");
  Serial.println("Great! You have pressed O! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(5);

  //P
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
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
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
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
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
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
  checkbtnn2();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  tmrpcm.play("S4.wav");
  Serial.println("Great! You have pressed S! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(2);
  checkPressedButton(3);
  checkPressedButton(4);

  //T
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
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
  checkbtnn1();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the sixth btn!");
  checkbtnn6();
  tmrpcm.play("U4.wav");
  Serial.println("Great! You have pressed U! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(6);

  //V
  Serial.println("Press the first btn!");
  checkbtnn1();
  Serial.println("Press the second btn!");
  checkbtnn2();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the sixth btn!");
  checkbtnn6();
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
  checkbtnn2();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
  Serial.println("Press the sixth btn!");
  checkbtnn6();
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
  checkbtnn1();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the sixth btn!");
  checkbtnn6();
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
  checkbtnn1();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fourth btn!");
  checkbtnn4();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
  Serial.println("Press the sixth btn!");
  checkbtnn6();
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
  checkbtnn1();
  Serial.println("Press the third btn!");
  checkbtnn3();
  Serial.println("Press the fifth btn!");
  checkbtnn5();
  Serial.println("Press the sixth btn!");
  checkbtnn6();
  tmrpcm.play("Z5.wav");
  Serial.println("Great! You have pressed Z! You have 10 seconds to feel the dot!");
  while(tmrpcm.isPlaying() == 1){}
  pause10();
  checkPressedButton(1);
  checkPressedButton(3);
  checkPressedButton(5);
  checkPressedButton(6);


  Serial.println("Congratulations! You have completed the tutorial!");

  checkMode();
}

//Free mode
void freeMode() {

  tmrpcm.play("Welcome.wav");
  while(tmrpcm.isPlaying() == 1){}
  tmrpcm.play("Welcome1.wav");
  while(tmrpcm.isPlaying() == 1){}

  boolean checkFree = true;

  do{
    delay(3000);
    readInput();
    check();
  }while(checkFree == true);
  Serial.println("Free mode done!");
}

//Drill mode
void drill() {


  tmrpcm.play("WDR.wav");
  Serial.println("Welcome to drill mode");
  while(tmrpcm.isPlaying() == 1){}
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

//---//---//
void getMode(){
  //str = "freemode";
  //str = "tutorial";
  //str = "CAT-DOG-ANT";

  str = Serial.readString();
  str.trim();

  Serial.println("Mode : " + str);

  if(str == "freemode"){
    Serial.println("Free Mode");
    freeMode();
  }
  else if(str == "tutorial"){
    Serial.println("Tutorial");
    tutorial();
  }
  else if(str.indexOf("-") > 0){
    Serial.println("Drill Mode");
    drill();
  }
  else{

  }
}

void checkMode(){
  getMode();
  pauseHalf();
}
//---//---//

void loop() {
  // put your main code here, to run repeatedly:
  checkMode();
}

