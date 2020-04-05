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

struct State{
    ll m1 = 1e9+7;
    ll m2 = 1e9+9;
    ll m3 = 1e9+21;
    ll m4 = 1000000531;
    ll a, b, c, d;
    ll power(ll el, ll m){
        ll mul = 2;
        ll acc = 1;
        while(el){
            if(el & 1)acc=(acc*mul)%m;
            mul = mul * mul % m;
            el>>=1;
        }
        return acc;
    }
    ll inverse(ll el, ll m){
        ll val = m-2;
        ll mul = el;
        ll acc = 1;
        while(val){
            if(val & 1)acc=(acc*mul)%m;
            mul = mul * mul % m;
            val>>=1;
        }
        return acc;
    }
    State divide(ll divisor){
        ll d1 = inverse(power(divisor, m1), m1);
        ll d2 = inverse(power(divisor, m2), m2);
        ll d3 = inverse(power(divisor, m3), m3);
        ll d4 = inverse(power(divisor, m4), m4);
        // cerr<<d1<<" "<<d2<<" "<<d3<<endl;
        return State(d1*a, d2*b, d3*c, d4*d);
    }
    State times(ll divisor){
        ll d1 = power(divisor, m1);
        ll d2 = power(divisor, m2);
        ll d3 = power(divisor, m3);
        ll d4 = power(divisor, m4);
        // cerr<<d1<<" "<<d2<<" "<<d3<<endl;
        return State(d1*a, d2*b, d3*c, d4*d);
    }
    State(ll _a,ll _b, ll _c, ll _d){
        a=_a%m1;
        b=_b%m2;
        c=_c%m3;
        d=_d%m4;
    }
    State(){
        a=b=c=d=1;
    }
    bool operator<(State s) const{
        if(s.a != a)return s.a < a;
        if(s.b != b)return s.b < b;
        if(s.d != d)return s.d < d;
        return s.c < c;
    }
    bool operator==(State s) const{
        return a == s.a && b == s.b && c == s.c && d == s.d;
    }
};

int A[N];
map<State, int>states;
map<int, bool>cur;

int main(){
    fastIO;
    int n;
    cin>>n;
    fori(n)cin>>A[i];
    State state = State();
    states[state]=-1;
    int ans = 1e7;
    fori(n){
        for(int j=2; j<=sqrt(A[i]); j++){
            bool cnt = false;
            while(A[i]%j == 0){
                A[i]/=j;
                cnt=!cnt;
            }
            if(cnt){
                if(cur[j])state=state.divide(j);
                else state = state.times(j);
                cur[j] = !cur[j];
                // cerr<<state.a<<" "<<state.b<<" "<<state.c<<endl;
            }
        }
        if(A[i]!=1){
            if(cur[A[i]])state=state.divide(A[i]);
            else state=state.times(A[i]);
            cur[A[i]] = !cur[A[i]];
            // cerr<<state.a<<" "<<state.b<<" "<<state.c<<endl;
        }
        if(states.count(state)){
            ans = min(ans, i-states[state]);
        }
        states[state] = i;
    }
    if(ans == 1e7)cout<<-1;
    else cout<<ans;
}
