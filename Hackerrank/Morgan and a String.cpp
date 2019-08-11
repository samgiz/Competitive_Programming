#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef int def; //default parameter for loops

#define fori(a) for(def i=0; i<(a); i++)
#define fori1(a) for(def i=1; i<=(a); i++)
#define fori_(a) for(def i=(a)-1; i>=0; i--)
#define fori1_(a) for(def i=(a); i>0; i--)
#define forii(a, b) for(def i=(a); i<(b); i++)
#define forii_(a, b) for(def i=(b)-1; i>=(a); i--)

#define forj(a) for(def j=0; j<(a); j++)
#define forj1(a) for(def j=1; j<=(a); j++)
#define forj_(a) for(def j=(a)-1; j>=0; j--)
#define forj1_(a) for(def j=(a); j>0; j--)
#define forjj(a, b) for(def j=(a); j<(b); j++)
#define forjj_(a, b) for(def j=(b)-1; j>=(a); j--)

#define fork(a) for(def k=0; k<(a); k++)
#define fork1(a) for(def k=1; k<=(a); k++)
#define fork_(a) for(def k=(a)-1; k>=0; k--)
#define fork1_(a) for(def k=(a); k>0; k--)
#define forkk(a, b) for(def k=(a); k<(b); k++)
#define forkk_(a, b) for(def k=(b)-1; k>=(a); k--)

#define forl(a) for(def l=0; l<(a); l++)
#define forl1(a) for(def l=1; l<=(a); l++)
#define forl_(a) for(def l=(a)-1; l>=0; l--)
#define forl1_(a) for(def l=(a); l>0; l--)
#define forll(a, b) for(def l=(a); l<(b); l++)
#define forll_(a, b) for(def l=(b)-1; l>=(a); l--)

#define forg(a) for(def g=0; g<(a); g++)
#define forg1(a) for(def g=1; g<=(a); g++)
#define forg_(a) for(def g=(a)-1; g>=0; g--)
#define forg1_(a) for(def g=(a); g>0; g--)
#define forgg(a, b) for(def g=(a); g<(b); g++)
#define forgg_(a, b) for(def g=(b)-1; g>=(a); g--)

#define forf(a) for(def f=0; f<(a); f++)
#define forf1(a) for(def f=1; f<=(a); f++)
#define forf_(a) for(def f=(a)-1; f>=0; f--)
#define forf1_(a) for(def f=(a); f>0; f--)
#define forff(a, b) for(def f=(a); f<(b); f++)
#define forff_(a, b) for(def f=(b)-1; f>=(a); f--)

#define forh(a) for(def h=0; h<(a); h++)
#define forh1(a) for(def h=1; h<=(a); h++)
#define forh_(a) for(def h=(a)-1; h>=0; h--)
#define forh1_(a) for(def h=(a); h>0; h--)
#define forhh(a, b) for(def h=(a); h<(b); h++)
#define forhh_(a, b) for(def h=(b)-1; h>=(a); h--)

#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
  }
  return out;
}
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::set<T>& v) {
  if ( !v.empty() ) {
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
  }
  return out;
}



const int N = 1e5+10;
const ll M = 1e9+7;

vector<pair<char, int>> A, B, Ans;

int main(){
	fastIO;
	int t;
	cin>>t;
	while(t--){
		string a, b;
		cin>>a>>b;
		// cerr<<a<<" "<<b<<endl;
		int ct = 0, last = a[0];
		A.clear(), B.clear(), Ans.clear();
		fori(a.size()){
			if(last == a[i])ct++;
			else A.pb(mp(a[i-1], ct)), last = a[i], ct=1;
		}
		A.pb(mp(a[a.size()-1], ct)), ct=0, last = b[0];
		fori(b.size()){
			if(last == b[i])ct++;
			else B.pb(mp(b[i-1], ct)), last = b[i], ct=1;
		}
		B.pb(mp(b[b.size()-1], ct)), ct=0;


		int c1=0, c2=0;
		while(c1<A.size()&&c2<B.size()){
			// cerr<<c1<<" "<<c2<<endl;
			if(A[c1].fi!=B[c2].fi){
				// this is incorrect, I need to look at the one coming afterwards
				if(A[c1].fi < B[c2].fi)Ans.pb(A[c1++]);
				else Ans.pb(B[c2++]);
				continue;
			}
			ct = 0;
			while(c1+ct<A.size() && c2+ct<B.size() && A[c1+ct] == B[c2+ct] 
				&& (ct==0 || A[c1+ct] < A[c1]))ct++;
				// cerr<<ct<<endl;
			// cerr<<c1<<" "<<c2<<" "<<ct<<endl;
			// logic of which side to pick goes here
			if(c1+ct==A.size()){
				// take from b
				fori(ct)Ans.pb(B[c2++]);
			}
			else if(c2+ct==B.size()){
				// take from a
				fori(ct)Ans.pb(A[c1++]);
			}
			else if(A[c1+ct] > A[c1]){
				// we have encountered an element that is larger than the original, so it does not matter which stack we start with.
				fori(ct)Ans.pb(B[c2++]);
			}
			else if(B[c2+ct] > A[c1]){
				// we have encountered an element that is larger than the original, so it does not matter which stack we start with.
				fori(ct)Ans.pb(A[c1++]);
			}
			else if(A[c1+ct].fi < B[c2+ct].fi){
				// We want to access elements of stack A first
				fori(ct)Ans.pb(A[c1++]);
			}
			else if(A[c1+ct].fi > B[c2+ct].fi){
				// We want to access elements of stack B first
				fori(ct)Ans.pb(B[c2++]);
			}
			else{
				// the elements are equal, the amount differs
				// We want to see what comes after the smaller stack and compare it to cur element in larger stack.
				if(A[c1+ct].se < B[c2+ct].se){
					// A is the smaller stack
					if(c1+ct+1 == A.size()){
						fori(ct+1)Ans.pb(B[c2++]);
					}
					else if(A[c1+ct+1].fi > B[c2+ct].fi){
						fori(ct+1)Ans.pb(B[c2++]);
					}
					else{
						//A[c1+ct+1].fi < B[c2+ct].fi
						fori(ct+1)Ans.pb(A[c1++]);
					}
				}
				else{
					// B is the smaller stack
					if(c2+ct+1 == B.size()){
						fori(ct+1)Ans.pb(A[c1++]);
					}
					else if(B[c2+ct+1].fi > A[c1+ct].fi){
						fori(ct+1)Ans.pb(A[c1++]);
					}
					else{
						fori(ct+1)Ans.pb(B[c2++]);
					}
				}
			}
		}
		forii(c1, A.size())Ans.pb(A[i]);
		forii(c2, B.size())Ans.pb(B[i]);
		// for(auto c: A){
		// 	cerr<<c.fi<<" "<<c.se<<endl;
		// }
		// for(auto c: B){
		// 	cerr<<c.fi<<" "<<c.se<<endl;
		// }
		for(auto c: Ans){
			fori(c.se)cout<<c.fi;
		}
		cout<<endl;
	}
}
