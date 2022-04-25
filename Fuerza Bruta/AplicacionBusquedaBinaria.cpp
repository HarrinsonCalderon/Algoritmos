#include<bits/stdc++.h>
using namespace std;

int main(){
    long long ejerciciosP,ejerciciosTio,porDiaP;
    while(cin >> porDiaP >> ejerciciosTio >> ejerciciosP){
            long long b=0,e=1e9,x,m;
            while(e-b>1){//siempre >1 o un error 1e-9
                m=(b+e)/2;
                if(ejerciciosTio+(m*(m+1)/2)>ejerciciosP+(m*porDiaP)){ //funcion a satisfacer
                    e=m;
                }else{
                    b=m;
                }
            }
            cout <<e<<endl;
    }
    return 0;
}

