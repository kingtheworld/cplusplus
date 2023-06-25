#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *pLeft;
    node *pRight;
};
typedef node* tree;
void khoitaocay(tree &a)
{
    a=NULL;
}
void themnodevaocay(tree &a,int x)
{
    if(a==NULL) {node *p=new node;
    p->data=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    a=p;
    }
    else {
        if(x<a->data) themnodevaocay(a->pLeft,x);
        else if(x>a->data) themnodevaocay(a->pRight,x);
    }
}
void duyet_NLR(tree a)
{
    if(a!=NULL){
        cout<<a->data<<" ";
         duyet_NLR(a->pLeft);
      duyet_NLR(a->pRight);
    }
}
int main()
{
}