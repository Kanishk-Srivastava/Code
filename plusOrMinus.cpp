#include<iostream>
using namespace std; 

void plusOrMinus(){
    int a,b,c;
    cin >>a>>b>>c; 
    if(a+b == c){
        cout << "+" << endl; 
    } else if (a-b == c){
        cout << "-" << endl; 
    }
}

int main() {
    int t; 
    cin >> t; 
    while(t--){
        plusOrMinus(); 
    }
}