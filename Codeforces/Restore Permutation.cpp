#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef int def; //default parameter for loops

#define fori(a) for(def i=0; i<(a); i++)
#define fori1(a) for(def i=1; i<=(a); i++)
#define fori_(a) for(def i=(a)-1; i>=0; i--)
#define fori1_(a) for(def i=(a); i>0; i--)
#define forii(a, b) for(def i=(a); i<(b); i++)
#define forii_(a, b) for(def i=(b)-1; i>=(a); i--)

#define forj(a) for(def j=0; j<(a); j++)
#define forj1(a) for(def j=1; j<=(a); j++)
#define forj_(a) for(def j=(a)-1; j>=0; j--)
#define forj1_(a) for(def j=(a); j>0; j--)
#define forjj(a, b) for(def j=(a); j<(b); j++)
#define forjj_(a, b) for(def j=(b)-1; j>=(a); j--)

#define fork(a) for(def k=0; k<(a); k++)
#define fork1(a) for(def k=1; k<=(a); k++)
#define fork_(a) for(def k=(a)-1; k>=0; k--)
#define fork1_(a) for(def k=(a); k>0; k--)
#define forkk(a, b) for(def k=(a); k<(b); k++)
#define forkk_(a, b) for(def k=(b)-1; k>=(a); k--)

#define forl(a) for(def l=0; l<(a); l++)
#define forl1(a) for(def l=1; l<=(a); l++)
#define forl_(a) for(def l=(a)-1; l>=0; l--)
#define forl1_(a) for(def l=(a); l>0; l--)
#define forll(a, b) for(def l=(a); l<(b); l++)
#define forll_(a, b) for(def l=(b)-1; l>=(a); l--)

#define forg(a) for(def g=0; g<(a); g++)
#define forg1(a) for(def g=1; g<=(a); g++)
#define forg_(a) for(def g=(a)-1; g>=0; g--)
#define forg1_(a) for(def g=(a); g>0; g--)
#define forgg(a, b) for(def g=(a); g<(b); g++)
#define forgg_(a, b) for(def g=(b)-1; g>=(a); g--)

#define forf(a) for(def f=0; f<(a); f++)
#define forf1(a) for(def f=1; f<=(a); f++)
#define forf_(a) for(def f=(a)-1; f>=0; f--)
#define forf1_(a) for(def f=(a); f>0; f--)
#define forff(a, b) for(def f=(a); f<(b); f++)
#define forff_(a, b) for(def f=(b)-1; f>=(a); f--)

#define forh(a) for(def h=0; h<(a); h++)
#define forh1(a) for(def h=1; h<=(a); h++)
#define forh_(a) for(def h=(a)-1; h>=0; h--)
#define forh1_(a) for(def h=(a); h>0; h--)
#define forhh(a, b) for(def h=(a); h<(b); h++)
#define forhh_(a, b) for(def h=(b)-1; h>=(a); h--)

#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
  }
  return out;
}
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::set<T>& v) {
  if ( !v.empty() ) {
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
  }
  return out;
}

const int N = 2e5+10;
const ll M = 1e9+7;

// Initial array and final answer array
ll P[N], Ans[N];

// sum keeps the sum of leaves in [a, b)
// l, r are children of node, which correspond to intervals [a, (a+b)/2) and [(a+b)/2, b)
struct node{
	ll a, b, sum;
	node *l, *r;
};

// Root node for segment tree
node* root = new node();

// Initialize segment tree. The leaves of the tree have values 0 through n inclusive.
void buildT(node*& cur, int a, int b){
	// Set interval
	cur->a = a;
	cur->b = b;
	if(a == b-1){
		// Base case
		cur->sum = a;
		return;
	}
	// Initialize empty chilren
	cur->l = new node();
	cur->r = new node();
	// Populate children
	buildT(cur->l, a, (a+b)/2);
	buildT(cur->r, (a+b)/2, b);
	// Calculate sum of interval [a, b)
	cur->sum = cur->l->sum + cur->r->sum;
}

// Get index of element for which the sum of smaller remaining elements is target
int getIndex(node*& cur, ll target){
	// Search for the first element with higher sum than target. This will be the required element.
	// Note: we can't search for the first element to match the sum and return an element that is one higher, since some elements might have a value of 0.
	if(cur->a == cur->b - 1)return cur->a;
	if(cur->l->sum <= target)return getIndex(cur->r, target-cur->l->sum);
	return getIndex(cur->l, target);
}

// Update element at index to 0
void updateT(node*& cur, int index){
	if(cur->a == cur->b - 1){
		// We arrived at the required index, remove element from further sum calculations
		cur->sum=0;
		return;
	}

	// Make sure to traverse the correct branch
	if(cur->r->a <= index)updateT(cur->r, index);
	else updateT(cur->l, index);

	// Recalculate sum
	cur->sum = cur->l->sum + cur->r->sum;
}

// Print all elements of the segment tree
void printAll(node*& cur){
	if(cur->a == cur->b - 1){
		cerr<<cur->sum<<" ";
		return;
	}
	printAll(cur->l);
	printAll(cur->r);
}

int main(){
	fastIO;

	// Read data
	int n;
	cin>>n;
	fori(n){
		cin>>P[i];
	}

	// Initialize segment tree (P is not required for this step)
	buildT(root, 0, n+1);

	// Calculate the answer backwards so that we know which elements can be counted in the provided sum
	fori_(n){
		// Find which index is at position i
		Ans[i] = getIndex(root, P[i]);
		// Remove the element from further calculations
		updateT(root, Ans[i]);
	}
	// Print answer
	fori(n)cout<<Ans[i]<<" ";
}
