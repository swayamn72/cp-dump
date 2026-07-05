#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll sum = accumulate(arr.begin(),arr.end(),0LL);
    if(arr[n-1]>0 || sum!=0){
        cout << -1 << "\n";
        return 0;
    }
    ll left = 1, right = n-1;
    ll res = -1;
    vi need(n), give(n);
    need[0] = max(0LL,-arr[0]);
    give[0] = max(0LL,arr[0]);
    for(ll i=1; i<n; i++){
        need[i] = need[i-1] + max(0LL,-arr[i]);
        give[i] = give[i-1] + max(0LL,arr[i]);
    }

    vi suff(n); suff[n-1] = arr[n-1];
    for(ll i=n-2; i>=0; i--) suff[i] = suff[i+1] + arr[i];
    while(left<=right){
        ll mid = left + (right-left)/2;
        bool flag = true;

        
        for(ll i=0; i<n; i++){
            ll avail = 0;
            if(i-mid>=0) avail = give[i-mid];
            if(need[i]>avail){
                flag = false;
                break;
            }
        }
        if(flag){
            res = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << res << "\n";
}