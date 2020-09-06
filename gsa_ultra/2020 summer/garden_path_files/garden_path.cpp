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
    #define debug(...) {cerr<<"dbg("; _debug(#__VA_ARGS__, __VA_ARGS__);}
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

// const int N = 1e6+10;
const ll MM = 1e9+7;

// input:
// N M K - size of board and number of empty tiles
// K lines, each containing a position of an empty tile, all different

// output
// number of possible ways to fill the board with dominoes modulo 1e9+7

const int max_N = 1e9;
const int max_M = 7;

vpii plants;
ll dp[31][(1<<max_M)][(1<<max_M)];

vector<int> gen;
void generate(int flag, int width, int start){
    gen.pb(flag);
    forii(start, width-1){
        if(((3 << i) & flag) == 0){
            generate(flag | (3<<i), width, i + 2);
        }
    }
}

int main(){
    fastIO;
    cout<<1<<endl;
    // get input
    int N, M, K;
    cin>>N>>M>>K;
    fori(K){
        int a, b;
        cin>>a>>b;
        plants.push_back({a, b});
    }
    sort(plants.begin(), plants.end());

    // push additional plants to end
    fori(M){
        plants.push_back({N, i});
    }
    K += M;
    // set up some helper variables
    int ms = (1 << M);
    int kk = 31; // up to where to calculate
    // set up the initial dp level
    fori(ms){
        gen.clear();
        generate(i, M, 0);
        for(auto &j: gen){
            dp[0][i][j] = 1;
        }
    }
    // set up the remaining dp levels
    forll(1, kk){
        fori(ms){
            forj(ms){
                int nj = (ms-1) & (~j);
                if(dp[l-1][i][j] != 0){
                    fork(ms){
                        dp[l][i][k] = (dp[l][i][k] + dp[l-1][i][j] * dp[l-1][nj][k]) % MM;
                    }
                }
            }
        }
    }

    vector<int>ans(ms), new_ans(ms);
    ans[ms-1] = 1;
    // debug(ans);
    int prev = -1;
    int cnt = 0;
    while(cnt < K){
        int ct = cnt;
        int flag = 0;
        int pp = plants[ct].fi - prev;
        prev = plants[ct].fi;
        // debug('a');
        while(ct < K && plants[ct].fi == plants[cnt].fi){
            flag |= (1<<plants[ct].se);
            ct += 1;
        }
        cnt = ct;
        //bits = [i for i in range(kk) if (1 << i) & m > 0]
        int last = 0;
        // debug('b');
        // debug("starting the checking for bits");
        fori(kk){
            // debug(i);
            if(((1 << i) & pp) == 0)continue;
            // cout<<i<<" ";
            if ((1 << i) == pp){
                last = i; break;
            }
            pp -= (1<<i);
            for(auto &ii: new_ans)ii = 0;
            forj(ms){
                if(ans[j] == 0)continue;
                int nj = (ms-1) & (~j);
                fork(ms){
                    new_ans[k] = (new_ans[k] + ans[j] * dp[i][nj][k]) % MM;
                }
            }
            ans = new_ans;
        } //in bits[:-1]: # The last bit should be treated in a special way for efficiency
        // cout<<endl;
        for(auto &i: new_ans)i = 0;
        // debug('c');
        forj(ms){
            if(ans[j] == 0)continue;
            int nj = (ms-1) & (~j);
            fork(ms){
                if((k&flag) > 0)continue;
                // if(ans[j] == 1 && dp[last][nj][k] == 1)debug(last, j, nj, k);
                new_ans[k|flag] = (new_ans[k|flag] + ans[j] * dp[last][nj][k]) % MM;
                // debug(k|flag, new_ans[k|flag], ans[j], dp[last][nj][k])
            }
        }
        ans = new_ans;
        // debug(ans);
    }
    cout<<ans[ms-1];
}

/*
10 5 2
4 0
7 0
*/