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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp;
        for(auto a : arr) mp[a]++;
        vi doubles, singles;
        for(auto a : mp){
            if(a.second%2) singles.push_back(a.first);
            for(ll i=0; i<(a.second/2); i++){
                doubles.push_back(a.first);
            }
        }
        
        sort(singles.rbegin(),singles.rend());
        sort(doubles.rbegin(),doubles.rend());
        ll sum = accumulate(doubles.begin(),doubles.end(),0LL);
        ll res = 0;
        if(doubles.size()>=2){
            res = 2*sum;
        }
        if(sum!=0){
            for(auto a : singles){
                if(a<(2*sum)){
                    res = max(res,2*sum+a);
                }
            }
            for(ll i=1; i<singles.size(); i++){
            if(singles[i-1]-singles[i]<2*sum){
                ll val = singles[i-1], val2 = singles[i];
                res = max(res,2*sum+val+val2);
            }
        }
        }
        
        cout << res << "\n";
    }
}