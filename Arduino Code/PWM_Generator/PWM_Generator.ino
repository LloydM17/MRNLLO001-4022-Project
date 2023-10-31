#include <TimerOne.h>
#define PWM1 9   // Pin for PWM 1
#define PWM 10   // Pin for PWM 2
int DC1 = 563.2;   // Intitial Duty cycle of 50%
int DC2 = 460.8;
int frqncy;   // Frequency Variable. Initial values of 50kHz
int driver = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT); // Logic High
digitalWrite(8,HIGH);
pinMode(7,INPUT);  // Brakes
pinMode(6,INPUT);  // Right Indicator
pinMode(5,INPUT);  // Left Indicator

Serial.begin(9600);
Timer1.initialize(20); //NB LINE: Set the PWM frequency to 85 kHz
Timer1. pwm(PWM, DC1); // Set the initial duty cycle
Timer1. pwm(PWM1, DC2); //Set initial duty cycle 
TCCR1A = 0b10110000 | (TCCR1A & 0b00001111) ; // invert pins
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Enter your Driver Instruction");  
   
  while (Serial.available()==0)  
  {                                       //Wait for user input  
    
  }  
  driver = Serial.parseInt(); 

  if(driver == 1){
    frqncy = 20; //50kHz
  }
  else if(driver == 2){
    frqncy = 18.18; //55kHz
  }
  else if(driver == 3){
    frqncy = 16.67; // 60kHz
  }
  else if(driver == 4){
    frqncy = 15.38; // 65kHz
  }
  else if(driver == 5){
    frqncy = 14.28; // 70kHz
  }
  else if(driver == 6){
    frqncy = 13.33; // 75kHz
  }
  else if(driver == 7){
    frqncy = 12.5; // 80kHz 
  }
  else if(driver == 8){
    frqncy = 11.76; // 85kHz
  }
  else if(driver == 9){
    frqncy = 50; // 20kHz
  }
  else if(driver == 10){
    frqncy = 33; // 30kHz
  }
  else if(driver == 11){
    frqncy = 25; // 40kHz
  }

  else if(driver == 12){
    frqncy = 22; // 45kHz
  }

  Timer1.setPeriod(frqncy);
  Serial.println(frqncy);
  Timer1.pwm(PWM, DC1); //Update Duty Cycle
  Timer1.pwm(PWM1, DC2); //Update Duty Cycle
 // delay(1000);
}

