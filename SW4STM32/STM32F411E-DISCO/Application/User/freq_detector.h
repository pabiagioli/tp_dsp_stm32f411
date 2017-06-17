/*
 * freq_detector.h
 *
 *  Created on: Jun 17, 2017
 *      Author: pampa
 */

#ifndef APPLICATION_USER_FREQ_DETECTOR_H_
#define APPLICATION_USER_FREQ_DETECTOR_H_

#include <stdint.h>
#include "arm_math.h"
#include "math_helper.h"
#include "stm32f411e_discovery.h"



void freq_detector_init();
uint32_t getBinFromSampleRate(uint8_t bin_num, uint16_t fft_size, uint32_t samplerate);
void freq_detector(uint16_t* audiobuff, uint32_t bufflength, uint32_t samplerate);

#endif /* APPLICATION_USER_FREQ_DETECTOR_H_ */
