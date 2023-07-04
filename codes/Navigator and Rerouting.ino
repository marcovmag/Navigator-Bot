

#define rsonartrig 13
#define rsonarecho 12
#define opL 9
#define opL2 8
#define opR 10
#define opR2 11
#define L_sensor  6
#define R_sensor 5
#define M_sensor 4
int time =0;
int cm = 0;
int op = 0;
int obs=0;
int a,b,c,d,e,f,x=0,y=1, h, k, x_temp, y_temp;
//int *j, *k;

long readUltrasonicDistance(int triggerPin, int echoPin)
{ pinMode(triggerPin, OUTPUT); 
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 milliseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
 
  // Reads the echo pin, and returns the sound wave travel time in millroseconds
  return pulseIn(echoPin, HIGH);
}
void checkObs()
{//measure ping time
  time = readUltrasonicDistance(rsonartrig, rsonarecho);
  // convert to cm
  cm = 0.01723 * time;
   if(cm>=20)
  {
   obs=0;
  }
  else 
  {obs=1;
   
  
  }
 }
void stop(){   digitalWrite(opL, LOW);

    digitalWrite(opL2, LOW);

    digitalWrite(opR, LOW);

    digitalWrite(opR2, LOW);
}
void setup()
{  pinMode(L_sensor, INPUT);
 pinMode(R_sensor, INPUT);
 

  pinMode(opL,LOW);
   pinMode(opL2,LOW);
  pinMode(opR,LOW);
    pinMode(opR2,LOW);
  Serial.begin(9600);

}
void turnright(){
    digitalWrite(opL, HIGH);

    digitalWrite(opL2, LOW);

    digitalWrite(opR, LOW);

    digitalWrite(opR2, LOW);  
    if (x == 0 && y == 1){x=1;y=0;}
    else if (x == 1 && y == 0){x=0;y=-1;}
    else if (x == 0 && y == -1){x= -1;y=0;}
    else if (x == -1 && y == 0){x=0;y=1;}
    if (x_temp == 0 && y_temp == 1){x_temp =1;y_temp=0;}
    else if (x_temp == 1 && y_temp == 0){x_temp=0;y_temp=-1;}
    else if (x_temp == 0 && y_temp == -1){x_temp= -1;y_temp=0;}
    else if (x_temp == -1 && y_temp == 0){x_temp=0;y_temp=1;}
  
    while(1){
      digitalWrite(opL, HIGH);

      digitalWrite(opL2, LOW);

      digitalWrite(opR, LOW);

      digitalWrite(opR2, LOW);
      
      if(digitalRead(M_sensor) == HIGH){
        break;
      }
    }
}

void turnleft(){
    digitalWrite(opL, LOW);

    digitalWrite(opL2, LOW);

    digitalWrite(opR, HIGH);

    digitalWrite(opR2, LOW);  
    
    if (x == 0 && y == 1){x= -1;y=0;}
    else if (x == -1 && y == 0){x=0;y=-1;}
    else if (x == 0 && y == -1){x= 1;y=0;}
    else if (x == 1 && y == 0){x=0;y=1;}
    if (x_temp == 0 && y_temp == 1){x_temp =-1;y_temp=0;}
    else if (x_temp == -1 && y_temp == 0){x_temp=0;y_temp=-1;}
    else if (x_temp == 0 && y_temp == -1){x_temp= 1;y_temp=0;}
    else if (x_temp == 1 && y_temp == 0){x_temp=0;y_temp=1;}
  
    while(1){
      digitalWrite(opL, LOW);

      digitalWrite(opL2, LOW);

      digitalWrite(opR, HIGH);

      digitalWrite(opR2, LOW);
      
      if(digitalRead(M_sensor) == HIGH){
        break;
      }
    }
}

void lineFollower()
{ Serial.print("\n line follower activated");
  
  if((digitalRead(L_sensor) == LOW) &&(digitalRead(M_sensor) == HIGH) &&  (digitalRead(R_sensor) == LOW)){

    Serial.println(" Left and Right sensors are LOW, Middle is high");

    digitalWrite(opR, HIGH);

    digitalWrite(opR2, LOW);

    digitalWrite(opL, HIGH);

    digitalWrite(opL2, LOW);

  } else if((digitalRead(L_sensor) == LOW) && (digitalRead(R_sensor) == HIGH)){

      Serial.println(" Left LOW and Right HIGH");
    digitalWrite(opL, HIGH);

    digitalWrite(opL2, LOW);

    digitalWrite(opR, LOW);

    digitalWrite(opR2, HIGH);    


   
  }else if((digitalRead(L_sensor) == HIGH) && (digitalRead(R_sensor) == LOW)){

   
    Serial.println(" Left HIGH and Right LOW");
    digitalWrite(opL, LOW);

    digitalWrite(opL2,HIGH);

    digitalWrite(opR, HIGH);

    digitalWrite(opR2, LOW);

    
  }else if ((digitalRead(L_sensor) == LOW) &&(digitalRead(M_sensor) == LOW) &&  (digitalRead(R_sensor) == LOW)){
    Serial.println(" Left and Right HIGH");

 stop();
  }}
//void rerouting()
//{
//  while(1){
//    digitalWrite(opR, LOW);
//
//    digitalWrite(opR2, HIGH);
//
//    digitalWrite(opL, LOW);
//
//    digitalWrite(opL2, HIGH);
//    if ((digitalRead(L_sensor) == HIGH) && (digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor == HIGH))){
//    break;
//    }
//  }
//    if (x == 0){
//      if ( f > 0 ){
//        f = f - 1;
//      }
//      else f = f + 1;
//    }
//    else if ( y == 0){
//      if ( e > 0 ){
//        e = e - 1;
//      }
//      else e = e + 1;
//    }
//
//
//    
//    if (y > 0){
//      if (e > 0){
//        turnright();
//        while ( e>0 ){
//        lineFollower();
//        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
//          e--;
//        }
//        turnleft();
//        while ( f > 0 ){
//        lineFollower();
//        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
//          f--;
//     }
//        
//      }
//      else if (e < 0){
//        turnleft();
//        while ( e < 0 ){
//        lineFollower();
//        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
//          e++;
//        turnright();
//        while ( f > 0 ){
//        lineFollower();
//        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
//          f--;
//        
//        }
//      }
//    }
//    
//  }
//      else if (y < 0){
//      if (e > 0){
//        turnleft();
//        while ( e > 0 ){
//        lineFollower();
//        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
//          e--;
//        }
//        turnright();
//        while ( f < 0 ){
//        lineFollower();
//        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
//          f++;
//     }
//        
//      }
//      else if (e < 0){
//        turnright();
//        while ( e < 0 ){
//        lineFollower();
//        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
//          e++;
//        turnleft();
//        while ( f < 0 ){
//        lineFollower();
//        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
//          f++;
//        
//        }
//      }
//    }
//    
//  }
//  loop();
//}
/* void case1()  // both positive
{
  if(y > 0){
    while ( f>0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          f--;
    }
    turnright();
     }
   while (e>0){
    linefollower();
    if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          e--;
     
   } 
   }
}
void case2() // both negative
{
  if(y > 0){
    turnleft();
    while (e<0){
    linefollower();
    if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          e++;
          turnleft();
    while ( f<0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          f++;
    }
   
   
  
}
void case3() // x positive y negative
{
  if(y > 0){
    turnright();
    while (e>0){
    linefollower();
    if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          e--;
    turnright();
    while ( f<0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          f++;
    }
   
   
}
void case4() // x negative y positive
{
  if(y > 0){
    while ( f>0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          f--;
    }
    turnleft();
     }
   while (e<0){
    linefollower();
    if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          e++;
} */
void loop()
{ f=d-b; e=c-a;
  checkObs();

 if (obs==1){
    
   stop();
   delay(200);
   checkObs();if(obs==1){
   Serial.print("\n clear my way"); 
     delay(1000);
     if(obs==1){Serial.print("\n Rerouting now"); // rerouting code 
     {
      while(1){
     
    digitalWrite(opR, LOW);

    digitalWrite(opR2, HIGH);

    digitalWrite(opL, LOW);

    digitalWrite(opL2, HIGH);
    if ((digitalRead(L_sensor) == HIGH) && (digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor == HIGH))){
    break;
    }
  }
    if (x == 0){
      if ( f > 0 ){
        f = f - 1;
      }
      else f = f + 1;
      }
    else if ( y == 0){
      if ( e > 0 ){
        e = e - 1;
      }
      else e = e + 1;
      }

        h = e - a;
        k = f - b;
        x_temp =  -1 * x;
        y_temp =  -1 * y;
        turnright();
        turnright();
        
        if (x_temp>0 ){
      
        while ( k>0 ){
        lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          k--;
        }
      if(h>=0)
      turnright();
      else if (h<0)
      turnleft();
      }
      if (y_temp>0 ){
      
      while ( h>0 ){
      lineFollower();
      if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
        h--;
     }
      if(k>=0)
      turnleft();
      else if (k<0)
      turnright();
      }
      if (x_temp<0 ){
      
      while ( k<0 ){
        lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          k++;
      }
     if(h>=0)
      turnright();
     else if (h<0)
      turnleft();
      }
     if (y_temp<0 ){
      
     while ( h<0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          h++;
        }
     if(k >= 0)
      turnright();
     else if (k<0)
      turnleft();

     if (h == 0 && k == 0 )
     {
      stop();
     }
   }
     }


    
 /*   if (y > 0){
      if (e == 0 && f > 0)
      {
        turnright();
        while(1)
        {
          lineFollower();
          if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          break;
          
        }
        turnleft();
        e = e + 1;
        h = a - e;
        k = b - f;
        if (y>0 ){
      
        while ( k>0 ){
        lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          k--;
        }
      if(h>=0)
      turnright();
      else if (h<0)
      turnleft();
      }
      if (x>0 ){
      
      while ( h>0 ){
      lineFollower();
      if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
        h--;
     }
      if(k>=0)
      turnleft();
      else if (k<0)
      turnright();
      }
      if (y<0 ){
      
      while ( k<0 ){
        lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          k++;
      }
     if(h>=0)
      turnright();
     else if (h<0)
      turnleft();
      }
     if (x<0 ){
      
     while ( h<0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          h++;
        }
     if(k >= 0)
      turnright();
     else if (k<0)
      turnleft();

     if (h == 0 && k == 0 )
     {
      stop();
     }
   }
      }

      if (e > 0){
        turnright();
        while ( e>0 ){
        lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          e--;
        }
        turnleft();
        while ( f > 0 ){
        lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          f--;
     }
        
      }
      else if (e < 0){
        turnleft();
        while ( e < 0 ){
        lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          e++;
        turnright();
        while ( f > 0 ){
        lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          f--;
        
        }
      }
    }
     }
   }
}
 
 
 
 
 
 
 
 else if(obs==0 && (digitalRead(M_sensor) == HIGH) ){

  /* if (f>0 && e > 0)
   *  {
   *  case1(e,f, y, x);
   *  }
   * else if (f<0 && e < 0)
   * {
   * case2(e,f, y, x);
   * }
   * else if (f < 0 && e > 0)
   * {
   * case3(e,f, y, x);
   * }
   * else if (f>0 && e > 0)
   * {
   * case4(e,f, y, x);
   * }
   */
 
    if (y>0 ){
      
     while ( f>0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          f--;
     }
     if(e>=0)
      turnright();
     else if (e<0)
      turnleft();
   }
   if (x>0 ){
      
     while ( e>0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          e--;
     }
      if(f>=0)
      turnleft();
     else if (f<0)
      turnright();
   }
   if (y<0 ){
      
     while ( f<0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          f++;
     }
     if(e>=0)
      turnright();
     else if (e<0)
      turnleft();
   }
   if (x<0 ){
      
     while ( e<0 ){
      lineFollower();
        if((digitalRead(L_sensor) == HIGH) &&(digitalRead(M_sensor) == HIGH) && (digitalRead(R_sensor) == HIGH))
          e++;
     }
     if(f >= 0)
      turnright();
     else if (f<0)
      turnleft();

     if (e == 0 && f == 0 )
     {
      stop();
     }
   }
   }
   }
   }
   }
