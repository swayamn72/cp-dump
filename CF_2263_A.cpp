#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll ones = 0;
        for(auto a : arr) if(a==1) ones++;
        ll zeros = n-ones;
        if(ones>=zeros) cout << "Bessie" << "\n";
        else cout << "Elsie" << "\n";        
    }
} 