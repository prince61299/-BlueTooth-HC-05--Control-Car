#include <SoftwareSerial.h>

//Define the Pins of Motor Driver
#define IN1 12
#define IN2 11
#define IN3 10
#define IN4 9

//Connection to the Bluetooth module with Arduino
SoftwareSerial mySerial(0, 1);  // RX, TX

String data;
int btVal;  //to store the value of Bluetooth signal

//Define the pinmode
void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  mySerial.begin(9600);
}

void loop() {
  while (mySerial.available()) {
    {
      data = mySerial.readStringUntil('\n');
    }

    btVal = (data.toInt());
    Serial.print("BlueTooth Value ");
    Serial.println(btVal);



    switch (btVal) {
      case 1:
        forward();
        break;

      case 2:
        reverse();
        break;

      case 3:
        left();
        break;

      case 4:
        right();
        break;

      case 5:
        stoprobot();
        break;
    }
  }


  if (mySerial.available() < 0) {
    //Serial.println("No Bluetooth Data ");
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stoprobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}