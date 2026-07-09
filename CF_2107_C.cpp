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
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        vi arr(n); for(auto &x : arr) cin >> x;
        
        ll idx = 0;
        while(idx<n && s[idx]=='1') idx++;
        ll index = idx;
        idx++;
        for(ll i=idx; i<n; i++){
            if(s[i]=='0') arr[i] = -1e13;
        }
        // ll maxsum = 0;
        ll curr = 0;
        // for(ll i=0; i<n; i++){
        //     curr += arr[i];
        //     maxsum = max(maxsum,curr);
        //     if(curr<0) curr=0;
        // }
        if(index!=n){
            ll maxleft = 0;
            ll curr2 = 0;
            for(ll i=index-1; i>=0; i--){
                curr2+=arr[i];
                maxleft = max(maxleft,curr2);
            }
            curr2 = 0;
            ll maxright = 0;
            for(ll i=index+1; i<n; i++){
                curr2+=arr[i];
                maxright = max(maxright,curr2);
            }
            arr[index] = k - (maxleft+maxright);
        }
        ll ans = 0;
        curr = 0;
        for(ll i=0; i<n; i++){
            curr += arr[i];
            ans = max(ans,curr);
            if(curr<0) curr = 0;
        }
        if(ans==k){
            cout << "Yes" << "\n";
            for(auto a : arr) cout << a << " ";
            cout << "\n"; 
        }else{
            cout << "No" <<  "\n";
        }
    }
}