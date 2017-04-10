void chirp(){
  float finitial = 0.01;
  float ffinal = 15;
  float k = (ffinal-finitial)/20;
  float func;
  float tfinal;
  float tinit;
  float phi;
  float x;
  
  tinit = time;
  tfinal = tinit + 10000;
while(time < tfinal){
  Serial.println(tinit);
    time = millis();
    x = 90+15*sin(2*PI*(finitial*((time-tinit)/1000)+(k/2)*((time-tinit)/1000)*((time-tinit)/1000)));
    Serial.print(x);
    Serial.print('\t');
    Serial.print(time);
    Serial.print('\t');
    Serial.println(tfinal);
    myservo.write(x);

  }
  }
