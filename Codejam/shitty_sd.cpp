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

// these could also be transformed into 1D arrays if necessary
// But they would need to be slightly bigger (r+2)*(c+2)
// Values reassigned every test
ll V[101][101];
bool bad[101][101], new_bad[101][101];

// The dimensions of the board
// Stdin
int r, c;

// running answer, running sum
// need to be reset at the start of each tests
// double check that does not overflow
ll ans;

// Check that i, j is inside the board
bool in_bounds(int i, int j){
    return i >= 0 && j >= 0 && i < r && j < c;
}
ll valueUp(int i, int j){
    for(int ii=i+1; ii<r; ii++){
        if(!bad[ii][j])return V[ii][j];
    }
    return 0;
}
ll valueDown(int i, int j){
    for(int ii=i-1; ii>=0; ii--){
        if(!bad[ii][j])return V[ii][j];
    }
    return 0;
}
ll valueLeft(int i, int j){
    for(int ii=j+1; ii<c; ii++){
        if(!bad[i][ii])return V[i][ii];
    }
    return 0;
}
ll valueRight(int i, int j){
    for(int ii=j-1; ii>=0; ii--){
        if(!bad[i][ii])return V[i][ii];
    }
    return 0;
}
bool remove(int i, int j){
    if(bad[i][j])return false;
    int nbrs = 0;
    ll sum = 0;
    ll v=valueUp(i, j);
    if(v){
        sum+=v;
        nbrs+=1;
    }
    v=valueDown(i, j);
    if(v){
        sum+=v;
        nbrs+=1;
    }
    v=valueRight(i, j);
    if(v){
        sum+=v;
        nbrs+=1;
    }
    v=valueLeft(i, j);
    if(v){
        sum+=v;
        nbrs+=1;
    }
    // cerr<<i<<" "<<j<<" "<<sum<<" "<<nbrs<<endl;
    if(nbrs == 0)return false;
    return sum > nbrs * V[i][j];
}

int main(){
    fastIO;
    // number of tests
    int t;
    cin>>t;
    fork1(t){
        // Output template string
        cout<<"Case #"<<k<<": ";
        // Input dimensions
        cin>>r>>c;
        fori(r){
            forj(c)bad[i][j]=false;
            forj(c)new_bad[i][j]=false;
        }

        // reset answer and sum
        ans = 0;

        // Input all values (r*c of them)
        fori(r){
            forj(c){
                cin>>V[i][j];
            }
        }
        while(true){
            bool f = true;
            fori(r){
                forj(c){
                    if(!bad[i][j])ans+=V[i][j];
                    if(remove(i, j)){
                        new_bad[i][j]=true;
                        f = false;
                    }
                }
            }
            if(f)break;

            fori(r){
                forj(c){
                    bad[i][j] = new_bad[i][j];
                }
            }
        }
        cout<<ans<<endl;
    }
}
