#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t = 1; 
    while(t--){
        ll n,d; cin >> n >> d;
        vector<ll> arr(1e6+2,0);
        for(ll i=0; i<n; i++){
            ll start, end; cin >> start >> end;
            ll lateststart = end - d;
            if(lateststart>=start){
                arr[start]++;
                arr[lateststart+1]--;
            }
        }
        ll curr = 0;
        ll res = 0;
        for(ll i=1; i<=1e6; i++){
            curr += arr[i];
            if(curr>=2){
                res += (curr*(curr-1))/2;
            }
        }
        cout << res;
    }
}