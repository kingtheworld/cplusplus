#include <iostream>
#include <string>
#include<algorithm>
#include <cmath>
#include <iomanip>
#include<map>
using namespace std;
template <typename temp>

struct node {
    temp data;
    node<temp>* next;
};
template <typename temp>

struct stack {
    node<temp>* top;
};
template <typename temp>

void khoitaostack(stack<temp>& s) {
    s.top = nullptr;
}
template <typename temp>

node<temp>* khoitaonode(temp data) {
    node<temp>* p = new node<temp>;
    p->data = data;
    p->next = nullptr;
    return p;
}
template <typename temp>
void Push(stack<temp>& s, node<temp>* p) {
    if (s.top == nullptr)
        s.top = p;
    else {
        p->next = s.top;
        s.top = p;
    }
}
template <typename temp>
bool IsEmpty(stack<temp> s)
{
    if (s.top == NULL)
        return true;
    return false;
}
template <typename temp>

bool Pop(stack<temp>& s, temp& data) {
   if (IsEmpty(s))
        return false;
    else {
        node<temp>* p = s.top;
        data = p->data;
        s.top = s.top->next;
        delete p;
    }
    return true;
}
template <typename temp>

bool Top(stack<temp> s, temp& x)
{
    if (IsEmpty(s))
        return false;
    x = s.top->data;
    return true;
}

int pr(string s)
{
    if(s=="~") return 4;
    else if (s=="^"||s=="|"||s=="&") return 3;
    else if (s == "/" || s == "*" ||s=="->"||s==">-")
        return 2;
    else if (s == "+" || s == "-"||s=="<->"||s==">-<")
        return 1;
    return 0;
}

bool check(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^"||s=="~"||s=="|"||s=="&"|| s == "^"||s=="->"||s=="<->"||s==">-<"||s==">-")
        return true;
    return false;
}
template <typename temp>
string Infix2Postfix(string b)
{
     stack<temp> s;
    khoitaostack(s);
    string ans ="";
    string a[b.size()];
    int T[b.size()]={};
    int so=0;
   int o=b.size();
    for(int i=0;i<o-2;i++)
    {
        if((b[i]=='-'&&b[i+1]=='>'))
        {
            a[so]="->";
            T[i]=1;
            T[i+1]=1;
            i++;
        }
       else if(b[i]=='<'&&b[i+1]=='-'&&b[i+2]=='>'){
          T[i]=1;
            T[i+1]=1;
            T[i+2]=1;
        a[so]="<->";
        i+=2;
       }
       else if(b[i]>='0'&&b[i]<='9')
       {
        while(b[i]>='0'&&b[i]<='9')
        {
            a[so]=a[so]+b[i];
            T[i]=1;
            i++;
        }
        i--;
       }
       else {
        a[so]=a[so]+b[i];
        T[i]=1;
       }
       so++;
    }
     if(b[b.size()-2]=='-'&&b[b.size()-1]=='>') {a[so]="->"; so++;}
    else
        for(int i=o-2;i<o;i++)
        {
            if(T[i]==0){
            if(b[i]>='0'&&b[i]<='9')
       {
        while(b[i]>='0'&&b[i]<='9')
        {
            a[so]=a[so]+b[i];
            i++;
        }
        i--;
       }
       else {
        a[so]=a[so]+b[i];
       }
       so++;
        }}
    int songoacmo=0;
        int songoacdong=0;
        string k="0";
    for(int i=0;i<so-1;i++)
    {
        if(a[i]==".") return "raise syntax error";
        if(a[i]==")") songoacdong++;
     if(a[i]=="(") songoacmo++;
     if(check(a[i])&&check(a[i+1])&&a[i+1]!="+"&&a[i+1]!="-"&&a[i+1]!="&"&&a[i+1]!="~") return "raise syntax error";
     //if(a[i]!=" "&&())
    }
     if(a[so-1]==")") songoacdong++;
     if(a[so-1]=="(") songoacmo++;
    if(songoacdong!=songoacmo) return "raise syntax error";
    for (int i = 0; i < so; i++)
    {
        if (a[i] == "(")
        {
            node<temp>* p = khoitaonode(a[i]);
            Push(s, p);
        }
        else if (a[i] == ")")
        {
            string m;
            while (Top(s, m) && m != "(")
            {
                if (Pop(s, m))
                    ans =ans+ m+" ";
            }
            Pop(s, m);
        }
        else if (check(a[i]))
        {
            string m;
            while (Top(s, m) && check(m) && pr(m) >= pr(a[i]))
            {
                if (Pop(s, m))
                    ans =ans+ m+" ";
            }
            node<temp>* p = khoitaonode(a[i]);
            Push(s, p);
        }
        else
            ans =ans+ a[i]+" ";
    }
    string m;
    while (Pop(s, m))
    {
        ans =ans+ m+" ";
    }
    return ans;
}
template <typename temp>
string Infix2Prefix(string b)
{
     stack<temp> s;
    khoitaostack(s);
  int o=b.size();
    string ans ="";
    string a[b.size()];
    int T[b.size()]={};
    int so=0;
    for(int i=0;i<o-2;i++)
    {
        if((b[i]=='-'&&b[i+1]=='>'))
        {
            a[so]="->";
            T[i]=1;
            T[i+1]=1;
            i++;
        }
       else if(b[i]=='<'&&b[i+1]=='-'&&b[i+2]=='>'){
          T[i]=1;
            T[i+1]=1;
            T[i+2]=1;
        a[so]="<->";
        i+=2;
       }
       else if(b[i]>='0'&&b[i]<='9')
       {
        while(b[i]>='0'&&b[i]<='9')
        {
            a[so]=a[so]+b[i];
            T[i]=1;
            i++;
        }
        reverse(a[so].begin(),a[so].end());
        i--;
       }
       else {
        a[so]=a[so]+b[i];
        T[i]=1;
       }
       so++;
    }
     if(b[b.size()-2]=='-'&&b[b.size()-1]=='>') {a[so]="->"; so++;}
    else
        for(int i=o-2;i<o;i++)
        {
            if(T[i]==0){
            if(b[i]>='0'&&b[i]<='9')
       {
        while(b[i]>='0'&&b[i]<='9')
        {
            a[so]=a[so]+b[i];
            i++;
        }
         reverse(a[so].begin(),a[so].end());
        i--;
       }
       else {
        a[so]=a[so]+b[i];
       }
       so++;
        }}
    int songoacmo=0;
        int songoacdong=0;
        string k="0";
    for(int i=0;i<so-1;i++)
    {
        if(a[i]==".") return "raise syntax error";
        if(a[i]==")") songoacdong++;
     if(a[i]=="(") songoacmo++;
     if(check(a[i])&&check(a[i+1])&&a[i+1]!="+"&&a[i+1]!="-"&&a[i+1]!="&"&&a[i+1]!="~") return "raise syntax error";
     //if(a[i]!=" "&&())
    }
     if(a[so-1]==")") songoacdong++;
     if(a[so-1]=="(") songoacmo++;
    if(songoacdong!=songoacmo) return "raise syntax error";
    for (int i = so-1; i >=0; i--)
    {
        if (a[i] == ")")
        {
            node<temp>* p = khoitaonode(a[i]);
            Push(s, p);
        }
        else if (a[i] == "(")
        {
            string m;
            while (Top(s, m) && m != ")")
            {
                if (Pop(s, m))
                    ans =ans+ m+" ";
            }
            Pop(s, m);
        }
        else if (check(a[i]))
        {
            string m;
            while (Top(s, m) && check(m) && pr(m) > pr(a[i]))
            {
                if (Pop(s, m))
                    ans =ans+ m+" ";
            }
            node<temp>* p = khoitaonode(a[i]);
            Push(s, p);
        }
        else
            ans =ans+ a[i]+" ";
    }
    string m;
    while (Pop(s, m))
    {
        ans =ans+ m+" ";
    }
   reverse(ans.begin(),ans.end()-1);
   return ans;
}
template <typename temp>
string PostfixPrefixCalculator(string b) {
    stack<temp> s;
    khoitaostack(s);
    string a[b.size()];
    int T[b.size()] = {};
    int so = 0;
    int o = b.size();
    for (int i = 0; i < o - 2; i++) {
        if (b[i] == '-' && b[i + 1] == '>') {
            a[so] = "->";
            T[i] = 1;
            T[i + 1] = 1;
            i++;
        } else if (b[i] == '<' && b[i + 1] == '-' && b[i + 2] == '>') {
            T[i] = 1;
            T[i + 1] = 1;
            T[i + 2] = 1;
            a[so] = "<->";
            i += 2;
        } else if (b[i] >= '0' && b[i] <= '9') {
            while (b[i] >= '0' && b[i] <= '9') {
                a[so] = a[so] + b[i];
                T[i] = 1;
                i++;
            }
            i--;
        } else if (b[i] == ' ') {
            T[i] = 1;
            continue;
        } else {
            a[so] = a[so] + b[i];
            T[i] = 1;
        }
        so++;
    }
    if (b[b.size() - 2] == '-' && b[b.size() - 1] == '>') {
        a[so] = "->";
        so++;
    } else {
        for (int i = o - 2; i < o; i++) {
            if (T[i] == 0) {
                if (b[i] >= '0' && b[i] <= '9') {
                    while (b[i] >= '0' && b[i] <= '9') {
                        a[so] = a[so] + b[i];
                        i++;
                    }
                    i--;
                } else if (b[i] == ' ') {
                    continue;
                } else {
                    a[so] = a[so] + b[i];
                }
                so++;
            }
        }
    }
    bool kiemtra = false;
    if (check(a[0])) {
        reverse(a, a + so);
        kiemtra = true;
    }

    for (int i = 0; i < so; i++) {
        if (check(a[i])) {
            double x=0, y=0;
            Pop(s, x);
             Pop(s, y);
            if (kiemtra) {
                temp temp1 = x;
                x = y;
                y = temp1;
            }
            double ans = 0;
            if (a[i] == "*")
                ans = x * y;
            else if (a[i] == "+")
                ans = x + y;
            else if (a[i] == "-")
                ans = y - x;
            else if (a[i] == "/")
                ans = y / x;
            else if (a[i] == "^") {
                ans = pow(y, x);
            }
            node<temp>* p = khoitaonode(ans);
            Push(s, p);
        } else {
            double x=stod(a[i]);
            node<temp>* p = khoitaonode(x);
            Push(s, p);
        }
    }
    double kq;
        Pop(s, kq);
        int ans=0;
    if(kq==floor(kq)||kq==ceil(kq)) ans=0;
    else{
        double l;
        if(kq>0)
        l=kq-floor(kq);
        else {
           l=ceil(kq)-kq;
        }
        string l1=to_string(l);
        if(l>0&&l<1){
            if(l>0&&(l-0.1*(l1[2]-'0'))<0.1){
                if(l>0&&(l-0.01*(l1[3]-'0')-0.1*(l1[2]-'0'))<0.01){
                    if(l>0&&(l-0.001*(l1[4]-'0')-0.01*(l1[3]-'0')-0.1*(l1[2]-'0'))<0.001&&l1[5]!='0'&&(l1[5]<'9'||l1[6]<5)){
                        ans=4;
                    }
                  else if(l1[4]!='0')  ans=3; 
                   else if(l1[3]!='0') ans=2;
                        else if(l1[2]!='0')  ans=1;
                     else ans=0;
                }
              else  ans=2;
            }
         else  ans=1;
        }
        else ans=0;
    }
    // Định dạng kết quả
  stringstream ss;
ss << fixed << setprecision(ans) << kq;
return ss.str();
}
template <typename temp>
string LogicInfix2Prefix(string b)
{    stack<temp> s;
    khoitaostack(s);
  int o=b.size();
    string ans ="";
    string a[b.size()];
    int T[b.size()]={};
    int so=0;
    for(int i=0;i<o-2;i++)
    {
        if((b[i]=='-'&&b[i+1]=='>'))
        {
            a[so]=">-";
            T[i]=1;
            T[i+1]=1;
            i++;
        }
       else if(b[i]=='<'&&b[i+1]=='-'&&b[i+2]=='>'){
          T[i]=1;
            T[i+1]=1;
            T[i+2]=1;
        a[so]=">-<";
        i+=2;
       }
       else if(b[i]>='0'&&b[i]<='9')
       {
        while(b[i]>='0'&&b[i]<='9')
        {
            a[so]=a[so]+b[i];
            T[i]=1;
            i++;
        }
        reverse(a[so].begin(),a[so].end());
        i--;
       }
       else if(b[i]==' ') continue;
       else {
        a[so]=a[so]+b[i];
        T[i]=1;
       }
       so++;
    }
     if(b[b.size()-2]=='-'&&b[b.size()-1]=='>') {a[so]=">-"; so++;}
    else
        for(int i=o-2;i<o;i++)
        {
            if(T[i]==0){
            if(b[i]>='0'&&b[i]<='9')
       {
        while(b[i]>='0'&&b[i]<='9')
        {
            a[so]=a[so]+b[i];
            i++;
        }
         reverse(a[so].begin(),a[so].end());
        i--;
       }
       else {
        a[so]=a[so]+b[i];
       }
       so++;
        }}
    int songoacmo=0;
        int songoacdong=0;
        string k="0";
    for(int i=0;i<so-1;i++)
    {
        if(a[i]==".") return "raise syntax error";
        if(a[i]==")") songoacdong++;
     if(a[i]=="(") songoacmo++;
     if(check(a[i])&&check(a[i+1])&&a[i+1]!="+"&&a[i+1]!="-"&&a[i+1]!="&"&&a[i+1]!="~") return "raise syntax error";
     //if(a[i]!=" "&&())
    }
     if(a[so-1]==")") songoacdong++;
     if(a[so-1]=="(") songoacmo++;
    if(songoacdong!=songoacmo) return "raise syntax error";
    for (int i = so-1; i >=0; i--)
    {
        if (a[i] == ")")
        {
            node<temp>* p = khoitaonode(a[i]);
            Push(s, p);
        }
        else if (a[i] == "(")
        {
            string m;
            while (Top(s, m) && m != ")")
            {
                if (Pop(s, m))
                    ans =ans+ m;
            }
            Pop(s, m);
        }
        else if (check(a[i]))
        {
            string m;
            while (Top(s, m) && check(m) && pr(m) > pr(a[i]))
            {
                if (Pop(s, m))
                    ans =ans+ m;
            }
            node<temp>* p = khoitaonode(a[i]);
            Push(s, p);
        }
        else
            ans =ans+ a[i];
    }
    string m;
    while (Pop(s, m))
    {
        ans =ans+ m;
    }
   reverse(ans.begin(),ans.end());
   return ans;
}
template <typename temp>
string LogicInfix2Postfix(string b)
{
     stack<temp> s;
    khoitaostack(s);
    string ans ="";
    string a[b.size()];
    int T[b.size()]={};
    int so=0;
   int o=b.size();
    for(int i=0;i<o-2;i++)
    {
        if((b[i]=='-'&&b[i+1]=='>'))
        {
            a[so]="->";
            T[i]=1;
            T[i+1]=1;
            i++;
        }
       else if(b[i]=='<'&&b[i+1]=='-'&&b[i+2]=='>'){
          T[i]=1;
            T[i+1]=1;
            T[i+2]=1;
        a[so]="<->";
        i+=2;
       }
       else if(b[i]>='0'&&b[i]<='9')
       {
        while(b[i]>='0'&&b[i]<='9')
        {
            a[so]=a[so]+b[i];
            T[i]=1;
            i++;
        }
        i--;
       }
       else if(b[i]==' ') continue;
       else {
        a[so]=a[so]+b[i];
        T[i]=1;
       }
       so++;
    }
     if(b[b.size()-2]=='-'&&b[b.size()-1]=='>') {a[so]="->"; so++;}
    else
        for(int i=o-2;i<o;i++)
        {
            if(T[i]==0){
            if(b[i]>='0'&&b[i]<='9')
       {
        while(b[i]>='0'&&b[i]<='9')
        {
            a[so]=a[so]+b[i];
            i++;
        }
        i--;
       }
       else {
        a[so]=a[so]+b[i];
       }
       so++;
        }}
    int songoacmo=0;
        int songoacdong=0;
        string k="0";
    for(int i=0;i<so-1;i++)
    {
        if(a[i]==".") return "raise syntax error";
        if(a[i]==")") songoacdong++;
     if(a[i]=="(") songoacmo++;
     if(check(a[i])&&check(a[i+1])&&a[i+1]!="+"&&a[i+1]!="-"&&a[i+1]!="&"&&a[i+1]!="~") return "raise syntax error";
     //if(a[i]!=" "&&())
    }
     if(a[so-1]==")") songoacdong++;
     if(a[so-1]=="(") songoacmo++;
    if(songoacdong!=songoacmo) return "raise syntax error";
    for (int i = 0; i < so; i++)
    {
        if (a[i] == "(")
        {
            node<temp>* p = khoitaonode(a[i]);
            Push(s, p);
        }
        else if (a[i] == ")")
        {
            string m;
            while (Top(s, m) && m != "(")
            {
                if (Pop(s, m))
                    ans =ans+ m;
            }
            Pop(s, m);
        }
        else if (check(a[i]))
        {
            string m;
            while (Top(s, m) && check(m) && pr(m) >= pr(a[i]))
            {
                if (Pop(s, m))
                    ans =ans+ m;
            }
            node<temp>* p = khoitaonode(a[i]);
            Push(s, p);
        }
        else
            ans =ans+ a[i];
    }
    string m;
    while (Pop(s, m))
    {
        ans =ans+ m;
    }
    return ans;
}
template <typename temp>
string LogicPostfixPrefixCalculator(string b,string value) {
    stack<temp> s;
    khoitaostack(s);
    string a[b.size()];
    int T[b.size()] = {};
    int so = 0;
    int o = b.size();
    for (int i = 0; i < o - 2; i++) {
        if (b[i] == '-' && b[i + 1] == '>') {
            a[so] = "->";
            T[i] = 1;
            T[i + 1] = 1;
            i++;
        } else if (b[i] == '<' && b[i + 1] == '-' && b[i + 2] == '>') {
            T[i] = 1;
            T[i + 1] = 1;
            T[i + 2] = 1;
            a[so] = "<->";
            i += 2;
        } else if (b[i] >= '0' && b[i] <= '9') {
            while (b[i] >= '0' && b[i] <= '9') {
                a[so] = a[so] + b[i];
                T[i] = 1;
                i++;
            }
            i--;
        } else if (b[i] == ' ') {
            T[i] = 1;
            continue;
        } else {
            a[so] = a[so] + b[i];
            T[i] = 1;
        }
        so++;
    }
    if (b[b.size() - 2] == '-' && b[b.size() - 1] == '>') {
        a[so] = "->";
        so++;
    } else {
        for (int i = o - 2; i < o; i++) {
            if (T[i] == 0) {
                if (b[i] >= '0' && b[i] <= '9') {
                    while (b[i] >= '0' && b[i] <= '9') {
                        a[so] = a[so] + b[i];
                        i++;
                    }
                    i--;
                } else if (b[i] == ' ') {
                    continue;
                } else {
                    a[so] = a[so] + b[i];
                }
                so++;
            }
        }
    }

  string vlue1[value.size()];
    int sovalue=0;
    int h=value.size();
    for(int i=0;i<h;i++)
    if(value[i]!=' ') {
        vlue1[sovalue]+=value[i];
        sovalue++;
    }
        map<string,int> value2;
    for(int i=0;i<sovalue/2;i++)
    {
    value2[vlue1[i]]=(vlue1[i+sovalue/2]=="0"?0:1);
    }

    bool kiemtra = false;
    if (check(a[0])) {
        reverse(a, a + so);
        kiemtra = true;
    }
  
    for (int i = 0; i < so; i++) {
        if (check(a[i])) {
           if(a[i]=="~") {s.top->data=(s.top->data==1?0:1);}
         else{   int ans = 0;
         int x=0,y=0;
         Pop(s,x);
          Pop(s,y);
          if (kiemtra) {
                temp temp1 = x;
                x = y;
                y = temp1;
            }
            if (a[i] == "&")
                ans = x & y;
            else if (a[i] == "|")
                ans = x | y;
            else if (a[i] == "<->")
                {ans=(x==y?1:0);
                    //ans = y ^ x;
                
                }
            else if (a[i] == "->")
            {
                if(x==y||(x==1&&y==0)) ans=1;
                else ans=0; 
            }
          
            node<temp>* p = khoitaonode(ans);
            Push(s, p);}
        } else {
            node<temp>* p = khoitaonode(value2[a[i]]);
            Push(s, p);
        }
    }
   
    int kq=0;
    Pop(s,kq);
    return (kq==1?"TRUE":"FALSE");
}

int main(){
    string a = " - ^ + 987 * 654 / 321 123 2 + 456 789";
    string b="49*(41*39)-(145+78)+193+(121*135+101-88)";
    string c="~t->t&~w|(z&(p&(w&(p|p&q)|y&z&z)<->x&(~p|z)&~y))";
    string d="->~t|&t~w&z<->&p&&|&w&|ppqyzz&&x|~pz~y";
    string value="t w z p q y x 1 1 1 1 1 1 1";
    cout << PostfixPrefixCalculator<double>(a) << endl;
   cout << Infix2Postfix<string>(b)<<endl;
    cout << Infix2Prefix<string>(b)<<endl;
    cout<<LogicInfix2Prefix<string>(c)<<endl;
    cout<<LogicInfix2Postfix<string>(c)<<endl;
    cout<<LogicPostfixPrefixCalculator<int>(d,value)<<endl;
    return 0;
}