/*
2 0 -3 4
6 3 2 -1
5 4 7 3
2 -6 8 1
*/
/*
3 0 1 4 2
5 6 3 2 1
1 2 0 1 5
4 1 0 1 7
1 0 3 0 5
*/
    #include<bits/stdc++.h>
    using namespace std;
    int matriz[50][50],memo[50][50],fila,columna;

    void init(){
    memset(memo,0,sizeof(memo));
        for(int i=1;i<=fila;i++){
            for(int j=1;j<=columna;j++){
               memo[i][j]=memo[i-1][j]+memo[i][j-1]+matriz[i-1][j-1]-memo[i-1][j-1];
            }
        }
    }
    /*int sumarRegion(int f1,int c1,int f2,int c2){
    return memo[f2][c2]-memo[f1-1][c2]-memo[f2][c1-1]+memo[f1-1][c1-1];
    }*/
    int sumarRegion(int f1,int c1,int f2,int c2){
        int p1_i, p1_j, p2_i, p2_j, p3_i, p3_j, p4_i, p4_j;
        p1_i = f1;
        p1_j = c1;

        p2_i = f1;
        p2_j = c2 + 1;

        p3_i = f2+1;
        p3_j = c2+1;

        p4_i = f2+1;
        p4_j = c1;
    return memo[p3_i][p3_j] - memo[p2_i][p2_j] - memo[p4_i][p4_j] + memo[p1_i][p1_j];
    }
    int main(){
    fila=columna=5;
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            cin>>matriz[i][j];
        }
    }
    init();
    cout<<"Tabla aditiva\n";
    for(int i=0;i<=fila;i++){
        for(int j=0;j<=columna;j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }


    cout<<sumarRegion(2,1,4,3)<<"\n";
    cout<<sumarRegion(1,1,2,2)<<"\n";
    cout<<sumarRegion(1,2,2,4)<<"\n";

    return 0;
    }
