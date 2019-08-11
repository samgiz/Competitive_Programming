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

const int N = 2e5+10;
const ll M = 1e9+7;

int n, k, m;
ll ans = 0;
struct Node{
	ll am=0, l=0, r=0, sum=0;
};
struct Change{
	ll pt, c, p;
};

Node T[4000100];
Change add[N], sub[N];


void update(ll cur, ll l, ll r, ll target, ll amount){
	// //cerr<<cur<<" a"<<endl;
	T[cur].sum += target*amount;
	T[cur].am += amount;
	//cerr<<l<<" "<<r<<" "<<T[cur].am<<" "<<T[cur].sum<<endl;
	if(l+1==r)return ;
	if(target<(l+r)/2)update(cur*2, l, (l+r)/2, target, amount);
	else update(cur*2+1, (l+r)/2, r, target, amount);
}

ll getPrice(ll cur, ll l, ll r, ll amount){
	//cerr<<l<<" "<<r<<" "<<amount<<endl;
	if(amount<=0)return 0;
	if(l+1==r)return l*min(amount, T[cur].am);
	if(T[cur].am <= amount) return T[cur].sum;
	ll a = getPrice(cur*2, l, (l+r)/2, amount), b = getPrice(cur*2+1, (l+r)/2, r, amount-T[cur*2].am);
	//cerr<<a<<" "<<b<<endl;
	return a+b;
}

int main(){
	fastIO;
	ifstream cin("tp.out");
	cin>>n>>k>>m;
	fori(m){
		cin>>add[i].pt>>sub[i].pt>>add[i].c>>add[i].p;
		sub[i].c=add[i].c;
		sub[i].p=add[i].p;
	}
	sort(add, add+m, [](Change a, Change b){return a.pt<b.pt;});
	sort(sub, sub+m, [](Change a, Change b){return a.pt<b.pt;});
	int ca = 0, cb = 0;
	// cerr<<ca<<" "<<cb<<" "<<n<<k<<" "<<m<<" "<<endl;
	fori1(n){
		// cerr<<i<<endl;
		//cerr<<i<<" a"<<endl;
		while(ca<m && add[ca].pt == i){
			//cerr<<add[ca].pt<<" add"<<endl;
			update(1, 1, 1000001, add[ca].p, add[ca].c);
			ca++;
		}
		//cerr<<" getPrice"<<endl;
		ans += getPrice(1, 1, 1000001, k);
		// cerr<<i<<" "<<getPrice(1, 1, 1000001, 1)<<endl;
		while(cb<m && sub[cb].pt == i){
			//cerr<<add[ca].pt<<" subtract"<<endl;
			update(1, 1, 1000001, sub[cb].p, -sub[cb].c);
			cb++;
		}
		//cerr<<endl;
	}
	cout<<ans<<endl;
}
