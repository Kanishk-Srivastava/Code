#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x; 
    int y;
    cin>>x; 
    cin>>y;
    //int x = max(a,b); 
    //int y = min(a,b);
    while(y%x!=0){
        int rem=y%x;
        y=x; 
        x=rem;  
    }
    cout<<x;
    return 0;
}