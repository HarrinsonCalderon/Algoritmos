//Nos dan n monedas y un k valor, y tenemos que encontrar la minima cantidad de modenas para llegar a k valor.
//Donde las monedas se pueden repetir
//ejemplo:
//Modenas:{1,3,5} valor =10
//podemos usar 5+5 o 3+3+1 o 1+1+1+1+1+1+1+1+1+1 o 5+3+1+1...¿Cual es la minima de todas ellas?
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;
int oo=10000;
cin>>n>>k;
int monedas[n];
for(int i=0;i<n;i++)
    cin>>monedas[i];
int dp[k+1];
dp[0]=0;
for(int i=1;i<=k;i++){//hasta el valor k como el problema de la mochila
    dp[i]=oo;//algo porque se que mas adelante va a cambiar
   for(int m=0;m<n;m++){
     if(i-monedas[m]>=0)
     dp[i]=min(dp[i],dp[i-monedas[m]]+1);
   }
}
//for(int i=0;i<=k;i++)cout<<dp[i]<<" ";
cout<<dp[k];

return 0;
}
