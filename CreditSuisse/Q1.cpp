#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    int mini;
    cin>>mini;
    for(int i=1; i<n; i++){
        int a;
        cin>>a;
        mini = min(a, mini);
        ans = max(ans, a - mini);
        // cerr<<a<<" "<<mini<<" "<<ans<<endl;
    }
    cout<<ans;
}