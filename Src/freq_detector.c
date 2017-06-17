/*
 * freq_detector.c
 *
 *  Created on: Jun 17, 2017
 *      Author: pampa
 */

#include "freq_detector.h"

#define NUMBER_OF_FREQS_TO_LOOK	3

static uint16_t fftSize = 1024;

static arm_rfft_fast_instance_f32 fftRealFastFloatInstance;

uint32_t freqsToLookFor [NUMBER_OF_FREQS_TO_LOOK] = {
				440,
				554,
				659
		};

uint32_t freqsDurationMs [NUMBER_OF_FREQS_TO_LOOK] = {
			1000,
			750,
			750
	};

void simple_lp_filter(float32_t  *input, float32_t *output, int32_t fftSize) {
	int i, k;
	float32_t mag, magin, phi;
	// The low-pass contour is 1 at 0 Hz
	// and 0 at the Nyquist
	output[0] = 1.f;
	output[1] = 0.f;
	for(i = 2, k = 0; i < fftSize; i+=2, k++) {
		// get the magnitudes of input
		magin = sqrtf(input[i] * input[i] + input[i+1] * input[i+1]);
		// apply the spectral contour
		mag = cosf(PI * k / fftSize) * magin;
		//get the phases
		phi = atan2f(input[i+1], input[i]);
		// convert to rectangular form
		output[i] = mag * cosf(phi);
		output[i+1] = mag * sinf(phi);
	}

}

uint32_t getBinFromSampleRate(uint8_t bin_num, uint16_t fft_size, uint32_t samplerate){
	return freqsToLookFor[bin_num] * ((uint32_t)fft_size) / samplerate;
}

void freq_detector_init(){
	//TickTock_Init();
	arm_rfft_fast_init_f32(&fftRealFastFloatInstance, fftSize);
}

void freq_detector(uint16_t* audiobuff, uint32_t bufflength, uint32_t samplerate){

	int i = 0;
	float32_t floatBuffer [samplerate];
	float32_t maxValue;

	/* Reference index at which max energy of bin occurs */
	uint32_t fftIndex = 0;

	//convert the uint16_t samples to float32_t samples
	arm_q15_to_float((q15_t *)audiobuff, floatBuffer, fftSize);
	// make the Real FFT with 1024 length and 22050 Hz
	//arm_cfft_f32(&fftComplexFloatInstance, floatBuffer, 0, 0);
	arm_rfft_fast_f32(&fftRealFastFloatInstance, floatBuffer, floatBuffer, 0);
	/* Calculates maxValue and returns corresponding BIN value */
	arm_max_f32(floatBuffer, fftSize, &maxValue, &fftIndex);
	//printf("freqLengthCounter %u \n", freqLengthCounter);

	for(i = 0; i< NUMBER_OF_FREQS_TO_LOOK ; i++){
		if(fftIndex == getBinFromSampleRate(i, fftSize, samplerate) || (i == 1 && fftIndex == getBinFromSampleRate(i, fftSize, samplerate) + 1)){
			BSP_LED_On(i);
		}
	}
}
