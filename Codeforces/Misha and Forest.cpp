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

const int N = 100001;

int Xor[N], Deg[N];

vpii Ans;

int main(){
	// fastInputOutput;

	queue<int>Leafs;
	int n;
	cin>>n;
	fori(n){
		cin>>Deg[i]>>Xor[i];
		if(Deg[i]==1)Leafs.push(i);
	}
	while(Leafs.size()){
		int f = Leafs.front();
		Leafs.pop();
		if(Deg[f]==0)continue;
		Ans.pb(mp(f, Xor[f]));
		Xor[Xor[f]]^=f;
		Deg[Xor[f]]--;
		if(Deg[Xor[f]]==1)Leafs.push(Xor[f]);
	}
	cout<<Ans.size()<<endl;
	for(auto i: Ans)cout<<i.fi<<" "<<i.se<<endl;
}
