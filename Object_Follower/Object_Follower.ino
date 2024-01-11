//Aslam Hpssain YT:
//Facebook:
//Do Subscribe

//Right Motor Pin Define
#define enA 5
#define in1 3
#define in2 4

//Left Motor Pin Define
#define in3 7 
#define in4 8 
#define enB 6

//Define the IR Signal Pin Connected to arduino
#define ir_L 12    
#define ir_F 11  
#define ir_R 10

int Speed = 100; // Write The Duty Cycle 0 to 255 Enable for Motor Speed 

int L_s, F_s, R_s; //Declared Variable to store the state of ir sensors


void setup(){ // put your setup code here, to run once

pinMode(ir_R, INPUT);// declare fire sensor pin as input
pinMode(ir_F, INPUT);// declare fire sensor pin as input
pinMode(ir_L, INPUT);// declare fire sensor pin as input

pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB 

analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
}

void loop() { 
sensorReading();
execute_Operation();
}


void sensorReading() {
  R_s = digitalRead(ir_R); //store the state of right sensor
  F_s = digitalRead(ir_F); //store the state of front sensor
  L_s = digitalRead(ir_L); //store the state of left sensor
}

void execute_Operation() {

if(F_s == 0) { forword(); }

else if(R_s == 0) { turnRight(); }

else if(L_s == 0) { turnLeft(); }

else if(L_s == 0 && F_s == 0) { turnLeft(); }

else if(R_s == 0 && F_s == 0) { turnRight(); }

else if(F_s == 0 && R_s == 0 && L_s == 0) { forword(); }

else { Stop(); }

}


//Functions for operating the motors
//______________________________________________

void forword(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void backword(){ //backword
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void turnRight(){ //turnRight
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void turnLeft(){ //turnLeft
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}