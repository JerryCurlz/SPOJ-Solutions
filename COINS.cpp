/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
ll dp[1000005];
void solve(){
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i < 1000005; i++){
		dp[i] = max((ll)i, dp[(int)i/2]+dp[(int)i/3]+dp[(int)i/4]);
	}
}
ll recurse(int n){
	if(n <= 1000000)
		return dp[n];
	return recurse(n/2)+recurse(n/3)+recurse(n/4);
}
int main(){
	solve();
	int n; 
    while(scanf("%d", &n) != EOF){
    	if(n <= 1000000){
    		cout<<dp[n]<<endl;
    	}else{
    		cout<<recurse(n)<<endl;
    	}
    }
    return 0;
}