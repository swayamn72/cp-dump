#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        sort(arr.rbegin(),arr.rend());
        ll maxv = arr[0];
        ll rem = sum - maxv;
        if(sum<=2 || maxv==1){
            cout << 0 << "\n";
            continue;
        }
        
        ll res = 0;
        if(maxv>=2) res = maxv;
        if(maxv>=2) res += min(maxv/2,rem);

        ll ans = 0;
        ll slots = 0; ll singles = 0;
        for(auto a : arr){
            if(a>1){
                ans += a;
                if(a==4){
                    slots++;
                }else if(a==5){
                    slots++;
                }else if(a>5){
                    slots += (a-2)/2;
                }
            }else{
                singles++;
            }
        }

        ans += min(singles,slots);
        res = max(res,ans);
        cout << res << "\n";
    }
}