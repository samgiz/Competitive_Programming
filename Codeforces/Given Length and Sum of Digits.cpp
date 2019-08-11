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

int main(){
	// fastInputOutput;
	int l, s;
	cin>>l>>s;
	if(l==1&&s==0){
		cout<<0<<" "<<0;
		exit(0);
	}
	if(l*9<s||s==0){
		cout<<-1<<" "<<-1;
		exit(0);
	}

	int cp = s;
	fori(l){
		if((l-1)*9+1>=cp && i==0){
			cout<<1;
			cp--;
		}
		else if((l-i-1)*9>=cp)cout<<0;
		else if(cp%9){
			cout<<cp%9;
			cp-=cp%9;
		}
		else cout<<9;
	}
	cout<<endl;
	cp = s;
	fori(l){
		if(cp>9){
			cout<<9;
			cp-=9;
		}
		else{
			cout<<cp;
			cp=0;
		}
	}
}
