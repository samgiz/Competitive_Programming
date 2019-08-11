#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

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
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int Cube[24];

void solved(){
	repi(6){
		repj(4){
			if(Cube[i*4]!=Cube[i*4+j])return;
		}
	}
	cout<<"YES";
	exit(0);
}
void turn1(){
	
	int A[24];
	repi(24)A[i]=Cube[i];
	Cube[4]=A[12];
	Cube[5]=A[13];
	Cube[16]=A[4];
	Cube[17]=A[5];
	Cube[20]=A[16];
	Cube[21]=A[17];
	Cube[12]=A[20];
	Cube[13]=A[21];
}

void turn2(){
	
	int A[24];
	repi(24)A[i]=Cube[i];
	Cube[0]=A[23];
	Cube[2]=A[21];
	Cube[4]=A[0];
	Cube[6]=A[2];
	Cube[8]=A[4];
	Cube[10]=A[6];
	Cube[23]=A[8];
	Cube[21]=A[10];
}
void turn3(){
	
	int A[24];
	repi(24)A[i]=Cube[i];
	Cube[2]=A[15];
	Cube[3]=A[13];
	Cube[16]=A[2];
	Cube[18]=A[3];
	Cube[9]=A[16];
	Cube[8]=A[18];
	Cube[15]=A[9];
	Cube[13]=A[8];
}

int main(){
	// fastInputOutput;
	
	repi(24)cin>>Cube[i];
	turn1();
	solved();
	turn1();turn1();
	solved();
	turn1();turn2();
	solved();
	turn2();turn2();
	solved();
	turn2();turn3();
	solved();
	turn3();turn3();
	solved();

	cout<<"NO";
}
