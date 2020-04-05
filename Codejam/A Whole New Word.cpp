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

int Chars[11][26];
bool Pos[11][26];
vector<string>Remaining;

int main(){
	fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";

		int n, l;
		cin>>n>>l;
		Remaining.clear();
		for(auto &i: Pos){
			for(auto &j: i)j=0;
		}
		string tp;
		fori(n){
			cin>>tp;
			Remaining.pb(tp);
		}
		fori(n){
			forj(l){
				Pos[j][Remaining[i][j]-'A']=1;
			}
		}
		string ans;
		fori(l){
			fori(26){
				forj(l){
					Chars[j][i]=0;
				}
			}
			fori(Remaining.size()){
				forj(l){
					Chars[j][Remaining[i][j]-'A']++;
				}
			}
			int m=-1;
			forj(26){
				if(!Pos[i][j])continue;
				if(m==-1||Chars[i][m]>Chars[i][j])m=j;
			}
			ans+=m+'A';
			// filter out all elements having character m in remaining
			vector<string>tp;
			for(auto &j: Remaining){
				if(j[i]==m+'A')tp.pb(j);
			}
			Remaining.swap(tp);
		}
		if(Remaining.size())cout<<'-'<<endl;
		else cout<<ans<<endl;
	}
}
