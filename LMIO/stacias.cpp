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
typedef unsigned long long ull;

#define K 100001

ll n;
ll L[K], R[K];
set<ll> s;

set<ll>Ans;

bool create(ll a, ll b){
	if(a == 1){
		ll sum = 0;
		for(auto i: s)
			sum+=i;
		return sum == b;
	}

	if(!s.count(a))return false;
	s.erase(a);
	return create(b-1, a);
}

void Dfs(ll a, ll b, ll mask){
	if(mask == (1<<n)-1)Ans.insert(b);
	for(int i=0; i<n; i++){
		if(mask&(1<<i))continue;
		if(L[i] == a){
			Dfs(max(a, b+R[i]), min(a, b+R[i]), mask|(1<<i));
		}
		if(L[i] == b){
			Dfs(max(b, a+R[i]), min(b, a+R[i]), mask|(1<<i));
		}
		if(R[i] == a){
			Dfs(max(a, b+L[i]), min(a, b+L[i]), mask|(1<<i));
		}
		if(R[i] == b){
			Dfs(max(b, a+L[i]), min(b, a+L[i]), mask|(1<<i));
		}
	}
}

int main(){
	fastInputOutput;
	
	cin>>n;
	ll area = 0;
	bool all1s = true;
	fori(n){
		cin>>L[i]>>R[i];
		if(R[i]!=1)all1s=false;
		area += L[i]*R[i];
	}
	if(all1s){
		Ans.insert(1);
		
		fori(n)s.insert(L[i]);
		if(area%L[n-1] == 0 && create(L[n-1], area/L[n-1]))
			Ans.insert(min(area/L[n-1], L[n-1]));

		fori(n)s.insert(L[i]);
		if(area%(L[n-1]+1) == 0 && create(area/(L[n-1]+1), (L[n-1]+1)))
			Ans.insert(min(area/(L[n-1]+1), L[n-1]+1));
s
	}
	else {fori(n){
		Dfs(L[i], R[i], 1<<i);
	}}
	cout<<Ans.size()<<endl;
	for(auto i: Ans)cout<<i<<endl;
}
