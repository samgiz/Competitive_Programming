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

int A[4][4];

int bits(int i)
{
	int ans=0;
    while(i){
    	ans+=i&1;
    	i>>=1;
    }
    return ans;
}

int main(){
	fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		int n;
		cin>>n;
		fori(n){
			forj(n){
				cin>>A[i][j];
			}
		}
		int ans = n*n-1;
		fori(1<<(n*n)){
			bool lg = 1;
			fork(n){
				forj(n){
					if((1<<(k*n+j))&i)continue;
					forl(n){
						if(((1<<(l*n+j))&i)==0 && l!=k && A[l][j]==A[k][j])lg=0;
					}
					forl(n){
						if(((1<<(k*n+l))&i)==0 && l!=j && A[k][l]==A[k][j])lg=0;
					}
				}
			}
			if(lg){
				// cerr<<bitset<4>(i)<<endl;
				ans = min(ans, bits(i));
			}
		}
		cout<<ans<<endl;
	}
}
	