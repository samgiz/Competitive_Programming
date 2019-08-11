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

const ll NM = 100010;
ll maxi = 0;

map<int, int> E[NM];
ll A[NM], B[NM], W[NM];

int main(){
	fastInputOutput;
	ll n, m;
	cin>>n>>m;
	fori(m){
		cin>>A[i]>>B[i]>>W[i];
	}
	for(int i=m-1; i>=0; i--){
		// best path starting with path i will be at least of length 1
		ll best = 1;

		// find maximum path from B[i] and weight >=W[i]
		auto it = E[B[i]].lower_bound(W[i]);

		// if such path exists, update current path of 1
		if(it!=E[B[i]].end())best = it->se+1;

		// find smaller or equal weight in A[i]
		it = E[A[i]].lower_bound(W[i]);

		// if we can achieve this result with smaller weight, do nothing
		if(it->se < best){

			// this is the best result for this weight so far
			E[A[i]][W[i]] = best;

			// erase any more weightful ones with worse scores
			for(auto it = E[A[i]].upper_bound(W[i]); it!=E[A[i]].end();){
				// iterator has worse score
				if(it->se < best){
					//erase it
					it = E[A[i]].erase(it);
				}
				//everything erased
				else break;
			}
		}
		// update best answer
		maxi = max(best, maxi);
	}

	// print best answer
	cout<<maxi<<endl;
}
