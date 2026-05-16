#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;
    while(t--){
        ll x,n; cin >> x >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        ll low = arr[0], high = arr[n-1], res = ULLONG_MAX;
        if(n==1 && arr[0]==0){
            cout << x << "\n";
            continue;
        }
        bool flag = false;
        string s = to_string(x);
        ll digits = s.size();
        
        // if(digits==1){
        //     ll ans = ULLONG_MAX;
        //     for(auto a : arr){
        //         ll diff;
        //         if(x>=a) diff = x-a;
        //         else diff = a-x;
        //         ans = min(ans,diff);
        //     } 
        //     cout << ans << "\n";
        //     continue;
        // }
        if(digits>1){
            string s1 = "";
            for(ll i=0; i<digits-1; i++) s1+= (high+'0');
            res = min(res, x-stoull(s1));
            // cout << s1 << "\n";
        }
        
        
        ll temp = low;
        if(temp==0) temp = arr[1];
        
        string s2 = "";
        s2 += (temp + '0');
        for(ll i=0; i<digits; i++) s2 += (low+'0');
        res = min(res, stoull(s2)-x);
        // cout << s2 << "\n";

        vector<bool> vis(10,false);
        for(auto a : arr) vis[a] = true;

        string pref = "";
        for(ll i=0; i<digits; i++){
            ll curr = s[i]-'0';

            ll higher = -1;
            for(auto a : arr){
                if(a>curr){
                    higher = a; break;
                }
            } 
            if(higher!=-1){
                string temps = pref;
                temps += (higher+'0');
                for(ll j=0; j<digits-i-1; j++) temps += (low+'0');
                ll val = stoull(temps);
                ll diff;
                if(val>=x) diff = val-x;
                else diff = x-val;
                // cout << temps << "\n";
                res = min(res, diff);
            }
            ll lower = -1;
            for(ll j=n-1; j>=0; j--){
                if(arr[j]<curr){
                    lower = arr[j];
                    break;
                }
                if(j==0) break;
            }
            if(lower!=-1){
                string temps = pref;
                temps += (lower+'0');
                for(ll j=0; j<digits-i-1; j++) temps += (high+'0');
                ll val = stoull(temps);
                ll diff; 
                if(val>=x) diff = val-x;
                else diff = x-val;
                // cout << temps << "\n";
                res = min(res, diff);
            }
            if(!vis[curr]) break;
            pref += (curr+'0');
            if(i==digits-1){
                res = 0;
            } 
        }
        cout << res << "\n";

    }
}

