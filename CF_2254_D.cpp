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
        vector<vector<ll>> v;
        for(ll i=0; i<n; i++){
            v.push_back({arr[i],i});
        }        
        sort(v.begin(),v.end());
        ll duplicates = 0;
        for(ll i=1; i<n; i++){
            if(v[i][0]==v[i-1][0]) duplicates++;
        }
        // for(auto a : v) cout << a[0] << " " << a[1] << "   ";
        // cout << "\n";
        if(v[0][0]!=0){
            cout << -1 << "\n";
            continue;
        }
        vi res(n,-1);
        ll sum = 0;
        ll count = 1;
        ll last = -1;
        ll left = 0;
        bool flag = true;
        for(ll i=1; i<n; i++){
            if(v[i][0]==v[i-1][0]){
                count++;
            }else{
                ll next = v[i][0];
                ll diff = next-sum;
                if(diff%count!=0){
                    flag = false;
                    break;
                }
                ll val = diff/count;
                if(val<=last){
                    flag = false;
                    break;
                }
                // cout << left << " " << i << "\n";
                for(ll j=left; j<i; j++){
                    res[v[j][1]] = val;
                }
                sum += (count*val);
                last = val;
                left = i;
                count = 1;
            }
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        ll temp = (left==0 ? 1 : last+1);
        for(ll i=left; i<n; i++) res[v[i][1]] = temp;
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}