/***********************
 Materia: Estructuras de datos
 Profesora: Miriam Pescador Rojas
 Descripcion: Implementacion de las funciones
 **************/
#ifndef _CLIENTE_H
#define _CLIENTE_H
#include <stdio.h>
#include "util.h"
typedef struct{
    long numCliente;
    char nombre[TAM];
    char paterno[TAM];
    char materno[TAM];
    char direccion[TAMMAX];
} Cliente;
Cliente Cliente_crear(char nombre[TAM], char app[TAM], char apm[TAM], char direccion[TAMMAX], long numero);
Cliente Cliente_registrar();
void Cliente_mostrar(Cliente *cliente);
#endif // _CLIENTE_H
