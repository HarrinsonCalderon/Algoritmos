#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct FenwickTree{
    vi ft;
    //indexamos desde 1
    void iniciar(int n){ ft.assign(n + 1, 0); }

    void iniciar(vi &v){
        ft.assign(v.size() + 1, 0);
        for(int i = 1; i <= v.size(); i++)
            actualizar(i, v[i - 1]);
    }
    //bit menos significativo en 1
    int lsOne(int n){ return n & (-n); }

    int rsq(int i){//suma de 1 hasta i
        int acum = 0;
        for(; i; i -= lsOne(i)) acum+=ft[i];
        return acum;
    }

    int rsq(int i, int j){//suma de i hasta j
        return rsq(j) - ((i==1)? 0: rsq(i - 1));
    }
    //Suma n a la posicion pos
    void actualizar(int pos, int n){//n = nuevo - anterior
        for(; pos < ft.size(); pos += lsOne(pos))
            ft[pos] += n;

    }

    void r(int pos, int n){//n = nuevo - anterior actualizaciones con 0 y demas
        for(; pos < ft.size(); pos += lsOne(pos))
             ft[pos] += n*-1;

    }
};

int main(){
    int arr[] = {0, 1, 0, 1, 2, 3, 2, 1, 1, 0};
    vi ar;
    for(int i = 0; i < 10; i++) ar.push_back(arr[i]);

    FenwickTree tree;
    tree.iniciar(ar);

    cout << tree.rsq(4) << endl;
    cout << tree.rsq(2, 2) << endl;
    tree.actualizar(2,2);
    cout << tree.rsq(2, 2) << endl;
    return 0;
}
