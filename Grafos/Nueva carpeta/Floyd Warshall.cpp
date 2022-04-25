//Dado un grafo halla la distancia mínima entre cualquier par de nodos. g[i][j] guardará la distancia mínima entre el nodo i y el j.
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int MAX = 505; //Cantidad maxima de nodos
int g[MAX][MAX]; //Matriz de adyacencia
//int camino[MAX][MAX]; terminar
int N, M; //Cantidad de nodos y aristas

void floydWarshall() {
    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
             //   if (g[i][k] < INF && g[k][j] < INF) //Si existen pesos negativos
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}


void init() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            g[i][j] = (i==j ? 0 : INF);
        }
    }
}
/*void mostrarCamino(int f,int c){
    if(camino[f][c]==f){
        cout<<f<<" ";
        return;
    }else{
        mostrarCamino(f,camino[f][c]);
        cout<<camino[f][c]<<" ";
    }
}*/
int main(){
N=5;
init();

    g[0][1] = 2;
	g[0][2] = 1;
	g[0][4] = 3;
	g[1][3] = 4;
	g[2][1] = 1;
	g[2][4] = 1;
	g[3][4] = 5;
	g[3][2] = 3;
	g[3][0] = 1;
	cout<<"\n";
		    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
	floydWarshall();
	    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<g[0][4]; //si es INF no existe conexion con el nodo i j
	return 0;
}

