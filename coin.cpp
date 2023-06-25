#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       /* long long a,b;
        cin>>a>>b;
        int k=a%3, h=b%3;
        if(a==0&&b==0) cout<<"YES"<<endl;
        else if((k==2&&h==1)||(k==1&&h==2))
        {
            int k=a/3, h=b/3;
            if(k>h) {
                a-= h*3;
                b-=h*3;
                if(a/2==b||b/2==a) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else {
                  a-= k*3;
                b-=k*3;
                if(b/2==a||a/2==b) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else if(k==0&&h==0)
        {
           long long n=max(a,b)-min(a,b);
           if(n%2==0)
           {
            if((max(a,b)-2*n)==(min(a,b)-n)&&(max(a,b)-2*n)%3==0) 
               cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
           }
        }
        else cout<<"NO"<<endl;*/
        long long a,b;
        cin>>a>>b;
        if(a==0&&b==0) cout<<"YES"<<endl;
        else{
          long long n=max(a,b)-min(a,b);       
            if((max(a,b)-2*n)==(min(a,b)-n)&&(max(a,b)-2*n)%3==0&&(max(a,b)-2*n)>=0&&(min(a,b)-n)>=0) 
               cout<<"YES"<<endl;
            else cout<<"NO"<<endl;}
    }
}