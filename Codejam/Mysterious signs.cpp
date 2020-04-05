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

const int S = 100001;
int D[S], A[S], B[S];

int main(){
	fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";

		int n;
		cin>>n;
		fori(n)cin>>D[i]>>A[i]>>B[i];
		vector<int>C, E;
		int cur=1;
		fori(n-1){
			if(D[i]+A[i]!=D[i+1]+A[i+1]){
				C.pb(cur);
				cur=1;
			}
			else cur++;
		}
		C.pb(cur);
			cur=1;
		fori(n-1){
			if(D[i]-B[i]!=D[i+1]-B[i+1]){
				E.pb(cur);
				cur=1;
			}
			else cur++;
		}
		E.pb(cur);
		// for(auto i: C)cerr<<i<<" ";cerr<<" aaa \n";
		// for(auto i: E)cerr<<i<<" ";cerr<<" bbb \n";
		

		// C always has the smaller cumulative element
		if(C[0]>E[0])C.swap(E);
		int ans=E[0], cnt=1;
		// initialize correctly
		int sum1=0, sum2=E[0], ct1=0, ct2=1, last=0;

		while(ct1<C.size()){
			while(ct1<C.size()&&sum1<=sum2){
				sum1+=C[ct1++];
			}

			if(ans==sum1-last&&sum1!=sum2)cnt++;
			else if(ans<sum1-last)cnt=1, ans=sum1-last;
			// cerr<<ans<<" "<<ct1<<" "<<ct2<<" "<<test<<endl;
			
			last=sum1-C[ct1-1];

			// swap vectors and values associated with them
			C.swap(E);
			swap(ct1, ct2);
			swap(sum1, sum2);
		}

		cout<<ans<<" "<<cnt<<endl;
	}
}
