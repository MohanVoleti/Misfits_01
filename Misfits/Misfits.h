/*******************************************************************************
  Title                 :   Smart Switch from Misfits
  Filename              :   Misfits.h
  Author                :   Ajee,Anto,Nithin,Mohan
  Origin Date           :   27/02/2012
  Version               :   1.0.0
  Compiler              :   Arduino 1.8.14
  Target                :   ESP32
  Notes                 :   None
*******************************************************************************/


// include library to read and write from flash memory
#include <EEPROM.h>
// define the number of bytes you want to access
#define EEPRO M_SIZE 1

struct Button {
  const uint8_t PIN;
  bool pressed;
};

Button ENTER = {2,false};
Button UP = {5,false};
Button DOWN = {18,false};
char Flash_Test;

void IRAM_ATTR isr() {
  ENTER.pressed = true;
}

void IRAM_ATTR isr_01() {
  UP.pressed = true;
}

void IRAM_ATTR isr_02() {
  DOWN.pressed = true;
}
