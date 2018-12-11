#pragma once
#include <stdio.h>
const int ancho=80;
const int alto=50;

typedef char TipoMatriz[alto][ancho];

typedef struct Pantalla{
  TipoMatriz miMatriz;
  void InicializarPantalla();
  void ImprimirCalendario();
};
