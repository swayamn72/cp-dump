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
        sort(arr.begin(),arr.end());
        ll diff = arr[n-1] - arr[0];
        
        vi neg, pos;
        ll zeros = 0;
        vi v;
        for(auto a : arr){
            if(a==0) zeros++;
            else if(a>0) pos.push_back(a);
            else neg.push_back(a);
        }
        while(zeros--) v.push_back(0);
        sort(neg.rbegin(),neg.rend());
        sort(pos.rbegin(),pos.rend());
        ll sum = 0;
        while(!neg.empty() && !pos.empty()){
            if(sum>0){
                sum += neg.back();
                v.push_back(neg.back());
                neg.pop_back();
            }else{
                sum += pos.back();
                v.push_back(pos.back());
                pos.pop_back();
            }
        }
        while(!neg.empty()){
            v.push_back(neg.back());
            neg.pop_back();
        }
        while(!pos.empty()){
            v.push_back(pos.back());
            pos.pop_back();
        }
        ll minv = v[0], maxv = v[0];
        sum = 0;
        ll maxdiff = 0;
        for(ll i=1; i<n; i++){
            sum += v[i];
            maxv = max(maxv,sum);
            minv = min(minv,sum);
            maxdiff = max({maxdiff,sum-minv,sum-maxv});
        }
        if(maxdiff>=diff){
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";
        for(auto a : v) cout << a << " ";
        cout << "\n";
    }
}