#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first

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

int main(){
	// fastInputOutput;
	double root2=sqrt(2);
	ll n;
	cin>>n;
	n--;
	ll A[40];
	repi(n){
		cin>>A[i];
	}
	double P=0;
	ll S=(1<<30);
	double P1=1;
	repi(n){
		P1/=root2;
		if(S<=(1<<(29-i))*A[i]){
			P+=P1*(S/(1<<(29-i)));
			S=0;
			break;
		}
		else{
			S-=(1<<(29-i))*A[i];	
			P+=P1*A[i];
		}
	}
	if(S){
		cout<<"impossible";
	}
	else{
		cout<<setprecision(20)<<(P-1)*(1/sqrt(root2)/root2+1/sqrt(root2));
	}
}
