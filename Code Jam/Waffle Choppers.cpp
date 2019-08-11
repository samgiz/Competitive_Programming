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
string s[102];
int R[102], C[102];
vector<int>RC, CC, RF, CF;//row cut, column cut
int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		int r, c, h, v;
		cin>>r>>c>>h>>v;
		RC.clear();
		CC.clear();
		CF.clear();RF.clear();
		RC.pb(0);
		CC.pb(0);
		CF.pb(0);RF.pb(0);
		fori(r)cin>>s[i];
		int sum=0;
		fori(r){
			forj(c){
				sum+=s[i][j]=='@';
			}
		}
		C[0]=0;
		forii(1, c+1){
			C[i]=C[i-1];
			forj(r)C[i]+=s[j][i-1]=='@';
		}
		int last = 0;
		bool lg = true;
		if(sum%(h+1)||sum%(v+1)||v+1>c||h+1>r)lg = false;
		fori(c+1){
			if(C[i]-last >= sum/(h+1)){
				CC.pb(i);
				last=C[i];
			}
		}

		last = 0;
		forkk(1, CC.size()){
			R[0]=0;
			if(CC.size()>1){
				forii(1, r+1){
					R[i]=R[i-1];
					forjj(CC[k-1], CC[k])R[i]+=s[i-1][j]=='@';
					if(R[i]-last==0)RF[i-]
					if(R[i]-last >= sum/(h+1)/(v+1)){
						RC.pb(i);
						RF.pb(i);
						last=R[i];
					}
				}
			}
		}
		for(auto i: RC)cerr<<i<<" ";cerr<<endl;
		for(auto i: CC)cerr<<i<<" ";cerr<<endl;	
		if(RC.size()!=h+2||CC.size()!=v+2)lg=false;
		if(lg){
			cerr<<"HEY"<<endl;
			forii(1, RC.size()){
				cerr<<i<<endl;
				forjj(1, CC.size()){
					cerr<<" "<<j<<endl;
					int cnt=0;
					forkk(RC[i-1], RC[i]){
						forll(CC[j-1], CC[j]){
							if(i==2&&j==1&&s[k][l]=='@')cerr<<k<<" "<<l<<endl;
							cnt+=s[k][l]=='@';
						}
					}
					cerr<<RC[i-1]<<CC[j-1]<<RC[i]<<CC[j]<<cnt<<endl;
					if(cnt!=sum/(h+1)/(v+1))
						lg=false;
				}
			}
		}
		if(lg){
			cout<<"POSSIBLE"<<endl;
		}
		else cout<<"IMPOSSIBLE"<<endl;
	}

}
