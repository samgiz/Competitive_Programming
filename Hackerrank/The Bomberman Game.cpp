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

char A[300][300], B[300][300];

int main(){
	// fastInputOutput;
	int r, c, n;
	cin>>r>>c>>n;
	fori(r){
		forj(c)cin>>A[i][j];
	}
	if(n>4)n=n%4+4;
	if(n%2==0){
		fori(r){
			forj(c)cout<<'O';cout<<endl;
		}
		exit(0);
	}
	n/=2;
	fori(n){
		fori(r){
			forj(c)B[i][j]='O';
		}
		fori(r){
			forj(c){
				if(A[i][j]=='O'){
					B[i][j]='.';
					if(i-1>=0)B[i-1][j]='.';
					if(j-1>=0)B[i][j-1]='.';
					if(i+1<r)B[i+1][j]='.';
					if(j+1<c)B[i][j+1]='.';
				}
			}
		}
		fori(r){
			forj(c)A[i][j]=B[i][j];
		}
	}
	fori(r){
		forj(c)cout<<A[i][j];cout<<endl;
	}
}
