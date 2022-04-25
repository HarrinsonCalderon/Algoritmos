#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
int n; //Cantidad de nodos
vector<int>grafo[MAX]; //Grafo
bool visitado[MAX]; //Si ya visite el nodo i
//Nodo para iniciar
void dfs(int s) {
    visitado[s] = true;
    for (int i=0;i<grafo[s].size();i++) {
        int v =grafo[s][i];
        if (!visitado[v]) {
            dfs(v);
        }
      }
}
//Limpiar la estructura grafo
void init() {
    for(int i = 0; i <= n; i++) {
        grafo[i].clear();
        visitado[i] = false;
    }
}

int main() {

    while (cin>>n) {

        init(); //necesaria
        for (int i = 0; i < n;i++) {
            int nodo, vert; //Nodo tiene vertices vert
            cin>>nodo>>vert;

            for (int j = 0; j < vert;j++) {
            int nodo2; //leemos el nodo adyacente a el nodo del for i
            cin>>nodo2;
            grafo[nodo].push_back(nodo2); //save
            }
        }
        //Estructura para recorrer todo el grafo es necesaria
        for (int i = 1; i <= n;i++) {
            if(!visitado[i]){
            dfs(i);
            }
        }
        //Esta no es necesaria es solo para mostrar la lista de adyacencia
        for (int i = 1; i <= n;i++) {
            cout<<i<<" ";
            for(int j=0;j<grafo[i].size();j++){
                cout<<grafo[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
/*
Ejemplo entrada
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
*/
