#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
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
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(m==1){
            cout << *max_element(arr.begin(),arr.end()) << "\n";
            continue;
        } 
        ll res = LLONG_MIN;
        ll sum = 0;
        priority_queue<ll> pq;
        for(ll i=0; i<m-1; i++){
            sum += arr[i];
            pq.push(arr[i]);
        }
        for(ll i=m-1; i<n; i++){
            while(pq.size()>m-1){
                sum -= pq.top(); pq.pop();
            }
            res = max(res,m*arr[i]-sum);
            pq.push(arr[i]); sum += arr[i];
        }
        cout << res << "\n";
    }
} 