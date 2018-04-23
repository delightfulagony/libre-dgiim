/**
   @file intervalo.cpp
   @brief Implementación de la clase @p Intervalo
   @author Gonzalo Moreno Soto - Grupo A
**/
#include <iostream>
#include "intervalo.h"
#include <assert.h>

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
  assert(validar(cotaInferior, cotaSuperior, true, true));
  cerradoInf = true;
  cerradoSup = true;
  cotaInf = cotaInferior;
  cotaSup = cotaSuperior;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)  {
  assert(validar(cotaInferior, cotaSuperior, cerradoInferior, cerradoSuperior));
    cerradoInf = cerradoInferior;
    cerradoSup = cerradoSuperior;
    cotaInf = cotaInferior;
    cotaSup = cotaSuperior;
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

bool Intervalo::validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)const  {
  bool answer = false;
  if (cotaInferior<cotaSuperior) {answer = true;} else if (cotaInferior==cotaSuperior and cerradoInferior==cerradoSuperior) {answer = true;}
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

Intervalo interseccion(const Intervalo &i1, const Intervalo &i2) {

  bool cerradoInferior = false;
  bool cerradoSuperior = false;
  double cotaInferior = 0;
  double cotaSuperior = 0;

  if (i1.cotaInf > i2.cotaInf) {
    cotaInferior = i1.cotaInf;
    cerradoInferior = i1.cerradoInf;
  } else if (i1.cotaInf < i2.cotaInf) {
    cotaInferior = i2.cotaInf;
    cerradoInferior = i2.cerradoInf;
  } else if (i1.cotaInf == i2.cotaInf) {
    cotaInferior = i1.cotaInf;
    if (i1.cerradoInf == true and i2.cerradoInf == true) {
      cerradoInferior = true;
    } else  {
      cerradoInferior = false;
    }
  }

  if (i1.cotaSup > i2.cotaSup) {
    cotaSuperior = i2.cotaSup;
    cerradoSuperior = i2.cerradoSup;
  } else if (i1.cotaSup < i2.cotaSup) {
    cotaSuperior = i1.cotaSup;
    cerradoSuperior = i1.cerradoSup;
  } else if (i1.cotaSup == i2.cotaSup) {
    cotaSuperior = i1.cotaSup;
    if (i1.cerradoSup == true and i2.cerradoSup == true) {
      cerradoSuperior = true;
    } else  {
      cerradoSuperior = false;
    }
  }

  if (i1.validar(cotaInferior, cotaSuperior, cerradoInferior, cerradoSuperior)) {
    Intervalo ans(cotaInferior, cotaSuperior, cerradoInferior, cerradoSuperior);
    return ans;
  } else  {
    Intervalo ans;
    return ans;
  }
}
