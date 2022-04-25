     #include<bits/stdc++.h>
    using namespace std;

    int UNVISITED=-1,dfsRoot,rootChildren,dfsNumberCounter;
    vector<int>dfs_num;/*Numero de iteraciones para llegar al nodo*/
    vector<int>dfs_low;/*Minimo de iteraciones para alcanzar un nodo*/
    vector<int>dfs_padre,punto_articulacion;
    vector<int>AdjList[100];
    int V=1; //Numero de nodos
    void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v] == UNVISITED) { // a tree edge
    dfs_padre[v] = u;
    if (u == dfsRoot){// special case if u is a root
        rootChildren++;
    }
    articulationPointAndBridge(v);
    if (dfs_low[v] >= dfs_num[u]){// for articulation point
    punto_articulacion[u] = true; // store this information first
    }
    if (dfs_low[v] > dfs_num[u]){ // for bridge
    printf(" Arista (%d, %d) es un puente\n", u, v); //Si los quiero los guardo
    }
    dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
    }else if (v != dfs_padre[u]){ // a back edge and not direct cycle
    dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
    }
    }
    }

    void init(){
    dfsNumberCounter = 0;
    dfs_num.assign(V, UNVISITED);
    dfs_low.assign(V, 0);
    dfs_padre.assign(V, 0);
    punto_articulacion.assign(V, 0);
        for(int i=0;i<V;i++){
            AdjList[i].clear();
        }
    }
    void solve(){
    printf("Puentes:\n"); //Puentes
    for (int i = 0; i < V; i++){
        if (dfs_num[i] == UNVISITED) {
        dfsRoot = i;
        rootChildren = 0;
        articulationPointAndBridge(i);
        punto_articulacion[dfsRoot] = (rootChildren > 1); // special case
        }
        }
    printf("Puntos de articulacion:\n");
    for (int i = 0; i < V; i++){
        if (punto_articulacion[i]){
        printf(" Nodo %d\n", i);
        }
    }
    }


    int main(){

    V=6;
    init();
    AdjList[1].push_back(2);
    AdjList[1].push_back(5);
    AdjList[2].push_back(3);
    AdjList[2].push_back(5);
    AdjList[3].push_back(2);
    AdjList[3].push_back(4);
    AdjList[4].push_back(2);
    AdjList[4].push_back(3);
    AdjList[4].push_back(6);
    solve();

    return 0;
    }
