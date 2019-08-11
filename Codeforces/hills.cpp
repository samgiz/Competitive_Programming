#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef int def; //default parameter for loops
#define fori(a) for(def i=0; i<(a); i++)
#define forii(a, b) for(def i=(a); i<(b); i++)
#define forj(a) for(def j=0; j<(a); j++)
#define forjj(a, b) for(def j=(a); j<(b); j++)
#define fork(a) for(def k=0; k<(a); k++)
#define forkk(a, b) for(def k=(a); k<(b); k++)
#define fore(a) for(def e=0; e<(a); e++)
#define foree(a, b) for(def e=(a); e<(b); e++)
#define forl(a) for(def l=0; l<(a); l++)
#define forll(a, b) for(def l=(a); l<(b); l++)

#define fastInputOutput ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int A[5001];
ll Hill[5001][3000], NoHill[5001][3000];

int dig(int a, int b){
	return max(0, b-a+1);
}
int main(){
	// fastInputOutput;
	int n;
	cin>>n;
	forii(0, 5001){
		for(auto &j: Hill[i])j = 100000000000;
	}
	forii(0, 5001){
		forjj(1, 3000)NoHill[i][j] = 100000000000;
	}
	fori(n)cin>>A[i];
	if(n==1){
		cout<<0;
		exit(0);
	}
	if(n==2){
		cout<<(A[0]==A[1]);
		exit(0);
	}
	Hill[0][1]=NoHill[1][1]=dig(A[0], A[1]);
	Hill[1][1] = dig(A[1], A[0])+dig(A[1], A[2]);
	forii(2, n-1){
		forjj(1, (n+1)/2+1){
			NoHill[i][j] = min(Hill[i-1][j], NoHill[i-1][j]);
			Hill[i][j] = min(NoHill[i-1][j-1]+dig(A[i], A[i-1]), (j==1?100000000000:Hill[i-2][j-1]+dig(A[i], min(A[i-1], A[i-2]-1))))+dig(A[i], A[i+1]);
		}
	}
	forjj(1, (n+1)/2+1){
		NoHill[n-1][j] = min(Hill[n-2][j], NoHill[n-2][j]);
		Hill[n-1][j] = min(NoHill[n-2][j-1]+dig(A[n-1], A[n-2]), (j==1?100000000000:Hill[n-3][j-1]+dig(A[n-1], min(A[n-2], A[n-3]-1))));
	}
	// cerr<<NoHill[3][0]<<endl;
	// forjj(1, (n+1)/2+1)cerr<<Hill[n-1][j]<<" "<<NoHill[n-1][j]<<endl;
	forjj(1, (n+1)/2+1)cout<<min(Hill[n-1][j], NoHill[n-1][j])<<" ";
}
