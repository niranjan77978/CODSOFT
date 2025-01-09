#include<iostream>
using namespace std;


int main(){
    float n,m;
    char op;  

    cout<<"Enter First Number: ";
    cin>>n;
    cout<<endl;

    cout<<"Enter Second Number: ";
    cin>>m;
    cout<<endl;

    cout<<"Enter Operation to be done( + , - , * , / ): ";
    cin>>op;
    cout<<endl;

    switch (op)
    {
    case '+':
        cout<<"Answer: "<<n+m<<endl;
        break;
    case '-':
        cout<<"Answer: "<<n-m<<endl;
        break;
    case '*':
        cout<<"Answer: "<<n*m<<endl;
        break;
    case '/':
        cout<<"Answer: "<<n/m<<endl;
        break;
    
    default:
        break;
    }

    return 0;
}