/* ITEM 5
Ejercicio 5: Estructuras y Punteros
Para entregar: Archivo fuente de la solución
Escriba un programa C que permita almacenar N datos de Libros en un array:
 id (numérico)
 nombre (cadena)
 autor (cadena)
 año publicación (numérico)
El usuario debe ingresar el tamaño de la lista N y según eso dimensionar el array de manera
dinámica (usando malloc, calloc, etc). Finalmente debe imprimirse en pantalla el listado de
libros ingresados.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int validarNumero(char []);
int funcionMagica(int);

typedef struct libro{
  int id;
  char nombre[50];
  char autor[30];
  int anho;
}libro;
void imprimir(libro *list, int );
void cargarlibros(libro *list, int );


int main(void){
  int i,N,M,aaux;
  char p[5],aux[5];
  int numero, numaux;
  M=0;aaux =1;
  libro *listLibros = NULL;
  do{//para validar que solo se ingrese numeros en la cantidad de libros, mediante una funcion que esta definida mas abajo
    printf("Ingrese cantidad de libros: ");
    scanf("%s", p);
    N= validarNumero(p);
  }while(N==0);//la condicion para que finalice el ciclo
  numero = atoi(p);//convertimos la cadena en entero
  listLibros = (libro*)malloc(numero*sizeof(libro));// solicitamos un bloque de memoria del tamaño que le pasamos como parámetro
  if (listLibros !=NULL){//si se llevo a cabo correctamente la solicitud anteriormente, procedemos a cargar los datos requeridos para el libro
    if(numero>=1){
      cargarlibros(listLibros, numero);//cargamos los datos solicitados por el programa al usuario
      imprimir(listLibros, numero);//imprimimos la lista de libros
    }else{
      printf("NO SE PUEDE CARGAR LIBROS CON 0 CANTIDADES\n");//si se ingresa el numero 0, saltara este mensaje
    }
    free(listLibros); //liberamos la reserva, para evitar que el sistema se quede sin recursos.
  }else{//el siguiente mensaje salta si dicha reserva de memoria no puede hacerse, ya que suponemos que excede lo que dispone la maquina para el programa
    printf("Memoria no asignada.\n");
    exit(0);
  }
  return 0;
}

void cargarlibros(libro *list, int numero){//funcion para cargar datos del libro
  int i,aaux, numaux, M;
  char aux[5];
  for (i=0;i<numero;i++){
    list[i].id= i+1;
    printf("Nombre del libro: ");
    scanf("%s",list[i].nombre);
    printf("Autor del libro: ");
    scanf("%s",list[i].autor);
    aaux=1;
    while( (M!=1) || (aaux!=4)){//condiciones para que sea validada el año del libro
      printf("Año del libro: ");
      scanf("%s",aux);
      M = validarNumero(aux);
      numaux = atoi(aux);
      aaux= funcionMagica(numaux);
    }
    list[i].anho= numaux;//posteriormente apuntamos el valor del año en el campo anho, despues de haber salido de la condicional anterior
    printf("\n_________________________\n");
  }
}

void imprimir(libro *list, int elem)//funcion para imprimir las infos de libros que se han ingresado
{
  int i;
  printf("\nLista de libros\n");
  printf("Total de libros: %i\n", elem);
  printf("_________________________");
  for (i=0; i<elem; i++){
    printf("\nId libro: %i", list[i].id);
    printf("\nNombre libro: %s", list[i].nombre);
    printf("\nAutor del libro:%s ", list[i].autor);
    printf("\nAño del libro: %i", list[i].anho);
    printf("\n_________________________\n");
  }
}

int validarNumero(char p[]){//funcion para validar que solo se ingrese numeros
  int i;
  for(i=0;i<strlen(p);i++){
    if(!(isdigit(p[i]))){
      printf("Ingrese solo numeros.\n");
      getchar();
      return 0;
    }
  }
  return 1;
}

int funcionMagica(int x){//implemente el codigo para validar el año, mediante sus digitos
  int t=x, n=1;
  while(t>=10){
    n++;
    t=t/10;
  }
  return n;
}
