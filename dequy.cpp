#include<bits/stdc++.h>
using namespace std;
FILE *fi,*fo;
string a="";
int main()
{
    char c;
    string s=" ";
    fi=fopen("Tepvanban.cpp","r");
    if (fi==NULL)
    {
        fprintf(stderr,"Khong the mo Tepvanban.txt\n");
        exit(1);
    }
    if ((fo=fopen("Tepvanbanmoi.cpp","w"))==NULL)
    {
        fprintf(stderr,"Khong the mo Tepvanbanmoi.txt\n");
        exit(1);
    }
    //while((c=fgetc(fi))!=EOF) fputc(c,fo);
    //fclose(fi);
    //fclose(fo);
    int k=0,dem=0;
    do
    {
         c=fgetc(fi);
      if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')) {k=1;   
    //  char b=c;
      //printf("%s\n%c\n",a,b);
      }
        if ((c==' '||c=='\t'||c=='\n'||c==EOF)&&k==1)
        {
          if(s.size()>=a.size())
         { for(int i=0;i<s.size();i++)
          {
            if(s[i]==' ')
            {
              bool ktra=true;
              for(int j=0;j<a.size();j++)
              {
                if(s[i+j+1]!=a[j]) {
                  ktra=false;
                }
              }
               if(ktra==true) s=s+' '+a;
            }
          }
         }
          else s=s+a;
          k=0;
          dem++;
          string a;
        }
    }
    while (c!=EOF);
    printf("So luong tu co trong van ban la : %d\n",dem);
printf("%s",s);
   fprintf(fo,"%s",s);
   fclose(fo);
 }