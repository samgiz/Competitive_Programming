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

int DP[1001][1001];

int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		// cerr<<s<<" a"<<endl;
		fori(s.size()){
			DP[i][i]=1;
			if(i)DP[i-1][i]=(s[i-1]==s[i])+1;
		}
		forii(2, s.size()){
			forj(s.size()-i){
				if(s[j]==s[j+i])DP[j][j+i]=DP[j+1][j+i-1]+2;
				else DP[j][j+i]=max(DP[j+1][j+i], DP[j][j+i-1]);
			}
		}
		// fori(s.size()){
		// 	forj(s.size())cerr<<DP[i][j]<<" ";cerr<<endl;
		// }
		cout<<DP[0][s.size()-1]<<endl;
	}
}
