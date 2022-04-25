///Permite determinar de manera eficiente a que conjunto pertenece un elemento,
///si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos en un uno.

#include<bits/stdc++.h>
using namespace std;

const int MAX=1000;
struct dsu{
int padre[MAX],len[MAX];


void iniciar(int n){
    //indexar desde 0,1 depende del prgblema
    for(int i=0;i<n;i++){
        padre[i]=i;
        len[i]=1;
    }
}
int find_(int x){
  if(padre[x]==x){
    return x;
  }
  return find_(padre[x]);
}

//El padre de a, que apunte a el padre de b
void merge_(int a,int b){
  padre[find_(a)]=find_(b);
}






///Comprension de caminos
int find_c(int x){
  if(padre[x]==x){
    return x;
  }
  return padre[x]=find_(padre[x]);
}
//pasar conjunto mas pequeño al mas grande
 void merge_c(int a,int b){ //a sera el mas grande, b el mas pequeño
  int fa=find_c(a);
  int fb=find_c(b);
  if(fa!=fb){
  if(len[fa]<len[fb]){
    swap(fa,fb);
  }
  len[fa]+=len[fb];
  padre[fb]=fa;
 }
}
};


int main(){

dsu d;
d.iniciar(10);
//cout<<d.find_(5)<<"\n";
d.merge_c(2,1);
d.merge_c(3,1);
d.merge_c(4,2);
cout<<d.find_(3)<<"\n";
d.merge_c(4,1);
cout<<d.find_(4)<<"\n";



return 0;
}
