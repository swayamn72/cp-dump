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
        string s; cin >> s;
        ll zeros = 0, ones = 0, twotofives = 0, sixto9 = 0;
        
        for(auto a : s){
            if(a=='0') zeros++;
            else if(a=='1') ones++;
            else if(a>='2' && a<='5') twotofives++;
            else sixto9++;
        }
        
        ll left = 0, right = n/4, res = 0;
        while(left<=right){
            ll mid = left + (right-left)/2;
            ll temp0 = zeros;
            ll temp1 = ones;
            ll temp25 = twotofives;
            ll temp69 = sixto9;
            bool flag = true;

            ll neededh = mid;

            ll take0 = min(temp0, neededh);
            temp0 -= take0;
            neededh -= take0;

            ll take1 = min(temp1, neededh);
            temp1 -= take1;
            neededh -= take1;

            if(neededh>0) flag = false;

            ll neededm1 = mid;
            
            ll take25m1 = min(temp25, neededm1);
            temp25 -= take25m1;
            neededm1 -= take25m1;

            ll take0m1 = min(temp0, neededm1);
            temp0 -= take0m1;
            neededm1 -= take0m1;
        
            ll take1m1 = min(temp1, neededm1);
            temp1 -= take1m1;
            neededm1 -= take1m1;

            if(neededm1>0) flag = false;

            ll neededh2forone = take1;
        
            ll take1h2 = min(temp1, neededh2forone);
            temp1 -= take1h2;
            neededh2forone -= take1h2;
            
            ll take0h2 = min(temp0, neededh2forone);
            temp0 -= take0h2;
            neededh2forone -= take0h2;
            
            if(neededh2forone > 0) flag = false;

            ll remaining_slots = (4 * mid) - (take0 + take1 + take25m1 + take0m1 + take1m1 + take1h2 + take0h2);
            ll remaining_pool = temp0 + temp1 + temp25 + temp69;
            
            if(remaining_pool < remaining_slots) flag = false;

            if(flag){
                res = mid;
                left = mid+1; 
            } else {
                right = mid-1; 
            }
        }
        cout << res << "\n";
    }
}