#include <bits/stdc++.h>
int A[1001];
int T[3];
using namespace std;
int main(){
	int n;
	cin>>n;
	for(auto &i: T)i=10000000;
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	for(int i=0; i<n; i++){
		int t;
		cin>>t;
		T[t-1]=min(T[t-1], A[i]);
	}
	cout<<min(T[0]+T[1], T[2]);
}