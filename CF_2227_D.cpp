#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll findmex(set<ll> &s){
    ll index = 0;
    while(s.find(index)!=s.end()){
        index++;
    }
    return index;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n; n*=2;
        ll m = n/2;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        ll res = 1;
        ll pos1 = -1, pos2 = -1;
        for(ll i=0; i<n; i++){
            if(arr[i]==0){
                if(pos1==-1) pos1 = i;
                else pos2 = i;
            }
        }
        // cout << pos1 << " " << pos2 << "\n";
        set<ll> s;
        ll left = pos1, right = pos1;
        while(left>=0 && right<n){
            if(arr[left]==arr[right]){
                s.insert(arr[left]);
                left--; right++;
            }else{
                break;
            }
        }
        res = max(res, findmex(s));
        s.clear();
        left = pos2, right = pos2;
        while(left>=0 && right<n){
            if(arr[left]==arr[right]){
                s.insert(arr[left]);
                left--; right++;
            }else{
                break;
            }
        }
        res = max(res, findmex(s));
        s.clear();
        if((pos2-pos1)%2==0){
            ll diff = (pos1+pos2);
            left = (pos2+pos1)/2; right = (pos1+pos2)/2;
            while(left>=0 && right<n){
                if(arr[left]==arr[right]){
                    s.insert(arr[left]);
                    left--; right++;
                }else{
                    break;
                }
            }
            res = max(res, findmex(s));
            s.clear();
        }else{
            left = pos1; right = pos2;
            ll diff = pos2-pos1;
            diff/=2;
            left += diff; right -= diff;
            while(left>=0 && right<n){
                if(arr[left]==arr[right]){
                    s.insert(arr[left]);
                    left--; right++;
                }else{
                    break;
                }
            }
            res = max(res, findmex(s));
            s.clear();
        }
        
        cout << res << "\n";
    }
}