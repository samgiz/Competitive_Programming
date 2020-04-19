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

ll V[N];
pii Sort[N];
ll Ans[N];
int r, c;

bool in_bounds(int i, int j){
    return i >= 0 && j >= 0 && i < r && j < c;
}
ll ans = 0, max_num = 0;
ll remaining = 0;
vpii tmp;
void handle(pii p){
    tmp.clear();
    int i = p.fi;
    int j = p.se;
    // cerr<<i<<" "<<j<<endl;
    int nbrs = 0;
    ll sum = 0;
    if(in_bounds(i+1, j)){
        nbrs++;
        sum += V[(i+1)*c+j];
        tmp.push_back({i+1, j});
    }
    if(in_bounds(i-1, j)){
        nbrs++;
        sum += V[(i-1)*c+j];
        tmp.push_back({i-1, j});
    }
    if(in_bounds(i, j+1)){
        nbrs++;
        sum += V[(i)*c+j+1];
        tmp.push_back({i, j+1});
    }
    if(in_bounds(i, j-1)){
        nbrs++;
        sum += V[(i)*c+j-1];
        tmp.push_back({i, j-1});
    }
    sort(tmp.begin(), tmp.end(), [](pii a, pii b){
        return V[a.fi*c + a.se] < V[b.fi*c + b.se];
    });
    ll cur = 0, curi = 0;
    while(nbrs > 0 && sum <= V[i*c+j]*nbrs){
        pii rem = tmp[curi];
        cur = max(cur, Ans[rem.fi*c+rem.se]+1);
        sum -= V[rem.fi*c+rem.se];
        nbrs -= 1;
    }
    if(nbrs == 0){
        remaining+=V[i*c+j];
        return;
    }
    ans += (cur+1)*V[i*c+j];
    max_num = max(max_num, cur+1);
}

int main(){
    fastIO;
    int t;
    cin>>t;
    fork1(t){
        cout<<"Case #"<<k<<": ";
        cin>>r>>c;
        ans = 0;
        remaining = 0;
        max_num = 0;
        fori(r){
            forj(c){
                cin>>V[i*c + j];
            }
        }
        fori(r*c)Ans[i] = r*c;
        fori(r){
            forj(c){
                Sort[i*c + j] = {i, j};
            }
        }
        sort(Sort, Sort + r*c, [](pii a, pii b){
            return V[a.fi*c + a.se] < V[b.fi*c + b.se];
        });
        fori(r*c){
            handle(Sort[i]);
            cerr<<ans<<endl;
        }
        ans += (max_num+1) * remaining;
        cout<<ans<<endl;
    }
}
