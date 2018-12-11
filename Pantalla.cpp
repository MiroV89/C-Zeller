#include <stdio.h>
#include "Pantalla.h"

void Pantalla::InicializarPantalla(){
  for (int i=0; i<alto; i++) {
    for (int j=0; j<ancho; j++) {
       miMatriz[i][j]=' ';
    }
  }
}

void Pantalla::ImprimirCalendario(){
  for (int j=0; j<alto; j++) { //selecciona fila
    for (int k=0; k<ancho; k++) { //imprime la fila
      printf( "%c", miMatriz[j][k]);
    }
    printf( "\n");
  }
}
