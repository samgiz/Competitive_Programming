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

int cur[26];

struct Anagram{
	int A[26];
	Anagram(){
		fori(26)A[i]=cur[i];
	}
	bool operator<(const Anagram &rhs) const {
	    fori(26){
	    	if(A[i]!=rhs.A[i])return A[i]<rhs.A[i];
	    }
		return false;
	}
};

map<Anagram, ll>M;

int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	while(t--){
		string s;
		ll ans=0;
		cin>>s;
		forii(1, s.size()){
			M.clear();
			forj(26)cur[j]=0;
			forj(i-1)cur[s[j]-'a']++;
			forjj(i-1, s.size()){
				cur[s[j]-'a']++;
				M[Anagram()]++;
				cur[s[j-i+1]-'a']--;
			}
			for(auto &i: M){
				ans+=i.se*(i.se-1)/2;
			}
		}
		cout<<ans<<endl;
	}
}
