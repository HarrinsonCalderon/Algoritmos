#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100010 //1000010

string T, P; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P


void kmpPre() {
  int i = 0, j = -1; b[0] = -1;
  while (i < m) {
    while (j >= 0 && P[i] != P[j]) j = b[j];
    i++; j++;
    b[i] = j;
} }
void kmp() {
  int i = 0, j = 0;
  while (i < n) {
    while (j >= 0 && T[i] != P[j]) j = b[j];
    i++; j++;
    if (j == m) {
      cout<<"P se encontro en la posicion "<<i - j<<"\n";
      j = b[j];
} } }

int main() {
  T="I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
  P="SEVENTY SEVEN";
  n=T.length();
  m=P.length();
  kmpPre();
  kmp();

  return 0;
}

