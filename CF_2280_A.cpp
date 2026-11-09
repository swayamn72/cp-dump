#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        bool flag = true;

        ll odd = 0, even = 0;
        for(auto x : a) if(x%2) odd++; else even++;

        ll odd2 = 0, even2 = 0;
        for(auto x : b) if(x%2) odd2++; else even2++;

        if(k%2==0){
            // even->odd no 
            if(even>even2) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }else{
            // odd->even no
            if(odd>odd2) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }     
    }
}