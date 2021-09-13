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
    int n, p; //num teams, num problems
    cin>>n>>p; // input above
    int last = -1; // initialize last element. We need this to be smaller than any input.
    vector<int>A(n); // store the n answers integers
    fori(n){ // iterate over all the penalties
        int cur;
        cin>>cur; // stores penalty
        if(cur == 0){ // no problem solved
            if(i != 0 && p != 1 && p != 0){ // will be ambiguous if there is a problem amount still not assigned
                cout<<"ambiguous"<<endl;
                exit(0);
            }
            p = 0; // all remaining people will solve 0
        }
        else if(cur < last){ // only reduce number of solved problems if we receive a lower penalty
            p--; // impossible to reach 0 here, as scoreboard is valid
        }
        A[i] = p; // assign the answer for the current team
        last = cur; // update last
    }
    if(p > 1){ // this means that there is some leeway, and we can -- all amounts of solves
        cout<<"ambiguous"<<endl;
    }
    else{ // otherwise the number of problems is tight
        fori(n)cout<<A[i]<<endl;
    }
}