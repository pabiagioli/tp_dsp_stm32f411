/**
  ******************************************************************************
  * @file    audioFilter.c 
  * @author  Gustavo Muro
  * @version V0.0.1
  * @date    30/05/2015
  * @brief   Filtrado de audio.
  ******************************************************************************
  * @attention
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions are met:
  *
  * 1. Redistributions of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  *
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  *
  * 3. Neither the name of the copyright holder nor the names of its
  *    contributors may be used to endorse or promote products derived from this
  *    software without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  * POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "audioFilter.h"
#include "arm_math.h"
#include "math_helper.h"

//#include "filters.h"

/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  const q15_t *pCoeff;
  int32_t length;
}dataFilter_type;

/* Private define ------------------------------------------------------------*/
#define FILTER_SAMPLES 32
#define BLOCK_SIZE     1

/* Private variables ---------------------------------------------------------*/
const int BL = 32;
static q31_t firStateI16[BLOCK_SIZE + 32 -1];
static arm_fir_instance_q31 firInstance;
static arm_rfft_instance_q15 fftRealQ15Instance;
static arm_rfft_fast_instance_f32 fftRealFastFloatInstance;

/*static const dataFilter_type dataFilters[AUDIO_FILTER_TOTAL_FILTERS] =
{
  {
    lp16000_50_1000,
    LP_FS16000_50_1000_LENGTH,
  },
  {
    hp16000_1000_50,
    HP_FS16000_1000_50_LENGTH,
  },
};*/

q31_t B[32] = {
		185768,      116227,      149117,      185174,      223721,      264146,
		305501,      346851,      387118,      425245,      460364,      491240,
		517067,      537328,      551009,      558058,      558058,      551009,
		537328,      517067,      491240,      460364,      425245,      387118,
		346851,      305501,      264146,      223721,      185174,      149117,
		116227,      185768
};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
extern void audioFilter_init(void)
{
	audioFilter_filterSel(AUDIO_FILTER_FILTER_SEL_LOW_PASS);
}

extern void audioFilter_filter(q15_t *src, q15_t *dest, uint32_t length)
{
	float32_t *srcF;
	arm_q15_to_float(src,&srcF[0],16);

	arm_rfft_fast_f32(&fftRealFastFloatInstance,srcF,srcF,0);

	arm_float_to_q15(srcF,dest,16);
	//arm_rfft_q15(&fftRealQ15Instance, src, dest);


	//Calcular f0 a partir de FFT para calcular los Hz


	/*uint32_t i;
	q31_t firInput [length];
	q31_t firOutput [length];
	int32_t blockSize = length;
	int power;
	float32_t tempDisto [length];
	// Ensure that the buffer length isn't longer than the sample size
	if (blockSize > FILTER_SAMPLES)
		blockSize = FILTER_SAMPLES;
	
	for(i = 0; i < blockSize; i ++){
		//convert it to 32bit integer
		firInput[i] = (int32_t) src[i];
	}

	// Call the FIR process function, num of blocks to process = (FILTER_SAMPLES / BLOCK_SIZE)
	for (i = 0; i < (FILTER_SAMPLES / BLOCK_SIZE); i++) //
	{
		// BLOCK_SIZE = samples to process per call
		//arm_fir_q31(&instance, &firInput[i * BLOCK_SIZE], &firOutput[i * BLOCK_SIZE], BLOCK_SIZE);
		arm_fir_q31(&firInstance, firInput + (i * BLOCK_SIZE), firOutput + (i * BLOCK_SIZE), BLOCK_SIZE);
	}
	//arm_q15_to_float(src,tempDisto,32);
	//for (i = 0; i< length; i++)
	//	tempDisto[i]= tanhf(tempDisto[i]);
	//arm_float_to_q15(tempDisto,dest,32);

	//arm_power_q31(&firOutput, blockSize, &power);

	// Convert output back to uint16 for plotting
	for (i = 0; i < (blockSize); i++)
	{
		dest[i] = (uint16_t)(firOutput[i] - 63500);
	}*/

}

extern void audioFilter_filterSel(audioFilter_filterSel_enum sel)
{
	/* inicializa la estructura del filtro. */
  /*arm_fir_init_q31(&firInstance,
		BL,
		&B[0],
		&firStateI16[0],
		BLOCK_SIZE);
		*/
	//arm_rfft_init_q15(&fftRealQ15Instance,512,0,0);

	arm_rfft_fast_init_f32(&fftRealFastFloatInstance,1024);
}



/* End of file ---------------------------------------------------------------*/
