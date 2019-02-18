/***********************
 Materia: Estructuras de datos
 Profesora: Miriam Pescador Rojas
 Descripcion: Implementacion de las funciones
 **************/
#include "cliente.h"

Cliente Cliente_crear(char nombre[TAM], char app[TAM], char apm[TAM], char direccion[TAMMAX], long numero){
    Cliente c;
    sprintf(c.nombre,nombre);
    sprintf(c.paterno,app);
    sprintf(c.materno,apm);
    sprintf(c.direccion,direccion);
    c.numCliente = numero;
    return c;
}
Cliente Cliente_registrar(){
    Cliente c;
    printf("Crear un nuevo cliente\n");
    printf("Numero de cliente: ");
    scanf("%ld",&c.numCliente);
    printf("Nombre: ");
    scanf("%30s",&c.nombre);
    printf("Apellido paterno: ");
    scanf("%30s",&c.paterno);
    printf("Apellido materno: ");
    scanf("%30s",&c.materno);
    printf("Direccion: ");
    char ca;
    scanf("%c",&ca);
    fgets(c.direccion,100,stdin);
    printf("Cliente creado exitosamente, numero de cliente: %d\n",c.numCliente);
    return c;
}
void Cliente_mostrar(Cliente *cliente){
    printf("///////////////////////////////////////////////////////////\n");
    printf("Mostrando los datos del cliente: %d\n",cliente->numCliente);
    printf("Nombre: %s %s %s\n",cliente->nombre,cliente->paterno,cliente->materno);
    printf("Direccion: \n%s\n",cliente->direccion);
    printf("///////////////////////////////////////////////////////////\n");
}
