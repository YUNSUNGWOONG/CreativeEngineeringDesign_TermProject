#include <AFMotor.h>
#include <SoftwareSerial.h>

int Tx = 9;
int Rx = 10;
SoftwareSerial mySerial(Tx, Rx); // RX, TX

//1번 모터만 제어
AF_DCMotor motor1(1);

//2번 모터만 제어
AF_DCMotor motor2(2);

//3번 모터만 제어
AF_DCMotor motor3(3);

//4번 모터만 제어
AF_DCMotor motor4(4);

String ms = "";
int num = 5;
int sp=180; //모터속도를 180으로 설정
int a;

void setup() {
  //블루투스 모듈을 9600이라는 속도로 사용
  Serial.begin(9600);
  mySerial.begin(9600);

  //1번 모터 속도설정
  motor1.setSpeed(sp);
  //1번 모터가 정지해있게 초기설정
  motor1.run(RELEASE);

  //2번 모터 속도설정
  motor2.setSpeed(sp);
  //2번 모터가 정지해있게 초기설정
  motor2.run(RELEASE);

  //3번 모터 속도설정
  motor3.setSpeed(sp);
  //3번 모터가 정지해있게 초기설정
  motor3.run(RELEASE);

  //4번 모터 속도설정
  motor4.setSpeed(sp);
  //4번 모터가 정지해있게 초기설정
  motor4.run(RELEASE);

}
void go();
void stop();

void loop(){
  if (mySerial.available()) {       
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {         
    mySerial.write(Serial.read());
  }
  
   

  ms = "";
  num=0;

  while(mySerial.available()){
    ms = mySerial.readStringUntil('c');
    num += ms.toInt();
    delay(10);

    if ((num /2) == 1){
      delay(5800);
    Serial.println(num);
    go();
    delay(2200);
    stop();

    delay(6500);


    go();
    delay(200);
    stop();

    delay(6000);

    go();
    delay(1590);
    stop();
    
  }
  }
  


  
  

}

void go()
{
  motor1.setSpeed(sp);
  motor2.setSpeed(sp);
  motor3.setSpeed(sp);
  motor4.setSpeed(sp);
  motor1.run(FORWARD);
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
  motor4.run(FORWARD);
}

void stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}