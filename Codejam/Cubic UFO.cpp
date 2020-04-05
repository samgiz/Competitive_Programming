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

const double beta = atan(sqrt(2.0));
const double pi4 = atan(1);
const double eps = 1e-12;

double area2(double alpha){
	double kk = cos(alpha);
	double tk = cos(alpha/2)-sqrt(3.0)/2*cos(alpha+beta);
	return kk+tk;
}

int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<":\n";
		double S;
		cin>>S;

		if(S<=1.414213){
			double alpha = pi4-acos(S/sqrt(2));
			cerr<<pi4<<" "<<sqrt(2)	<<endl;
			cout<<0.5<<" "<<0<<" "<<0<<endl;
			cout<<0<<" "<<sin(alpha)/2<<" "<<cos(alpha)/2<<endl;
			cout<<0<<" "<<sin(alpha+2*pi4)/2<<" "<<cos(alpha+2*pi4)/2<<endl;
		}
		else{
			double a=0, b=pi4;

			while(b-a>eps){
				double alpha = (a+b)/2;
				if(area2(alpha)<S)a = alpha;
				else b = alpha;
			}

			cout<<cos(a)/2<<" "<<0<<" "<<sin(a)/2<<endl;
			cout<<-sin(a)/2<<" "<<sqrt(2)/4<<" "<<cos(a)/2<<endl;
			cout<<-sin(a)/2<<" "<<-sqrt(2)/4<<" "<<cos(a)/2<<endl;
		}

	}
}
