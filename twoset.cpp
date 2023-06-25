#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <vector>

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
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^" || s == "~" || s == "|" || s == "&" || s == "^" || s == "->" || s == "<->")
        return true;
    return false;
}

string LogicPostfixPrefixCalculator(string expression, string values) {
    stack s;
    khoitaostack(s);
    vector<string> a(expression.size());
    vector<int> T(expression.size(), 0);
    int so = 0;
    int o = expression.size();
    
    for (int i = 0; i < o - 2; i++) {
        if (expression[i] == '-' && expression[i + 1] == '>') {
            a[so] = "->";
            T[i] = 1;
            T[i + 1] = 1;
            i++;
        } else if (expression[i] == '<' && expression[i + 1] == '-' && expression[i + 2] == '>') {
            T[i] = 1;
            T[i + 1] = 1;
            T[i + 2] = 1;
            a[so] = "<->";
            i += 2;
        } else if (expression[i] >= '0' && expression[i] <= '9') {
            while (expression[i] >= '0' && expression[i] <= '9') {
                a[so] = a[so] + expression[i];
                T[i] = 1;
                i++;
            }
            i--;
        } else if (expression[i] == ' ') {
            T[i] = 1;
            continue;
        } else {
            a[so] = a[so] + expression[i];
            T[i] = 1;
        }
        so++;
    }
    
    if (expression[o - 2] == '-' && expression[o - 1] == '>') {
        a[so] = "->";
        so++;
    } else {
        for (int i = o - 2; i < o; i++) {
            if (T[i] == 0) {
                if (expression[i] >= '0' && expression[i] <= '9') {
                    while (expression[i] >= '0' && expression[i] <= '9') {
                        a[so] = a[so] + expression[i];
                        i++;
                    }
                    i--;
                } else if (expression[i] == ' ') {
                    continue;
                } else {
                    a[so] = a[so] + expression[i];
                }
                so++;
            }
        }
    }

    vector<string> value1;
    string temp = "";
    for (char c : values) {
        if (c != ' ')
            temp += c;
        else if (temp != "") {
            value1.push_back(temp);
            temp = "";
        }
    }
    
    map<string, int> value2;
    for (int i = 0; i < value1.size() / 2; i++) {
        value2[value1[i]] = (value1[i + value1.size() / 2] == "0" ? 0 : 1);
    }

    bool kiemtra = false;
    if (check(a[0])) {
        reverse(a.begin(), a.end());
        kiemtra = true;
    }

    for (int i = 0; i < so; i++) {
        if (check(a[i])) {
            if (a[i] == "~") {
                s.top->data = (s.top->data == 1 ? 0 : 1);
            } else {
                int ans = 0;
                int x, y;
                Pop(s, x);
                Pop(s, y);
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
                    ans = y ^ x;
                else if (a[i] == "->") {
                    if (x == y || (x == 1 && y == 0)) ans = 1;
                    else ans = 0;
                }
                node* p = khoitaonode(ans);
                Push(s, p);
            }
        } else {
            node* p = khoitaonode(value2[a[i]]);
            Push(s, p);
        }
    }

    int kq = 0;
    Pop(s, kq);
    return (kq == 1 ? "TRUE" : "FALSE");
}

int main() {
    string expression = "<->&p|qrt";
    string values = "p q r t 0 1 1 1";
    cout << LogicPostfixPrefixCalculator(expression, values) << endl;

    return 0;
}