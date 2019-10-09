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

ll DP[1000001], A[1000001];

queue<ll> Reachable;
ll j = 0;

int main(){
	fastInputOutput;
	int n, a, b;
	cin>>n>>a>>b;
	b = min(2*a-1, b);
	priority_queue<pll, vpll, greater<pll>>Q;
	queue<pll>Pre;
	fori(n)cin>>A[i];
	sort(A, A+n);
	forii(1, n+1)DP[i]=1000001;
	forii(a, n+1){
		if(Pre.size() && Pre.front().se == i-a)Q.push(Pre.front()), j = i-a, Pre.pop();
		if(Q.size())cerr<<j<<" "<<Q.top().fi<<" "<<Q.top().se<<" "<<Q.size()<<endl;
		while(Q.size() && (Q.top().fi <= A[i-1]-A[Q.top().se] || Q.top().se < i-b))Q.pop();

		if(j>=i-b && j<=i-a && DP[j] <= A[i-1]-A[j])DP[i] = A[i-1]-A[j];
		if(Q.size()) DP[i] = min(DP[i], Q.top().fi);
		
		if(DP[i]!=1000001)Pre.push(mp(DP[i], i)), Reachable.push(i);
	}
	cerr<<DP[a]<<endl;

	cerr<<DP[a+1]<<endl;
	cerr<<DP[a+2]<<endl;
	cout<<DP[n];
}
