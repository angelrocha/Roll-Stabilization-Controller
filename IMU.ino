void initSensors()
{
  if(!accel.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println(F("Ooops, no LSM303 detected ... Check your wiring!"));
    while(1);
  }
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  if(!bmp.begin())
  {
    /* There was a problem detecting the BMP180 ... check your connections */
    Serial.println("Ooops, no BMP180 detected ... Check your wiring!");
    while(1);
  }
}

//    @brief  Constantly check the roll/pitch/heading/altitude/temperature
/**************************************************************************/
void imu()
{
  sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_event_t bmp_event;
  sensors_vec_t   orientation;

  /* Calculate pitch and roll from the raw accelerometer data */
  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
  {
    /* 'orientation' should have valid .roll and .pitch fields */
    //Serial.print(F("Roll: "));
    Serial.print(time);
    Serial.print(',');
    Serial.print(orientation.roll);
    Serial.print(',');
    //Serial.print(F("Pitch: "));
    Serial.print(orientation.pitch);
    Serial.print(',');
  }
  
  /* Calculate the heading using the magnetometer */
  mag.getEvent(&mag_event);
  if (dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation))
  {
    /* 'orientation' should have valid .heading data now */
    //Serial.print(F("Heading: "));
    Serial.print(orientation.heading);
    Serial.print(',');
  }
  
  
  sensors_event_t event;
  accel.getEvent(&event);
  //Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  //Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  //Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  gyro.getEvent(&event);
  //Serial.print(F("GYRO  "));
  //Serial.print("X: "); Serial.print(event.gyro.x); Serial.print("  ");
  //Serial.print("Y: "); Serial.print(event.gyro.y); Serial.print("  ");
  //Serial.print("Z: "); Serial.print(event.gyro.z); Serial.print("  ");Serial.println("rad/s "); 
  beta = .98;
  dt = 0.02;
  theta = beta*(orientation.pitch+event.gyro.y*dt)+(1-beta)*event.acceleration.y; /* y axis filtering */
  phi = beta*(orientation.roll+event.gyro.x*dt)+(1-beta)*event.acceleration.x; /* x axis filtering */
  yaw = beta*(orientation.heading+event.gyro.y*dt)+(1-beta)*event.acceleration.z; /* z axis filtering */
  //Serial.print(F("theta: "));
  Serial.print(theta);
  Serial.print(',');
  //Serial.print(F("phi: "));
  Serial.print(phi);
  Serial.print(',');
  //Serial.print(F("yaw: "));
  Serial.print(yaw);
  Serial.println();
  
}


