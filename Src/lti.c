/* Copyright 2017, Gustavo Muro gustmuro@gmail.com
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
 */

/*==================[inclusions]=============================================*/
#include "lti.h"
#include "stdlib.h"

/*==================[macros and definitions]=================================*/
#define LENGTH_VECTOR_INPUT		5
#define LENGTH_VECTOR_OUTPUT	1

#define K_SHIFT					14

typedef int64_t acum_type;
typedef int32_t product_type;

/*==================[internal data declaration]==============================*/
static int16_t vectorInput[LENGTH_VECTOR_INPUT];
static int16_t vectorOutput[LENGTH_VECTOR_OUTPUT];

static const int16_t vector_b[LENGTH_VECTOR_INPUT] =
{
	32767,
	0,
	0,
	0,
	0,
};

static const int16_t vector_a[LENGTH_VECTOR_OUTPUT] =
{
	-16000,
};

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

extern void lti_init(void)
{
}

extern int16_t lti_process(int16_t sampleInput)
{
	int32_t i;
	acum_type acumX = 0;
	acum_type acumY = 0;
	acum_type result;
	int16_t sampleOutput;

	/* desplaza vector de entrada para guardar el nuevo valor en la posición 0 */
	for (i = LENGTH_VECTOR_INPUT-1 ; i > 0 ; i--)
	{
		vectorInput[i] = vectorInput[i-1];
	}

	/* guarda el nuevo valor de la entrada en la posición 0 */
	vectorInput[0] = sampleInput;

	/* producto escalar entre vector de entrada y coeficientes */
	for (i = 0 ; i < LENGTH_VECTOR_INPUT ; i++)
	{
		acumX += (acum_type)((product_type)vectorInput[i] * (product_type)vector_b[i]);
	}

	/* producto escalar entre vector de salida y coeficientes */
	for (i = 0 ; i < LENGTH_VECTOR_OUTPUT ; i++)
	{
		acumY += (acum_type)((product_type)vectorOutput[i] * (product_type)vector_a[i]);
	}

	result = (acumX - acumY) >> K_SHIFT;

	if (result > INT16_MAX)
		result = INT16_MAX;
	if (result < INT16_MIN)
		result = INT16_MIN;

	sampleOutput = (int16_t)result;

	/* desplaza vector de salida para guardar el nuevo valor en la posición 0 */
	for (i = LENGTH_VECTOR_OUTPUT-1 ; i > 0 ; i--)
	{
		vectorOutput[i] = vectorOutput[i-1];
	}

	/* guarda nuevo valor de salida en la posición 0 */
	vectorOutput[0] = sampleOutput;

	return sampleOutput;
}

/*==================[end of file]============================================*/
