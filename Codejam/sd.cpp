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

struct Interval{
    // Exact place in interval to update the other when eaten
    int i, j;
    int o;
    bool eaten = false;
    Interval *next, *prev;
    Interval(){}
    Interval(int k, int l){
        i=k;j=l;
    }
};

// size r*c. Store the initial values
ll V[N];

// two sets, so I can switch between them and add to new set while reading the old one
set<pii>to_eat[2];

// these could also be transformed into 1D arrays if necessary
// But they would need to be slightly bigger (r+2)*(c+2)
// Values reassigned every test
vector<Interval*>row[N];
vector<Interval*>col[N];

// The map from index in V to either row or column interval element
// Values reassigned every test
map<int, Interval*>R, C;

// The dimensions of the board
// Stdin
int r, c;

// running answer, running sum
// need to be reset at the start of each tests
// double check that does not overflow
ll ans, sum;

// Empty element to add to edges of board
Interval* Empty;

// Check that i, j is inside the board
bool in_bounds(int i, int j){
    return i >= 0 && j >= 0 && i < r && j < c;
}
bool to_be_eaten(int i, int j){
    // cerr<<"To be eaten start: "<<i<<" "<<j<<endl;
    // cerr<<"start_to_be_eaten "<<i<<" "<<j<<endl;
    // This case should catch Empty
    if(!in_bounds(i, j)){
        // cerr<<"Not in bounds"<<endl;
        return false;
    }
    // cerr<<i<<" "<<j<<endl;
    // cerr<<"in_bounds_to_be_eaten "<<i<<" "<<j<<endl;
    // Get the row and column Interval objects
    Interval* ro = R[i*c+j];
    Interval* co = C[i*c+j];

    // Don't readd elements that were already eaten
    if(ro->eaten){
        // cerr<<"Already eaten\n";
        return false;
    }
    // cerr<<"not_yet_eaten_to_be_eaten "<<i<<" "<<j<<endl;
    // cerr<<i<<" "<<j<<endl;
    // Sum of elements around object
    ll sum = 0;

    // Count number of non-Empty neighbours
    int nbrs=0;
    if(ro->next != Empty){
        // cerr<<"next in row: "<<ro->next->i<<" "<<ro->next->j<<" "<<V[ro->next->i*c+ro->next->j]<<endl;
        // cerr<<"a "<<ro->next->i<<" "<<ro->next->j<<endl;
        sum += V[ro->next->i*c+ro->next->j];
        nbrs += 1;
    }
    if(ro->prev != Empty){
        // cerr<<"prev in row: "<<ro->prev->i<<" "<<ro->prev->j<<" "<<V[ro->prev->i*c+ro->prev->j]<<endl;
        // cerr<<"a "<<ro->prev->i<<" "<<ro->next->j<<endl;
        sum += V[ro->prev->i*c+ro->prev->j];
        nbrs += 1;
    }
    if(co->next != Empty){
        // cerr<<"next in col: "<<co->next->i<<" "<<co->next->j<<endl;
        sum += V[co->next->i*c+co->next->j];
        nbrs += 1;
    }
    if(co->prev != Empty){
        // cerr<<"prev in col: "<<co->prev->i<<" "<<co->prev->j<<endl;
        sum += V[co->prev->i*c+co->prev->j];
        nbrs += 1;
    }
    // the element will never be removed
    if(nbrs == 0){
        // cerr<<"no neighbours\n";
        return false;
    }
    // cerr<<"end_to_be_eaten "<<i<<" "<<j<<" "<<sum<<" "<<V[i*c+j]*nbrs<<endl;
    // return whether the average is larger than element value
    // cerr<<"sum vs V*nbrs vs V vs nbrs "<<sum<<" "<<V[i*c+j]*nbrs<<" "<<V[i*c+j]<<" "<<nbrs<<endl;
    return sum > V[i*c+j]*nbrs;
}

int main(){
    fastIO;
    // number of tests
    int t;
    cin>>t;
    // A dummy interval to add to edges
    // Initialize basic important properties
    Empty = new Interval();
    Empty->eaten = true;
    Empty->next = Empty;
    Empty->prev=Empty;
    fork1(t){
        // Output template string
        cout<<"Case #"<<k<<": ";

        // Input dimensions
        cin>>r>>c;

        // Initialize coordinates to be outside the board for Empty
        Empty->i=r;
        Empty->j=0;
        R[r*c]=Empty;
        C[r*c]=Empty;

        // reset answer and sum
        ans = 0;
        sum = 0;

        // Input all values (r*c of them)
        fori(r){
            forj(c){
                cin>>V[i*c + j];
            }
        }

        // sum up the values
        fori(r*c)sum+=V[i];

        // create row intervals
        fori(r){
            // resize row if necessary (need c+2 size)
            if(row[i].size() < c+2)row[i].resize(c+2);
            // First and last empty
            row[i][0] = Empty;

            // set the remaining intervals
            forj(c)row[i][j+1] = new Interval(i, j);

            // First and last empty
            row[i][c+1] = Empty;
        }
        // bind row intervals
        fori(r){
            // j does not need to correspond to column number
            forjj(1, c+1){
                row[i][j]->next = row[i][j+1];
                row[i][j]->prev = row[i][j-1];
                R[i*c+j-1] = row[i][j];
            }
        }
        // set up column intervals
        forj(c){
            // resize if necessary
            if(col[j].size() < r+2)col[j].resize(r+2);

            // first and last row empty
            col[j][0] = Empty;

            // remaining column intervals
            fori(r)col[j][i+1] = new Interval(i, j);

            // first and last row empty
            col[j][r+1] = Empty;
        }

        // bind columns
        forj(c){
            forii(1, r+1){
                col[j][i]->next = col[j][i+1];
                col[j][i]->prev = col[j][i-1];
                C[(i-1)*c+j] = col[j][i];
            }
        }
        // Add elements that will be eaten first
        fori(r){
            forj(c){
                if(to_be_eaten(i, j)){
                    // if(i == r && j == 0)cerr<<"WHATTHEFUCK)))";
                    // if(R[i*c+j] == Empty || C[i*c+j] == Empty)cerr<<"AAAAAAAAAA";
                    // cerr<<i<<" "<<j<<endl;
                    to_eat[0].insert({i,j});
                }
            }
        }
        // current to_eat set to read from
        int cur = 0;

        // All players contribute in the first round
        ans = sum;
        // int kk = 0;
        // cerr<<"HELLO "<<to_eat[cur].size()<<" "<<to_eat[cur+1].size()<<endl;

        // while there are elements in the set
        while(to_eat[cur].size()){
            // cerr<<"###############################";
            // if(to_eat[cur].count({r, 0}))exit(0);
            // kk++;
            // if(kk > r*c+1)exit(0);
            bool act = 0;
            // Iterate over players that need to be eaten
            // cerr<<"to_eat";
            // for(auto i: to_eat[cur]){
            //     cerr<<"("<<i.fi<<", "<<i.se<<"), ";
            // }cerr<<endl;
            set<pii>possibly_to_be_eaten;
            for(auto &p: to_eat[cur]){
                // fetch some objects
                int i = p.fi;
                int j = p.se;
                // cerr<<i<<" "<<j<<endl;
                Interval* ro = R[i*c+j];
                Interval* co = C[i*c+j];
                // if(ro == Empty)cerr<<"AAAAAAAAAAAA";

                // if this element has already been eaten, don't repeat
                if(ro->eaten)continue;
                act=true;
                // mark element as eaten
                ro->eaten = true;
                co->eaten = true;

                // subtract the value of element from subsequent rounds
                sum -= V[i*c+j];
                // Update the neighbouring element neighbours if necessary
                if(!(ro->next->eaten) && !to_eat[cur].count({ro->next->i, ro->next->j})){
                    // cerr<<"B"<<Empty->i<<" "<<Empty->j<<endl;
                    while(to_eat[cur].count({ro->next->prev->i, ro->next->prev->j})){
                        // if(ro->next->prev == ro->next->prev->prev)exit(0);
                        ro->next->prev = ro->next->prev->prev;
                    }
                }
                if(!(ro->prev->eaten) && !to_eat[cur].count({ro->prev->i, ro->prev->j})){
                    while(to_eat[cur].count({ro->prev->next->i, ro->prev->next->j})){
                        // if(ro->prev->next == ro->prev->next->next)exit(0);
                        ro->prev->next = ro->prev->next->next;
                    }
                }
                if(!(co->next->eaten) && !to_eat[cur].count({co->next->i, co->next->j})){
                    while(to_eat[cur].count({co->next->prev->i, co->next->prev->j})){
                        // if(co->next->prev == co->next->prev->prev)exit(0);
                        co->next->prev = co->next->prev->prev;
                    }
                }
                if(!(co->prev->eaten) && !to_eat[cur].count({co->prev->i, co->prev->j})){
                    while(to_eat[cur].count({co->prev->next->i, co->prev->next->j})){
                        // if(co->prev->next == co->prev->next->next)exit(0);
                        co->prev->next = co->prev->next->next;
                    }
                }
                // these elements can possibly be eaten next time
                possibly_to_be_eaten.insert({ro->next->i, ro->next->j});
                possibly_to_be_eaten.insert({ro->prev->i, ro->prev->j});
                possibly_to_be_eaten.insert({co->next->i, co->next->j});
                possibly_to_be_eaten.insert({co->prev->i, co->prev->j});
                
            }
            for(auto &kk: possibly_to_be_eaten){
                int i = kk.fi;
                int j = kk.se;
                if(to_be_eaten(i, j)){
                    // if(R[(i)*c+j+1] == Empty)cerr<<"BBBBBBBBB";
                    // if(i == r && j+1 == 0)cerr<<"WHAT THE FUCKa";
                    to_eat[1-cur].insert({i, j});
                }
            }
            to_eat[cur].clear();
            // cerr<<ans<<endl;
            if(act)ans += sum;
            // cerr<<ans<<endl;
            cur = 1 - cur;
        }
        cout<<ans<<endl;
    }
}
