#include <iostream>
#include <iterator>
#include <cstring>
#include <type_traits>

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <bitset>

#include <algorithm>
#include <cmath>

#include <random>
#include <cassert>
#include <ctime>
#include <ratio>
#include <functional>
#include <sstream>

using namespace std;

#define pb push_back
#define fi first
#define se second

typedef int _def;

#define fori(a) for(_def i=0; i<(a); i++)
#define fori1(a) for(_def i=1; i<=(a); i++)
#define fori_(a) for(_def i=(a)-1; i>=0; i--)
#define fori1_(a) for(_def i=(a); i>0; i--)
#define forii(a, b) for(_def i=(a); i<(b); i++)
#define forii_(a, b) for(_def i=(b)-1; i>=(a); i--)

#define forj(a) for(_def j=0; j<(a); j++)
#define forj1(a) for(_def j=1; j<=(a); j++)
#define forj_(a) for(_def j=(a)-1; j>=0; j--)
#define forj1_(a) for(_def j=(a); j>0; j--)
#define forjj(a, b) for(_def j=(a); j<(b); j++)
#define forjj_(a, b) for(_def j=(b)-1; j>=(a); j--)

#define fork(a) for(_def k=0; k<(a); k++)
#define fork1(a) for(_def k=1; k<=(a); k++)
#define fork_(a) for(_def k=(a)-1; k>=0; k--)
#define fork1_(a) for(_def k=(a); k>0; k--)
#define forkk(a, b) for(_def k=(a); k<(b); k++)
#define forkk_(a, b) for(_def k=(b)-1; k>=(a); k--)

#define forl(a) for(_def l=0; l<(a); l++)
#define forl1(a) for(_def l=1; l<=(a); l++)
#define forl_(a) for(_def l=(a)-1; l>=0; l--)
#define forl1_(a) for(_def l=(a); l>0; l--)
#define forll(a, b) for(_def l=(a); l<(b); l++)
#define forll_(a, b) for(_def l=(b)-1; l>=(a); l--)

#define forg(a) for(_def g=0; g<(a); g++)
#define forg1(a) for(_def g=1; g<=(a); g++)
#define forg_(a) for(_def g=(a)-1; g>=0; g--)
#define forg1_(a) for(_def g=(a); g>0; g--)
#define forgg(a, b) for(_def g=(a); g<(b); g++)
#define forgg_(a, b) for(_def g=(b)-1; g>=(a); g--)

#define forf(a) for(_def f=0; f<(a); f++)
#define forf1(a) for(_def f=1; f<=(a); f++)
#define forf_(a) for(_def f=(a)-1; f>=0; f--)
#define forf1_(a) for(_def f=(a); f>0; f--)
#define forff(a, b) for(_def f=(a); f<(b); f++)
#define forff_(a, b) for(_def f=(b)-1; f>=(a); f--)

#define forh(a) for(_def h=0; h<(a); h++)
#define forh1(a) for(_def h=1; h<=(a); h++)
#define forh_(a) for(_def h=(a)-1; h>=0; h--)
#define forh1_(a) for(_def h=(a); h>0; h--)
#define forhh(a, b) for(_def h=(a); h<(b); h++)
#define forhh_(a, b) for(_def h=(b)-1; h>=(a); h--)

#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template <typename T, typename U>
ostream& operator<<(ostream& out, const pair<T, U> & p) {
    out << '{' << p.fi << ':' << p.se << '}';
    return out;
}

template <template <typename, typename...> class Container, 
        typename Value,
        typename... AddParams,
        typename std::enable_if<!std::is_same<Container<Value, AddParams...>,std::string>::value>::type* = nullptr >
ostream& operator<<(ostream& out, const Container<Value, AddParams...> & container) {
    out << '{';
    bool f = true;
    for(auto &i: container){
        if(!f) out << ", ";
        else f = false;
        out << i;
    }
    out << '}';
    return out;
}

#ifdef CP_DEBUG_
    #define debug(...) cerr<<"dbg("; _debug(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...)
#endif
template <typename Arg1>
void _debug(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << ')' << endl;
}

template <typename Arg1, typename... Args>
void _debug(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma-names) << " : " << arg1 << " | " ; 
    while(*comma == ',' || *comma == ' ')
        ++comma;
    _debug(comma, args...);
}

const int N = 1e6+10;
//const ll M = 1e9+7;
int s, ra, pa, rb, pb, c; // max 36 rooms

struct State{
    pii a, b;
    ll board;
    State(pii a_, pii b_, ll board_){
        this->a = a_;
        this->b = b_;
        this->board = board_;
    }
    bool operator==(const State& other) const
    {
        return a == other.a && b == other.b && board == other.board;
    }
    bool operator<(const State& other) const
    {
        if(a != other.a) return a < other.a;
        if(b != other.b)return b < other.b;
        return board < other.board;
    }
    

};

std::ostream& operator<< (std::ostream &out, State const& data) {
    out << data.a << ';';
    out << data.b << ';';
    out << std::bitset<64>(data.board);
    return out;
}
map<State, int>M;
map<pair<ll, pii>, int>dp;

bool is_toggled(ll state, pii pos){
    int r = pos.fi;
    int p = pos.se;
    // debug(r, p, (p-1 + (r-1)*(r-1)));
    return state&(((ll)1)<<(p-1 + (r-1)*(r-1)));
}

void toggle(ll& state, pii pos){
    int r = pos.fi;
    int p = pos.se;
    // debug(r, p, (p-1 + (r-1)*(r-1)));
    state ^= (((ll)1)<<(p-1 + (r-1)*(r-1)));
}

vector<pii> get_positions(ll board, pii a){
    vpii positions;
    if(a.se > 1 && !is_toggled(board, {a.fi, a.se-1}))
        positions.pb({a.fi, a.se-1});
    if(a.se < a.fi*2-1 && !is_toggled(board, {a.fi, a.se+1}))
        positions.pb({a.fi, a.se+1});
    if(a.se % 2 == 0 && a.fi != 1 && !is_toggled(board, {a.fi-1, a.se-1}))
        positions.pb({a.fi-1, a.se-1});
    if(a.se % 2 == 1 && a.fi != s && !is_toggled(board, {a.fi+1, a.se+1}))
        positions.pb({a.fi+1, a.se+1});
    return positions;
}

ll clear_unreachable(ll board){
    return board;
}

int search(ll board, pii pos){
    debug("search");
    board = clear_unreachable(board);
    auto f = dp.find({board, pos});
    if(f != dp.end())
        return (*f).se;
    vpii positions = get_positions(board, pos);
    if(positions.size() == 0){
        dp[{board, pos}] = 0;
        return 0;
    }
    int ans = 0;
    for(auto &i: positions){
        toggle(board, i);
        ans = max(ans, search(board, i));
        toggle(board, i);
    }
    dp[{board, pos}] = ans;
    return ans+1;
}
int recurseB(State);
int recurseA(State state){
    debug("Recurse A");
    auto f = M.find(state);
    if(f != M.end()){
        debug("returning answer 0 positions A");
        return (*f).se;
    }
    ll board = clear_unreachable(state.board);
    vpii positions = get_positions(board, state.a);
    debug(positions);
    if(positions.size() == 0){
        int ans = search(board, state.b);
        M[state] = -ans;
        return -ans;
    }
    int ans = -1000;
    for(auto &i: positions){
        toggle(board, i);
        ans = max(recurseB(State({i.fi, i.se}, state.b, board)), ans);
        toggle(board, i);
    }
    M[state] = ans;
    return ans;
}

int recurseB(State state){
    debug("Recurse B");
    auto f = M.find(state);
    if(f != M.end()){
        debug("returning answer 0 positions B");
        return (*f).se;
    }
    ll board = clear_unreachable(state.board);
    vpii positions = get_positions(board, state.b);
    if(positions.size() == 0){
        int ans = search(board, state.a);
        M[state] = ans+1;
        return ans+1;
    }
    int ans = 1000;
    for(auto &i: positions){
        toggle(board, i);
        ans = min(recurseA(State(state.a, {i.fi, i.se}, board)), ans);
        toggle(board, i);
    }
    M[state] = ans;
    return ans;
}

int main(){
    // fastIO;
    int t;
    cin>>t;
    for(int aaa=1; aaa<=t; aaa++){
        cout<<"Case #"<<aaa<<": ";
        cin>>s>>ra>>pa>>rb>>pb>>c;
        ll V=0;
        fori(c){
            int r, p;
            cin>>r>>p;
            toggle(V, {r, p});
        }
        toggle(V, {ra, pa});
        toggle(V, {rb, pb});
        M.clear();
        dp.clear();
        int ans = recurseA(State({ra, pa}, {rb, pb}, V));
        debug(M);
        debug(dp);
        cout<<ans<<endl;
    }
}
