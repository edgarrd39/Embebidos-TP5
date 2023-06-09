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

/** \brief Implementación Calculadora
 **
 ** Implementacion Calculadora
 **
 ** \addtogroup name Calculadora
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "calculadora.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/* === Macros definitions ====================================================================== */
// #ifndef OPERACIONES
// #define OPERACIONES 16
// #endif

/* === Private data type declarations ========================================================== */

//! Estructura de la operacion
struct operacion_s {
    char operador;         //!< Operador de la operacion
    funciont_t funcion;    //!< Función del operador
    operacion_t siguiente; //!< PUntero a la operacion siguiente;
};

//! Estructura de la calculadora
struct calculadora_s {
    operacion_t operaciones;
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

operacion_t BuscarOperacion(calculadora_t calculadora, char operador);
/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {
    operacion_t result = NULL;

    if (calculadora) {
        for (operacion_t actual = calculadora->operaciones; actual != NULL; actual = actual->siguiente) {
            if (actual->operador == operador) {
                result = actual;
                break;
            }
        }
    }
    return result;
}
/* === Public function implementation ========================================================= */

calculadora_t CrearCalculadora(void) {
    calculadora_t result = malloc(sizeof(struct calculadora_s));
    if (result) {
        memset(result, 0, sizeof(struct calculadora_s));
    }
    return result;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion) {
    operacion_t operacion = NULL;

    if (!BuscarOperacion(calculadora, operador))
        operacion = malloc(sizeof(struct operacion_s));

    if ((operacion) && !BuscarOperacion(calculadora, operador)) {
        operacion->operador = operador;
        operacion->funcion = funcion;
        operacion->siguiente = calculadora->operaciones;
        calculadora->operaciones = operacion;
    }
    return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena) {
    int a, b;
    char operador;
    int result = 0;

    for (int indice = 0; indice < strlen(cadena); indice++) {
        if (cadena[indice] < '0') {
            operador = cadena[indice];
            a = atoi(cadena);
            b = atoi(cadena + indice + 1);

            break;
        }
    }

    operacion_t operacion = BuscarOperacion(calculadora, operador);
    if (operacion) {
        result = operacion->funcion(a, b);
    }
    return result;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
