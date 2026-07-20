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
        if(k%2==0){
            ll curmex = 0;
            while(mp.count(curmex)) curmex++;
            cout << curmex << "\n";
        }else{
            bool used = false;
            ll curmex = 0;
            while(true){
                if(mp[curmex]>0){
                    curmex++;
                }else{
                    if(!used){
                        used = true;
                        if(mp[curmex+1]>0){
                            mp[curmex]++;
                            mp[curmex+1]--;
                        }
                    }else{
                        break;
                    }
                }
            }
            cout << curmex << "\n";
        }
    }
}