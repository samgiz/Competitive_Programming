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

int A[30][2][30][30]; // second is 1 if carry, 0 if no carry

int countones(int n){
	int ct = 0;
	while(n)ct+=(n&1), n>>=1;
	return ct;
}

int main(){
	fastIO;
	int t;
	cin>>t;
	fori(t){
		int a, b, c;
		cin>>a>>b>>c;
		int cnt=0, ca = countones(a), cb = countones(b);
		fori(30){
			forj(2){
				fork(30){
					forl(30){
						A[i][j][k][l]=0;
					}
				}
			}
		}
		if(c&1){
			if(ca)A[0][0][ca-1][cb]=1;
			if(cb)A[0][0][ca][cb-1]=1;
		}
		else{
			if(ca&&cb)A[0][1][ca-1][cb-1]=1;
			A[0][0][ca][cb]=1;
		}
		c>>=1;
		while(c){
			cnt++;
			fori(30){// a ones left
				forj(30){// b ones left
					if(c&1){
						A[cnt][0][i][j]+=A[cnt-1][1][i][j]; // do nothing, just carry over
						if(i&&j)A[cnt][1][i-1][j-1]+=A[cnt-1][1][i][j]; // use 2 bits plus previous carry
						if(i)A[cnt][0][i-1][j]+=A[cnt-1][0][i][j]; // no carry, use a's bit
						if(j)A[cnt][0][i][j-1]+=A[cnt-1][0][i][j]; // no carry, use b's bit
					}
					else{
						A[cnt][0][i][j]+=A[cnt-1][0][i][j]; // no carry, no bits
						if(i&&j)A[cnt][1][i-1][j-1]+=A[cnt-1][0][i][j]; // use 2 bits, no previous carry
						if(i)A[cnt][1][i-1][j]+=A[cnt-1][1][i][j]; // use carry, use a's bit
						if(j)A[cnt][1][i][j-1]+=A[cnt-1][1][i][j]; // use carry, use b's bit
					}
				}
			}
			c>>=1;
		}
		cout<<A[cnt][0][0][0]<<endl;
	}

}
