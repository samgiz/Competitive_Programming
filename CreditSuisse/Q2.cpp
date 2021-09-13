#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    int prev;
    cin>>prev;
    for(int i=1; i<n; i++){
        int next;
        cin>>next;
        ans += max(0, next - prev);
        prev = next;
    }
    cout<<ans;
}