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
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp; for(auto a : arr) mp[a]++;
        ll res = 0;
        while(!mp.empty()){ // mp[1] = 3 , mp[3] = 3;
            vi v;
            while(v.size()<m){
                vi toerase;
                for(auto a : mp){
                    mp[a.first]--;
                    v.push_back(a.first);
                    if(mp[a.first]==0) toerase.push_back(a.first);
                    if(v.size()==m) break;
                }
                for(auto a : toerase) mp.erase(a);
                if(mp.empty()) break;
            }
            sort(v.begin(),v.end());
            ll extra = 1;
            ll temp = 1;
            for(ll i=1; i<v.size(); i++){
                if(v[i]==v[i-1]){
                    temp++;
                    extra = max(temp,extra);
                }else{
                    temp = 1;
                }
            }
            if(res!=0) res -= (m-v[v.size()-1]);
            res += m; res += (extra-1); 
        }
        cout << res << "\n";
    }
}