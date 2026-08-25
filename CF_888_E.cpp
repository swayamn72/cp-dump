#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << arr[0]%m;
            continue;
        }
        vi left, right;
        for(ll i=0; i<n/2; i++) left.push_back(arr[i]);
        for(ll i=n/2; i<n; i++) right.push_back(arr[i]);

        auto subsets = [&](vi &v)->vi{
            ll sz = v.size();
            vi ans;
            for(ll mask=0; mask<(1<<sz); mask++){
                ll cur = 0;
                for(ll i=0; i<sz; i++){
                    if((mask>>i)&1){
                        cur = (cur + v[i])%m;
                    }
                }
                ans.push_back(cur);
            }
            return ans;
        };
        vi s1 = subsets(left);
        vi s2 = subsets(right);

        sort(s1.begin(),s1.end());
        s1.erase(unique(s1.begin(),s1.end()),s1.end());
        sort(s2.begin(),s2.end());
        s2.erase(unique(s2.begin(),s2.end()),s2.end());

        ll res = 0;
        for(auto a : s1){
            res = max(res,a%m);
            auto it = lower_bound(s2.begin(),s2.end(),m-a);
            if(it!=s2.begin()){
                it--;
                res = max(res,(ll)((a+(*it))%m));
            }
            res = max(res,(a+s2.back())%m);
        }
        cout << res << "\n";
    }
} 