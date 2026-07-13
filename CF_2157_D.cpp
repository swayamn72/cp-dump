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
        ll n,l,r; cin >> n >> l >> r;
        vi arr(n); for(auto &x : arr) cin >> x;
        
        vi v;
        ll leftcase = 0, rightcase = 0;

        for(auto a : arr){
            if(a<=l){
                leftcase += (l-a);
                rightcase += (r-a);
            }else if(a>=r){
                leftcase += (a-l);
                rightcase += (a-r);
            }else{
                v.push_back(a);
            }
        }
        ll res = min(leftcase,rightcase);
        if(v.size()==0){
            cout << res << "\n";
            continue;
        }

        sort(v.begin(),v.end());
        n = v.size();
        vi pref(n), suff(n);

        pref[0] = v[0];
        for(ll i=1; i<n; i++) pref[i] = pref[i-1]+v[i];

        suff[n-1] = v[n-1];
        for(ll i=n-2; i>=0; i--) suff[i] = suff[i+1]+v[i];

        auto getscore = [&](ll leftlen, ll rightlen){
            ll prefval = 0;
            if(leftlen>0) prefval = pref[leftlen-1];

            ll suffval = 0;
            if(rightlen>0) suffval = suff[n-rightlen];

            ll ans1 = leftcase + suffval - (rightlen * l);
            ans1 -= (prefval - (leftlen * l));

            ll ans2 = rightcase + (r * leftlen) - prefval;
            ans2 += (suffval - (rightlen * r));
            
            return min(ans1,ans2);
        };

        for(ll i=0; i<=n; i++){
            res = max(res,getscore(i,n-i));
            if(i+1<=n){
                res = max(res,getscore(i,n-i-1));
            }
        }

        cout << res << "\n";
    }
}