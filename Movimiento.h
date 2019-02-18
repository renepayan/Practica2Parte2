/***********************
 Materia: Estructuras de datos
 Profesora: Miriam Pescador Rojas
 Descripcion: Definicion de la estructura movimiento y la funcion crear movimiento
 **************/

#ifndef _MOVIMIENTO_H
#define _MOVIMIENTO_H
#include "cuenta.h"
typedef struct{
    long numMovto;
    char tipo[30];
    char fecha[11];
    char hora[6];
    double monto;
    Cuenta cta;
} Movimiento;

Movimiento Movimiento_crear(long numero, char tipo[30], char fecha[11], char hora[6], double monto, Cuenta* cuenta);
void Movimiento_mostrar(Movimiento *m);
#endif // _MOVIMIENTO_H
