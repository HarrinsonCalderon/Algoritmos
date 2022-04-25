#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>g;
vector<int>dis;

void dijkstra(int s){
 //distancia, nodo y ordene por distancia de menor a mayor
 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
 dis[s]=0;
 q.push({0,s});

 while(q.size()){
    //saco el meno en distancia
    int u=q.top().second;
    int w=q.top().first;
    q.pop();
    //procesa el minimo
    if(dis[u]!=w)continue;
    for(auto e:g[u]){
         int nodo=e.first;
         int nuevopeso=w+e.second;
         //relajacion
         if(dis[nodo]>nuevopeso){
            dis[nodo]=nuevopeso;
            q.push({nuevopeso,nodo}); //para que siga sacando el menor
         }
    }
 }

}


int main(){
int nodos,aristas;
int u,v,w;
cin>>nodos>>aristas;
g.assign(nodos+1,vector<pair<int,int>>(0));
dis.assign(nodos+1,INT_MAX);
for(int i=0;i<aristas;i++){
    cin>>u>>v>>w; //de u a v con peso w
    g[u].push_back({v,w});
}
/*
for(int i=0;i<g.size();i++){
 for(int j=0;j<g[i].size();j++){
    cout<<g[i][j].first<<" ";
 }
 cout<<"\n";
}*/
int a;
a=1;//desde a a todos los nodos
dijkstra(a);
for(int i=1;i<dis.size();i++){
    cout<<"distancia minima de "<<a<<" hasta "<<i<<" es:"<<dis[i]<<"\n";
}
return 0;
}
/*
5 6
1 3 2
1 2 1
2 3 4
2 4 3
3 5 5
4 5 6

*/
