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
#define repll(a, b) for(def l=(a); l<(b); l++)

#define fastInputOutput ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

struct tres{
	ll fi, se, th; // city1, city2, cost
	tres(){}
	tres(ll d, ll e, ll f){
		fi=d;se=e;th=f;
	}
};

ll Rank[100001], Par[100001];

int parent(int i){
	if(Par[i]==i)return i;
	return Par[i]=parent(Par[i]);
}

void join(tres road){
	int a = parent(road.fi);
	int b = parent(road.se);
	// if(a==b)continue;
	if(Rank[a]>=Rank[b]){
		Rank[a]+=Rank[b];
		Par[b]=a;
	}
	else{
		Rank[b]+=Rank[a];
		Par[a]=b;
	}
}

int main(){
	// fastInputOutput;
	ifstream cin("mootube.in");
	ofstream cout("mootube.out");
	
	

	int n, q;
	cin>>n>>q;

	vector<tres>Roads, Qs;
	vpll Ans;


	repi(n+1)Par[i]=i, Rank[i]=1;

	ll a, b, c;
	repi(n-1){
		cin>>a>>b>>c;
		Roads.pb(tres(a, b, c));
	}

	sort(Roads.begin(), Roads.end(), [](tres a, tres b){return a.th>b.th;});

	repi(q){
		cin>>a>>b;
		Qs.pb(tres(i, a, b));
	}
	sort(Qs.begin(), Qs.end(), [](tres a, tres b){return a.se>b.se;});
	int cnt=0;
	for(auto q : Qs){
		// cerr<<q.fi<<" "<<q.se<<" "<<q.th<<" "<<Roads[cnt].th<<endl;
		while(cnt<n-1 && q.se<=Roads[cnt].th){
			// cerr<<q.fi<<" "<<cnt<<endl;
			join(Roads[cnt++]);
		}

		Ans.pb(mp(q.fi, Rank[parent(q.th)]-1));
	}
	sort(Ans.begin(), Ans.end());
	for(auto i : Ans)cout<<i.se<<endl;
}
