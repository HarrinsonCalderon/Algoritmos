#include<bits/stdc++.h>
using namespace std;

///Hacer el hash de un string
long long compute_hash(string const& s) {///suma desde 0 hasta n-1 s[i]*pi mod m
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

///Separa en grupos todas las subcadenas de una cadena
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

int main(){


vector<string>s;
s.push_back("a");//0
s.push_back("a");//1
s.push_back("b");//2
s.push_back("a");//3
s.push_back("b");//4
vector<vector<int>>g;
g=group_identical_strings(s);
for(int i=0;i<g.size();i++){
 for(int j=0;j<g[i].size();j++){//da las posiciones del grupo
    cout<<g[i][j]<<" ";
 }
 cout<<"\n";
}

return 0;
}













