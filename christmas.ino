
/*
Lighting for Christmas. 9 channels

          _/\_
          \__/   ............>  LEDMain
    / / / / | \ \ \ \
   1  2 3 4 5 6 7 8 9
      
*/
int LED[] = {3,4,5,6,7,8,9,10,11};
int LEDMain = 2;

void setup() {
  int i;
  for (i=0; i<9; i++) {
    pinMode(LED[i], OUTPUT);
  }
  pinMode(LEDMain, OUTPUT);
}

void turnoff(){
 int i;
  for (i=0; i<9; i++) {
    digitalWrite(LED[i], LOW);
  }
}

void turnon(){
 int i;
  for (i=0; i<9; i++) {
    digitalWrite(LED[i], HIGH);
  }
}



void blink1(int sleepTime) {
  digitalWrite(LEDMain, HIGH);
  int j;
  int i;
  for (i=0; i<9; i++) {
    if (i % 2 != 0) {
     digitalWrite(LED[i], HIGH);
    } else {
      digitalWrite(LED[i], LOW);
    }
  }
  delay(sleepTime);
  for (j=0; j<9; j++) {
    if (j % 2 != 0) {
    digitalWrite(LED[j], LOW);
    } else {
      digitalWrite(LED[j], HIGH);
    }
  }
  delay(sleepTime);
}

void blink2(int sleepTime) {
  int i;
  int j;
  int toggle=0;
  int toggle_time=0;
  for (i=0; i<9; i++) {
    j = i - 1;
    if (i==0) { j=8;}
    digitalWrite(LED[i], HIGH);
    digitalWrite(LED[j], LOW);
    if (toggle_time>1){
     if (toggle==0){toggle=1;}
      else {toggle=0;}
      toggle_time=0;
      digitalWrite(LEDMain, toggle);
    }
    toggle_time++;
    
    delay(sleepTime);
  }
  for (i=7; i>0; i--) {
    j = i + 1;
    digitalWrite(LED[i], HIGH);
    digitalWrite(LED[j], LOW);
    if (toggle_time>1){
     if (toggle==0){toggle=1;}
      else {toggle=0;}
      toggle_time=0;
      digitalWrite(LEDMain, toggle);
    }
    toggle_time++;
    
    delay(sleepTime);
  }
  digitalWrite(LED[1], LOW);
}

void blink3(int sleepTime) {
  int i;
  digitalWrite(LEDMain, HIGH);
  for (i=0 ; i<5; i++) {
    digitalWrite(LED[i], HIGH);
    digitalWrite(LED[8-i], HIGH);
    digitalWrite(LED[i-1], LOW);
    digitalWrite(LED[9-i], LOW);
    delay(sleepTime);
  }
    for (i=3 ; i>0; i--) {
    digitalWrite(LED[i], HIGH);
    digitalWrite(LED[8-i], HIGH);
    digitalWrite(LED[i+1], LOW);
    digitalWrite(LED[7-i], LOW);
    delay(sleepTime);
  }
  turnoff();
}

void blink4(int sleepTime) {
  int i;
  digitalWrite(LEDMain, LOW);
  for (i=0 ; i<5; i++) {
    digitalWrite(LED[i], HIGH);
    digitalWrite(LED[8-i], HIGH);
    delay(sleepTime);
  }
  digitalWrite(LEDMain, HIGH);
  delay(sleepTime);
    for (i=4 ; i>-1; i--) {
    digitalWrite(LED[i], LOW);
    digitalWrite(LED[8-i], LOW);
    delay(sleepTime);
  }
  digitalWrite(LEDMain, LOW);
  delay(sleepTime);
}

void blink5(int sleepTime) {
  int i;
  int j;
  
  //Entering

  for (i=0; i<9; i++) {
     for (j=0; j<9-i; j++) {
      digitalWrite(LED[j], HIGH);
     
      if (j>0) {
      digitalWrite(LED[j-1], LOW);
      }
      delay(sleepTime);
     }
  }
  digitalWrite(LEDMain, HIGH);
  delay(sleepTime);
  // Removing
  for (i=8; i>-1; i--) {
     for (j=i; j<9; j++) {
        digitalWrite(LED[j], LOW);
        if (j<8){
           digitalWrite(LED[j+1], HIGH);
        }
        delay(sleepTime);
     }
  }
  digitalWrite(LEDMain, LOW);
  delay(sleepTime);
  
  for (i=0; i<9; i++) {
     for (j=0; j<9-i; j++) {
      digitalWrite(LED[8-j], HIGH);
      if (j>0){
        digitalWrite(LED[9-j], LOW);  
      }
      delay(sleepTime);
     }
  }
  digitalWrite(LEDMain, HIGH);
  delay(sleepTime);
  for (i=8; i>-1; i--) {
     for (j=i; j<9; j++) {
        digitalWrite(LED[8-j], LOW);
        if (j<8){
           digitalWrite(LED[7-j], HIGH);
        }
        delay(sleepTime);
     }
  }
  digitalWrite(LEDMain, LOW);
  delay(sleepTime);

}

void loop() {
  
  int l;
  
  turnoff();
  for (l=0; l<3; l++){
    blink1(1000);
  }
  
  turnoff();
  for (l=0; l<3; l++) {
    blink2(100);  
  }
  
  
  turnoff();
  for (l=0; l<3; l++) {
    blink3(500);
  }
  
  turnoff();
  for (l=0; l<3; l++) {
    blink4(500);
  }
  

  turnoff();
  blink5(80);
}
