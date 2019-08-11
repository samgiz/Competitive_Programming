#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

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
typedef vector<long long> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


vi Tun[100001];
char Visited[100001];
queue<int> farmers, bessies;

int main(){
	// fastInputOutput;
	ifstream cin("atlarge.in");
	ofstream cout("atlarge.out");

	int n, k;
	cin>>n>>k;
	
	repi(n-1){
		int a, b;
		cin>>a>>b;
		Tun[a].pb(b);
		Tun[b].pb(a);
	}

	// if Bessie is at an exit, she will be caught by one farmer at that exit
	if(Tun[k].size()==1){
		cout<<1;
		return 0;
	}
	
	repi(n+1){
		if(Tun[i].size()==1){
			farmers.push(i);
			Visited[i]='F';
		}
	}

	bessies.push(k);
	Visited[k]='B';

	int ans = 0;

	while(bessies.size()){
		int s=farmers.size();
		for(int i=0; i<s; i++){
			int f = farmers.front();
			farmers.pop();

			for(auto i : Tun[f]){
				if(Visited[i])continue;
				Visited[i]='F';
				farmers.push(i);
			}
		}
		s=bessies.size();
		for(int i=0; i<s; i++){
			int f = bessies.front();
			bessies.pop();

			for(auto i : Tun[f]){
				if(Visited[i]=='B')continue;
				if(Visited[i]=='F'){
					// cerr<<i<<" e"<<endl;
					++ans; 
					continue;
				}
				// cerr<<i<<" f"<<endl;
				Visited[i]='B';
				bessies.push(i);
			}
		}
	}

	cout<<ans<<endl;
}
