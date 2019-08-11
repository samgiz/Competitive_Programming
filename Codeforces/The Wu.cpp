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

int W[20];
int WSum[5000];
int M[5000];
int DP[5000][101];
string s;
int tp;
int K[500001], T[500001];

int main(){
	fastInputOutput;
	int n, m, q;
	cin>>n>>m>>q;
	for(int i=n-1; i>=0; i--){
		cin>>W[i];
	}
	char c;
	fori(m){
		tp = 0;
		cin>>s;
		for(auto c: s)
			tp=(tp<<1)+c-'0';
		M[tp]++;
	}

	fori(q){
		cin>>s;
		for(auto c: s)
			T[i]=(T[i]<<1)+c-'0';
		cin>>K[i];
	}

	fori(1<<n){
		forj(n){
			if(((1<<j)&i)==0)WSum[i]+=W[j];
		}
	}

	fori(1<<n){
		forj(1<<n){
			if(M[j]==0)continue;
			int p = WSum[i^j];
			if(p<=100){
				// cerr<<i<<" "<<a.fi<<" "<<WSum[i^a.fi]<<" a"<<endl;
				DP[i][p]+=M[j];
			}
		}
		forjj(1, 101)DP[i][j]+=DP[i][j-1];
	}

	fori(q){
		cout<<DP[T[i]][K[i]]<<endl;
	}
}
