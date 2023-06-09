/************************************************************************************************
Copyright (c) 2023, Edgardo Rodrigo Díaz <rodrigo.09tuc@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief Trabajo Práctico Nº5
 **
 **
 ** \addtogroup tp5 TPN5
 ** \brief Se diseñara una calculadora usando puntero a funciones
 * JSON
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include <stdio.h>
#include "calculadora.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int producto(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    if (b == 0) {
        printf("No se puede dividir por cero\n");
        return 0;
    } else
        return a / b;
}

/* === Public function implementation ========================================================== */

int main(void) {

    int resultado_suma;
    int resultado_resta;
    int resultado_producto;
    int resultado_division;

    calculadora_t calculadora = CrearCalculadora();

    AgregarOperacion(calculadora, '+', suma);
    AgregarOperacion(calculadora, '-', resta);
    AgregarOperacion(calculadora, '*', producto);
    AgregarOperacion(calculadora, '/', division);

    resultado_suma = Calcular(calculadora, "4+3");
    printf("Resultado suma %i\r\n", resultado_suma);
    resultado_resta = Calcular(calculadora, "4-3");
    printf("Resultado resta %i\r\n", resultado_resta);
    resultado_producto = Calcular(calculadora, "4*3");
    printf("Resultado producto %i\r\n", resultado_producto);
    resultado_division = Calcular(calculadora, "12/3");
    printf("Resultado division %i\r\n", resultado_division);

    return 0;
}
/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
