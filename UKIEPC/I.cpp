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
    int n;
    cin>>n;
    vector<int>A(n);
    fori(n){
        cin>>A[i];
    }
    vector<int> B = A;
    map<int, int>M;
    sort(B.begin(), B.end());
    fori(n)M[A[i]] = i;
    cout<<3<<endl;

    // 1st iteration
    vector<int>ans; // store positions to change
    fori(n/4){ // store the first n/4 positions
        ans.push_back(i);
    }
    for(int i=0; i<n && (int)ans.size() < n/2; i++){ // store (at most) n/4 smallest elements out of position
        if(M[B[i]] != i && M[B[i]] >= n/4){
            ans.push_back(M[B[i]]);
        }
    }
    for(int i=0; i<n && (int)ans.size() < n/2; i++){ // store remaining smallest elements that are in position
        if(M[B[i]] == i && M[B[i]] >= n/4){
            ans.push_back(M[B[i]]);
        }
    }
    vector<int>array; // elements that we are soting
    for(auto i: ans)array.push_back(A[i]); // collect
    // for(auto j: array){debug(j);}
    // cerr<<endl;
    sort(ans.begin(), ans.end());
    sort(array.begin(), array.end()); //sort
    // for(auto j: array){debug(j);}
    for(int i=0; i<n/2; i++)A[ans[i]] = array[i]; // reassign
    // for(auto i: A){debug(i);}
    fori(n)M[A[i]] = i; // update map
    
    for(auto i: ans)cout<<i+1<<" ";
    cout<<endl; // print the indices
    ans.clear(); // clear for next iteration

    // the first n/4 elements should be sorted at this point
    // ITERATION 2

    forii(n/4, n/2){ // the next n/4 unsorted positions
        ans.push_back(i);
    }
    for(int i=0; i<n && (int)ans.size() < n/2; i++){ // add (at most) n/4 smallest elements out of position
        if(M[B[i]] != i && M[B[i]] >= n/2){
            ans.push_back(M[B[i]]);
        }
    }
    for(int i=0; i<n && (int)ans.size() < n/2; i++){ // add remaining smallest elements
        ans.push_back(A[i]);
    }
    sort(ans.begin(), ans.end());
    for(auto i: ans)cout<<i+1<<" ";
    cout<<endl; // print out the answer
    ans.clear();

    forii(n/2, n){ // bottom half sorted; sort top half
        cout<<i+1<<" ";
    }cout<<endl;
}