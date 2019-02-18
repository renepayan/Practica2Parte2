/***********************
 Materia: Estructuras de datos
 Profesora: Miriam Pescador Rojas
 Descripcion: Implementacion de las funciones correspondentes a la estructura cuenta
 **************/

#include "cuenta.h"
void Cuenta_retirar(Cuenta *c, double monto){
    c->saldo-=monto;
    printf("El retiro de %lf ha sido efectuado con exito en la cuenta: %ld, saldo actual: %lf\n",monto,c->numCuenta,c->saldo);
}
void Cuenta_depositar(Cuenta *c, double monto){
    c->saldo+=monto;
    printf("El deposito de %lf ha sido efectuado con exito en la cuenta: %ld, saldo actual: %lf\n",monto,c->numCuenta,c->saldo);
}
void Cuenta_cambiarNip(Cuenta *c, char nip[4]){
    for(int i = 0;i<4;i++){
        c->nip[i] = (int)(nip[i] - '0');
    }
    printf("Nip cambiado Exitosamente\n");
}
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

