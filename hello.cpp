#include <iostream>
#include <string>
#include<algorithm>
#include <cmath>
#include <iomanip>
#include<map>

using namespace std;

struct node {
    int data;
    node* next;
};

struct stack {
    node* top;
};

void khoitaostack(stack& s) {
    s.top = nullptr;
}

node* khoitaonode(int data) {
    node* p = new node;
    p->data = data;
    p->next = nullptr;
    return p;
}

void Push(stack& s, node* p) {
    if (s.top == nullptr)
        s.top = p;
    else {
        p->next = s.top;
        s.top = p;
    }
}

void Pop(stack& s, int& data) {
    if (s.top == nullptr)
        data = -1;
    else {
        data = s.top->data;
        node* p = s.top;
        s.top = s.top->next;
        delete p;
    }
}

bool check(string s) {
 if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^"||s=="~"||s=="|"||s=="&"|| s == "^"||s=="->"||s=="<->")
        return true;
    return false;
}

string LogicPostfixPrefixCalculator(string b,string value) {
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
         int x,y;
         Pop(s,x);
         Pop(s,y);
          if (kiemtra) {
                int temp = x;
                x = y;
                y = temp;
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
          
            node* p = khoitaonode(ans);
            Push(s, p);}
        } else {
            node* p = khoitaonode(value2[a[i]]);
            Push(s, p);
        }
    }
   
    int kq=0;
    Pop(s,kq);
    return (kq==1?"TRUE":"FALSE");
}

int main(){
    string a = "->~t|&t~w&z<->&p&&|&w&|ppqyzz&&x|~pz~y";
    string value="t w z p q y x 1 1 1 1 1 1 1";
    cout << LogicPostfixPrefixCalculator(a,value) << endl;

    return 0;
}