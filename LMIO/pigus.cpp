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
#define N 500001
struct Road{
	int a, b;
	ll c;
	Road(){}
	Road(int a, int b, ll c){
		this->a = a;
		this->b = b;
		this->c = c;
	}
	
};

bool operator<(const Road& r, const Road& q){
	return r.c < q.c;
}
ll pti(pii a){
	return ((ll)a.fi)*1000000+a.se;
}

pii itp(ll a){
	return mp(a%1000000, a/1000000);
}

ll Max[N], Joined[N], Cost[N];
unordered_map<ll, ll>M;

int main(){
	fastInputOutput;
	int n, m;
	cin>>n>>m;

	priority_queue<Road>Q;

	fori(m){
		int a, b;
		ll c;
		cin>>a>>b>>c;

		Q.push(Road(a, b, c));

		Max[a]+=c;
		Max[b]+=c;

		M[pti(mp(a, b))] = c;
		M[pti(mp(b, a))] = c;
	}

	ll ans = 0;
	fori(n+1)ans = max(ans, Max[i]);
	fori(n+1)Joined[i] = -1;

	while(Q.size()){
		Road t = Q.top();
		Q.pop();
		if(Joined[t.a] != -1){
			int k = Joined[t.a];
			ll tp = M[pti(mp(k, t.b))];
			if(tp)ans = max(Cost[k]+tp+M[pti(mp(t.a, t.b))], ans);
		}
		if(Joined[t.b] != -1){
			int k = Joined[t.b];
			ll tp = M[pti(mp(k, t.a))];
			if(tp)ans = max(tp+Cost[k]+M[pti(mp(t.a, t.b))], ans);
		}
		if(Joined[t.a] == -1 && Joined[t.b] == -1){
			Joined[t.a] = t.b;
			Joined[t.b] = t.a;
			Cost[t.a]=t.c;
			Cost[t.b]=t.c;
		}
	}
	cout<<ans;
}
