#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef int def; //default parameter for loops

#define fori(a) for(def i=0; i<(a); i++)
#define fori1(a) for(def i=1; i<=(a); i++)
#define fori_(a) for(def i=(a)-1; i>=0; i--)
#define fori1_(a) for(def i=(a); i>0; i--)
#define forii(a, b) for(def i=(a); i<(b); i++)
#define forii_(a, b) for(def i=(b)-1; i>=(a); i--)

#define forj(a) for(def j=0; j<(a); j++)
#define forj1(a) for(def j=1; j<=(a); j++)
#define forj_(a) for(def j=(a)-1; j>=0; j--)
#define forj1_(a) for(def j=(a); j>0; j--)
#define forjj(a, b) for(def j=(a); j<(b); j++)
#define forjj_(a, b) for(def j=(b)-1; j>=(a); j--)

#define fork(a) for(def k=0; k<(a); k++)
#define fork1(a) for(def k=1; k<=(a); k++)
#define fork_(a) for(def k=(a)-1; k>=0; k--)
#define fork1_(a) for(def k=(a); k>0; k--)
#define forkk(a, b) for(def k=(a); k<(b); k++)
#define forkk_(a, b) for(def k=(b)-1; k>=(a); k--)

#define forl(a) for(def l=0; l<(a); l++)
#define forl1(a) for(def l=1; l<=(a); l++)
#define forl_(a) for(def l=(a)-1; l>=0; l--)
#define forl1_(a) for(def l=(a); l>0; l--)
#define forll(a, b) for(def l=(a); l<(b); l++)
#define forll_(a, b) for(def l=(b)-1; l>=(a); l--)

#define forg(a) for(def g=0; g<(a); g++)
#define forg1(a) for(def g=1; g<=(a); g++)
#define forg_(a) for(def g=(a)-1; g>=0; g--)
#define forg1_(a) for(def g=(a); g>0; g--)
#define forgg(a, b) for(def g=(a); g<(b); g++)
#define forgg_(a, b) for(def g=(b)-1; g>=(a); g--)

#define forf(a) for(def f=0; f<(a); f++)
#define forf1(a) for(def f=1; f<=(a); f++)
#define forf_(a) for(def f=(a)-1; f>=0; f--)
#define forf1_(a) for(def f=(a); f>0; f--)
#define forff(a, b) for(def f=(a); f<(b); f++)
#define forff_(a, b) for(def f=(b)-1; f>=(a); f--)

#define forh(a) for(def h=0; h<(a); h++)
#define forh1(a) for(def h=1; h<=(a); h++)
#define forh_(a) for(def h=(a)-1; h>=0; h--)
#define forh1_(a) for(def h=(a); h>0; h--)
#define forhh(a, b) for(def h=(a); h<(b); h++)
#define forhh_(a, b) for(def h=(b)-1; h>=(a); h--)

#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
  }
  return out;
}
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::set<T>& v) {
  if ( !v.empty() ) {
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
  }
  return out;
}

const int N = 3e5+10;
const ll M = 1e9+7;

int Par[N], Sz[N];
ll C[N];
struct tres{
	int a, b, c;
};

tres T[N];

vpii E[N];
ll Am[N];
int n, m;

int parent(int n){
	if(Par[n] == n)return n;
	return Par[n] = parent(Par[n]);
}

void recurse(int cur, int last){
	Am[cur] = 1;
	for(auto i: E[cur]){
		int next  = i.fi;
		int w = i.se;
		if(next == last)continue;
		recurse(next, cur);
		Am[cur] += Am[next];
		// cerr<<cur<<" "<<next<<" "<<Am[next]*(n-Am[next])<<endl;
		C[w] += Am[next]*(n-Am[next]);
	}
}

int main(){
	fastIO;
	
	cin>>n>>m;
	fori1(n)Par[i] = i;
	fori1(n)Sz[i] = 1;
	fori(m){
		cin>>T[i].a>>T[i].b>>T[i].c;
	}
	sort(T, T+m, [](tres a, tres b){return a.c < b.c;});
	fori(m){
		int a = parent(T[i].a);
		int b = parent(T[i].b);
		int c = T[i].c;
		if(a == b) continue;
		if(Sz[a] > Sz[b]){
			Sz[a] += Sz[b];
			Par[b] = a;
		}
		else{
			Sz[b] += Sz[a];
			Par[a] = b;
		}
		E[T[i].a].pb({T[i].b, T[i].c});
		E[T[i].b].pb({T[i].a, T[i].c});
	}
	int start = 0;
	fori1(n){
		if(E[i].size()==1){
			start = i;
			break;
		}
	}
	// cerr<<start<<" "<<endl;
	recurse(start, 0);
	// fori(10)cerr<<C[i]<<" ";cerr<<endl;
	fori(N){
		C[i+1] += C[i]/2;
		C[i] %= 2;
	}
	bool f = false;
	fori_(N){
		// cerr<<i<<endl;
		if(f || C[i]){
			f = true;
			cout<<C[i];
		}
	}
}
