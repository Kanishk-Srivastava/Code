#include <iostream>
using namespace std;
int main() {
	int t; 
    cin>>t;
	while(t--){
		int num;
		cin >> num;   
		if(num == 2){
			cout<<"No";
		} else if(num%2 == 0){
			cout<<"Yes";
		}
	}
	

}