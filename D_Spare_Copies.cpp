#include <bits/stdc++.h>
#include <numeric>
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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        if(sum>n){
            cout << "NO" << "\n";
            continue;
        }
        // for(ll i=0; i<n; i++) arr.push_back(arr[i]);
        bool flag = true;
        
        set<ll> s;
        for(ll i=0; i<n; i++){
            if(arr[i]>1) s.insert(i);
        }
        auto check = [&]()->bool{
            for(ll i=0; i<n; i++){
                ll left = (i-1+n)%n;
                ll right = (i+1)%n;
                if(arr[left]==1 && arr[right]==1 && arr[i]>1) return false;
            }
            return true;
        };
        for(ll k=0; k<10; k++){
            ll i = *(s.begin());
            ll left = (i-1+n)%n;
            ll right = (i+1)%n;
            arr[left]++; if(arr[left]>1) s.insert(left);
            arr[right]++; if(arr[right]>1) s.insert(right);
            arr[i]-=2; if(arr[i]<2) s.erase(i);
            flag = check();
            if(!flag) break; 
        }

        cout << (flag ? "YES" : "NO") << "\n";
    }
}