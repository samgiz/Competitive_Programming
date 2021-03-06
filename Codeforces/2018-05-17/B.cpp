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

pii Intro[200001];
int main(){
	fastInputOutput;
	stack<int> Extro;
	int n;
	cin>>n;
	fori(n){
		cin>>Intro[i].fi;
		Intro[i].se = i+1;
	}
	sort(Intro, Intro+n);
	int cnt = 0;
	fori(2*n){
		char c;
		cin>>c;
		if(c=='0'){
			Extro.push(Intro[cnt].se);
			cout<<Intro[cnt++].se<<" ";
		}
		else{
			cout<<Extro.top()<<" ";
			Extro.pop();
		}
	}
}
