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

int dp[501][501];

int main(){
	fastInputOutput;
	int M = 500;
	fori(M){
		forj(M)dp[i][j]=-1;
	}
	dp[0][0]=0;
	fori(50){
		forj(50){
			if(i==0 && j==0)continue;
			for(int k=M; k>=i; k--){
				for(int l=M; l>=j; l--){
					if(dp[k-i][l-j]!=-1)
						dp[k][l] = max(dp[k-i][l-j]+1, dp[k][l]);
				}
			}
		}
	}

	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		int r, b;
		cin>>r>>b;
		cout<<dp[r][b]<<endl;
	}
}
