#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll a,b,x,y; cin >> a >> b >> x >> y;
        x = abs(x); y = abs(y);
        ll horizontal = x, vertical = y;
        ll minv = min(x,y);
        ll res = 0;
        res += (min(a,b) * minv);
        x -= minv; y -= minv;
        if(vertical==0 && horizontal==0){
            cout << res << "\n";
            continue;
        }
        // cout << res << "\n";
        if(a<=b){
            // horizontal cost less on odd
            if(horizontal>0){
                horizontal--; res += a;
                ll ans;
                if(horizontal%2==0){
                    ans = (horizontal*2-1)*a;
                }else{
                    ans = 
                }
            }
        }else{

        }
    }
}