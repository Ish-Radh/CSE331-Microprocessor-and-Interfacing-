
int I0 = 5;  //Input pins connected to digital pin 
int I1 = 4;
int I2 = 3;
int I3 = 2;

int O0=9; //Output pins connected to digital pin 
int O1=10;
int O2=11;
int O3=12;





void setup() {
 
  pinMode(I0,INPUT);  //Sets I0,I1,I2,I3 as INPUT
  pinMode(I1,INPUT);
  pinMode(I2,INPUT);
  pinMode(I3,INPUT);
  
  pinMode(O0,OUTPUT);  //Sets output pins as OUTPUT
  pinMode(O1,OUTPUT);
  pinMode(O2,OUTPUT);
  pinMode(O3,OUTPUT);  

}

void loop() {
  boolean I0State = digitalRead(I0);  //Reads input pins
  boolean I1State = digitalRead(I1);
  boolean I2State = digitalRead(I2);
  boolean I3State = digitalRead(I3);
  
  boolean O0State;
  boolean O1State;
  boolean O2State;
  boolean O3State;

 O0State= (!I3State & !I2State & !I1State & !I0State)|(!I2State & I1State & I0State)|(I3State & !I1State & I0State)|(I3State & I1State& !I0State);    //Setting the kmap equations for each output pins
 O1State= (!I3State & I1State)|(I2State & !I0State)|(I3State & !I2State & !I1State)|(I3State & !I2State & I0State);
 O2State= (!I3State & !I1State)|(!I2State & !I1State & !I0State)|(!I3State & I2State);
 O3State= (!I3State & !I2State)|(!I3State & I0State)|(I2State & I1State & I0State)|(I3State & !I1State & !I0State);

 
 digitalWrite(O0,O0State);  //lighting of the LED's
 digitalWrite(O1,O1State);
 digitalWrite(O2,O2State);
 digitalWrite(O3,O3State);


}
