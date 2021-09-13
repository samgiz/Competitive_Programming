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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    
    ll c, e, m;
    cin>>c>>e>>m;
    if(c!=4 || e % 2 != 0){
        cout<<"impossible"<<endl;
        exit(0);
    }
    // e / 2 ^2 = (h-2)^2 + (w-2)^2 + 2m
    // e = 2*(h-2) + 2*(w-2)
    // m = (h-2)*(w-2)
    // w >= h
    if(m == 0){
        ll h = 2;
        ll w = e / 2 + 2;
        cout<<w<<" "<<h<<endl;
        exit(0);
    }
    for(ll i = 1; i*i<=m; i++){
        if(m % i == 0){
            ll h = i;
            ll w = m / i;
            if(e == 2*h + 2*w){
                cout << w+2 <<" "<< h+2<<endl;
                exit(0);
            }
        }
    }
    cout<<"impossible"<<endl;
}