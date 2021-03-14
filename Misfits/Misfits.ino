/*******************************************************************************
  Title                 :   Smart Switch from Misfits
  Filename              :   Misfits.c
  Author                :   Ajee,Anto,Nithin,Mohan
  Origin Date           :   27/02/2012
  Version               :   1.0.0
  Compiler              :   Arduino 1.8.14
  Target                :   ESP32
  Notes                 :   None
*******************************************************************************/
/*
   Functionality :
                  1.Keys input
                  2.Welcome page
                  3.Timer settings                 
*/
/******************************************************************************
  Includes
*******************************************************************************/

#include "Misfits.h"

void setup() {
  Serial.begin(115200);
  pinMode(ENTER.PIN, INPUT);
  attachInterrupt(ENTER.PIN, isr, FALLING);
  attachInterrupt(UP.PIN, isr_01, FALLING);
  attachInterrupt(DOWN.PIN, isr_02, FALLING);
    // initialize EEPROM with predefined size
  EEPROM.begin(EEPROM_SIZE);
  Flash_Test = EEPROM.read(0);
}

void loop() {
  if (ENTER.pressed) 
  {
      Serial.println(" ENTER ");
      ENTER.pressed = false;
  }
  if (UP.pressed) 
  {
      Serial.println(Flash_Test);
      UP.pressed = false;
       EEPROM.write(0, 't'); 
       EEPROM.commit();
  }
    if (DOWN.pressed) 
  {
      Serial.println(" DOWN ");
      DOWN.pressed = false;
  }
}
