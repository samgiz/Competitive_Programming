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

// struct Tres{
//     int i, j, h;
//     bool vis = false;
//     Tres(int ii, int jj, int hh){
//         i =ii;
//         j =jj;
//         h =hh;
//     }
//     bool operator<(Tres t) const {
//         return h < t.h;
//     }
// }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int h, w;
    cin>>h>>w;
    vector<vector<int>>X(h, vector<int>(w));
    vector<vector<bool>>vis(h, vector<bool>(w));
    vector<pair<int, int>>els; 
    fori(h){
        forj(w){
            int x;cin>>x;els.push_back({i, j});
            X[i][j] = x;
        }
    }
    sort(els.begin(), els.end(), [&X](pair<int, int> a, pair<int, int> b){
        return X[a.first][a.second] > X[b.first][b.second];
    });
    int ans = 0;
    for(auto &i: els){
        int el = X[i.first][i.second];
        if(vis[i.first][i.second] || el <= 1)continue;
        ans += 1;
        vis[i.first][i.second] = true;
        stack<pair<int, int>>S;
        S.push(i);
        while(S.size()){
            auto t = S.top();
            int el = X[t.first][t.second];
            S.pop();
            vector<pair<int, int>>nbrs = {{t.first + 1, t.second}, {t.first - 1, t.second}, {t.first, t.second + 1}, {t.first, t.second - 1}};
            for(auto &i: nbrs){
                if(i.first >= 0 && i.second >= 0 && i.first < h && i.second < w){
                    int next = X[i.first][i.second];
                    if(next <= el && next != 0 && !vis[i.first][i.second]){
                        vis[i.first][i.second] = true;
                        S.push(i);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}