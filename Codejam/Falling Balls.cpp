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

int B[101];
int ct = 0;
int next(){
	while(B[ct]==0)ct++;
	B[ct]--;
	return ct;
}

char Ans[101][101];
int main(){
	fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		ct=0;
		fori(101){
			forj(101){
				Ans[i][j]='.';
			}
		}
		cout<<"Case #"<<test<<": ";
		int n;
		int dis = 0;
		cin>>n;
		fori(n)cin>>B[i];
		if(B[0]==0 || B[n-1]==0){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		fori(n){
			int k = next();
			dis = max(dis, abs(k-i));
			forl(abs(k-i)){
				if(k<i)Ans[l][i-l]='/';
				else Ans[l][i+l]='\\';
			}
		}

		cout<<dis+1<<endl;
		fori(dis+1){
			forj(n){
				cout<<Ans[i][j];
			}cout<<endl;
		}
	}
}
