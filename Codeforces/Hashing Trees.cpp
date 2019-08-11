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

int A[100001], Fst[100001], snd;
vi A1, A2;

int main(){
	fastInputOutput;
	int h;
	cin>>h;
	fori(h+1)cin>>A[i];
	int k = -1;
	fori(h){
		if(A[i]>1&&A[i+1]>1){
			k=i+1; break;
		}
	}
	if(k==-1){
		cout<<"perfect";
		exit(0);
	}
	for(auto &i: Fst)i=-1;
	Fst[0]=1;
	A1.pb(0), A2.pb(0);
	int cur = 1;
	forii(2,200001){
		if(A[cur]==0)cur++;
		if(cur==h+1)break;
		A[cur]--;
		// cerr<<cur<<" "<<i<<endl;
		A1.pb(Fst[cur-1]);
		if(cur == k && Fst[cur]!=-1 && snd!=i-1)A2.pb(snd);
		else A2.pb(Fst[cur-1]);
		if(Fst[cur]==-1)Fst[cur]=i;
		else snd = i;
	}
	cout<<"ambiguous"<<endl;
	for(auto i: A1)cout<<i<<" ";cout<<endl;
	for(auto i: A2)cout<<i<<" ";cout<<endl;
	cerr<<Fst[1];
}
