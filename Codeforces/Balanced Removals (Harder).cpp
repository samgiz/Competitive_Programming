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


struct Pt{
    int x,  y,  z, i;
    bool operator==(const Pt a) const{
        return a.x == x && a.y == y && a.z == z;
    }
    bool operator!=(const Pt a) const{
        return !(*this == a);
    }
    bool operator<(const Pt a) const{
        if(a.x !=x)return x<a.x;
        if(a.y != y)return y<a.y;
        return z<a.z;
    }
};

map<Pt, int>M;
// x1 < x2 < x3

int ct = 0, ct2 = 0;
Pt P[N], P2[N], P3[N];
bool Paired[N];

vpii Ans;

int main(){
    fastIO;
    int n;
    cin>>n;
    fori(n)cin>>P[i].x>>P[i].y>>P[i].z;

    fori(n)P[i].i = i+1;

    sort(P, P+n);
    // fori(n)cerr<<P[i].i<<" ";

    fori(n){
        if(i == n-1){
            P2[ct++] = P[i];
            break;
        }
        if(P[i].x == P[i+1].x && P[i].y == P[i+1].y){
            // cerr<<'a'<<endl;
            Ans.pb({P[i].i, P[i+1].i});
            i++;
        }
        else P2[ct++] = P[i];
    }
    fori(ct){
        if(i == ct-1){
            P3[ct2++] = P2[i];
            break;
        }
        if(P2[i].x == P2[i+1].x){
            // cerr<<'b'<<endl;
            Ans.pb({P2[i].i, P2[i+1].i});
            i++;
        }
        else P3[ct2++] = P2[i];
    }
    for(int i=0; i<ct2; i+=2){
        // cerr<<'c'<<endl;
        Ans.pb({P3[i].i, P3[i+1].i});
    }
    for(auto i: Ans){
        cout<<i.fi<<" "<<i.se<<endl;
    }
}


/*#include <bits/stdc++.h>

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


struct Pt{
    int x,  y,  z, i;
    bool operator==(const Pt a) const{
        return a.x == x && a.y == y && a.z == z;
    }
    bool operator!=(const Pt a) const{
        return !(*this == a);
    }
    bool operator<(const Pt a) const{
        if(a.x !=x)return x<a.x;
        if(a.y != y)return y<a.y;
        return z<a.z;
    }
};

map<Pt, int>M;
// x1 < x2 < x3

int ct = 0, ct2 = 0, ct3 = 0, ct4 = 0;
Pt P[N], P2[N], P3[N], P4[N], P5[N];
bool Paired[N];

vpii Ans;

int main(){
    fastIO;
    int n;
    cin>>n;
    fori(n)cin>>P[i].x>>P[i].y>>P[i].z;

    fori(n)P[i].i = i+1;

    sort(P, P+n);
    fori(n)cerr<<P[i].i<<" ";

    fori(n){
        if(i == n-1){
            P2[ct++] = P[i];
            break;
        }
        if(P[i].x == P[i+1].x && P[i].y == P[i+1].y){
            cerr<<'a'<<endl;
            Ans.pb({P[i].i, P[i+1].i});
            i++;
        }
        else P2[ct++] = P[i];
    }
    fori(ct){
        if(i == ct-1){
            P3[ct2++] = P2[i];
            break;
        }
        if(P2[i].x == P2[i+1].x){
            cerr<<'b'<<endl;
            Ans.pb({P[i].i, P[i+1].i});
            i++;
        }
        else P3[ct2++] = P2[i];
    }
    fori(ct2){
        if(i == ct2-1){
            P4[ct3++] = P3[i];
            break;
        }
        if(P3[i].y == P3[i+1].){
            cerr<<'b'<<endl;
            Ans.pb({P[i].i, P[i+1].i});
            i++;
        }
        else P3[ct2++] = P2[i];
    }
    for(int i=0; i<ct2; i+=2){
        cerr<<'c'<<endl;
        Ans.pb({P3[i].i, P3[i+1].i});
    }
    for(auto i: Ans){
        cout<<i.fi<<" "<<i.se<<endl;
    }
}
*/