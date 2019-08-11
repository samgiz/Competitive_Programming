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
// #define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

struct tres{
	int x, y, z;
	tres(){}
	tres(int a, int b, int c){
		x=a;
		y=b;
		z=c;
	}
};

set<tres>Checked;

int n, m, k, q;

bool operator==(const tres& lhs, const tres& rhs)
{
    return lhs.x==rhs.x&&lhs.y==rhs.y&&lhs.z==rhs.z;
}
bool operator<(const tres& lhs, const tres& rhs)
{
    if(lhs.x!=rhs.x)return lhs.x<rhs.x;
	if(lhs.y!=rhs.y)return lhs.y<rhs.y;
	if(lhs.z!=rhs.z)return lhs.z<rhs.z;
	return false;
}

bool inBounds(int a, int b, int c){
	return a<=n&&b<=m&&c<=k&&a>0&&b>0&&c>0;
}

bool notOne(int i, int j, int k){
	return (i!=0)+(j!=0)+(k!=0)!=1;
}

int main(){
	// fastInputOutput;
	
	cin>>n>>m>>k>>q;
	int h = -1, a=1, b=1, c=1;
	for(int i=0; i<=q/4; i++){
		int a1 = (((ll)rand())*rand()+rand())%n+1;
		int b1 = (((ll)rand())*rand()+rand())%m+1;
		int c1 = (((ll)rand())*rand()+rand())%k+1;
		cout<<"? "<<a1<<" "<<b1<<" "<<c1<<endl;
		int tp;
		cin>>tp;
		if(tp>h)h=tp, a=a1, b=b1, c=c1;
	}
	
	
	Checked.insert(tres(a, b, c));
	while(true){
		bool lg = true;
		forii(-1, 2){
			forjj(-1, 2){
				forll(-1, 2){ 
					if(!inBounds(a+i, b+j, c+l)||Checked.count(tres(a+i, b+j, c+l))||notOne(i, j, l))continue;
					Checked.insert(tres(a+i, b+j, c+l));
					cout<<"? "<<a+i<<" "<<b+j<<" "<<c+l<<endl;
					int tp;
					cin>>tp;
					if(tp>h)a+=i, b+=j, c+=l, lg=false, h=tp;
					cerr<<lg<<endl;
					if(!lg)break;
				}
				if(!lg)break;
			}
			if(!lg)break;
		}

		if(lg){
			cout<<"! "<<a<<" "<<b<<" "<<c<<endl;
			break;
		}
	}
}
