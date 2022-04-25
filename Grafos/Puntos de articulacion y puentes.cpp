#include<bits/stdc++.h>
using namespace std;

int UNVISITED=-1,dfsRoot,rootChildren,dfsNumberCounter;
vector<int>dfs_num;
vector<int>dfs_low;
vector<int>g[100];
vector<int>dfs_padre,punto_articulacion;
int nodos,aristas;
void articulationPointAndBridge(int u) {
 dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)g[u].size(); j++) {
        int v = g[u][j];
      if (dfs_num[v] == UNVISITED) {
        dfs_padre[v] = u;
        if (u == dfsRoot){// special case if u is a root
             rootChildren++;
         }
    articulationPointAndBridge(v);
     if (dfs_low[v] >= dfs_num[u]){//puntos de articulacion
     punto_articulacion[u] = true;
     }
     if (dfs_low[v] > dfs_num[u]){ // para puente
     printf(" Arista (%d, %d) es un puente\n", u, v); //Si los quiero los guardo
     }
     dfs_low[u] = min(dfs_low[u], dfs_low[v]);
     }else if (v != dfs_padre[u]){
     dfs_low[u] = min(dfs_low[u], dfs_num[v]);
     }
    }
}

 void init(){
 dfsNumberCounter = 0;
 dfs_num.assign(nodos, UNVISITED);
 dfs_low.assign(nodos, 0);
 dfs_padre.assign(nodos, 0);
 punto_articulacion.assign(nodos, 0);
     for(int i=0;i<nodos;i++){
         g[i].clear();
     }
 }
 void solve(){
 printf("Puentes:\n"); //Puentes
 for (int i = 0; i < nodos; i++){
     if (dfs_num[i] == UNVISITED) {
     dfsRoot = i;
     rootChildren = 0;
     articulationPointAndBridge(i);
     punto_articulacion[dfsRoot] = (rootChildren > 1); // special case
     }
     }
 printf("Puntos de articulacion:\n");
 for (int i = 0; i < nodos; i++){
     if (punto_articulacion[i]){
     printf(" Nodo %d\n", i);
     }
 }
 }


int main(){
int u,v;
cin>>nodos>>aristas;
init();
for(int i=0;i<aristas;i++){
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
}

solve();

return 0;

}

/*
6 6
0 1
1 2
1 3
1 4
1 5
4 5

*/

