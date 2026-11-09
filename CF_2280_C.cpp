#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll res = 0;
        for(ll i=1; i<n; i++) res = max(res,abs(arr[i]-arr[i-1]));

        vi diff(n,0);
        for(ll i=1; i<n; i++){
            diff[i] = abs(arr[i]-arr[i-1]);
        }
        ll maxdiff = *max_element(diff.begin(),diff.end());
        if(maxdiff==0){
            cout << 0 << "\n";
            continue;
        }
        ll left = -1;
        for(ll i=0; i<n; i++){
            if(maxdiff==diff[i]){
                left = i;
                break;
            }
        }
        ll right = -1;
        for(ll i=n-1; i>=0; i--){
            if(maxdiff==diff[i]){
                right = i;
                break;
            }
        }
        if(right!=left){
            for(ll i=left; i<=right-1; i++){
                arr[i]*=2;
            }
            reverse(arr.begin()+left,arr.begin()+right);
            ll res2 = 0;
            for(ll i=1; i<n; i++){
                res2 = max(res2,abs(arr[i]-arr[i-1]));
            }
            cout << min(res,res2) << "\n";
            continue;
        }
        vi pref(n+1,0);
        for(ll i=1; i<n; i++) pref[i] = max(pref[i-1],diff[i]);

        vi suff(n+1,0);
        for(ll i=n-1; i>=1; i--) suff[i] = max(suff[i+1],diff[i]);
        
        ll temp = 0;
        for(ll i=left; i<n; i++){
            if(i>left) temp = max(temp,2*diff[i]);
            ll curr = max({pref[left-1],abs(arr[left-1]-2*arr[i]),temp});
            if(i!=n-1) curr = max({curr,abs(2*arr[left]-arr[i+1]),suff[i+2]});
            res = min(res,curr);
        }
        temp = 0;
        for(ll i=left-1; i>=0; i--){
            if(i<=left-2) temp = max(temp,2*diff[i+1]);
            ll curr = max({abs(2*arr[i]-arr[left]),suff[left+1],temp});
            if(i>=1) curr = max({curr,abs(arr[i-1]-2*arr[left-1]),pref[i-1]});
            res = min(res,curr);
        }
        cout << res << "\n";
    }
}