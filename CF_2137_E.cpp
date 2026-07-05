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
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        map<ll,ll> mp;
        for(auto a : arr) mp[a]++;
        ll mex = 0;
        while(mp.count(mex)) mex++;
        ll m = 0;
        while(mp.count(m) && mp[m]==1) m++;
        // cout << mex << "\n";
        k--; 
        ll count = 0;
        for(ll i=0; i<n; i++){
            if(mp[arr[i]]>1 || arr[i]>mex){
                arr[i] = mex;
                count++;
            }
        }
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        if(count>1 && k>0){
            if(m==mex){
                if(k%2) sum += count;
            }else{
                sum = m*(m-1)/2;
                if(k%2){
                    sum += (n-m)*m;
                }else{
                    sum += (n-m)*(m+1);
                }
            }
        }
        cout << sum << "\n";
    }
}