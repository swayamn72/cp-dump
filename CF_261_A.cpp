#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m; cin >> m;
    vector<ll> q(m); for(auto &x : q) cin >> x;
    ll n; cin >> n;
    vector<ll> arr(n); for(auto &x : arr) cin >> x;

    sort(q.begin(),q.end());
    sort(arr.rbegin(),arr.rend());
    ll res = 0;
    ll val = q[0];
    ll ptr = 0;
    while(ptr<n){
        for(ll i=ptr; i<ptr+val; i++){
            if(i>=n) break;
            res += arr[i];
        }
        ptr += (val+2);
    }
    cout << res;
}