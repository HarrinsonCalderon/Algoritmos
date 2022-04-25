#include<bits/stdc++.h>
using namespace std;

int main() {

int nodos,aristas,u,v;
int entrantes[nodos]={0}; //para cada nodo cuantas fechas entran

cin>>nodos>>aristas;
vector<vector<int>>g(nodos);

for(int i=0;i<aristas;i++){
    cin>>u>>v;
    g[u].push_back(v);
    entrantes[v]++;
}
queue<int>q;
vector<int>salida;
for(int i=0;i<nodos;i++){
    if(entrantes[i]==0){
        q.push(i);
    }
}
while(q.size()){
    int s=q.front();
    salida.push_back(s);
    q.pop();
    for(int i=0;i<g[s].size();i++){
        int ii=g[s][i];
        entrantes[ii]--;
        if(entrantes[ii]==0){
            q.push(ii); //puedo hacer la tarea
        }
    }
}
cout<<"\n";
for(int i=0;i<salida.size();i++){
    cout<<i<<" ";
}
return 0;
}
/**
6 5
0 3
1 3
1 4
2 4
2 5
*/

