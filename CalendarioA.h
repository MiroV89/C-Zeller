#pragma once

#include "CalendarioM.h"
#include "Pantalla.h"


typedef struct CalendarioA{
  Pantalla p;
  bool EsBisiesto(int anno);
  int DiasInicioAnno(int anno);
  void PintaMatriz (int anno);
};

