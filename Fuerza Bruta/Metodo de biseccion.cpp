#include<bits/stdc++.h>
using namespace std;
//////////////////////////////////////

double f1(double x) {//Función a evaluar
    return 4*(x*x)-5*x;
}
double bis1(double a, double b) {//Intervalos
 double m = 0;
     for (int it = 0; it < 90; it++) { //Numero de it para la presicion para calcularla logbase2
     m = (a + b) / 2.0;
     if (f1(a) * f1(m) < 0) //Busco a la derecha
        b = m;
     else //Busco a la izquierda
        a = m;
     }
 return m;//jugar con a,b,m y la presicion
}

//////////////////////////////////////

//////////////////////////////////////
double f2(double x){
    return 4*(x*x)-5*x;
}

double EPS=1e-9;

double bis2(double a,double b){
  double lo = a, hi = b,m;
  while (hi-lo>EPS){
    m = (lo+hi)/2;
    if (f2(lo) * f2(m) <= 0){
      hi = m;
    } else {
      lo = m;
    }
  }
  return lo; // Dependiendo
}
//////////////////////////////////////

int main(){
cout<<bis1(1,1.9)<<"\n";

cout<<bis2(1,1.9);
return 0;
}
