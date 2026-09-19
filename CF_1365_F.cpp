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
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        bool flag = true;
        
        if(n%2 && a[n/2]!=b[n/2]){
            cout << "No" << "\n";
            continue;
        }
        ll ptr = n;
        for(ll i=0; i<n/2; i++){
            ptr--;
            if(a[i]==b[i] && a[ptr]==b[ptr]) continue;
            if(a[i]==b[ptr] && a[ptr]==b[i]) continue;
            flag = false; break;
        }
        cout << (flag ? "Yes" : "No") << "\n";
    }
} 