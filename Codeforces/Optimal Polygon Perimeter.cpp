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

ll X[N], Y[N];

ll maxi(ll a, ll b, ll c){
	// cerr<<a<<" "<<b<<" "<<c<<endl;
	return abs(X[a]-X[b])+abs(X[a]-X[c])+abs(X[b]-X[c])+abs(Y[a]-Y[b])+abs(Y[a]-Y[c])+abs(Y[b]-Y[c]);
}

int main(){
	fastIO;
	ll n;
	cin>>n;
	ll mx=1e8, Mx=-1e8, my=1e8, My=-1e8, mxi=0, Mxi=0, myi=0, Myi=0;
	fori(n){
		cin>>X[i]>>Y[i];
	}
	fori(n){
		if(X[i]<mx){
			mxi = i;
			mx = min(X[i], mx);
		}
		if(Y[i]<my){
			myi = i;
			my = min(Y[i], my);
		}
		if(X[i]>Mx){
			Mxi = i;
			Mx = max(X[i], Mx);
		}
		if(Y[i]>My){
			Myi = i;
			My = max(Y[i], My);
		}
	}
	// cerr<<'a'<<endl;
	ll ans = (Mx-mx)*2+(My-my)*2;
	// cerr<<'a'<<endl;
	ll k = 0;
	fori(n){ 
		k = max(k, maxi(mxi, myi, (ll) i));
	}
	fori(n){ 
		k = max(k, maxi(Mxi, myi, (ll) i));
	}
	fori(n){ 
		k = max(k, maxi(mxi, Myi, (ll) i));
	}
	fori(n){ 
		k = max(k, maxi(Mxi, Myi, (ll) i));
	}
	cout<<k<<" ";
	fori(n-3){
		cout<<ans<<" ";
	}
}
