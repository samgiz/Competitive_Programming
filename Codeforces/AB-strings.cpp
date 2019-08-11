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

int main(){
	// fastInputOutput;
	string s, t;
	cin>>s>>t;
	vector<pii>Ops;

	// if both words start with the same letter, change that
	if(s[0]==t[0]){
		int a=s.size()-1, b=t.size()-1;
		int b1=0, b2=0;
		fori(s.size()-1)b1+=(s[i]!=s[i+1]);
		fori(t.size()-1)b2+=(t[i]!=t[i+1]);
		if(b1>b2){
			while(s[--a]==t[b]);
			Ops.pb(mp(a+1, b+1));
			string tp = s.substr(0, a+1);
			s = s.substr(a+1)+t;
			t = tp;
		}
		else{
			while(t[--b]==s[a]);
			Ops.pb(mp(a+1, b+1));
			string tp = t.substr(0, b+1);
			t = t.substr(b+1)+s;
			s = tp;
		}
	}cout<<s<<" "<<t<<endl;
	cerr<<'a'<<endl;
	// if the block sizes have a difference of >2, reduce that difference
	int b1=0, b2=0;
	fori(s.size()-1)b1+=(s[i]!=s[i+1]);
	fori(t.size()-1)b2+=(t[i]!=t[i+1]);
	cerr<<'b'<<endl;
	int a=0, b=0;
	if(b1>b2+1){
		cerr<<'c'<<endl;
		if(b2>1){
			b1++;
			b2--;
			while(t[++b]==t[0]);
		}
		cerr<<'d'<<endl;
		while(abs(b1-b2)>2){
			if(s[a]==s[++a])b1--, b2++;
		}
		cerr<<'e'<<endl;
		cerr<<a<<" "<<b<<endl;
		string tp = s.substr(0, a)+t.substr(b);
		cerr<<'f'<<endl;
		s = t.substr(0, b)+s.substr(a);
		cerr<<'g'<<endl;
		t = tp;
		cerr<<'h'<<endl;
	}
	else if(b2>b1+1){
		cerr<<'c'<<endl;
		if(b1>1){
			b2++;
			b1--;
			while(s[++a]==s[0]);
		}
		cerr<<'d'<<endl;
		while(abs(b1-b2)>2	){
			if(t[b]==t[++b])b1++, b2--;
		}
		cerr<<'e'<<endl;
		string tp = s.substr(0, a)+t.substr(b);
		cerr<<'f'<<endl;
		s = t.substr(0, b)+s.substr(a);
		cerr<<'g'<<endl;
		t = tp;
		cerr<<'h'<<endl;
	}
	a=s.size()-1, b=t.size()-1;
	int n = 0;

	// do either one or the other, not both
	if(s[a]=='b'){
		while(true){
			if(n%2){
				while(a>=0&&s[a]=='a'){
					a--;
				}
				while(b>=0&&t[b]=='b'){
					b--;
				}
				if(a==-1&&b==-1)break;
				Ops.pb(mp(b+1, a+1));
			}
			else{
				while(a>=0&&s[a]=='b'){
					a--;
				}
				while(b>=0&&t[b]=='a'){
					b--;
				}
				if(a==-1&&b==-1)break;
				Ops.pb(mp(a+1, b+1));
			}
			n++;
		}
	}
	else{
		while(true){
			if(n%2){
				while(a>=0&&s[a]=='b'){
					a--;
				}
				while(b>=0&&t[b]=='a'){
					b--;
				}
				if(a==-1&&b==-1)break;
				Ops.pb(mp(b+1, a+1));
			}
			else{
				while(a>=0&&s[a]=='a'){
					a--;
				}
				while(b>=0&&t[b]=='b'){
					b--;
				}
				if(a==-1&&b==-1)break;
				Ops.pb(mp(a+1, b+1));
			}
			n++;
		}
	}	
	cout<<Ops.size()<<endl;
	for(auto i: Ops){
		cout<<i.fi<<" "<<i.se<<endl;
	}

}
