#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
int n, A[200001];
int cnt=1, ans=0;
map<int, int> M;
int nextEl(){
	while(M[cnt])cnt++;
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	cin>>n;
	for(int i=0; i<n; i++)cin>>A[i];

	for(int i=0; i<n; i++)M[A[i]]++;
	for(int i=0; i<n; i++){
		if(M[A[i]]==1)continue;

		int nex=nextEl();

		if(M[A[i]]<1||nex<A[i]){
			ans++;
			M[A[i]]--;
			A[i]=nex;
			M[nex]=1;
		}
		else{
			M[A[i]]=0;
		}
	}
	cout<<ans<<endl;
	for(int i=0; i<n; i++)cout<<A[i]<<" ";

	cerr<<endl;
}