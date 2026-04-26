#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;   
    while(t--){
        ll n,k,p,m; cin >> n >> k >> p >> m;
        vi arr(n); for(auto &x:arr) cin >> x;
        if(k>=n){
            cout << m/arr[p-1] << "\n";
            continue;
        }
        ll wincost = arr[p-1];
        ll initialcost = wincost;
        if(p > k){
            vi frontcards;
            for(int i=0; i<p-1; i++) frontcards.push_back(arr[i]);
            sort(frontcards.begin(), frontcards.end());
            for(int i=0; i<p-k; i++) initialcost += frontcards[i];
        }
        if(m<initialcost){
            cout << 0 << "\n";
            continue;
        }
        ll res = 1;
        ll left = m - initialcost;
        vi othercards;
        for(int i=0; i<n; i++) {
            if(i!=p-1) othercards.push_back(arr[i]);
        }
        sort(othercards.begin(), othercards.end());
        ll cyclecost = wincost;
        for(int i = 0; i < n - k; i++) cyclecost += othercards[i];
        res += left/cyclecost;
        cout << res << "\n";
    }
    return 0;
}