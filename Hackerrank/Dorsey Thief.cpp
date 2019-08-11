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

struct Person{
	ll w, p;
};
Person A[1000001];
ll Max[5001];

int main(){
	fastInputOutput;
	int n, x;
	cin>>n>>x;
	fori(n)cin>>A[i].p>>A[i].w;
	forii(1, x+1)Max[i]=-1;
	fori(n){
		for(int j=x-A[i].w; j>=0; j--){
			if(Max[j]==-1)continue;
			Max[A[i].w+j]=max(Max[A[i].w+j], Max[j]+A[i].p);
		}
	}
    if(Max[x]!=-1)cout<<Max[x];
    else cout<<"Got caught!";
}
