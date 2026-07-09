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
        map<ll,ll> mp;
        for(auto a : arr) mp[a]++;
        ll total = n;
        ll res = 0;
        ll count = mp.size();

        while(count>0){
            bool flag = false;
            for(auto a : mp){
                if(a.second==1){
                    flag = true;
                    break;
                }
            }
            if(flag && total<=k){
                ll diff = k-total;
                if(diff%count==0){
                    res++;
                }
            }

            vi todelete;
            for(auto &a : mp){
                a.second--;
                total--;
                if(a.second==0){
                    todelete.push_back(a.first);
                    count--;
                }
            }
            for(auto a : todelete){
                mp.erase(a);
            }
        }
        
        cout << res << "\n";
    }
}