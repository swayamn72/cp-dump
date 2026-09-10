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
        if(arr[0]==0 && arr[n-1]==0){
            cout << 0 << "\n";
            continue;
        }        
        ll zeros = 0;
        for(auto a : arr) if(!a) zeros++;
        if(zeros<=1){
            cout << -1 << "\n";
            continue;
        }
        ll count = 0;
        if(arr[0]==0) count++;
        if(arr[n-1]==0) count++;
        cout << 2 - count << "\n";
    }
} 