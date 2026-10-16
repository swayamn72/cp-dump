#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << 0 << "\n";
            continue;
        }
        vi suffgcd(n); 
        suffgcd[n-1] = 0;
        for(ll i=n-2; i>=0; i--) suffgcd[i] = gcd(suffgcd[i+1],arr[i+1]);
        // for(auto a : suffgcd) cout << a << " "; cout << "\n";

        vector<vi> vv; 
        ll maxv = arr[n-1], minv = arr[n-1];
        for(ll i=0; i<n-1; i++){
            if(suffgcd[i]==0){
                maxv = max(maxv,arr[i]);
                minv = min(minv,arr[i]);
            }
        }
        for(ll i=0; i<n-1; i++){
            if(suffgcd[i]==0) continue;
            if(arr[i]>=minv && arr[i]<=maxv) continue;
            if(arr[i]<minv){
                ll diff = minv-arr[i];
                ll g = suffgcd[i];
                ll div = diff/g;
                arr[i]+=div*g;
            }else{
                ll diff = arr[i]-minv;
                ll g = suffgcd[i];
                ll div = (diff+g-1)/g;
                arr[i] -= div*g;
            }
            vv.push_back({arr[i],suffgcd[i]});
        }
        if(vv.empty()){
            cout << maxv-minv << "\n";
            continue;
        }
        ll res = LLONG_MAX;
        // for(auto a : vv) cout << a[0] << " " << a[1] << "\n";
        sort(vv.begin(),vv.end());
        for(ll i=0; i<vv.size(); i++){
            res = min(res,maxv-vv[i][0]);
            maxv = max(maxv,vv[i][0]+vv[i][1]);
        }
        res = min(res,maxv-minv);
        cout << res << "\n";
    }
}