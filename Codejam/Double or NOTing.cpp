#include <iostream>
#include <iomanip>
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
    while(*name == ' ' || *name == ',')++name;
    cerr << name << " : " << arg1 << ')' << endl;
}

template <typename Arg1, typename... Args>
void _debug(const char* names, Arg1&& arg1, Args&&... args){
    int depth = 0;
    string variable;
    while(*names == ' ' || *names == ',')++names;
    while(*names != ',' || depth){
        if(*names == '[' || *names == '{' || *names == '(')depth++;
        if(*names == ']' || *names == '}' || *names == ')')depth--;
        variable += *names;
        ++names;
    }
    while(variable.back() == ' ')variable.pop_back();
    cerr << variable << " : " << arg1 << " | " ;
    _debug(names, args...);
}

const int N = 1e6+10;
//const ll M = 1e9+7;

int main(){
    // fastIO;
    int t;
    cin>>t;
    for(int test = 0; test < t; test++){
        cout << "Case #" << test+1 << ": ";
        string s, e;
        cin>>s>>e;
        int n = s.size(), m = e.size();
        vector<int>s_groups, e_groups;
        char cur = s[0], am = 0;
        fori(n){
            if(cur == s[i])am += 1;
            else{
                cur = s[i];
                s_groups.pb(am);
                am = 1;
            }
        }
        s_groups.pb(am);
        cur = e[0];
        am = 0;
        fori(m){
            if(cur == e[i])am += 1;
            else{
                cur = e[i];
                e_groups.pb(am);
                am = 1;
            }
        }
        e_groups.pb(am);
        // TODO: test this maybe
        if(s_groups.size() + (s[n-1] == '1' || s == "0") < e_groups.size()){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        if(e == "0"){
            if(s == "0"){
                cout << "0" << endl;
            }
            else cout << s_groups.size() << endl;
            continue;
        }
        // debug(s_groups, e_groups);
        bool possible = false;
        // TODO: handle 0s separately
        // TODO: it may be possible to reuse the last block of s
        if(s == "0"){
            // e != 0
            // 1 to convert to e
            // e_groups[0] times double
            if(e == "1"){
                cout << 1 << endl;
            }
            else if(e[1] == '0'){
                cout << 1 + e_groups[1] << endl;
            }
            else if(e_groups.size() == 1){
                cout << 2 + e_groups[0] << endl;
            }
            else {
                cout << 2 + e_groups[0] + e_groups[1] << endl;
            }
            continue;
        }
        fori(s_groups.size()+1){
            // skip i of the original groups
            // the initial swap is the number of nots we perform
            if(s_groups.size() - i > e_groups.size()){
                // debug(i, "sizes wrong");
                continue;
            }
                
            // the number of NOT operations we end up performing
            int ans = i;
            bool pos = true;
            forj(e_groups.size()){
                if(j + i < s_groups.size()){
                    if(j + i == s_groups.size() - 1 && (s[n-1] == '0' || i > 0) && e_groups[j] >= s_groups[i+j] && (e_groups.size() != s_groups.size() || s[n-1] == '0')){
                        // we reuse last block, so one less not needed.
                        ans += e_groups[j] - s_groups[i+j];
                    }
                    else if(s_groups[i+j] != e_groups[j]){
                        pos = false;
                        // debug(i, j, "non-match");
                        break;
                    }
                }
                else
                    ans += e_groups[j];
            }

            if(!pos)
                continue;

            cout << ans << endl;
            possible = true;
            break;
        }

        if(!possible){
            throw std::runtime_error("Found impossible position not filtered out by initial check\n");
        }
        // cout << "IMPOSSIBLE" << endl;
    }
    
}
