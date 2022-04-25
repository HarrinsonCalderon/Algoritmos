#include<bits/stdc++.h>
using namespace std;
vector<long>mem(1000,0);
long fibo(int n){
mem[0]=0;
mem[1]=1;
for(int i=2;i<=n;i++){
    mem[i]=mem[i-1]+mem[i-2];
}
return mem[n];
}
int main(){
long n=5;
cout<<fibo(n);
return 0;
}
//Completamos la tabla hasta el valor requerido
