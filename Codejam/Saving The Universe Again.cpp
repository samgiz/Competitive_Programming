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

int calculate(string p){
	int sum = 0, power = 1;
	for(auto i: p){
		if(i=='C')power<<=1;
		else sum+=power;
	}
	return sum;
}

int main(){
	// fastInputOutput;
	
	int t;
	cin>>t;
	for(int k=1; k<=t; k++){
		cout<<"Case #"<<k<<": ";
		int d;
		string p;
		cin>>d>>p;
		int ans = 0;
		while(true){
			if(calculate(p)<=d){
				cout<<ans<<endl; 
				break;
			}
			bool lg = true;
			for(int i=p.size()-2; i>=0; i--){
				if(p[i]=='C'&&p[i+1]=='S'){
					swap(p[i], p[i+1]);
					lg=false;
					ans++;
					break;
				}
			}
			if(lg){
				cout<<"IMPOSSIBLE"<<endl;
				break;
			}
		}
	}
}
