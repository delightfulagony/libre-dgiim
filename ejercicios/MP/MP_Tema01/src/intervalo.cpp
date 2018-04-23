/**
   @file intervalo.cpp
   @brief Implementación de la clase @p Intervalo
   @author Gonzalo Moreno Soto - Grupo A
**/
#include <iostream>
#include "intervalo.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//                                 METODOS                                   //
///////////////////////////////////////////////////////////////////////////////
Intervalo::Intervalo()  {
  cerradoInf = false;
  cerradoSup = false;
  cotaInf = 0;
  cotaSup = 0;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior)  {
  if (validar(cotaInferior, cotaSuperior, true, true)) {
    cerradoInf = true;
    cerradoSup = true;
    cotaInf = cotaInferior;
    cotaSup = cotaSuperior;
  }
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)  {
  if (validar(cotaInferior, cotaSuperior, cerradoInferior, cerradoSuperior)) {
    cerradoInf = cerradoInferior;
    cerradoSup = cerradoSuperior;
    cotaInf = cotaInferior;
    cotaSup = cotaSuperior;
  }
}

double Intervalo::getCotaInf()const  {return cotaInf;}

double Intervalo::getCotaSup()const  {return cotaSup;}

bool Intervalo::esCerradoInf()const  {return cerradoInf;}

bool Intervalo::esCerradoSup()const  {return cerradoSup;}

bool Intervalo::esVacio()const {
  bool answer = true;
  if ((cotaInf-cotaSup) != 0) {
    answer = false;
  }
  return answer;
}

bool Intervalo::estaDentro(double n)const  {
  bool answer = false;
  if (n>=cotaInf and n<cotaSup and cerradoInf) {
    answer = true;
  } else if (n<=cotaSup and n>cotaInf and cerradoSup) {
    answer = true;
  } else if (n>cotaInf and n<cotaSup) {
    answer = true;
  }
  return answer;
}

bool Intervalo::validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)  {
  bool answer = false;
  if (cotaInferior<cotaSuperior) {answer = true;}
  return answer;
}

///////////////////////////////////////////////////////////////////////////////
//                                FUNCIONES                                  //
///////////////////////////////////////////////////////////////////////////////
void escribir(const Intervalo &i) {
  char cotaInf = '(';
  if (i.esCerradoInf()) {cotaInf = '[';}
  char cotaSup = ')';
  if (i.esCerradoSup()) {cotaSup = ']';}
  cout << cotaInf << i.getCotaInf() << "," << i.getCotaSup() << cotaSup;
}

void leer(Intervalo &i) {
  char Inf;
  char Sup;
  bool cerradoInf;
  bool cerradoSup;
  double cotaInf;
  double cotaSup;
  char coma;

  cin >> Inf >> cotaInf >> coma >> cotaSup >> Sup;

  if (Inf == '[') {cerradoInf = true;}  else if (Inf == '(') {cerradoInf = false;}
  if (Sup == ']') {cerradoSup = true;}  else if (Sup == ')') {cerradoSup = false;}

  Intervalo aux(cotaInf, cotaSup, cerradoInf, cerradoSup);

  i = aux;
}
