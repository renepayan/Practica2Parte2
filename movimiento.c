/***********************
 Materia: Estructuras de datos
 Profesora: Miriam Pescador Rojas
 Descripcion: Implementacion de las funciones correspondientes a la estructura de movimiento
 **************/

#include "movimiento.h"

Movimiento Movimiento_crear(long numero, char tipo[30], char fecha[11], char hora[6], double monto, Cuenta* cuenta){
    Movimiento m;
    m.numMovto = numero;
    sprintf(m.tipo,tipo);
    sprintf(m.hora,hora);
    sprintf(m.fecha,fecha);
    m.cta = *cuenta;
    m.monto = monto;
    return m;
}
void Movimiento_mostrar(Movimiento *m){
    printf("    ########################################\n");
    printf("    Numero de movimiento: %ld\n",m->numMovto);
    printf("    Fecha: %s\n",m->fecha);
    printf("    Hora: %s\n",m->hora);
    printf("    Tipo: %s\n",m->tipo);
    printf("    Monto: %lf\n",m->monto);
    printf("    ########################################\n");
}
