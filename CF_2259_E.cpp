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
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<pair<ll,ll>> v;
        for(ll i=0; i<n; i++){
            if(arr[i]==-1) continue;
            if(arr[i]==0) continue;
            ll left = i - (arr[i]-1);
            ll right = i + (arr[i]-1);
            left = max(0LL,left);
            right = min(right,n-1);
            v.push_back({left,right});
        }
        sort(v.begin(),v.end());
        if(v.empty()){
            string res(n,'1');
            cout << res << "\n";
            continue;
        }
        string res(n,'0');
        vector<pair<ll,ll>> intervals;
        auto [l,r] = v[0];
        for(ll i=1; i<v.size(); i++){
            auto [a,b] = v[i];
            if(a<=r){
                r = max(r,b);
            }else{
                intervals.push_back({l,r});
                l=a; r=b;
            }
        }
        intervals.push_back({l,r});
        // for(auto [a,b] : intervals) cout << a << " " << b << "   ";
        // cout << "\n";
        vector<bool> used(n,true);
        for(auto [a,b] : intervals){
            for(ll i=a; i<=b; i++) used[i] = false;
        }
        bool flag = true;
        for(ll i=0; i<n; i++){
            if(arr[i]==-1) continue;
            ll left = i-arr[i];
            ll right = i+arr[i];
            bool flag1 = false;
            if(left>=0 && used[left]) flag1 = true;
            bool flag2 = false;
            if(right<n && used[right]) flag2 = true;

            if((!flag1) && (!flag2)){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        for(ll i=0; i<n; i++) if(used[i]) res[i] = '1';
        cout << res << "\n";
    }
} 