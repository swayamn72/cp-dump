#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,x,y; cin >> n >> x >> y;
        if(n==1){
            cout << "YES" << "\n";
            continue;
        }
        vi fib(n+2);
        fib[0] = 1;
        fib[1] = 1;
        for(ll i=2; i<=n+1; i++) fib[i] = fib[i-1] + fib[i-2];
        // for(auto a : fib) cout << a << " ";
        // cout << "\n";

        ll h = fib[n], w = fib[n+1];
        // cout << h << " " << w << "\n";
        bool flag = true;
        while(n>1){
            if(y>fib[n-1] && y<=fib[n]){
                flag = false;
                break;
            }
            ll nextx, nexty;
            if(y<=fib[n-1]){
                nextx = y;
            }else{
                nextx = y - fib[n];
            }
            nexty = x;
            x = nextx;
            y = nexty;
            n--;
        }
        cout << (flag ? "YES" : "NO") << "\n";
        continue;

        ll val1 = h-x;
        val1 = max(val1,h-val1-1);
        
        ll val2 = w-y;
        val2 = max(val2,w-val2-1);

        if(val2>val1) swap(val2,val1);

        // cout << "val1 : " <<   val1 << "   val2 : " << val2 << "\n";

        if(val1>=fib[n] && val2>=fib[n-1]){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }

    }
}
// 5 2 12