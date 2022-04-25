//Dado un grafo halla la distancia mínima entre cualquier par de nodos. g[i][j] guardará la distancia mínima entre el nodo i y el j.
//NODOS MAXIMOS <=500
#include<bits/stdc++.h>
using namespace std;

const int oo=10000;

int main(){

int n,m;
cin>>n>>m;
vector<vector<int>>min_dis(n,vector<int>(n,oo));
vector<vector<int>>nxt(n,vector<int>(n,-1));
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    min_dis[u-1][v-1]=w;
    nxt[u-1][v-1]=v-1;
}
for(int i=0;i<n;i++){
    min_dis[i][i]=0;
    nxt[i][i]=i;
}
for(int k=0;k<n;k++){
   for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
        if(min_dis[i][j]>min_dis[i][k]+min_dis[k][j]){
          min_dis[i][j]=min(min_dis[i][j],min_dis[i][k]+min_dis[k][j]);
          nxt[i][j]=nxt[i][k];
        }

      }
   }
}
cout<<"Minima distancia\n";
for(int i=0;i<n;i++){
 for(int j=0;j<n;j++){
    cout<<min_dis[i][j]<<" ";
 }
 cout<<"\n";
}
cout<<"Camino minimo de from a to\n";
int from,to;
from=4;
to=3;
from--;to--;
if(min_dis[from][to]==oo){
    cout<<"No hay camino\n";
}else{
    while(from!=to){
        cout<<from+1<<" ";
        from=nxt[from][to];
    }
    cout<<from+1<<"\n";
}

return 0;
 }
/**
4 5
2 1 4
1 3 -2
2 3 3
3 4 2
4 2 -1

*/
