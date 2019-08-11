#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first

typedef int def; //default parameter for loops
#define repi(a) for(def i=0; i<(a); i++)
#define repii(a, b) for(def i=(a); i<(b); i++)
#define repj(a) for(def j=0; j<(a); j++)
#define repjj(a, b) for(def j=(a); j<(b); j++)
#define repk(a) for(def k=0; k<(a); k++)
#define repkk(a, b) for(def k=(a); k<(b); k++)
#define repe(a) for(def e=0; e<(a); e++)
#define repee(a, b) for(def e=(a); e<(b); e++)
#define repl(a) for(def l=0; l<(a); l++)
#define repll(a, b) for(def l=(a); l<(b); l++)

#define fastInputOutput ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
	// fastInputOutput;
	int n, k;
	cin>>n>>k;
	int A[100001];
	repi(n)cin>>A[i];
	int M;
	if(k==1){
		M=1000000000;
		repi(n)M=min(M, A[i]);
	}
	else if(k==2){
		int C[100001], B[100001];
		C[0]=A[0];
		repii(1, n){
			C[i]=min(C[i-1], A[i]);
		}
		B[n-1]=A[n-1];
		for(int i=n-2; i>=0; i--){
			B[i]=min(B[i-1], A[i]);
		}
		M=-1000000000;
		repi(n-1)M=max(M, max(C[i],B[i+1]));
	}
	else{
		M=-1000000000;
		repi(n)M=max(M, A[i]);
	}
	cout<<M;
}
