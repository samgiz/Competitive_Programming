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

const int N = 5e5+10;

vpll E[N];

struct State{
    const ll m1 = 1e9+7, m2 = 1e9+9, m3 = 1e9+21;
    ll a, b, c;
    State(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    State(){
        a = b = c = 0;
    }
    bool operator==(const State& other) const{
        return a == other.a && b == other.b && c == other.c;
    }
    bool operator<(const State& other) const{
        if(a != other.a)return a < other.a;
        if(b != other.b)return b < other.b;
        return c < other.c;
    }
    State operator^(const State& other){
        return State(a^other.a, b^other.b, c^other.c);
    }
    State operator*(const State& other){
        return State((a*other.a)%m1, (b*other.b)%m2, (c*other.c)%m3);
    }
    void operator=(const State& other){
        a = other.a;
        b = other.b;
        c = other.c;
    }
};

State modPowState(ll num){
    // cerr<<num<<endl;
    State ans = State(1, 1, 1);
    State mul = State(2, 2, 2);
    while(num){
        if(num&1)ans=ans * mul;
        num >>= 1;
        mul = mul * mul;
    }
    return ans;
}
map<State, int>states;
ll ans = 0;
void dfs(int cur, int par, State state){
    // cerr<<cur<<" "<<par<<" "<<state.a<<" "<<state.b<<" "<<state.c<<" "<<states[state]<<endl;
    ans += states[state]++;
    for(auto &i: E[cur]){
        if(i.fi == par)continue;
        dfs(i.fi, cur, state ^ modPowState(i.se));
    }
}

int main(){
    fastIO;
    int g;
    cin>>g;
    while(g--){
        ans = 0;
        states.clear();
        ll n;
        cin>>n;
        fori1(n)E[i].clear();
        fori(n-1){
            int u, v, w;
            cin>>u>>v>>w;
            E[u].pb({v, w});
            E[v].pb({u, w});
        }
        dfs(1, 0, State());
        cout<<n * (n-1) /2 - ans<<endl;
    }
}
