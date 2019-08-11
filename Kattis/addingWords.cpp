#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first

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
// #define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
	fastInputOutput;
	set<string>Defined;
	map<string, int>M;
	map<int, string>Lang;
	string command;
	while(cin>>command){
		if(command=="clear"){
			M.clear();
			Lang.clear();
			Defined.clear();
		}
		else if(command=="def"){
			string s;
			int n;
			cin>>s>>n;
			if(Defined.count(s)){
				Lang[M[s]]="";
			}
			M[s]=n;
			Lang[n]=s;
			Defined.insert(s);
		}
		else{
			bool lg=true;
			string tmp, full, c;
			cin>>tmp;
			full = tmp + " ";
			if(!Defined.count(tmp))lg=false;
			int s=M[tmp];
			while(true){
				cin>>c;
				full+=c+" ";
				if(c=="=") break;
				cin>>tmp;
				if(!Defined.count(tmp))lg=false;
				full+=tmp+" ";
				if(c=="+") s+=M[tmp];
				else s-=M[tmp];
			}
			cout<<full<<(lg&&Lang[s]!=""?Lang[s]:"unknown")<<endl;
		}
	}
}
