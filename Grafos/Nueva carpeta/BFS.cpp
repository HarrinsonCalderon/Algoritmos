#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005; //Cantidad maxima de nodos
vector<int> grafo[MAX]; //Lista de adyacencia
long long dist[MAX]; //Almacena la distancia a cada nodo o visitado o no dist<0==no visitado
int N, M; //Cantidad de nodos y aristas
int n;
//BFS tambien halla la distancia mas corta entre el nodo inicial u y los demas nodos si todas las aristas tienen peso 1.
void bfs(int u) { //u punto de partida
    queue<int> q;
    q.push(u);
    dist[u] = 0; //visitado

    while (q.size()) {
        u = q.front();
        q.pop();
        for (int i=0;i<grafo[u].size();i++) {
            int v=grafo[u][i];
            if (dist[v] == -1) { //no visitado
                dist[v] = dist[u] + 1; //actualizamos
                q.push(v); //revisar sus adyacentes
            }
        }
    }
}

void init() {
    for(int i = 0; i <= N; i++) {
        grafo[i].clear();
        dist[i] = -1;
    }
}
int main(){

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
           bfs(i);
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
