#include<iostream>
using namespace std;

int main()
{   
    int t; 
    cin>>t; 

    while(t--){
        int a,b,c; 
        int ans;
        cin>>a; 
        cin>>b; 
        cin>>c; 
        if(a==b || b==c || c==a){
             if(a != b && b != c && a==c){
                ans=b;
             }
             if(a != c && b != c && a==b){
                ans=c;
             }
             if(a != c && b != a && b==c){
                ans=a;
             }
        }
        cout<<ans<<endl;
    }

 return 0;
}