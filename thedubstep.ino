void thedubstep(){
  for (pos = 90; pos <= 120; pos += 30) {
    alpha = (digitalRead(2)==1);
    if(alpha!=lastAlpha)
    {
    myservo.write(pos);
    Serial.print(pos);
    Serial.print("\t");
    time = millis();
    Serial.println(time);
    delay(1000);
    }
    else{
      chirpcomplete = false;
      break;
    }
  }
  for (pos = 120; pos >= 60; pos -= 60) {
    alpha = (digitalRead(2)==1);
    if(alpha!=lastAlpha)
    {
    myservo.write(pos);
    Serial.print("\t");
    time = millis();
    Serial.println(time);
    delay(2000);
    }
     else{
      chirpcomplete = false;
    }
  }
  for (pos = 60; pos <= 90; pos += 30) {
    alpha = (digitalRead(2)==1);
    if(alpha!=lastAlpha)
    {
    myservo.write(pos);
    Serial.print(pos);
    Serial.print("\t");
    time = millis();
    Serial.println(time);
    delay(1000);
    }
     else{
      chirpcomplete = false;
    }
  }
  dubletcomplete = true;
  chirpcomplete = false;
}

