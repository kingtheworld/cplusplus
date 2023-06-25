#include <bits/stdc++.h>
using namespace std;

void thuatsinh(int n, char *X, int m, bool &k) {
    int i = m - 1;
    k = false;
    while (i >= 0 && X[i] == n - m + i + 1){
        i--;}
    if (i < 0)
        k = true;
    else {
        X[i] = X[i] + 1;
        for (int j = i + 1; j < m; j++)
            X[j] = X[j - 1] + 1;
    }
}

int main() {
    int n = 26;
    char X[10000];
    for (int i = 0; i < n; i++)
       { X[i] = char(i + 97);
       cout<<X[i]<<endl;
       }
    int m;
    cin >> m;
    bool k = false;
    int count =0;
    while (!k) {
      count++;
      if(count==1) break;
         for (int i = 0; i < m; i++)
            cout << X[i];
        cout << endl;
        thuatsinh(n, X, m, k);
    }
    return 0;
}