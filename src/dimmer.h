/* 4-channels 12V LED dimmer project
 *
 *    Copyright (C) 2017  Vasim V.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with this program. */


#ifndef DIMMER_H_
#define DIMMER_H_

// Debug info over serial interface
//#define SERIAL_DEBUG

// Resistors divider ratio (43K/(1/(1/11K+1/MCU_INPUT_RESISTANCE)))
#define DIVIDER_RATIO 4.93

// PWM prescaler - 1, from 24 MHz (2 for 125ns pulse units, 5 for 250ns pulse units, 23 for 1 us pulse units)
#define PWMPRESCALER 23

// PWM period (in pulse units)
#define PWMRANGE 1022

// ADC channels number (5 ADC inputs + Temperature + Vdd)
#define MY_ADC_CHANNELS 7

// PWM output channels number
#define MY_PWM_CHANNELS 4

// Maximum command length
#define MAX_COMMAND_LENGTH 16

// Time period for reporting ADC values (in ms)
#define REPORT_PERIOD 500

// main setup/loop routines
extern void Setup();
extern void Loop();

// From main.c
extern ADC_HandleTypeDef hadc;
extern DMA_HandleTypeDef hdma_adc;
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim14;
extern IWDG_HandleTypeDef hiwdg;

// Voltage reference correction, should be 3300 (but in real life...)
#define VREF_CORRECTION 3300

// Internal voltage reference raw value at 30 degrees C, VDDA=3.3V
#define VREFINT_CAL (*((uint16_t *) 0x1FFFF7BA))
//Temperature sensor raw value at 30 degrees C, VDDA=3.3V
#define TS_CAL1 (*((uint16_t *) 0x1FFFF7B8))
//Temperature sensor raw value at 110 degrees C, VDDA=3.3V
#define TS_CAL2 (*((uint16_t *) 0x1FFFF7C2))

#endif /* DIMMER_H_ */