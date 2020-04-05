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

ll W[100001];
ll DP[100001];
ll Top[100001];

int main(){
	fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		ll n;
		cin>>n;
		ll ct=1;
		fori(n)cin>>W[i];
		DP[1]=W[0];
		Top[1]=W[0];
		forii(1, n){
			bool lg = DP[ct]<=W[i]*6;
			if(lg){
				DP[ct+1] = DP[ct]+W[i];
				Top[ct+1] = W[i];
			}

			for(int j=ct-1; j>=0; j--){
				if(DP[j]+W[i]<DP[j+1] && 6*W[i]>=DP[j]){
					DP[j+1]=DP[j]+W[i];
					Top[j+1]=W[i];
				}
			}

			ct+=lg;
		}

		cout<<ct<<endl;
	}
}
