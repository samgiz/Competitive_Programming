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

struct Answer(){
    int left, right, all, max;
    Answer(){}
    Answer(int l, int r, int a, int m) : left{l}, right{r}, all{a}, max{m} {}
};

vector<int>A, Sum, Square;
Answer solve(int l, int r){
    Answer a = Answer(max(0, A[l]), max(0, A[l]), A[l], max(0, A[l]));
    if(r == l+1){
        return Answer(max(0, A[l]), max(0, A[l]), A[l], max(0, A[l]));
    }
    solve(mid, r);
}

int main(){
    fastIO;
    int n;
    int A.resize(n);
    fori(n)cin>>A[i];
    int Sum.resize(n+1);
    fori1(n)Sum[i] = Sum[i-1] + A[i-1];
    int Square.resize(n+1);
    fori1(n)Square[i] = Square[i-1] + A[i-1]*A[i-1];
    Answer ans = Answer(max(0, A[l]), max(0, A[l]), A[l], max(0, A[l]));
    cout<<solve(0, n).max<<endl;
}
