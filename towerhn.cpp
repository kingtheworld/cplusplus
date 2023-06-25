#include<bits/stdc++.h>
using namespace std;
void towerhn(int n, char a,char b, char c)
{
    if(n==1) 
    {
      cout<<a<<" "<<c<<endl;
      return;
    }  
        towerhn(n-1,a,c,b);
        towerhn(1,a,b,c);
        towerhn(n-1,b,a,c);
    
}
int main()
{
    int n;
    cin>>n;
    char a='1',b='2',c='3';
    cout<<pow(2,n)-1<<endl;
    towerhn(n,a,b,c);
}