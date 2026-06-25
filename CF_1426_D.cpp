#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll cursum = 0;
    set<ll> s;
    s.insert(0);
    ll res = 0;
    for(ll i=0; i<n; i++){
        cursum += arr[i];
        if(s.count(cursum)){
            res++;
            s.clear(); 
            s.insert(0); 
            s.insert(arr[i]);
            cursum = arr[i];
        }        
        s.insert(cursum);
    }
    cout << res << "\n";
}
// 0 1 -4 -1
// 1 