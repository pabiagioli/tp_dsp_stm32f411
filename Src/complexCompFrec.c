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
#include "complexCompFrec.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

extern void complexCompFrec_init(void)
{
}

extern int8_t complexCompFrec_process(q15_t *pSrc, int32_t lengthSrc,
		q15_t *pSine, q15_t *pCos, int32_t lengthSin,
		q63_t *pIm, q63_t *pRe)
{
	q63_t acumIm = 0, acumRe = 0, dot;
	int32_t i;

	int8_t ret = 0;;

	/* si no entra un número entero de veces la senoide sale */
	if (lengthSrc % lengthSin)
	{
		ret = -1;
	}
	else
	{
		for (i = 0 ; i < lengthSrc ; i += lengthSin)
		{
			arm_dot_prod_q15(&pSrc[i], pSine, lengthSin, &dot);
			acumIm += dot;

			arm_dot_prod_q15(&pSrc[i], pCos, lengthSin, &dot);
			acumRe += dot;
		}

		*pIm = acumIm;
		*pRe = acumRe;
	}

	return ret;
}

/*==================[end of file]============================================*/
