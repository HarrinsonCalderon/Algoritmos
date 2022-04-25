#include<bits/stdc++.h>
using namespace std;

struct st_LP{ ///info de cada nodo
  st_LP *left,*right;
  int sum,l,r,m,lazy;
  st_LP(int l,int r):l(l),r(r),sum(0),lazy(0){ //intervalos men,may
       if(l!=r){
        m=(l+r)/2;
        left=new st_LP(l,m);
        right=new st_LP(m+1,r);

       }
  }
  void propagate(){
    if(lazy!=0){
        ///actualizar nodo
        sum=(r-l+1)*lazy;
        if(l!=r){
            left->lazy=lazy;
            right->lazy=lazy;
        }
        ///actualizar hijos
        lazy=0;
    }
  }
  ///actualice de a hast_LPa b con el valor v
  void update(int a,int b,int v){
    propagate();
    if(a>r || b<l) return ;
    if(a<=l && r<=b){
        lazy=v;
        propagate();
        return;
    }
    left->update(a,b,v);
    right->update(a,b,v);
    sum=left->sum+right->sum;
  }

  //suma en el intervalo a,b O l,r
  int get(int a,int b){
        propagate();
     if(a>r || b<l)
        return 0;
     if(a<=l && r<=b)
        return sum;
     return left->get(a,b)+right->get(a,b);
  }
};

int main(){

  st_LP tree(0,8);
  for(int i=0;i<8;i++){
    int x;
    cin>>x;
    tree.update(i,i,x);
  }
  //
  cout<<tree.get(1,1)<<"\n";
  //intervalo i,j,nuevo valor
  tree.update(1,1,0); //no actualiza el rango en 0
  cout<<tree.get(1,1);
return 0;
}

/**
1 2 7 5 9 10 2 3

*/


