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
        vector<string> arr(3);
        for(auto &x : arr) cin >> x;
        for(auto a : arr) cout << a[0];
        cout << "\n";        
    }
} 