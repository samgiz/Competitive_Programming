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

const int N = 200001;

int A[N][20];

int main(){
	// fastInputOutput;
	int n, m;
	cin>>n>>m;
	fori(1<<n)cin>>A[i][0];
	forii(1, 20){
		// cerr<<i<<endl;
		for(int j=0; j<(1<<n); j+=(1<<i)){
			if(j+(1<<(i-1))>=(1<<n))A[j][i]=A[j][i-1];
			else if(i%2){// perform or
				A[j][i]=A[j][i-1]|A[j+(1<<(i-1))][i-1];
			}
			else{ //perform xor
				A[j][i]=A[j][i-1]^A[j+(1<<(i-1))][i-1];
			}
		}
		// cerr<<i<<endl;
	}
	fori(m){
		int p, b;
		cin>>p>>b;
		p--;
		A[p][0]=b;

		forii(1, 20){
			// cerr<<i<<endl;
			int j = (p>>i)<<i;
			if(j+(1<<(i-1))>=(1<<n))A[j][i]=A[j][i-1];
			else if(i%2){// perform or
				A[j][i]=A[j][i-1]|A[j+(1<<(i-1))][i-1];
			}
			else{ //perform xor
				A[j][i]=A[j][i-1]^A[j+(1<<(i-1))][i-1];
			}
			// cerr<<i<<endl;
		}

		cout<<A[0][19]<<endl;
	}
}
