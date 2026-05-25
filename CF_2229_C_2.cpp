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
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        
        vi suff(n); suff[n-1] = arr[n-1];
        for(ll i=n-2; i>=0; i--) suff[i] = suff[i+1] + arr[i];
        suff.push_back(0);
        
        ll index = -1;

        ll cursum = 0;
        for(ll i=0; i<n; i++){
            if(arr[i]>0){
                ll newsum = cursum + suff[i+1] - arr[i];
                if(newsum > sum){
                    sum = newsum;
                    index = i;
                }
            }
            cursum += abs(arr[i]);
        }
        if(index==-1){
            cout << 0 << "\n" << "\n";
            continue;
        }
        bool flag = true;
        vi res;
        for(ll i=index-1; i>=0; i--){
            if(flag && arr[i]>0){
                res.push_back(i+1);
                flag = !flag;
            }else if(!flag && arr[i]<0){
                res.push_back(i+1);
                flag = !flag;
            }
        }
        res.push_back(index+1);
        cout << res.size() << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}