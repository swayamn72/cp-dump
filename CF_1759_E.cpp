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
        ll n,h; cin >> n >> h;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        
        // g b b
        stack<ll> st; st.push(2); st.push(2); st.push(3);
        ll power = h;
        ll ans1 = 0;
        for(auto a : arr){
            if(a<power){
                ans1++;
                power += a/2;
            }else{
                if(!st.empty()){
                   ll val = st.top(); st.pop();
                   if(val==2) power*=2;
                   else power*=3;
                   if(a<power){
                    ans1++;
                    power += a/2;
                    continue;
                   }
                }else{
                    break;
                }
                if(!st.empty()){
                   ll val = st.top(); st.pop();
                   if(val==2) power*=2;
                   else power*=3;
                   if(a<power){
                    ans1++;
                    power += a/2;
                    continue;
                   }
                }else{
                    break;
                }
                if(!st.empty()){
                   ll val = st.top(); st.pop();
                   if(val==2) power*=2;
                   else power*=3;
                   if(a<power){
                    ans1++;
                    power += a/2;
                    continue;
                   }
                }else{
                    break;
                }
            }
        }

        // b g b
        stack<ll> st2; st2.push(2); st2.push(3); st2.push(2);
        ll power2 = h;
        ll ans2 = 0;
        for(auto a : arr){
            if(a<power2){
                ans2++;
                power2 += a/2;
            }else{
                if(!st2.empty()){
                   ll val = st2.top(); st2.pop();
                   if(val==2) power2*=2;
                   else power2*=3;
                   if(a<power2){
                    ans2++;
                    power2 += a/2;
                    continue;
                   }
                }else{
                    break;
                }
                if(!st2.empty()){
                   ll val = st2.top(); st2.pop();
                   if(val==2) power2*=2;
                   else power2*=3;
                   if(a<power2){
                    ans2++;
                    power2 += a/2;
                    continue;
                   }
                }else{
                    break;
                }
                if(!st2.empty()){
                   ll val = st2.top(); st2.pop();
                   if(val==2) power2*=2;
                   else power2*=3;
                   if(a<power2){
                    ans2++;
                    power2 += a/2;
                    continue;
                   }
                }else{
                    break;
                }
            }
        }

        // b b g 
        stack<ll> st3; st3.push(3); st3.push(2); st3.push(2);
        ll power3 = h;
        ll ans3 = 0;
        for(auto a : arr){
            if(a<power3){
                ans3++;
                power3 += a/2;
            }else{
                if(!st3.empty()){
                   ll val = st3.top(); st3.pop();
                   if(val==2) power3*=2;
                   else power3*=3;
                   if(a<power3){
                    ans3++;
                    power3 += a/2;
                    continue;
                   }
                }else{
                    break;
                }
                if(!st3.empty()){
                   ll val = st3.top(); st3.pop();
                   if(val==2) power3*=2;
                   else power3*=3;
                   if(a<power3){
                    ans3++;
                    power3 += a/2;
                    continue;
                   }
                }else{
                    break;
                }
                if(!st3.empty()){
                   ll val = st3.top(); st3.pop();
                   if(val==2) power3*=2;
                   else power3*=3;
                   if(a<power3){
                    ans3++;
                    power3 += a/2;
                    continue;
                   }
                }else{
                    break;
                }
            }
        }
        cout << max({ans1,ans2,ans3}) << "\n";
    }
}