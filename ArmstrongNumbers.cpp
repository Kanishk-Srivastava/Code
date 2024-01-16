#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;



int main()
{
    int n; 
    cin>>n; 
    int originalN=n; 
    int cubeSum = 0; 
    while(n != 0){
        int x,cube; 
        x=n%10; 
        cube = x*x*x;
        cubeSum = cube + cubeSum;
        n /= 10; 
    }
    cout<<"OriginalN = "<<originalN <<endl;
    if(originalN == cubeSum){
        cout<<"YES"<<endl; 
    } else cout<<"No"<<endl;
    
 return 0;
}