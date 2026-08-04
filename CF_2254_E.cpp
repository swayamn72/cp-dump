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
        vi pos, neg;
        for(auto a : arr){
            if(a>0) pos.push_back(a);
            else neg.push_back(a);
        }        
        if(pos.empty()){
            cout << -1 << "\n";
            continue;
        }
        vi pref;
        map<ll,ll> mp;
        for(auto a : neg) mp[-a]++;
        sort(pos.begin(),pos.end());
        ll cursum = 0;
        ll ptr = 0;
        bool flag = true;
        while(ptr<pos.size()){
            cursum += pos[ptr];
            pref.push_back(pos[ptr]);
            ptr++;

            while(true){
                auto it = mp.lower_bound(cursum);
                if(it==mp.begin()) break;
                it--;
                cursum -= it->first;
                pref.push_back(-(it->first));
                it->second--;
                if(it->second==0) mp.erase(it);
            }
        }
        if(pref.size()<n){
            cout << -1 << "\n";
            continue;
        }
        vi res(n); res[0] = pref[0];
        for(ll i=1; i<n; i++) res[i] = res[i-1] + pref[i];
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}