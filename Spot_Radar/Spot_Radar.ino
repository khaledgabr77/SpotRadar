/* Copyright (c) 2021, Micropolis
 * All rights reserved.
 * Khaled Gabr
 * 
/*
 * rosserial Publisher SpotRadar
 * Publishing Digital Data (0,1), 0 << Free and 1 << object.
 * 
 */

#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

std_msgs::Int16 microRadar;
ros::Publisher spot("distance", &microRadar);
const int radar_pin = 22;

void setup() {
  nh.getHardware()->setBaud(9600);
  //Serial.begin(9600);

  nh.initNode();
  nh.advertise(spot); 
  pinMode(radar_pin, INPUT);


}

void loop() {

    microRadar.data = digitalRead(radar_pin); // This is just setup code 
    spot.publish(&microRadar);
    nh.spinOnce();


}
