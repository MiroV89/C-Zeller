#include <stdio.h>
#include "CalendarioA.h"


int main () {
  /*Entrada de datos*/
  CalendarioA caa;

  int anno;
  printf("\250A%co (1601..3000)?", 164);
  //printf ( "¿Año (1601-3000)?" );
  scanf ("%d", &anno );
  printf ( "\n" );
  if (anno <1601 || anno>3000) {
    printf ("El a%co seleccionado es incorrecto.", 164);
  } else {
    caa.PintaMatriz(anno);
  }
  return 0;

}
