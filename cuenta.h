/***********************
 Materia: Estructuras de datos
 Profesora: Miriam Pescador Rojas
 Descripcion: Definicion de la estructura cuenta y la funcion para mostrar una cuenta
 **************/

#ifndef _CUENTA_H
#define _CUENTA_H
#include "cliente.h"
#include "util.h"

typedef struct{
    long numCuenta;
    char tipo[30];
    int nip[4];
    double saldo;
    Cliente titular;
}Cuenta;

void Cuenta_mostrar(Cuenta* cuenta);
Cuenta Cuenta_crear(long numCuenta, char tipo[TAM], int nip[4], double saldo, Cliente *titular);
#endif // _CUENTA_H
