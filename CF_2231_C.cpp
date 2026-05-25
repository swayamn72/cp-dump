#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll val = *min_element(arr.begin(),arr.end());

        ll res = LLONG_MAX;
        
        vi values; values.push_back(1);
        values.push_back(2);
        while(val!=1){
            values.push_back(val);
            if(val%2==0) val/=2;
            else val++;
        }
        // vi values; values.push_back(val+1); values.push_back(val);
        // ll val2 = val+1;
        // while((val2)/2>0){
        //     values.push_back(val2/2);
        //     values.push_back(val2/2+1);
        //     val2/=2;
        // }
        // while((val/2)>0){
        //     values.push_back(val/2);
        //     values.push_back(val/2+1);
        //     val/=2;
        // }
        // for(ll i=1; i<=16; i++) values.push_back(i);
        // for(auto a : values) cout << a << " ";
        // cout << "\n";
        // set<ll> s;
        // vi values2;
        // for(ll i=0; i<values.size(); i++){
        //     if(s.find(values[i])!=s.end()) continue;
        //     s.insert(values[i]);
        //     values2.push_back(values[i]);
        // }

        for(auto u : values){
            ll val = u;
            ll ans = 0;
            bool flag = true;
            for(auto a : arr){
                ll num = a;
                while(num!=val){
                    ans++;
                    if(num%2==0){
                        num/=2;
                    }else{
                        num++;
                    }
                    if(num<val-1){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) res = min(res,ans);
            if(val%2==1) val++;
            else val/=2;
        }
        cout << res << "\n";
    }
}