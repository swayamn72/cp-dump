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
        for(ll i=0; i<n-1; i++) arr[i] = i+2;
        arr[n-1] = 1;
        for(auto a : arr) cout << a << " ";
        cout << "\n";       
    }
} 