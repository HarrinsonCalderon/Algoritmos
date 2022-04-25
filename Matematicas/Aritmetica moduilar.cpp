#include<bits/stdc++.h>
using namespace std;


int mcd(int a,int b){return a? mcd(b%a,a): b;}
int mcm(int a,int b){return a*(b/mcd(a,b));}

/// x^n=x*x*x*..n O (log N)
int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}

/// (x^n)%m  O(log N)
int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}

/// Ax+By=gcd(A,B)
int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
void extendedEuclid(){
int A=16,B=10;
extendedEuclid(A, B);
cout<<A<<"*"<<x<<" + "<<B<<"*"<<y<<"="<<d;
}

int main(){


}



