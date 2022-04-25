#include<bits/stdc++.h>
using namespace std;

///Hacer el hash de un string
long long compute_hash(string s) {///suma desde 0 hasta n-1 s[i]*p^i mod m
    const int p = 31; //minusculas p=31 ,  minusculas y masyuscula p=53
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
int main(){
cout<<compute_hash("ab")<<"\n";
return 0;
}













