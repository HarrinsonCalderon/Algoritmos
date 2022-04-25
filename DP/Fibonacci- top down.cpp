#include<bits/stdc++.h>
using namespace std;

vector<long>mem(1000,0);
long fibo(int n){
if(n<=1)
   return n;
    if(mem[n]!=0)
      return n; //No lo hemos calculado
    return mem[n]=fibo(n-1)+fibo(n-2);
}
int main(){
long n=5;
cout<<fibo(n);

return 0;
}
//todo lo calculado lo guardamos, si necesitamos algo lo retornamos
