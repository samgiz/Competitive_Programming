#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

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
#define reps(a) for(def s=0; s<(a); s++)
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
	int n;
	cin>>n;
	int A[3][6];
	repi(n){
		repj(6)cin>>A[i][j];
	}
	set<int>S;
	repi(n){
		repj(6)S.insert(A[i][j]);
	}
	if(n>=2){
		repi(n){
			repj(n){
				if(i==j)continue;
				repk(6){
					repe(6)S.insert(A[i][k]*10+A[j][e]);
				}
			}
		}
	}

	if(n==3){
		repi(n){
			repj(n){
				if(i==j)continue;
				repk(n){
					if(i==k||j==k)continue;
					repe(6){
						repl(6){
							reps(6)S.insert(A[i][e]*100+A[j][l]*10+A[k][s]);
						}
					}
				}
			}
		}
	}

	repii(1,1000){
		if(!S.count(i)){
			cout<<i-1;
			return 0;
		}
	}
}

