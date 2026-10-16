#include <bits/stdc++.h>
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
        string s; cin >> s;
        
        vi twos, zeros, fives, sixes;
        for(ll i=0; i<n; i++){
            if(s[i]=='2') twos.push_back(i+1);
            else if(s[i]=='0') zeros.push_back(i+1);
            else if(s[i]=='5') fives.push_back(i+1);
            else if(s[i]=='6') sixes.push_back(i+1);
        }
        vi flatdiff(n+3,0), constdiff(n+3,0), slopediff(n+3,0);


        for(ll i=1; i<=n; i++){
            auto it = lower_bound(twos.begin(),twos.end(),i);
            if(it==twos.end()) continue;
            ll p1 = *it;

            it = lower_bound(zeros.begin(),zeros.end(),p1+1);
            if(it==zeros.end()) continue;
            ll p0 = *it;

            it = lower_bound(twos.begin(),twos.end(),p0+1);
            if(it==twos.end()) continue;
            ll p2 = *it;

            it = lower_bound(fives.begin(),fives.end(),p2+1);
            if(it==fives.end()) continue;
            ll left = *it;

            it = lower_bound(sixes.begin(),sixes.end(),p2+1);
            ll right = (it != sixes.end()) ? *it : (n + 1);

            if(right<left) continue;
            // left - 5end, right = 6 start
            ll diff = right-left;
            ll k = right-1;
            
            flatdiff[i] += diff;
            flatdiff[left+1] -= diff;
            if(left+1<=k){
                constdiff[left+1] += (k+1);
                constdiff[k+1] -= (k+1);

                slopediff[left+1]++;
                slopediff[k+1]--;
            }
        }
        for(ll i=1; i<=n; i++){
            flatdiff[i] += flatdiff[i-1];
            constdiff[i] += constdiff[i-1];
            slopediff[i] += slopediff[i-1];
        }

        for(ll i=1; i<=n; i++){
            ll bad = flatdiff[i] + (constdiff[i]-i*slopediff[i]);
            ll total = i*(n-i+1);
            cout << total-bad << " ";
        }
        cout << "\n";
    }
}