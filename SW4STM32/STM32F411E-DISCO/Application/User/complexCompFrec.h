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

#ifndef COMPLEX_COMP_FREC_H
#define COMPLEX_COMP_FREC_H

/*==================[inclusions]=============================================*/
#include "arm_math.h"

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
extern void complexCompFrec_init(void);


/** \brief Calcula componentes en parte real y parte imaginaria de una
 **        de una frecuencia dada en un conjunto de muestras de una señal
 **
 **  IMPORTANTE: la longitud del la señal debe ser múltimplo entero de la
 **  longitud de la senoide.
 **
 ** \param[in]    pSrc puntero a las muestras de la señal
 ** \param[in]    lengthSrc cantidad de muestras de la señal
 ** \param[in]    pSine puntero a las muestras del seno de la frecuencia deseada
 ** \param[in]    pCos puntero a las muestras del coseno de la frecuencia deseada
 ** \param[in]    lengthSin longitud de muestras de la senoide
 ** \param[out]   pIm componente en parte imaginaria representada en 34.30
 ** \param[out]   pRe componente en parte real representada en 34.30
 ** \return       0 si se pudo calcular
 **               -1 si hubo error.
 **/
extern int8_t complexCompFrec_process(q15_t *pSrc, int32_t lengthSrc,
		q15_t *pSine, q15_t *pCos, int32_t lengthSin,
		q63_t *pIm, q63_t *pRe);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef COMPLEX_COMP_FREC_H */

