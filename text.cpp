#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include <map>

using namespace std;

struct node{
    string data;
    node *pNext;
};

struct stack {
    node *pTop;
};

node* khoitaonode(string x)
{
    node* p = new node;
    if (p == NULL) {
        cout << "Không đủ bộ nhớ để cấp phát";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

void khoitaostack(stack& s)
{
    s.pTop = NULL;
}

bool IsEmpty(stack s)
{
    if (s.pTop == NULL)
        return true;
    return false;
}

void Push(stack& s, node* p)
{
    if (p == NULL)
        return;
    if (IsEmpty(s))
    {
        s.pTop = p;
    }
    else {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

bool Pop(stack& s, string& x)
{
    if (IsEmpty(s))
        return false;
    else {
        node* p = s.pTop;
        x = p->data;
        s.pTop = s.pTop->pNext;
        delete p;
    }
    return true;
}

bool Top(stack s, string& x)
{
    if (IsEmpty(s))
        return false;
    x = s.pTop->data;
    return true;
}

int pr(string s)
{
    if(s=="~") return 4;
    else if (s=="^"||s=="|"||s=="&") return 3;
    else if (s == "/" || s == "*" ||s=="->")
        return 2;
    else if (s == "+" || s == "-"||s=="<->")
        return 1;
    return 0;
}

bool check(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^"||s=="~"||s=="|"||s=="&"|| s == "^"||s=="->"||s=="<->")
        return true;
    return false;
}

string Infix2Postfix(string b)
{
     stack s;
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
            node* p = khoitaonode("(");
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
            node* p = khoitaonode(a[i]);
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

string Infix2Prefix(string b)
{
     stack s;
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
            node* p = khoitaonode(")");
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
            node* p = khoitaonode(a[i]);
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

string PostfixPrefixCalculator(string b)
{
    
      stack s;
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
            string x, y;
            Pop(s, x);
            Pop(s, y);
            double c = stod(x);
            double d = stod(y);
            if (kiemtra) {
                double temp = c;
                c = d;
                d = temp;
            }
            double ans = 0;
            if (a[i] == "*")
                ans = c * d;
            else if (a[i] == "+")
                ans = c + d;
            else if (a[i] == "-")
                ans = d - c;
            else if (a[i] == "/")
                ans = d / c;
            else if (a[i] == "^") {
                ans = 1;
                for (int j = 0; j < c; j++)
                    ans *= d;
            }
            node* p = khoitaonode(to_string(ans));
            Push(s, p);
        } else {
            node* p = khoitaonode(a[i]);
            Push(s, p);
        }
    }

    string kq;
    Pop(s, kq);
    double result = stod(kq);

    // Định dạng kết quả
    stringstream ss;
    ss << fixed << setprecision(4) << result;
    return ss.str();
}

string LogicPostfixPrefixCalculator(string b,string value)
{
    
      stack s;
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
    for(int i=0;i<value.size();i++)
    if(value[i]!=' ') {
        vlue1[sovalue]=value[i];
        so++;
    }
        map<string,int> value2;
    for(int i=0;i<sovalue/2;i++)
    value2[vlue1[i]]=(vlue1[i+sovalue/2]=="0"?0:1);
    bool kiemtra = false;
    if (check(a[0])) {
        reverse(a, a + so);
        kiemtra = true;
    }
    for (int i = 0; i < so; i++) {
        if (check(a[i])) {
            if(a[i]=="~") {
                
            }
        } else {
            node* p = khoitaonode(a[i]);
            Push(s, p);
        }
    }

    string kq;
    Pop(s, kq);
    double result = stod(kq);

    // Định dạng kết quả
    stringstream ss;
    ss << fixed << setprecision(4) << result;
    return ss.str();
}

string LogicInfix2Postfix(string b)
{
     stack s;
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
            node* p = khoitaonode("(");
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
            node* p = khoitaonode(a[i]);
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

string LogicInfix2Prefix(string b)
{
     stack s;
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
            node* p = khoitaonode(")");
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
            node* p = khoitaonode(a[i]);
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

int main()
{
    string a ="987 654 321 123 / * + 2 ^ 456 789 + -";
    cout << PostfixPrefixCalculator(a)<<endl;
   // cout<<intopre(a,s);
    return 0;
}