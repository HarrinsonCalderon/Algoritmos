#include<bits/stdc++.h>
using namespace std;

int MAX=100;

const int gris=2,negro=1,blanco=-1;

vector<vector<int>>g(MAX);
vector<int>dfs_num;
vector<int>dfs_padre;
int ncc;
void graphCheck(int u){
  dfs_num[u]=gris;
  for(int i=0;i<g[u].size();i++){
    int v=g[u][i];
    if(dfs_num[v]==blanco){ //three edge, gris a blanco
        dfs_padre[v]=u; //padre de u
        graphCheck(v);
    }else if(dfs_num[v]==gris){ //gris a gris
        if(v==dfs_padre[u]){
            printf(" Bidirectional (%d, %d) - (%d, %d)\n", u, v, v, u);
        }else{ //encontramos un ciclo
            printf(" Back Edge (%d, %d) (Cycle)\n", u, v);
        }
    }else if(dfs_num[v]==negro){ //gris a negro
            printf(" Forward/Cross Edge (%d, %d)\n", u, v);
    }
  }
  dfs_num[u]=negro;
}

int main() {
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);
int nodos,aristas,a,b;

cin>>nodos>>aristas;
for(int i=0;i<nodos;i++){
  g[i].clear();
}
for(int i=0;i<aristas;i++){
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs_num.assign(nodos,blanco);
dfs_padre.assign(nodos,-1);

ncc=0;
for(int i=0;i<nodos;i++){
    if(dfs_num[i]==blanco){
      printf("Componente %d:\n", ++ncc), graphCheck(i);       // 2 lines in one

    }
}
return 0;
}

/**
9 8
0 1
1 3
3 4
1 2
3 2
7 6
8 6

3 3
2 1
1 3
3 2
*/

