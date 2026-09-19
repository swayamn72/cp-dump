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
        vi arr(n); 
        arr[0] = 1; arr[n-1] = 2;
        for(ll i=1; i<n-1; i++) arr[i] = i+2;
        for(auto a : arr) cout << a << " ";
        cout << "\n";        
    }
} 