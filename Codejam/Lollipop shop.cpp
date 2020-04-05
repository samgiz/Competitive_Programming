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
// #define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int A[200];
bool Taken[200];
int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		int n;
		cin>>n;
		for(auto &i: A)i=0;
		for(auto &i: Taken)i=0;
		
		fori(n){
			vector<int> Choices;
			int k;
			cin>>k;
			forj(k){
				int tp;
				cin>>tp;
				A[tp]++;
				if(Taken[tp])continue;
				if(Choices.empty()||A[Choices[0]]==A[tp])Choices.pb(tp);
				else if(A[Choices[0]]>A[tp])Choices.clear(), Choices.pb(tp);
			}
			
			if(Choices.empty())cout<<-1<<endl;
			else{
				int ind = rand()%Choices.size();
				cout<<Choices[ind]<<endl;
				Taken[Choices[ind]]=1;
			}
		}
	}
}

