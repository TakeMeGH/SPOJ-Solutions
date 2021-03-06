/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD                 1000000007LL
#define pb                   push_back
#define EPS                 1e-9
#define FOR(i,n)             for(int i = 0;i < n; i++)
#define FORE(i,a,b)         for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io                     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl                 '\n'
#define F                     first
#define S                     second
#define sp                     ' '
#define M_PI                   3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e4+5;
int minMoney[MAXN];

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        int e, f, n;
        cin >> e >> f >> n;
        FORE(i,1,MAXN)  minMoney[i] = MOD;
        vector<ii> table;
        FOR(i, n){
            int val, weight; cin >> val >> weight; table.pb({weight, val});
        }
        int diff = f-e;
        sort(table.begin(), table.end());
        int minnWeight = table[0].F;
        minMoney[0] = 0;
        for(int i = minnWeight; i <= diff; i++){
            // to change value of minMoney[i]
            for(int j = 0;j < table.size(); j++){
                int w = table[j].F;
                int v = table[j].S;
                if(w > i)
                    break;
                else{
                    minMoney[i] = min(minMoney[i], minMoney[i-w] + v);
                }
            } 
        }
        if(minMoney[diff] == MOD)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << minMoney[diff] << "." << endl;
    }
    return 0;
}
