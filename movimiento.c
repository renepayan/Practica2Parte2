#include "movimiento.h"

Movimiento Movimiento_crear(long numero, char tipo[30], char fecha[10], char hora[5], double monto, Cuenta* cuenta){
    Movimiento m;
    m.numMovto = numero;
    sprintf(m.tipo,tipo);
    sprintf(m.fecha,fecha);
    sprintf(m.hora,hora);
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
