/***********************
 Materia: Estructuras de datos
 Profesora: Miriam Pescador Rojas
 Descripcion: Implementacion de las funciones
 **************/
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "cuenta.h"
#include "Movimiento.h"
#include <time.h>
Cuenta *cuentas;
Movimiento *movimientos;
Cliente *clientes;
int clienteActual = 0;
int cuentaActual = 0;
int movimientoActual = 0;

void verCliente(Cliente c){
    Cliente_mostrar(&c);
}
int cambiarNip(Cuenta *c, char nip[4]){
    for(int i = 0;i<4;i++){
        c->nip[i] = (int)(nip[i] - '0');
    }
    printf("Nip cambiado Exitosamente\n");
}
void listarCuentas(){
    printf("Mostrando lista de cuentas: \n");
    for(int i = 0;i<cuentaActual;i++){
        Cuenta_mostrar(&cuentas[i]);
        printf("-------------------------------------------\n");
    }
}
void listarMovimientosCuenta(Cuenta *cuenta){
    for(int i = 0;i<movimientoActual;i++){
        if(movimientos[i].cta.numCuenta == cuenta->numCuenta)
            Movimiento_mostrar(&movimientos[i]);
    }
}
void listarCuentasCliente(Cliente *cliente){
    printf("Mostrando lista de cuentas: \n");
    for(int i = 0;i<cuentaActual;i++){
        if(cuentas[i].titular.numCliente == cliente->numCliente){
            Cuenta_mostrar(&cuentas[i]);
            printf("Movimientos: \n");
            listarMovimientosCuenta(&cuentas[i]);
            printf("-------------------------------------------\n");
        }
    }
}
void agregarCliente(Cliente c){
    clientes = (Cliente*)realloc(clientes,sizeof(Cliente)*(clienteActual+1));
    clientes[clienteActual] = c;
    clienteActual++;
}
void agregarCuenta(Cuenta c){
    cuentas = (Cuenta*)realloc(cuentas,sizeof(Cuenta)*(cuentaActual+1));
    cuentas[cuentaActual] = c;
    cuentaActual++;
}
void agregarMovimiento(Movimiento m){
    movimientos = (Movimiento*)realloc(movimientos,sizeof(Movimiento)*(movimientoActual+1));
    movimientos[movimientoActual] = m;
    movimientoActual++;
}
void listarClientes(){
    printf("Mostrando lista de clientes: \n");
    for(int i = 0;i<clienteActual;i++){
        Cliente_mostrar(&clientes[i]);
    }
}
int buscarCuenta(long numero){
    int i = -1;
    for(i = 0;i<cuentaActual;i++){
        if(cuentas[i].numCuenta == numero){
            break;
        }
    }
    return (i == cuentaActual?-1:i);
}
int buscarCliente(long numero){
    int i = -1;
    for(i = 0;i<clienteActual;i++){
        if(clientes[i].numCliente == numero){
            break;
        }
    }
    return (i == cuentaActual?-1:i);
}
void depositar(Cuenta *c, double monto){
    c->saldo+=monto;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* retorno[30];
    sprintf(retorno,"%d/%d/%d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    char retorno1[5];
    sprintf(retorno1,"%d:%d",tm.tm_hour, tm.tm_min);
    agregarMovimiento(Movimiento_crear(movimientoActual+1,"deposito",retorno,retorno1,monto,c));
    printf("El deposito de %lf ha sido efectuado con exito en la cuenta: %ld, saldo actual: %lf\n",monto,c->numCuenta,c->saldo);
}
void retirar(Cuenta *c, double monto){
    c->saldo-=monto;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* retorno[30];
    sprintf(retorno,"%d/%d/%d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    char retorno1[5];
    sprintf(retorno1,"%d:%d",tm.tm_hour, tm.tm_min);
    agregarMovimiento(Movimiento_crear(movimientoActual+1,"retiro",retorno,retorno1,monto,c));
    printf("El deposito de %lf ha sido efectuado con exito en la cuenta: %ld, saldo actual: %lf\n",monto,c->numCuenta,c->saldo);
}

int main(){
    agregarCliente(Cliente_crear("Mario Alberto","Rosas","Solis","Tamaulipas 36, Col.Roma D.F.",578690));
    agregarCliente(Cliente_crear("Rosa","Martinez","Perez","La Escalera 9, Col.Lindavista, D.F",1525482));
    int nip[] = {5,6,8,7};
    agregarCuenta(Cuenta_crear(47568690,"debito",nip,15230.5,&clientes[0]));
    int nip1[] = {2,1,5,5};
    agregarCuenta(Cuenta_crear(12154825,"credito",nip1,5000.0,&clientes[0]));
    int nip2[] = {1,5,8,9};
    agregarCuenta(Cuenta_crear(2849896,"inversion",nip2,6500,&clientes[1]));
    agregarMovimiento(Movimiento_crear(534000,"deposito","13/04/2014","12:40",1600.0,&cuentas[0]));
    agregarMovimiento(Movimiento_crear(489620,"compra","05/05/2014","18:50",1600.0,&cuentas[1]));
    agregarMovimiento(Movimiento_crear(158685,"deposito","06/03/2014","14:30",1600.0,&cuentas[2]));
    agregarMovimiento(Movimiento_crear(781596,"consulta","04/04/2014","17:06",1600.0,&cuentas[2]));
    agregarMovimiento(Movimiento_crear(3985525,"retiro","07/05/2014","13:02",1600.0,&cuentas[2]));
    long numero;
    int posicion;
    int opcion;
    char nipNuevo[4];
    double monto;
    while(1){
        printf("Opciones Disponibles:\n1)Cambiar Nip\n2)Consulta de saldo\n3)Deposito a cuenta\n4)Disposicion de efectivo\n5)Mostrar informacion del cliente\n6)Salir\nOpcion: ");
        scanf("%d",&opcion);
        fflush(stdin);
        if(opcion>=1 && opcion<=6){
            switch(opcion){
            case 1:
                listarCuentas();
                while(1){
                    printf("Ingrese el numero de cuenta: ");
                    scanf("%ld",&numero);
                    fflush(stdin);
                    posicion = buscarCuenta(numero);
                    if(posicion == -1){
                        printf("Cuenta no encontrada\n");
                    }else{
                        break;
                    }
                }
                while(1){
                    printf("Ingrese el nuevo NIP: ");
                    scanf("%c%c%c%c",&nipNuevo[0],&nipNuevo[1],&nipNuevo[2],&nipNuevo[3]);
                    fflush(stdin);
                    int i = 0;
                    for(i = 0;i<4;i++){
                        if((int)(nipNuevo[i]- '0')<0 || (int)(nipNuevo[i]- '0')>9){
                            printf("Error: NIP invalido\n");
                            break;
                        }
                    }
                    if(i == 4){
                        cambiarNip(&cuentas[posicion],nipNuevo);
                        break;
                    }
                }

                char nip[4];
                break;
            case 2:
                listarCuentas();
                while(1){
                    printf("Ingrese el numero de cuenta: ");
                    scanf("%ld",&numero);
                    posicion = buscarCuenta(numero);
                    if(posicion == -1){
                        printf("Cuenta no encontrada\n");
                    }else{
                        break;
                    }
                }
                Cuenta_mostrar(&cuentas[posicion]);
                printf("-------------------------------------------\n");
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                char* retorno[30];
                sprintf(retorno,"%d/%d/%d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
                char retorno1[5];
                sprintf(retorno1,"%d:%d",tm.tm_hour, tm.tm_min);
                agregarMovimiento(Movimiento_crear(movimientoActual+1,"consulta",retorno,retorno1,monto,&cuentas[posicion]));
                break;
            case 3:
                listarCuentas();
                while(1){
                    printf("Ingrese el numero de cuenta: ");
                    scanf("%ld",&numero);
                    fflush(stdin);
                    posicion = buscarCuenta(numero);
                    if(posicion == -1){
                        printf("Cuenta no encontrada\n");
                    }else{
                        break;
                    }
                }
                while(1){
                    printf("Ingrese el monto a depositar: ");
                    scanf("%lf",&monto);
                    fflush(stdin);
                    if(monto<=0.0){
                        printf("Monto Invalido\n");
                    }else{
                        break;
                    }
                }
                depositar(&cuentas[posicion],monto);
                break;
            case 4:
                listarCuentas();
                while(1){
                    printf("Ingrese el numero de cuenta: ");
                    scanf("%ld",&numero);
                    fflush(stdin);
                    posicion = buscarCuenta(numero);
                    if(posicion == -1){
                        printf("Cuenta no encontrada\n");
                    }else{
                        break;
                    }
                }
                while(1){
                    printf("Ingrese el monto a retirar: ");
                    scanf("%lf",&monto);
                    fflush(stdin);
                    if(monto<=0 || (cuentas[posicion].tipo!="credito" && cuentas[posicion].saldo-monto<0)){
                        printf("Monto Invalido\n");
                    }else{
                        break;
                    }
                }
                retirar(&cuentas[posicion],monto);
                break;
            case 5:
                listarClientes();
                while(1){
                    printf("Ingrese el numero de cliente: ");
                    scanf("%ld",&numero);
                    fflush(stdin);
                    posicion = buscarCliente(numero);
                    if(posicion == -1){
                        printf("Cliente no encontrado\n");
                    }else{
                        break;
                    }
                }
                Cliente_mostrar(&clientes[posicion]);
                listarCuentasCliente(&clientes[posicion]);
                break;
            case 6:
                return 0;
                break;
            }
        }else{
            printf("Opcion invalida\n");
        }
    }
    return 0;
}
