#include<iostream>
#include<random>
using namespace std;

int randNum(){
    random_device rand;
    mt19937 gen(rand());

    //range
    uniform_int_distribution<int> dist(1,10);

    //generate random number
    int rNum = dist(gen);

    return rNum;
}

int main(){
    int g;  //user guess
    int r = randNum();  //random number
    cout<<endl;

    do{
        cout<<"Enter Your Number (1-10): ";
        cin>>g;

        if(g == r){
            cout<<"Correct Answer."<<endl;
        }else{
            cout<<"Wrong Guess! Try Again."<<endl<<endl;
        }
    }while(g!=r);
    
    return 0;
}