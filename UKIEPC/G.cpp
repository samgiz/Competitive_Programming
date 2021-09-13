#include <bits/stdc++.h>

using namespace std;

#define fori(a) for(int i=0; i<(a); i++)
#define forii(a, b) for(int i=(a); i<(b); i++)
#define forj(a) for(int j=0; j<(a); j++)
#define forjj(a, b) for(int j=(a);j<(b); j++)

#define debug(...) cerr<<"dbg(";_debug(#__VA_ARGS__, __VA_ARGS__)


#define ll long long
#define endl "\n"
template <typename Arg1>
void _debug(const char* name, Arg1&& arg1){
    while(*name == ' ' || *name == ','){
        ++name;
    }
    cerr<<name<<" : "<<arg1<<')'<<endl;

}
template <typename Arg1, typename... Args>
void _debug(const char* names, Arg1&& arg1, Args&&... args){
    int depth = 0;
    string variable;
    while(*names == ' '||*names == ',')++names;
    while(*names != ','|| depth){
        if(*names == '[' || *names == '{' || *names == '(')depth++;
        if(*names == ']' || *names == '}' || *names == ')')depth--;
        variable += *names;++names;
    }
    while(variable.back()==' ')variable.pop_back();
    cerr << variable << " : " << arg1 << " | " ;
    _debug(names, args...);
}

struct Tres{
    int a, b;
    ll cost;
    bool vis = false;
    Tres(int ii, int jj, int hh){
        a =ii;
        b =jj;
        cost =hh;
    }
};

vector<int>Rank, Par;

int parent(int k){
    if(k == Par[k])return k;
    return Par[k] = parent(Par[k]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector<Tres>Links;
    fori(m){
        int city, cost;
        cin>>city>>cost;
        Links.push_back(Tres(0, city, cost));
    }
    fori(n){
        int cost;
        cin>>cost;
        Links.push_back(Tres(i+1, (i+1)%n+1, cost));
    }
    sort(Links.begin(), Links.end(), [](Tres a, Tres b){
        return a.cost < b.cost;
    });
    Rank.resize(n+1), Par.resize(n+1);
    fori(n+1)Par[i] = i;
    ll ans = 0;
    int components = n+1;
    for(auto tres: Links){
        int a = parent(tres.a);
        int b = parent(tres.b);
        if(a == b)continue;
        // debug(tres.a, tres.b);
        ans += tres.cost;
        if(Rank[a] >= Rank[b]){
            if(Rank[a] == Rank[b]){
                Rank[a]++;
            }
            Par[b] = a;
        }
        else Par[a] = b;
        components -= 1;
        if(components == 1)break;
    }
    // debug(components);
    cout<<ans<<endl;
}