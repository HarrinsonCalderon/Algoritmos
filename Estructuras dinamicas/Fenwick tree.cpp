///Estructura de datos que permite procesar consultas por rangos y actualizaciones individuales sobre un arreglo.

#include<bits/stdc++.h>
using namespace std;

const int MX = 1e5;
int bit[MX+1];//guardar suma en la posicion i

///quiero sumar val a la posicion k,  es asigno y actualizo para la derecha
///Para reemplazar es restar segun el rsq
void add(int k, int val) {
    for (; k <= MX; k += k&-k) bit[k] += val;
}

///suma de un prefijo hasta k, es de k a la izquierda
int rsq(int k) {
    int sum = 0;
    for (; k >= 1; k -= k&-k) sum += bit[k];
    return sum;
}
///suma en un rango entre i,j
int rsq(int i, int j) { return rsq(j) - rsq(i-1); }

int lower_find(int val) { /// last value < or <= to val
    int id = 0;
    for (int i = 31-__builtin_clz(MX); i >= 0; --i) {
        int nid = id | (1<<i);
        if (nid <= MX && bit[nid] <= val) { /// change <= to <
            val -= bit[nid];
            id = nid;
        }
    }
    return id;
}

void iniciar(int n){
    n++;
    memset(bit,0,n);
}
void iniciar(vector<int>v){
   int n=v.size()+1;
   for(int i=1;i<=n;i++){
     add(i,v[i-1]);
   }
}

int main(){
iniciar(9);
vector<int>l={1,3,2,1,4,5};

iniciar(l);

for(int i=0;i<=l.size();i++){
    cout<<bit[i]<<" ";
}
cout<<"\n";
cout<<rsq(4+1)<<"\n";
cout<<rsq(2,4+1)<<"\n";
return 0;
}
