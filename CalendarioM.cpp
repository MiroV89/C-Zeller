#include <stdio.h>
#include "CalendarioM.h"
#include "Pantalla.h"
#include <string.h>
/* nombreMes:
  Nos dice el nombre del mes en que estamos.
*/
Pantalla p;


/* EsBisiesto:
  Nos dice si un año dado es bisiesto o no para poder sumar los años.
*/
bool CalendarioM::EsBisiesto (int anno) {
  if ((anno% 400 == 0)) {
    return true;
  } else if ((anno % 4 == 0) && (anno % 100 != 0 )) {
    return true;
  } else {
    return false;
  }
}

/* InicioMes:
  Nos dice los dias pasados dentro del año actual hasta el inicio del mes dado.
*/
int CalendarioM::DiasInicioMes (int mes, int anno){
  int cuentaDias=0;
  int diasMes;

  /*Calcula los dias que han pasado desde el principio del año*/
  for (int i = 0; i<mes; i++) {
    if ((i==0)||(i==2) || (i==4) || (i==6) || (i==7) || (i==9)) {
      diasMes=31;
    } else if (i==1) {
      if (EsBisiesto (anno)) {
        diasMes = 29;
      } else {
        diasMes = 28;
      }
    }else {
      diasMes = 30;
    }
    cuentaDias= cuentaDias + diasMes;
  }
  return cuentaDias;
}

/* CalcFila: Calcula el numero de filas ( 1 fila = 1 mes) que tiene que saltar para colocarse)
*/
int CalendarioM::CalcFila (int mes){
  switch (mes) {
    case 0: return 0; break;
    case 1: return 0; break;
    case 2: return 0; break;
    case 3: return 1; break;
    case 4: return 1; break;
    case 5: return 1; break;
    case 6: return 2; break;
    case 7: return 2; break;
    case 8: return 2; break;
    case 9: return 3; break;
    case 10: return 3; break;
    case 11: return 3; break;
  }return mes;
}

 /*Calcular los dias del mes*/
int CalendarioM::CalcDia (int mes, int anno){
  int diasMes;
  if ((mes==0)||(mes==2) || (mes==4) || (mes==6) || (mes==7) || (mes==9) || (mes==11)) {
      diasMes=31;
    } else if (mes==1)
    { if (EsBisiesto (anno))
              { diasMes = 29;}
          else{ diasMes = 28;}
    }
      else {
      diasMes = 30;
    } return diasMes;
}
void CalendarioM::ImprimirMes(int mes, int inicio,int anno, Pantalla &p){

/*Definir los nombres de los meses*/
typedef char Nombres[12][10];
Nombres nombreMes={       {'E','N','E','R','O',' ',' ',' ',' ',' '} , {'F','E','B','R','E','R','O',' ',' ',' '},
                          {'M','A','R','Z','O',' ',' ',' ',' ',' '},{'A','B','R','I','L',' ',' ',' ',' ',' '},
                          {'M','A','Y','O',' ',' ',' ',' ',' ',' '} , {'J','U','N','I','O',' ',' ',' ',' ',' '},
                          {'J','U','L','I','O',' ',' ',' ',' ',' '},{'A','G','O','S','T','O',' ',' ',' ',' '},
                          {'S','E','P','T','I','E','M','B','R','E'},{'O','C','T','U','B','R','E',' ',' ',' '},
                          {'N','O','V','I','E','M','B','R','E',' '},{'D','I','C','I','E','M','B','R','E',' '} };

/*Definir la cadena de caracteres de los dias de la semana de la cabecera*/
typedef char NombresSemana[22];
NombresSemana nombreSem={ 'L','U',' ','M','A',' ','M','I',' ','J','U',' ','V','I',' ','|',' ','S','A',' ','D','O'};

int Fila=0;
int Col=0;
int diasMes=CalcDia(mes, anno);

/*Pasar el año a caracteres*/
typedef char annoCaracter[4];
annoCaracter cAnno;
sprintf (cAnno, "%d", anno);


/*Situar el mes en una de las tres columnas*/
  Col = (mes % 3) * 25+1;
/*Calcular en que fila se encuentra el mes*/
  Fila = (CalcFila(mes))* 11;
  diasMes=CalcDia(mes, anno);



/*Imprimir el nombre del mes*/
  for (int i=0; i<10; i++){
    p.miMatriz[Fila][Col+i]=nombreMes[mes][i];
  }

/*Imprimir el año*/
for (int i=0; i<4; i++){
p.miMatriz[Fila][Col+18+i]=cAnno[i];
}

/*Imprimir primera fila*/
 for(int i=0; i<22; i++){
    p.miMatriz[Fila+1][Col+i] = '=';
  }

/*Imprimir los nombres de los dias de la semana en la cabecera*/
for (int i=0; i<22; i++){
  p.miMatriz[Fila+2][Col+i]=nombreSem[i];
}
/*Imprimir tercera fila*/
for(int i=0; i<22; i++){
    p.miMatriz[Fila+3][Col+i] = '=';
 }


/*Imprimir separacion del calendario entre dias laborales y fin de semana*/
  p.miMatriz[Fila+4][Col+15] = '|';
  p.miMatriz[Fila+5][Col+15] = '|';
  p.miMatriz[Fila+6][Col+15] = '|';
  p.miMatriz[Fila+7][Col+15] = '|';
  p.miMatriz[Fila+8][Col+15] = '|';


/*Imprimir puntos antes de empezar los dias*/
for (int i=0; i<inicio; i++){
      if (i<5){
          p.miMatriz[Fila+4][Col+3*i+1] = '.';
}
      else{
         p.miMatriz[Fila+4][Col+3*i+3] = '.';
   }

  }


/* Imprimir dias dependiendo del dia en el que empiezan*/
if (inicio==0){
  p.miMatriz[Fila+4][Col+1]='1';
  p.miMatriz[Fila+4][Col+4]='2';
  p.miMatriz[Fila+4][Col+7]='3';
  p.miMatriz[Fila+4][Col+10]='4';
  p.miMatriz[Fila+4][Col+13]='5';
  p.miMatriz[Fila+4][Col+18]='6';
  p.miMatriz[Fila+4][Col+21]='7';
  p.miMatriz[Fila+5][Col+1]='8';
  p.miMatriz[Fila+5][Col+4]='9';
  p.miMatriz[Fila+5][Col+6]='1';
  p.miMatriz[Fila+5][Col+7]='0';
  p.miMatriz[Fila+5][Col+9]='1';
  p.miMatriz[Fila+5][Col+10]='1';
  p.miMatriz[Fila+5][Col+12]='1';
  p.miMatriz[Fila+5][Col+13]='2';
  p.miMatriz[Fila+5][Col+17]='1';
  p.miMatriz[Fila+5][Col+18]='3';
  p.miMatriz[Fila+5][Col+20]='1';
  p.miMatriz[Fila+5][Col+21]='4';
  p.miMatriz[Fila+6][Col]='1';
  p.miMatriz[Fila+6][Col+1]='5';
  p.miMatriz[Fila+6][Col+3]='1';
  p.miMatriz[Fila+6][Col+4]='6';
  p.miMatriz[Fila+6][Col+6]='1';
  p.miMatriz[Fila+6][Col+7]='7';
  p.miMatriz[Fila+6][Col+9]='1';
  p.miMatriz[Fila+6][Col+10]='8';
  p.miMatriz[Fila+6][Col+12]='1';
  p.miMatriz[Fila+6][Col+13]='9';
  p.miMatriz[Fila+6][Col+17]='2';
  p.miMatriz[Fila+6][Col+18]='0';
  p.miMatriz[Fila+6][Col+20]='2';
  p.miMatriz[Fila+6][Col+21]='1';
  p.miMatriz[Fila+7][Col]='2';
  p.miMatriz[Fila+7][Col+1]='2';
  p.miMatriz[Fila+7][Col+3]='2';
  p.miMatriz[Fila+7][Col+4]='3';
  p.miMatriz[Fila+7][Col+6]='2';
  p.miMatriz[Fila+7][Col+7]='4';
  p.miMatriz[Fila+7][Col+9]='2';
  p.miMatriz[Fila+7][Col+10]='5';
  p.miMatriz[Fila+7][Col+12]='2';
  p.miMatriz[Fila+7][Col+13]='6';
  p.miMatriz[Fila+7][Col+17]='2';
  p.miMatriz[Fila+7][Col+18]='7';
  p.miMatriz[Fila+7][Col+20]='2';
  p.miMatriz[Fila+7][Col+21]='8';
  if (diasMes==28){
  p.miMatriz[Fila+8][Col+15]=' ';}
  else if (diasMes==29){
      p.miMatriz[Fila+8][Col]='2';
      p.miMatriz[Fila+8][Col+1]='9';
      p.miMatriz[Fila+8][Col+4]='.';
      p.miMatriz[Fila+8][Col+7]='.';
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if (diasMes==30){
      p.miMatriz[Fila+8][Col]='2';
      p.miMatriz[Fila+8][Col+1]='9';
      p.miMatriz[Fila+8][Col+3]='3';
      p.miMatriz[Fila+8][Col+4]='0';
      p.miMatriz[Fila+8][Col+7]='.';
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if(diasMes==31){
      p.miMatriz[Fila+8][Col]='2';
      p.miMatriz[Fila+8][Col+1]='9';
      p.miMatriz[Fila+8][Col+3]='3';
      p.miMatriz[Fila+8][Col+4]='0';
      p.miMatriz[Fila+8][Col+6]='3';
      p.miMatriz[Fila+8][Col+7]='1';
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
}
else if (inicio==1){
  p.miMatriz[Fila+4][Col+4]='1';
  p.miMatriz[Fila+4][Col+7]='2';
  p.miMatriz[Fila+4][Col+10]='3';
  p.miMatriz[Fila+4][Col+13]='4';
  p.miMatriz[Fila+4][Col+18]='5';
  p.miMatriz[Fila+4][Col+21]='6';
  p.miMatriz[Fila+5][Col+1]='7';
  p.miMatriz[Fila+5][Col+4]='8';
  p.miMatriz[Fila+5][Col+7]='9';
  p.miMatriz[Fila+5][Col+9]='1';
  p.miMatriz[Fila+5][Col+10]='0';
  p.miMatriz[Fila+5][Col+12]='1';
  p.miMatriz[Fila+5][Col+13]='1';
  p.miMatriz[Fila+5][Col+17]='1';
  p.miMatriz[Fila+5][Col+18]='2';
  p.miMatriz[Fila+5][Col+20]='1';
  p.miMatriz[Fila+5][Col+21]='3';
  p.miMatriz[Fila+6][Col]='1';
  p.miMatriz[Fila+6][Col+1]='4';
  p.miMatriz[Fila+6][Col+3]='1';
  p.miMatriz[Fila+6][Col+4]='5';
  p.miMatriz[Fila+6][Col+6]='1';
  p.miMatriz[Fila+6][Col+7]='6';
  p.miMatriz[Fila+6][Col+9]='1';
  p.miMatriz[Fila+6][Col+10]='7';
  p.miMatriz[Fila+6][Col+12]='1';
  p.miMatriz[Fila+6][Col+13]='8';
  p.miMatriz[Fila+6][Col+17]='1';
  p.miMatriz[Fila+6][Col+18]='9';
  p.miMatriz[Fila+6][Col+20]='2';
  p.miMatriz[Fila+6][Col+21]='0';
  p.miMatriz[Fila+7][Col]='2';
  p.miMatriz[Fila+7][Col+1]='1';
  p.miMatriz[Fila+7][Col+3]='2';
  p.miMatriz[Fila+7][Col+4]='2';
  p.miMatriz[Fila+7][Col+6]='2';
  p.miMatriz[Fila+7][Col+7]='3';
  p.miMatriz[Fila+7][Col+9]='2';
  p.miMatriz[Fila+7][Col+10]='4';
  p.miMatriz[Fila+7][Col+12]='2';
  p.miMatriz[Fila+7][Col+13]='5';
  p.miMatriz[Fila+7][Col+17]='2';
  p.miMatriz[Fila+7][Col+18]='6';
  p.miMatriz[Fila+7][Col+20]='2';
  p.miMatriz[Fila+7][Col+21]='7';
  p.miMatriz[Fila+8][Col]='2';
  p.miMatriz[Fila+8][Col+1]='8';
  if (diasMes==28){
      p.miMatriz[Fila+8][Col+4]='.';
      p.miMatriz[Fila+8][Col+7]='.';
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }else if (diasMes==29){
      p.miMatriz[Fila+8][Col+3]='2';
      p.miMatriz[Fila+8][Col+4]='9';
      p.miMatriz[Fila+8][Col+7]='.';
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if (diasMes==30){
      p.miMatriz[Fila+8][Col+3]='2';
      p.miMatriz[Fila+8][Col+4]='9';
      p.miMatriz[Fila+8][Col+6]='3';
      p.miMatriz[Fila+8][Col+7]='0';
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if(diasMes==31){
      p.miMatriz[Fila+8][Col+3]='2';
      p.miMatriz[Fila+8][Col+4]='9';
      p.miMatriz[Fila+8][Col+6]='3';
      p.miMatriz[Fila+8][Col+7]='0';
      p.miMatriz[Fila+8][Col+9]='3';
      p.miMatriz[Fila+8][Col+10]='1';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }

}
else if (inicio==2){
  p.miMatriz[Fila+4][Col+7]='1';
  p.miMatriz[Fila+4][Col+10]='2';
  p.miMatriz[Fila+4][Col+13]='3';
  p.miMatriz[Fila+4][Col+18]='4';
  p.miMatriz[Fila+4][Col+21]='5';
  p.miMatriz[Fila+5][Col+1]='6';
  p.miMatriz[Fila+5][Col+4]='7';
  p.miMatriz[Fila+5][Col+7]='8';
  p.miMatriz[Fila+5][Col+10]='9';
  p.miMatriz[Fila+5][Col+12]='1';
  p.miMatriz[Fila+5][Col+13]='0';
  p.miMatriz[Fila+5][Col+17]='1';
  p.miMatriz[Fila+5][Col+18]='1';
  p.miMatriz[Fila+5][Col+20]='1';
  p.miMatriz[Fila+5][Col+21]='2';
  p.miMatriz[Fila+6][Col]='1';
  p.miMatriz[Fila+6][Col+1]='3';
  p.miMatriz[Fila+6][Col+3]='1';
  p.miMatriz[Fila+6][Col+4]='4';
  p.miMatriz[Fila+6][Col+6]='1';
  p.miMatriz[Fila+6][Col+7]='5';
  p.miMatriz[Fila+6][Col+9]='1';
  p.miMatriz[Fila+6][Col+10]='6';
  p.miMatriz[Fila+6][Col+12]='1';
  p.miMatriz[Fila+6][Col+13]='7';
  p.miMatriz[Fila+6][Col+17]='1';
  p.miMatriz[Fila+6][Col+18]='8';
  p.miMatriz[Fila+6][Col+20]='1';
  p.miMatriz[Fila+6][Col+21]='9';
  p.miMatriz[Fila+7][Col]='2';
  p.miMatriz[Fila+7][Col+1]='0';
  p.miMatriz[Fila+7][Col+3]='2';
  p.miMatriz[Fila+7][Col+4]='1';
  p.miMatriz[Fila+7][Col+6]='2';
  p.miMatriz[Fila+7][Col+7]='2';
  p.miMatriz[Fila+7][Col+9]='2';
  p.miMatriz[Fila+7][Col+10]='3';
  p.miMatriz[Fila+7][Col+12]='2';
  p.miMatriz[Fila+7][Col+13]='4';
  p.miMatriz[Fila+7][Col+17]='2';
  p.miMatriz[Fila+7][Col+18]='5';
  p.miMatriz[Fila+7][Col+20]='2';
  p.miMatriz[Fila+7][Col+21]='6';
  p.miMatriz[Fila+8][Col]='2';
  p.miMatriz[Fila+8][Col+1]='7';
  p.miMatriz[Fila+8][Col+3]='2';
  p.miMatriz[Fila+8][Col+4]='8';
  if (diasMes==28){
      p.miMatriz[Fila+8][Col+7]='.';
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }else if (diasMes==29){
      p.miMatriz[Fila+8][Col+6]='2';
      p.miMatriz[Fila+8][Col+7]='9';
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if (diasMes==30){
      p.miMatriz[Fila+8][Col+6]='2';
      p.miMatriz[Fila+8][Col+7]='9';
      p.miMatriz[Fila+8][Col+9]='3';
      p.miMatriz[Fila+8][Col+10]='0';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if(diasMes==31){
      p.miMatriz[Fila+8][Col+6]='2';
      p.miMatriz[Fila+8][Col+7]='9';
      p.miMatriz[Fila+8][Col+9]='3';
      p.miMatriz[Fila+8][Col+10]='0';
      p.miMatriz[Fila+8][Col+12]='3';
      p.miMatriz[Fila+8][Col+13]='1';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }




}
else if (inicio==3){
  p.miMatriz[Fila+4][Col+10]='1';
  p.miMatriz[Fila+4][Col+13]='2';
  p.miMatriz[Fila+4][Col+18]='3';
  p.miMatriz[Fila+4][Col+21]='4';
  p.miMatriz[Fila+5][Col+1]='5';
  p.miMatriz[Fila+5][Col+4]='6';
  p.miMatriz[Fila+5][Col+7]='7';
  p.miMatriz[Fila+5][Col+10]='8';
  p.miMatriz[Fila+5][Col+13]='9';
  p.miMatriz[Fila+5][Col+17]='1';
  p.miMatriz[Fila+5][Col+18]='0';
  p.miMatriz[Fila+5][Col+20]='1';
  p.miMatriz[Fila+5][Col+21]='1';
  p.miMatriz[Fila+6][Col]='1';
  p.miMatriz[Fila+6][Col+1]='2';
  p.miMatriz[Fila+6][Col+3]='1';
  p.miMatriz[Fila+6][Col+4]='3';
  p.miMatriz[Fila+6][Col+6]='1';
  p.miMatriz[Fila+6][Col+7]='4';
  p.miMatriz[Fila+6][Col+9]='1';
  p.miMatriz[Fila+6][Col+10]='5';
  p.miMatriz[Fila+6][Col+12]='1';
  p.miMatriz[Fila+6][Col+13]='6';
  p.miMatriz[Fila+6][Col+17]='1';
  p.miMatriz[Fila+6][Col+18]='7';
  p.miMatriz[Fila+6][Col+20]='1';
  p.miMatriz[Fila+6][Col+21]='8';
  p.miMatriz[Fila+7][Col]='1';
  p.miMatriz[Fila+7][Col+1]='9';
  p.miMatriz[Fila+7][Col+3]='2';
  p.miMatriz[Fila+7][Col+4]='0';
  p.miMatriz[Fila+7][Col+6]='2';
  p.miMatriz[Fila+7][Col+7]='1';
  p.miMatriz[Fila+7][Col+9]='2';
  p.miMatriz[Fila+7][Col+10]='2';
  p.miMatriz[Fila+7][Col+12]='2';
  p.miMatriz[Fila+7][Col+13]='3';
  p.miMatriz[Fila+7][Col+17]='2';
  p.miMatriz[Fila+7][Col+18]='4';
  p.miMatriz[Fila+7][Col+20]='2';
  p.miMatriz[Fila+7][Col+21]='5';
  p.miMatriz[Fila+8][Col]='2';
  p.miMatriz[Fila+8][Col+1]='6';
  p.miMatriz[Fila+8][Col+3]='2';
  p.miMatriz[Fila+8][Col+4]='7';
  p.miMatriz[Fila+8][Col+6]='2';
  p.miMatriz[Fila+8][Col+7]='8';
  if (diasMes==28){
      p.miMatriz[Fila+8][Col+10]='.';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }else if (diasMes==29){
      p.miMatriz[Fila+8][Col+9]='2';
      p.miMatriz[Fila+8][Col+10]='9';
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if (diasMes==30){
      p.miMatriz[Fila+8][Col+9]='2';
      p.miMatriz[Fila+8][Col+10]='9';
      p.miMatriz[Fila+8][Col+12]='3';
      p.miMatriz[Fila+8][Col+13]='0';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if(diasMes==31){
      p.miMatriz[Fila+8][Col+9]='2';
      p.miMatriz[Fila+8][Col+10]='9';
      p.miMatriz[Fila+8][Col+12]='3';
      p.miMatriz[Fila+8][Col+13]='0';
      p.miMatriz[Fila+8][Col+17]='3';
      p.miMatriz[Fila+8][Col+18]='1';
      p.miMatriz[Fila+8][Col+21]='.';
  }
}
else if (inicio==4){
  p.miMatriz[Fila+4][Col+13]='1';
  p.miMatriz[Fila+4][Col+18]='2';
  p.miMatriz[Fila+4][Col+21]='3';
  p.miMatriz[Fila+5][Col+1]='4';
  p.miMatriz[Fila+5][Col+4]='5';
  p.miMatriz[Fila+5][Col+7]='6';
  p.miMatriz[Fila+5][Col+10]='7';
  p.miMatriz[Fila+5][Col+13]='8';
  p.miMatriz[Fila+5][Col+18]='9';
  p.miMatriz[Fila+5][Col+20]='1';
  p.miMatriz[Fila+5][Col+21]='0';
  p.miMatriz[Fila+6][Col]='1';
  p.miMatriz[Fila+6][Col+1]='1';
  p.miMatriz[Fila+6][Col+3]='1';
  p.miMatriz[Fila+6][Col+4]='2';
  p.miMatriz[Fila+6][Col+6]='1';
  p.miMatriz[Fila+6][Col+7]='3';
  p.miMatriz[Fila+6][Col+9]='1';
  p.miMatriz[Fila+6][Col+10]='4';
  p.miMatriz[Fila+6][Col+12]='1';
  p.miMatriz[Fila+6][Col+13]='5';
  p.miMatriz[Fila+6][Col+17]='1';
  p.miMatriz[Fila+6][Col+18]='6';
  p.miMatriz[Fila+6][Col+20]='1';
  p.miMatriz[Fila+6][Col+21]='7';
  p.miMatriz[Fila+7][Col]='1';
  p.miMatriz[Fila+7][Col+1]='8';
  p.miMatriz[Fila+7][Col+3]='1';
  p.miMatriz[Fila+7][Col+4]='9';
  p.miMatriz[Fila+7][Col+6]='2';
  p.miMatriz[Fila+7][Col+7]='0';
  p.miMatriz[Fila+7][Col+9]='2';
  p.miMatriz[Fila+7][Col+10]='1';
  p.miMatriz[Fila+7][Col+12]='2';
  p.miMatriz[Fila+7][Col+13]='2';
  p.miMatriz[Fila+7][Col+17]='2';
  p.miMatriz[Fila+7][Col+18]='3';
  p.miMatriz[Fila+7][Col+20]='2';
  p.miMatriz[Fila+7][Col+21]='4';
  p.miMatriz[Fila+8][Col]='2';
  p.miMatriz[Fila+8][Col+1]='5';
  p.miMatriz[Fila+8][Col+3]='2';
  p.miMatriz[Fila+8][Col+4]='6';
  p.miMatriz[Fila+8][Col+6]='2';
  p.miMatriz[Fila+8][Col+7]='7';
  p.miMatriz[Fila+8][Col+9]='2';
  p.miMatriz[Fila+8][Col+10]='8';
  if (diasMes==28){
      p.miMatriz[Fila+8][Col+13]='.';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }else if (diasMes==29){
      p.miMatriz[Fila+8][Col+12]='2';
      p.miMatriz[Fila+8][Col+13]='9';
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if (diasMes==30){
      p.miMatriz[Fila+8][Col+12]='2';
      p.miMatriz[Fila+8][Col+13]='9';
      p.miMatriz[Fila+8][Col+17]='3';
      p.miMatriz[Fila+8][Col+18]='0';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if(diasMes==31){
      p.miMatriz[Fila+8][Col+12]='2';
      p.miMatriz[Fila+8][Col+13]='9';
      p.miMatriz[Fila+8][Col+17]='3';
      p.miMatriz[Fila+8][Col+18]='0';
      p.miMatriz[Fila+8][Col+20]='3';
      p.miMatriz[Fila+8][Col+21]='1';
  }
}
else if (inicio==5){
  p.miMatriz[Fila+4][Col+18]='1';
  p.miMatriz[Fila+4][Col+21]='2';
  p.miMatriz[Fila+5][Col+1]='3';
  p.miMatriz[Fila+5][Col+4]='4';
  p.miMatriz[Fila+5][Col+7]='5';
  p.miMatriz[Fila+5][Col+10]='6';
  p.miMatriz[Fila+5][Col+13]='7';
  p.miMatriz[Fila+5][Col+18]='8';
  p.miMatriz[Fila+5][Col+21]='9';
  p.miMatriz[Fila+6][Col]='1';
  p.miMatriz[Fila+6][Col+1]='0';
  p.miMatriz[Fila+6][Col+3]='1';
  p.miMatriz[Fila+6][Col+4]='1';
  p.miMatriz[Fila+6][Col+6]='1';
  p.miMatriz[Fila+6][Col+7]='2';
  p.miMatriz[Fila+6][Col+9]='1';
  p.miMatriz[Fila+6][Col+10]='3';
  p.miMatriz[Fila+6][Col+12]='1';
  p.miMatriz[Fila+6][Col+13]='4';
  p.miMatriz[Fila+6][Col+17]='1';
  p.miMatriz[Fila+6][Col+18]='5';
  p.miMatriz[Fila+6][Col+20]='1';
  p.miMatriz[Fila+6][Col+21]='6';
  p.miMatriz[Fila+7][Col]='1';
  p.miMatriz[Fila+7][Col+1]='7';
  p.miMatriz[Fila+7][Col+3]='1';
  p.miMatriz[Fila+7][Col+4]='8';
  p.miMatriz[Fila+7][Col+6]='1';
  p.miMatriz[Fila+7][Col+7]='9';
  p.miMatriz[Fila+7][Col+9]='2';
  p.miMatriz[Fila+7][Col+10]='0';
  p.miMatriz[Fila+7][Col+12]='2';
  p.miMatriz[Fila+7][Col+13]='1';
  p.miMatriz[Fila+7][Col+17]='2';
  p.miMatriz[Fila+7][Col+18]='2';
  p.miMatriz[Fila+7][Col+20]='2';
  p.miMatriz[Fila+7][Col+21]='3';
  p.miMatriz[Fila+8][Col]='2';
  p.miMatriz[Fila+8][Col+1]='4';
  p.miMatriz[Fila+8][Col+3]='2';
  p.miMatriz[Fila+8][Col+4]='5';
  p.miMatriz[Fila+8][Col+6]='2';
  p.miMatriz[Fila+8][Col+7]='6';
  p.miMatriz[Fila+8][Col+9]='2';
  p.miMatriz[Fila+8][Col+10]='7';
  p.miMatriz[Fila+8][Col+12]='2';
  p.miMatriz[Fila+8][Col+13]='8';
  if (diasMes==28){
      p.miMatriz[Fila+8][Col+18]='.';
      p.miMatriz[Fila+8][Col+21]='.';
  }else if (diasMes==29){
      p.miMatriz[Fila+8][Col+17]='2';
      p.miMatriz[Fila+8][Col+18]='9';
      p.miMatriz[Fila+8][Col+21]='.';
  }
  else if (diasMes==30){
      p.miMatriz[Fila+8][Col+17]='2';
      p.miMatriz[Fila+8][Col+18]='9';
      p.miMatriz[Fila+8][Col+20]='3';
      p.miMatriz[Fila+8][Col+21]='0';
  }
  else if(diasMes==31){
      p.miMatriz[Fila+8][Col+17]='2';
      p.miMatriz[Fila+8][Col+18]='9';
      p.miMatriz[Fila+8][Col+20]='3';
      p.miMatriz[Fila+8][Col+21]='0';
      p.miMatriz[Fila+9][Col]='3';
      p.miMatriz[Fila+9][Col+1]='1';
      p.miMatriz[Fila+9][Col+4]='.';
      p.miMatriz[Fila+9][Col+7]='.';
      p.miMatriz[Fila+9][Col+10]='.';
      p.miMatriz[Fila+9][Col+13]='.';
      p.miMatriz[Fila+9][Col+15]='|';
      p.miMatriz[Fila+9][Col+18]='.';
      p.miMatriz[Fila+9][Col+21]='.';
  }
}
else if (inicio==6){
  p.miMatriz[Fila+4][Col+21]='1';
  p.miMatriz[Fila+5][Col+1]='2';
  p.miMatriz[Fila+5][Col+4]='3';
  p.miMatriz[Fila+5][Col+7]='4';
  p.miMatriz[Fila+5][Col+10]='5';
  p.miMatriz[Fila+5][Col+13]='6';
  p.miMatriz[Fila+5][Col+18]='7';
  p.miMatriz[Fila+5][Col+21]='8';
  p.miMatriz[Fila+6][Col+1]='9';
  p.miMatriz[Fila+6][Col+3]='1';
  p.miMatriz[Fila+6][Col+4]='0';
  p.miMatriz[Fila+6][Col+6]='1';
  p.miMatriz[Fila+6][Col+7]='1';
  p.miMatriz[Fila+6][Col+9]='1';
  p.miMatriz[Fila+6][Col+10]='2';
  p.miMatriz[Fila+6][Col+12]='1';
  p.miMatriz[Fila+6][Col+13]='3';
  p.miMatriz[Fila+6][Col+17]='1';
  p.miMatriz[Fila+6][Col+18]='4';
  p.miMatriz[Fila+6][Col+20]='1';
  p.miMatriz[Fila+6][Col+21]='5';
  p.miMatriz[Fila+7][Col]='1';
  p.miMatriz[Fila+7][Col+1]='6';
  p.miMatriz[Fila+7][Col+3]='1';
  p.miMatriz[Fila+7][Col+4]='7';
  p.miMatriz[Fila+7][Col+6]='1';
  p.miMatriz[Fila+7][Col+7]='8';
  p.miMatriz[Fila+7][Col+9]='1';
  p.miMatriz[Fila+7][Col+10]='9';
  p.miMatriz[Fila+7][Col+12]='2';
  p.miMatriz[Fila+7][Col+13]='0';
  p.miMatriz[Fila+7][Col+17]='2';
  p.miMatriz[Fila+7][Col+18]='1';
  p.miMatriz[Fila+7][Col+20]='2';
  p.miMatriz[Fila+7][Col+21]='2';
  p.miMatriz[Fila+8][Col]='2';
  p.miMatriz[Fila+8][Col+1]='3';
  p.miMatriz[Fila+8][Col+3]='2';
  p.miMatriz[Fila+8][Col+4]='4';
  p.miMatriz[Fila+8][Col+6]='2';
  p.miMatriz[Fila+8][Col+7]='5';
  p.miMatriz[Fila+8][Col+9]='2';
  p.miMatriz[Fila+8][Col+10]='6';
  p.miMatriz[Fila+8][Col+12]='2';
  p.miMatriz[Fila+8][Col+13]='7';
  p.miMatriz[Fila+8][Col+17]='2';
  p.miMatriz[Fila+8][Col+18]='8';
  if (diasMes==28){
      p.miMatriz[Fila+8][Col+21]='.';
  }else if (diasMes==29){
      p.miMatriz[Fila+8][Col+20]='2';
      p.miMatriz[Fila+8][Col+21]='9';
  }
  else if (diasMes==30){
      p.miMatriz[Fila+8][Col+20]='2';
      p.miMatriz[Fila+8][Col+21]='9';
      p.miMatriz[Fila+9][Col]='3';
      p.miMatriz[Fila+9][Col+1]='0';
      p.miMatriz[Fila+9][Col+4]='.';
      p.miMatriz[Fila+9][Col+7]='.';
      p.miMatriz[Fila+9][Col+10]='.';
      p.miMatriz[Fila+9][Col+13]='.';
      p.miMatriz[Fila+9][Col+15]='|';
      p.miMatriz[Fila+9][Col+18]='.';
      p.miMatriz[Fila+9][Col+21]='.';
  }
  else if(diasMes==31){
      p.miMatriz[Fila+8][Col+20]='2';
      p.miMatriz[Fila+8][Col+21]='9';
      p.miMatriz[Fila+9][Col]='3';
      p.miMatriz[Fila+9][Col+1]='0';
      p.miMatriz[Fila+9][Col+3]='3';
      p.miMatriz[Fila+9][Col+4]='1';
      p.miMatriz[Fila+9][Col+7]='.';
      p.miMatriz[Fila+9][Col+10]='.';
      p.miMatriz[Fila+9][Col+13]='.';
      p.miMatriz[Fila+9][Col+15]='|';
      p.miMatriz[Fila+9][Col+18]='.';
      p.miMatriz[Fila+9][Col+21]='.';
  }
}
}
