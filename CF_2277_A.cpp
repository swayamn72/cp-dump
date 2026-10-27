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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp; for(auto a : arr) mp[a]++;
        ll extra = 0;
        ll mex = 0;
        while(true){
            bool flag = true;
            if(mp.count(mex)){
                ll f = mp[mex];
                if(f>=k){
                    extra += f-k;
                }else{
                    ll need = k-f;
                    if(extra<need){
                        flag = false;
                    }else{
                        extra -= need;
                    }
                }
            }else{
                flag = false;
            }
            if(!flag) break;
            mex++;
        }        
        cout << mex << "\n";
    }
}