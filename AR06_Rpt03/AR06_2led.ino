const int ledA   =  3;
const int ledB   =  5;

int number = 20;
boolean flag = true;

void setup()
{
  Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop()
{
  digitalWrite(ledA,HIGH);
  digitalWrite(ledB,LOW);
  delay(100 * number);
  digitalWrite(ledA,LOW);
  digitalWrite(ledB,HIGH);
  Serial.print("delay = ");
  Serial.print(100 * number);
  Serial.println(" msec");
  delay(100* number);

  if (flag) {
    number++;
  } else {
    number--;
  }

  if(number >=20) {
    flag = false;
  }
  else if(number == 1) {
    flag = true;
  }
  
  }

