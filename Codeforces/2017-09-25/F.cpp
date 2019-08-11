#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
// #define endl '\n'

int Path[3001];
bool Exists[3001][3001];

int main(){
	// ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m, q;
	cin>>n>>m>>q;
	// cerr<<'a'<<endl;
	for(int i=0; i<=n; i++)Path[i]=4000;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		// cerr<<u<<" "<<v<<endl;
		Path[u]=min(Path[u], v); 	
		// cerr<<u<<" "<<Path[u]<<" "<<v<<" "<<Path[v]<<endl;
	}

	for(int i=1; i<=n; i++){
		if(Path[i]==4000)continue;
		int c=Path[i];
		set<int>Checked;
		Checked.insert(i);
		while(true){
			if(Checked.count(c))break;
			// cerr<<c<<" "<<Path[c]<<endl;
			Exists[i][c]=true;
			Checked.insert(c);
			c=Path[c];
		}
	}
	int s, t, k;
	// cerr<<'a'<<endl;
	for(int i=0; i<q; i++){
		cin>>s>>t>>k;
		// cerr<<s<<" "<<t<<endl;
		if(!Exists[s][t])cout<<-1<<endl;
	}
}