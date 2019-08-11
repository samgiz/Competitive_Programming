#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a, b, f, k, cnt=0, am;
	cin>>a>>b>>f>>k;
	bool lg=0;
	if(b<f||b<a-f||(b<2*f&&k>=3)||(b<2*(a-f)&&k>=2)){
		cout<<-1;
		return 0;
	}
	am=b;
	for(int i=0; i<k; i++){
		if(i==k-1){
			cnt+=(am<a);
			break;
		}
		if(lg==0){
			cnt+=(am<a+a-f);
			am=(am<a+a-f?b-a+f:am-a);
		}
		else{
			cnt+=(am<a+f);
			am=(am<a+f?b-f:am-a);
		}
		// cerr<<i<<" "<<am<<" "<<cnt<<endl;

		lg=!lg;
	}
	cout<<cnt;
	cerr<<endl;
}