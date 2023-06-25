#include<iostream>
using namespace std;
#include<fstream>
typedef struct node{
   int data;
   NODE *pNext;
} NODE;
struct list{
   NODE *pHead;
   NODE *pTail;
};
void khoitao(list &l)
{
   l.pHead=NULL;
   l.pTail=NULL;
}
NODE *khoitaonode(int x)
{
   NODE *p= new NODE;
   if(p==NULL) return NULL;
   p->data=x;
   p->pNext=NULL;
   return p;
}
void themvaodau(list &l, NODE *p)
{
   if(l.pHead==NULL)
   {
      l.pHead=l.pTail=p;
   }
   else{
      p->pNext=l.pHead;
      l.pHead=p;
   }
}
void themvaocuoi(list &l, NODE*p)
{
 if(l.pHead==NULL)
 {
   l.pHead=l.pTail=NULL;
 }
 else{
   l.pTail->pNext=p;
   l.pTail=p;
 }
}
void xuatdanhsach(list l)
{
   for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
   {
      cout<<k->data;
   }
}
void themnodevaonode(list &l, node *q, node *p)
{
   for(NODE *k=l.pHead;k!=NULL;k->pNext)
   {
      if(k->data==q->data)
      {
         
         q->pNext=p->pNext;
         p->pNext=q;
      }
   }
}
int main()
{
   list l;
   khoitao(l);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int x;
      cin>>x;
      NODE *p=khoitaonode(x);
      themvaodau(l,p);
   }
}