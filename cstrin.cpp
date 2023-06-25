#include<bits/stdc++.h>
using namespace std;
set<string> xuat;
int dem=0,ktra[100]={};
char A[10]={};
string s;
void xuatstring(int i)
{
  for(int j=0;j<s.size();j++)
  {
   if(ktra[j]==0)
    {  
      A[i]=s[j];
      ktra[j]=1;
      if(i==s.size()) {
         string a="";
         for(int k=1;k<=s.size();k++) a=a+A[k];
         xuat.insert(a);
      } 
      else {
         xuatstring(i+1);
      }
          ktra[j]=0;
    }
  }
}
int main()
{
  cin>>s;
  xuatstring(1);
  //cout<<xuat.size()<<endl;
  int dem=0;
  for(auto c:xuat)
  {
    dem++;
  }
  cout<<dem<<endl;
   for(auto c:xuat)
  {
     cout<<c<<endl;
}
}