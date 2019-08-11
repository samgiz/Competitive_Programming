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
#define forf(a) for(def f=0; f<(a); f++)
#define forff(a, b) for(def f=(a); f<(b); f++)
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

char A[20][20];
int n, m;

bool valid(int a, int b){
	return a>=0&&b>=0&&a<n&&b<m&&A[a][b]=='G';
}

int main(){
	// fastInputOutput;
	
	cin>>n>>m;
	fori(n){
		forj(m)cin>>A[i][j];
	}

	int ans = 0;
	fori(n){
		fork(m){
			fore(20){
				if(!valid(i+e, k)||!valid(i-e, k)||!valid(i, k-e)||!valid(i, k+e))break;
				forj(n){
					forl(m){
						forf(20){
							if(!valid(j+f, l)||!valid(j-f, l)||!valid(j, l-f)||!valid(j, l+f)||(abs(i-j)<=e&&abs(k-l)<=f)||(abs(i-j)<=f&&abs(k-l)<=e)||(abs(i-j)==0&&abs(k-l)<=e+f)||(abs(i-j)<=f+e&&abs(k-l)==0))break;
							if(ans<(1+4*e)*(1+4*f)) cerr<<i<<" "<<k<<" "<<e<<"   "<<j<<" "<<l<<" "<<f<<endl;
							ans = max(ans, (1+4*e)*(1+4*f));
						}
					}
				}
			}
		}
	}
	cout<<ans;
}
