//distancia minima con pesos negativos, y ciclos negativos
//bellman ford, desde un nodo a todos los demas nodos
#include<bits/stdc++.h>
using namespace std;

const int oo=100000;
struct edge{
    int u,v,w;
};

int main(){

int nodos,aristas;
cin>>nodos>>aristas;

edge edges[oo];
for(int i=0;i<aristas;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges[i].u=u;
    edges[i].v=v;
    edges[i].w=w;
}
int source;
//cin>>source;

source=0;
int min_dis[oo];
for(int i=0;i<nodos+5;i++)
    min_dis[i]=100000;

min_dis[source]=0;

for(int i=0;i<nodos-1;i++){
      for(int j=0;j<aristas;j++){
        if(min_dis[edges[j].v]>min_dis[edges[j].u]+edges[j].w){
           min_dis[edges[j].v]=min_dis[edges[j].u]+edges[j].w;
                //memorizar el padre para el camino (e.u) edges[j].u
        }
    }
}
 for(int j=0;j<aristas;j++){
        if(min_dis[edges[j].v]>min_dis[edges[j].u]+edges[j].w){
           cout<<"Existe ciclo negativo\n";
        }
    }

cout<<"Minimas distancias desde source\n";
for(int i=0;i<nodos;i++){
    cout<<i+1<<" = "<<min_dis[i]<<"\n";
}



return 0;
}

