#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll res = 0; 
        priority_queue<ll> pq;
        ll cursum = 0;
        for(ll i=m; i<n; i++){
            cursum += arr[i];
            if(arr[i]<0) pq.push(-arr[i]);
            if(cursum<0){
                cursum += (2*pq.top()); pq.pop();
                res++;
            }
        }
        if(m==1){
            cout << res << "\n";
            continue;
        }
        if(arr[m-1]>0){
            res++;
            arr[m-1] = -arr[m-1];
        }

        priority_queue<ll> pq2;
        ll curr = 0;

        for(ll i=m-1; i>=1; i--){
            curr += arr[i];
            if(arr[i]>0) pq2.push(arr[i]);
            if(curr>0){
                curr -= 2*pq2.top(); pq2.pop();
                res++;
            }
        }
        cout << res << "\n";
    }
}