//El algoritmo de Euclides extendido retorna el gcd(a, b) y calcula los coeficientes enteros X y Y que satisfacen la ecuación: a*X + b*Y = gcd(a, b).

#include<bits/stdc++.h>
using namespace std;
int x,y,d;
void extendedEuclid(int a, int b) {
if (b == 0) { x = 1; y = 0; d = a; return; } // base case
extendedEuclid(b, a % b); // similar as the original gcd
int x1 = y;
int y1 = x - (a / b) * y;
x = x1;
y = y1;
}

int main(){
extendedEuclid(4,6);
cout<<"x:"<<x<<" y:"<<y<<" d:"<<d<<"\n";

return 0;
}

