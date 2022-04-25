#include<bits/stdc++.h>
using namespace std;
     void pascal(long n) {
            if(n==0){
                cout<<"1";
            }else{
            cout<<"1";

            long ans = 1;
            for (int i = 1; i < n; i++) {
                ans = ans * (n - i + 1) / i;
                cout<<" "<<ans;
            }
            cout<<" 1";

         }
    }
int main(){
   pascal(5);
    return 0;
}

