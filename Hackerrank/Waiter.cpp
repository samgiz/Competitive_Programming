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

const int Q = 1300;
const int N = 50001;

vi Primes;

vi B[N], A;

bool isPrime(int a){
	for(auto &i: Primes){
		if(a%i==0)return false;
	}
	return true;
}

int main(){
	// fastInputOutput;
	int p = 2;
	while(Primes.size()<Q){
		// cerr<<Primes.size()<<endl;
		if(isPrime(p))Primes.pb(p);
		p++;
	}
	int n, q;
	cin>>n>>q;
	while(n--){
		// cerr<<n<<" ";
		int a;
		cin>>a;
		int lg = false;
		fori(q){
			if(a%Primes[i]==0){
				B[i].pb(a), lg = true;
				break;
			}
		}
		if(!lg)A.pb(a);
	}
	// cerr<<Primes[0]<<endl;
	fori(Q){
		if(B[i].size()==0)continue;
		if(i%2==0){
			for(auto j: B[i])cout<<j<<endl;
		}
		else{
			for(int j = B[i].size()-1; j>=0; j--)cout<<B[i][j]<<endl;
		}
	}
	if(q%2){
		for(auto j: A)cout<<j<<endl;
	}
	else{
		for(int j = A.size()-1; j>=0; j--)cout<<A[j]<<endl;
	}
}
