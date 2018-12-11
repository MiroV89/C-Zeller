
#pragma once
#include "Pantalla.h"

typedef struct CalendarioM{
  bool EsBisiesto(int Anno);
  int DiasInicioMes (int mes, int anno);
  int CalcFila(int mes);
  int CalcDia(int mes, int anno);
  void ImprimirMes(int mes, int inicio, int anno, Pantalla &p);
};

