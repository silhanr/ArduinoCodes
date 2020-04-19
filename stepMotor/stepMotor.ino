/*
 * 
 * Datasheet https://arduino-shop.cz/docs/produkty/0/759/eses1500636008.pdf
 * 
 * https://components101.com/motors/28byj-48-stepper-motor
 * 
 * 
 *  
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D

 8 9 10 11 12
 | | |  |  | 
 G F 8  A  B

 E D 3 C .
 | | | | |
 3 4 5 6 
 
 */


int pinIn1 = 1;
int pinIn2 = 2;
int pinIn3 = 7;
int pinIn4 = 13;

int pinA = 11;
int pinB = 12;
int pinC = 6;
int pinD = 4;
int pinE = 3;
int pinF = 9;
int pinG = 8;

//int pinDot = 7;
int D1 = 5;
int D2 = 10;

// se zvětšujícím se číslem se rychlost zmenšuje
int speed = 1;

int degree = 360;

int counter=0;

void setup() {
  
  // initialize the digital pins as outputs.
    
  pinMode(pinIn1, OUTPUT);     
  pinMode(pinIn2, OUTPUT);     
  pinMode(pinIn3, OUTPUT);     
  pinMode(pinIn4, OUTPUT);

  
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  

}



void displayNumber(int number){
  switch(number){
    case 0:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;
      
    case 1:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
      
    case 2:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;
      
    case 3:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;
      
    case 4:
      digitalWrite(D1, HIGH);
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
      
    case 5:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
      
    case 6:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
      
    case 7:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 8:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
    case 9:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
    default:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;
  }
}

void makeStep(int step){
  switch(step){
    case 1:
      digitalWrite(pinIn1, HIGH);
      digitalWrite(pinIn2, LOW);
      digitalWrite(pinIn3, LOW);
      digitalWrite(pinIn4, LOW);
      break;
    case 2:
      digitalWrite(pinIn1, HIGH);
      digitalWrite(pinIn2, HIGH);
      digitalWrite(pinIn3, LOW);
      digitalWrite(pinIn4, LOW);
      break;
    case 3:
      digitalWrite(pinIn1, LOW);
      digitalWrite(pinIn2, HIGH);
      digitalWrite(pinIn3, LOW);
      digitalWrite(pinIn4, LOW);
      break;
    case 4:
      digitalWrite(pinIn1, LOW);
      digitalWrite(pinIn2, HIGH);
      digitalWrite(pinIn3, HIGH);
      digitalWrite(pinIn4, LOW);
      break;
    case 5:
      digitalWrite(pinIn1, LOW);
      digitalWrite(pinIn2, LOW);
      digitalWrite(pinIn3, HIGH);
      digitalWrite(pinIn4, LOW);
      break;
    case 6:
      digitalWrite(pinIn1, LOW);
      digitalWrite(pinIn2, LOW);
      digitalWrite(pinIn3, HIGH);
      digitalWrite(pinIn4, HIGH);
      break;
    case 7:
      digitalWrite(pinIn1, LOW);
      digitalWrite(pinIn2, LOW);
      digitalWrite(pinIn3, LOW);
      digitalWrite(pinIn4, HIGH);
      break;   
    case 8:
      digitalWrite(pinIn1, HIGH);
      digitalWrite(pinIn2, LOW);
      digitalWrite(pinIn3, LOW);
      digitalWrite(pinIn4, HIGH);
      break;
      
    default:
      
      break;
  }
}



void loop() {
  
  
  for(int j=1;j<512;j++){
     for(int i=1;i<=8;i++){
      makeStep(i);
    
      delay(speed);
    }
    
  }
  counter++;
  displayNumber(counter % 10);
  
}
