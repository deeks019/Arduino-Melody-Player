#include <Servo.h>
int button1 = 4;
int button2 = 5;
int buzzer1 = 2;
int buzzer2 = 3;
int led1 = 6;
int led2 = 7;
int servoPin=8;
Servo myServo;
bool servoToggle=false;
void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(0);
}
void loop() {
  if (digitalRead(button1) == LOW) {
    melody1();
  } else if (digitalRead(button2) == LOW) {
    melody2();
  } else {
    noTone(buzzer1);
    noTone(buzzer2);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}
void melody1() {
  playNote(buzzer1, led1, 392, 300);   
  playNote(buzzer1, led1, 392, 300);   
  playNote(buzzer1, led1, 440, 600);   
  playNote(buzzer1, led1, 392, 600);   
  playNote(buzzer1, led1, 523, 600);   
  playNote(buzzer1, led1, 494, 1200);  
  playNote(buzzer1, led1, 392, 300);   
  playNote(buzzer1, led1, 392, 300);   
  playNote(buzzer1, led1, 440, 600);   
  playNote(buzzer1, led1, 392, 600);   
  playNote(buzzer1, led1, 587, 600);   
  playNote(buzzer1, led1, 523, 1200);  
  playNote(buzzer1, led1, 392, 300);   
  playNote(buzzer1, led1, 392, 300);   
  playNote(buzzer1, led1, 784, 600);   
  playNote(buzzer1, led1, 659, 600);   
  playNote(buzzer1, led1, 523, 600);   
  playNote(buzzer1, led1, 494, 600);   
  playNote(buzzer1, led1, 440, 1200);  
  playNote(buzzer1, led1, 698, 300);   
  playNote(buzzer1, led1, 698, 300);   
  playNote(buzzer1, led1, 659, 600);   
  playNote(buzzer1, led1, 523, 600);   
  playNote(buzzer1, led1, 587, 600);   
  playNote(buzzer1, led1, 523, 1200); 
  noTone(buzzer1);
}
void melody2() {
playNote(buzzer1, led2, 784, 600);  
playNote(buzzer1, led2, 740, 600);
playNote(buzzer1, led2, 659, 600); 
playNote(buzzer1, led2, 587, 600);  
playNote(buzzer1, led2, 659, 300);  
playNote(buzzer1, led2, 659, 600);
playNote(buzzer1, led2, 784, 600);  
playNote(buzzer1, led2, 740, 600);  
playNote(buzzer1, led2, 659, 600);  
playNote(buzzer1, led2, 587, 600);  
playNote(buzzer1, led2, 659, 300);  
playNote(buzzer1, led2, 659, 300);
noTone(buzzer2);
}
void playNote(int buzzerPin, int ledPin, int frequency, int duration) {
  digitalWrite(ledPin, HIGH);    
  tone(buzzerPin, frequency);   
  if (servoToggle) {
    myServo.write(90);
  }
  else
  {
    myServo.write(0);
  }
  servoToggle =!servoToggle;  
  delay(duration);                
  noTone(buzzerPin);              
  digitalWrite(ledPin, LOW);      
  delay(100);                     
}
