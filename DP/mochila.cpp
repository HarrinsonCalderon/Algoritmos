    #include<bits/stdc++.h>
    using namespace std;

    int peso[50]={0},valor[50]={0}; //MAX
    int memo[50][50]; //MAX o dentro de mochila
    void mochila(int canArticulos,int maxPeso){ //BOTTOM-UP

        for(int i=0;i<=canArticulos;i++){
            for(int j=0;j<=maxPeso;j++){
                if(i==0 ||j==0)memo[i][j]=0; //para que no de errores de memoria
                else if(peso[i-1]<=j){
                  memo[i][j]=max(memo[i-1][j],valor[i-1]+memo[i-1][j-peso[i-1]]); //me puedo llevar el anterior O el valor actual mas el valor que me resta de la fila anterior
                }else  { //tomo el mejor con el peso j hasta el momento
                  memo[i][j]=memo[i-1][j];
                }
            }
        }



    }
    int main(){
    peso[0]=3;
    peso[1]=2;
    peso[2]=1;

    valor[0]=5;
    valor[1]=3;
    valor[2]=4;

    mochila(3,5);//3=cantidad de objetos, 5=peso maximo

    for(int i=0;i<=3;i++){
        for(int j=0;j<=5;j++){
          cout<<memo[i][j]<<" ";
        }
          cout<<"\n";
        }
     cout<<"\n"<<memo[3][5]<<" Es el valor maximo";

     return 0;
    }

