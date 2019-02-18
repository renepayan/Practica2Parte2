#include "cuenta.h"

void Cuenta_mostrar(Cuenta* cuenta){
    printf("-------------------------------------------\n");
    printf("Numero de cuenta: %ld\n",cuenta->numCuenta);
    printf("Tipo de cuenta: %s\n",cuenta->tipo);
    printf("NIP: %d%d%d%d\n",cuenta->nip[0],cuenta->nip[1],cuenta->nip[2],cuenta->nip[3]);
    printf("Saldo actual: %lf\n",cuenta->saldo);
    printf("Cliente: %ld\n",cuenta->titular.numCliente);
    //printf("-------------------------------------------\n");
}
Cuenta Cuenta_crear(long numCuenta, char tipo[TAM], int nip[4], double saldo, Cliente *titular){
    Cuenta c;
    c.numCuenta = numCuenta;
    sprintf(c.tipo,tipo);
    c.nip[0] = nip[0];
    c.nip[1] = nip[1];
    c.nip[2] = nip[2];
    c.nip[3] = nip[3];
    c.saldo = saldo;
    c.titular = *titular;
    return c;
}

