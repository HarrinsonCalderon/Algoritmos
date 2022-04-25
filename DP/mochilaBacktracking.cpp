#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1010
#define MAX_W 40

int N, MW, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int mochila(int id, int w) { //Top-Down
  if (id == N || w == 0) return 0; //casos base
  if (memo[id][w] != -1) return memo[id][w]; //si ya tengo algo optimo
  if (W[id] > w)         return memo[id][w] = mochila(id + 1, w); //LLamar con id++ para seguir
  return memo[id][w] = max(mochila(id + 1, w), V[id] + mochila(id + 1, w - W[id])); //calculando el mejor valor
}

int main() {

    memset(memo, -1, sizeof memo);
    //Cantidad articulos
    N=4;
    //valor
    V[0] = 100;
    V[1] = 70;
    V[2] = 50;
    V[3] = 10;
    //peso
    W[0] = 10;
    W[1] = 4;
    W[2] = 6;
    W[3] = 12;
    //peso maximo
    MW=12;

    cout<<mochila(0, MW)<<"\n";
    for(int i=0;i<=MW+2;i++){
        for(int j=0;j<=MW;j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }
  return 0;
}
