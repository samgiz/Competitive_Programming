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

const int N = 1000010;

bool Val[N], Switched[N];
int Not[N], AndOr1[N], AndOr2[N];
string Op[N];

bool initial(int cur){
	if(Op[cur]=="NOT"){
		Val[cur]=!initial(Not[cur]);
	}
	else if(Op[cur]=="AND"){
		Val[cur]=initial(AndOr1[cur])&initial(AndOr2[cur]);
	}
	else if(Op[cur]=="OR"){
		Val[cur]=initial(AndOr1[cur])|initial(AndOr2[cur]);
	}
	else if(Op[cur]=="XOR"){
		Val[cur]=initial(AndOr1[cur])^initial(AndOr2[cur]);
	}
	return Val[cur];
}

void switched(int cur, bool other, string op, int par){
	Switched[cur]=Val[1];
	if(op=="NOT"){
		Switched[cur]=Switched[par];
	}
	else if(op=="AND"){
		if((Val[cur]&other)!=((!Val[cur])&other))Switched[cur]=Switched[par];
	}
	else if(op=="OR"){
		if((Val[cur]|other)!=((!Val[cur])|other))Switched[cur]=Switched[par];
	}
	else if(op=="XOR"){
		if((Val[cur]^other)!=((!Val[cur])^other))Switched[cur]=Switched[par];
	}

	if(Op[cur]=="IN")return;
	if(Op[cur]=="NOT")switched(Not[cur], 0, "NOT", cur);
	else switched(AndOr1[cur], Val[AndOr2[cur]], Op[cur], cur), switched(AndOr2[cur], Val[AndOr1[cur]], Op[cur], cur);
}

int main(){
	// fastInputOutput;
	int n;
	cin>>n;
	forii(1, n+1){
		cin>>Op[i];
		if(Op[i]=="IN"){
			cin>>Val[i];
		}
		else if(Op[i]=="NOT"){
			cin>>Not[i];
		}
		else cin>>AndOr1[i]>>AndOr2[i];
	}
	initial(1);
	Switched[1]=!Val[1];
	if(Op[1]=="NOT")switched(Not[1], 0, "NOT", 1);
	else switched(AndOr1[1], Val[AndOr2[1]], Op[1], 1), switched(AndOr2[1], Val[AndOr1[1]], Op[1], 1);

	forii(1, n+1){
		if(Op[i]=="IN")cout<<Switched[i];
	}
	// cerr<<endl;
	// forii(1, n+1){
	// 	cerr<<Val[i];
	// }
}
