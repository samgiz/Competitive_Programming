#include <bits/stdc++.h>

using namespace std;

int main(){
	set<string>Normal, Grumpy;
	Normal.insert("don't think so");
	Normal.insert("great!");
	Normal.insert("not bad");
	Normal.insert("don't touch me!");
	Normal.insert("cool");
	
	Grumpy.insert("are you serious?");
	Grumpy.insert("go die in a hole");
	Grumpy.insert("worse");
	Grumpy.insert("terrible");
	Grumpy.insert("don't even");
	Grumpy.insert("no way");	
	for(int i=0; i<10; i++){
		cout<<i<<endl;
		string tp;
		getline(cin, tp);
		if(Grumpy.count(tp)){
			cout<<"grumpy"<<endl;
			return 0;
		}
		if(Normal.count(tp) || i > 2){
			cout<<"normal"<<endl;
			return 0;
		}
	}
}
