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

#ifndef CALCULADORA_H
#define CALCULADORA_H

/** \brief Modulo Calculadora
 **
 ** Creación de la calculadora que realiza operaciones
 ** Matematicas usando funciones de callback
 **
 ** \addtogroup calculadora CALCULADORA
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

//! Referencia a un descriptor para gestionar una calculadora
typedef struct calculadora_s * calculadora_t;

//! Referencia a un descriptor para gestionar operaciones matematicas
typedef struct operacion_s * operacion_t;

//! Referencia a una funcion de callback
typedef int (*funciont_t)(int, int);
/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Creación del objeto calculadora
 *
 * Crea un objeto del tipo Calculadora
 *
 * @return calculadora_t
 */
calculadora_t CrearCalculadora(void);

/**
 * @brief Agrega operaciones matemáticas
 *
 * Agregan operaciones matematicas dependiendo del operador elegido
 *
 * @param calculadora Puntero al descriptor calculadora
 * @param operador Caracter de la operacion matemática
 * @param funcion Función de Callback a las operaciones matemáticas
 * @return true
 * @return false
 */
bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion);

/**
 * @brief Realiza el calculo matemático
 *
 * Realiza el calculo matemático usando las funciones de acuerdo al operador elegido
 *
 * @param calculadora Puntero al descriptor calculadora
 * @param cadena Puntero a la cadena que contiene la operacion con el operando
 * @return int El resultado de la operacion elegida
 */
int Calcular(calculadora_t calculadora, char * cadena);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* CALCULADORA_H */