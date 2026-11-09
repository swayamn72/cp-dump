#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Basis{
    ll b[60] = {0};
    ll sz = 0;
    void insert(ll x){
        for(ll i=59; i>=0; i--){
            if((x>>i)&1LL){
                if(!b[i]){
                    b[i] = x;
                    sz++;
                    return;
                }
                x^=b[i];
            }
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll xorsum = 0;
        Basis basis;
        for(auto a : arr){
            xorsum ^= a;
            basis.insert(xorsum);
        }        
        if(xorsum==0){
            cout << -1 << "\n";
            continue;
        }
        cout << basis.sz << "\n";
    }
}