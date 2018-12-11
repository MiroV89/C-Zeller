/*Calendario Anual*/
#include <stdio.h>
#include "CalendarioM.h"
#include "Pantalla.h"
#include "CalendarioA.h"
//Pantalla p;
CalendarioA caa;
CalendarioM cam;

/* EsBisiesto:
  Nos dice si un año dado es bisiesto o no para poder sumar los años.
*/
bool CalendarioA::EsBisiesto (int Anno) {
  if ((Anno% 400 == 0)) {
    return true;
  } else if ((Anno % 4 == 0) && (Anno % 100 != 0 )) {
    return true;
  } else {
    return false;
  }
}

/* DiasInicioAnno:
 Calcula dias transcurridos desde 1/1/1601 a 31 de diciembre del año anterior al que queremos
*/
int CalendarioA::DiasInicioAnno (int anno) {
  int diasTotales=0;
  int diasAnno=0;

  for (int i = 1601; i <= anno-1; i++) {
    if (EsBisiesto(i)) {
      diasAnno = 366;
    } else {
      diasAnno = 365;
    }
    diasTotales = diasTotales + diasAnno;
  }
  return diasTotales;
}


void CalendarioA::PintaMatriz(int anno){

  // Ponemos la matrzi de pantalla en blanco
  int inicioAnno = DiasInicioAnno(anno);
  int inicioMes = 0;
  int diaSemana = 0;
 p.InicializarPantalla();

  for(int mes=0; mes<12; mes++){
    inicioMes = cam.DiasInicioMes(mes, anno);
   // inicioMes = inicioMes + inicioAnno;
    diaSemana = (inicioAnno + inicioMes) % 7;
  //  printf("DA=%2d", diaSemana);
    cam.ImprimirMes (mes, diaSemana, anno,p);
  }
  // Imprimimos la matriz Pantalla
  p.ImprimirCalendario();
}

