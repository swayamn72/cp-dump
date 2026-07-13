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
        ll n,k,x; cin >> n >> k >> x;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        
        int left = 1, right = x;
        vi res;
        while(left<=right){
            ll m = left + (right-left)/2;
            vi pos;
            
            for(ll i=1; i<arr.size(); i++){
                ll lefti = arr[i-1]+m, righti = arr[i]-m;
                for(ll j=lefti; j<=righti; j++){
                    pos.push_back(j);
                    if(pos.size()>=k) break;
                }
                if(pos.size()>=k) break;
            }
            ll idx = arr[0] - m;
            for(ll i=0; i<=idx; i++){
                if(pos.size()>=k) break;
                pos.push_back(i);
            }
            idx = arr[arr.size()-1] + m;
            for(ll i=idx; i<=x; i++){
                if(pos.size()>=k) break;
                pos.push_back(i);
            }
            if(pos.size()>=k){
                res = pos;
                left = m+1;
            }else{
                right = m-1;
            }
        }
        if(res.size()==0){
            for(ll i=0; i<k; i++) res.push_back(i);
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}