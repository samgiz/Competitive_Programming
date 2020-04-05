#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef int def; //default parameter for loops
#define fori(a) for(def i=0; i<(a); i++)
#define forii(a, b) for(def i=(a); i<(b); i++)
#define forj(a) for(def j=0; j<(a); j++)
#define forjj(a, b) for(def j=(a); j<(b); j++)
#define fork(a) for(def k=0; k<(a); k++)
#define forkk(a, b) for(def k=(a); k<(b); k++)
#define fore(a) for(def e=0; e<(a); e++)
#define foree(a, b) for(def e=(a); e<(b); e++)
#define forl(a) for(def l=0; l<(a); l++)
#define forll(a, b) for(def l=(a); l<(b); l++)

#define fastInputOutput ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// #define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


void pr(int a, int b){
	cout<<a<<" "<<b<<endl;
}

void join(int a, int b, int c, int d){
	pr(a, c);
	pr(a, d);
	pr(b, c);
	pr(b, d);
}
bool E[60][60], Ring[60][60];
bool Checked[60];
int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		int l, u;
		cin>>l>>u;
		u = 15;
		cout<<u<<endl;
		fori(u-1)pr(i+1, i+2);
		pr(u, 1);

		pr(1, 4);
		pr(4, 9);
		pr(9, 1);

		join(2, 3, 10, 11);
		join(5, 6, 12, 13);
		join(7, 8, 14, 15);

		int n;
		cin>>n;
		for(auto &i: E){
			for(auto &j: i)j = 0;
		}
		for(auto &i: Ring){
			for(auto &j: i)j = 0;
		}
		for(auto &i: Checked){
			i = 0;
		}
		fori(2*n){
			int a, b;
			cin>>a>>b;
			E[b][a]=1;
			E[a][b]=1;
		}


		forii(1, n+1){
			forjj(1, n+1){
				if(!E[i][j])continue;
				int cnt = 0;
				forkk(1, n+1){
					cnt+=(E[i][k]&&E[j][k]);
				}
				if(cnt==2){
					Ring[i][j]=1;
					Ring[j][i]=1;
					Checked[i]=1;
					Checked[j]=1;
				}
			}
		}
		vector<int>A;
		forii(1, n+1){
			if(!Checked[i]){
				A.pb(i);
				forjj(1, n){
					if(Checked[j]&&E[i][j])Ring[i][j]=1, Ring[j][i]=1;
				}
			}
		}
		for(auto i: A)cerr<<i<<" : ";cerr<<endl;
		vector<int>Ans;
		for(auto i: A){
			int last = i, cur;
			Ans.pb(i);
			forjj(1, n+1){
				if(Ring[j][last]){
					cur=j;
					while(cur!=i){
						cerr<<cur<<": ";
						Ans.pb(cur);
						forkk(1, n+1){
							if(k!=last&&Ring[k][cur]){
								last = cur;
								cur = k;
								break;
							}
						}

					}
					cerr<<endl;
					break;
				}
			}
			if(!Checked[Ans[3]]&&!Checked[Ans[8]])break;
			else Ans.clear();
			Ans.pb(i);
			last = i;
			for(int j=n; j>0; j--){
				if(Ring[j][last]){
					cur=j;
					while(cur!=i){
						cerr<<cur<<": ";
						Ans.pb(cur);
						forkk(1, n+1){
							if(k!=last&&Ring[k][cur]){
								last = cur;
								cur = k;
								break;
							}
						}

					}
					cerr<<endl;
					break;
				}
			}
			if(!Checked[Ans[3]]&&!Checked[Ans[8]])break;
			else Ans.clear();
		}
		for(auto i: Ans)cout<<i<<" ";cout<<endl;
	}
}
