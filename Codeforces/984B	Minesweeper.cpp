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

char A[101][101];
int n, m;

bool isBomb(int a, int b){
	return a>=0 && b>=0 && a<n && b<m && A[a][b] == '*';
}

int main(){
	// fastInputOutput;
	
	cin>>n>>m;
	fori(n){
		forj(m)cin>>A[i][j];
	}
	fori(n){
		forj(m){
			int t = 0;
			forkk(-1, 2){
				forll(-1, 2){
					if(k==0&&l==0)continue;
					t+=isBomb(i+k, j+l);
				}
			}
			if(A[i][j]=='*' || A[i][j]-'0' == t || A[i][j] == '.' && t==0)continue;
			cout<<"NO";
			exit(0);
		}
	}
	cout<<"YES";
}
