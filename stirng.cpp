#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

const int MAX = 100;

struct student{
    char name[20];
    long int rollno;
    char sex;
    float height;
    float weight;
};

int main() {
    student cls[MAX];
    int i,n;
    float Ah,Aw;
    cout << "How many names ? \n";
    cin >> n;

    for (i = 0; i <= n-1; ++i){
        cout << "record = "<< i+1 << endl;
        cout << "name : "; cin>> cls[i].name;
        cout << "rollno : "; cin>> cls[i].rollno;
        cout << "sex : "; cin>> cls[i].sex;
        cout << "height : "; cin>> cls[i].height;
        cout << "weight : "; cin>> cls[i].weight;
        cout << endl;
    }
    cout <<setw(20)<<left<<"Name" << setw(20)<<left<< "Rollno"  << setw(20)<<left<< "Sex" << setw(20)<<left<< "Height" << setw(20)<<left<<"Weight"<<endl;
        for (i = 0; i <= n-1; ++i){
            cout <<fixed<<setprecision(2)<<setw(20)<<left<< cls[i].name << setw(20)<<left<< cls[i].rollno <<setw(20)<<left<< cls[i].sex << setw(20)<<left<<cls[i].height<<setw(20)<<left<<cls[i].weight<<"\n";
        Ah = Ah +cls[i].height ;
        Aw = Aw + cls[i].weight;
        }
cout <<fixed<<setprecision(5)<< Ah /n << " "<< Aw/n;
    
}