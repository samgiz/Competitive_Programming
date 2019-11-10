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

deque<int>Col[N];
deque<int>Row[N];
int c1, c2, r1, r2;

int main(){
    fastIO;
    int n, m, k;
    cin>>n>>m>>k;
    fori(k){
        int a, b;
        cin>>a>>b;
        Col[b-1].pb(a-1);
        Row[a-1].pb(b-1);
    }
    fori1(n)sort(Row[i].begin(), Row[i].end());
    fori1(m)sort(Col[i].begin(), Col[i].end());

    c1 = 0, r1 = 0, c2 = n-1, r2 = m-1;
    while(true){
        // right
        while(Row[r1].size() && Row[r1][0] < c1)Row[r1].pop_front();
        while(Row[r1].size() && Row[r1][Row[r1].size()-1] > c2)Row[r1].pop_back();
        if(Row[r1].size() && Row[r1][0] == c1 && r1 != r2){
            cerr<<'a';
            cout<<"No";
            exit(0);
        }
        
        if(Row[r1].size()){
            if(!(Row[r1][Row[r1].size()-1] == c2 && Row[r1][Row[r1].size()-1] - Row[r1][0] == Row[r1].size()-1)){
                // Additional checks
                cout<<"No";
                exit(0);
            }
            forii(r1+1, r2+1){
                while(Row[i].size() && Row[i][0] < c1)Row[i].pop_front();
                while(Row[i].size() && Row[i][Row[i].size()-1] > c2)Row[i].pop_back();
                if(Row[i].size() < Row[r1].size() 
                || Row[i][Row[i].size()-1] != Row[r1][Row[r1].size()-1] 
                || Row[r1][0] != Row[i][Row[i].size()-Row[r1].size()]){
                    // Additional checks
                    cerr<<'b';
                    cout<<"No";
                    exit(0);
                }
            }
            c2 = Row[r1][0]-1;
        }
        r1++;
        if(c1 > c2 || r1 > r2)break;
        cerr<<c1<<" "<<c2<<" "<<r1<<" "<<r2<<endl;

        // down
        while(Col[c2].size() && Col[c2][0] < r1)Col[c2].pop_front();
        while(Col[c2].size() && Col[c2][Col[c2].size()-1] > r2)Col[c2].pop_back();
        if(Col[c2].size() && Col[c2][0] == r1 && c1 != c2){
            cout<<"No";
            cerr<<'c';
            exit(0);
        }
        if(Col[c2].size()){
            if(!(Col[c2][Col[c2].size()-1] == r2 && Col[c2][Col[c2].size()-1] - Col[c2][0] == Col[c2].size()-1)){
                // Additional checks
                cout<<"No";
                exit(0);
            }
            forii(c1, c2){
                while(Col[i].size() && Col[i][0] < r1)Col[i].pop_front();
                while(Col[i].size() && Col[i][Col[i].size()-1] > r2)Col[i].pop_back();
                if(Col[i].size() < Col[c2].size() 
                || Col[i][Col[i].size()-1] != Col[c2][Col[c2].size()-1] 
                || Col[c2][0] != Col[i][Col[i].size()-Col[c2].size()]){
                    // Additional checks
                    cout<<"No";
                    exit(0);
                }
            }
            r2 = Col[c2][0]-1;
        }
        c2--;
        if(c1 > c2 || r1 > r2)break;


        // left
        while(Row[r2].size() && Row[r2][0] < c1)Row[r2].pop_front();
        while(Row[r2].size() && Row[r2][Row[r2].size()-1] > c2)Row[r2].pop_back();
        if(Row[r2].size() && Row[r2][Row[r2].size()-1] == c2 && r1 != r2){
            cout<<"No";
            cerr<<'e';
            exit(0);
        }
        
        if(Row[r2].size()){
            if(!(Row[r2][0] == c1 && Row[r2][Row[r2].size()-1] - Row[r2][0] == Row[r2].size()-1)){
                // Additional checks
                cout<<"No";
                exit(0);
            }
            forii(r1, r2){
                while(Row[i].size() && Row[i][0] < c1)Row[i].pop_front();
                while(Row[i].size() && Row[i][Row[i].size()-1] > c2)Row[i].pop_back();
                if(Row[i].size() < Row[r2].size() 
                || Row[i][0] != Row[r2][0] 
                || Row[r2][Row[r2].size()-1] != Row[i][Row[r2].size()-1]){
                    // Additional checks
                    cerr<<'b';
                    cout<<"No";
                    exit(0);
                }
            }
            c1 = Row[r2][Row[r2].size()-1]+1;
        }
        r2--;
        if(c1 > c2 || r1 > r2)break;


        // up
        while(Col[c1].size() && Col[c1][0] < r1)Col[c1].pop_front();
        while(Col[c1].size() && Col[c1][Col[c1].size()-1] > r2)Col[c1].pop_back();
        if(Col[c1].size() && Col[c1][Col[c1].size()-1] == r2 && c1 != c2){
            cout<<"No";
            exit(0);
        }
        if(Col[c1].size()){
            if(!(Col[c1][0] == r1 && Col[c1][Col[c1].size()-1] - Col[c1][0] == Col[c1].size()-1)){
                // Additional checks
                cout<<"No";
                exit(0);
            }
            forii(c1+1, c2+1){
                while(Col[i].size() && Col[i][0] < r1)Col[i].pop_front();
                while(Col[i].size() && Col[i][Col[i].size()-1] > r2)Col[i].pop_back();
                if(Col[i].size() < Col[c1].size() 
                || Col[i][0] != Col[c1][0] 
                || Col[c1][Col[c1].size()-1] != Col[i][Col[c1].size()-1]){
                    // Additional checks
                    cout<<"No";
                    exit(0);
                }
            }
            r1 = Col[c1][Col[c1].size()-1] + 1;
        }
        c1++;
        if(c1 > c2 || r1 > r2)break;
    }
    cout<<"Yes";
}
