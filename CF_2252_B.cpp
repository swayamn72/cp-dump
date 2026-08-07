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
        string s; cin >> s;
        ll temp = 1;
        vi v;
        ll ones = 0, zeros = 0;
        ll zeroseq = 0, oneseq = 0;
        if(s[0]=='1') ones++;
        else zeros++;
        for(ll i=1; i<n; i++){
            if(s[i]=='1') ones++;
            else zeros++;
            if(s[i]==s[i-1]){
                temp++;
            }else{
                if(s[i-1]=='0') zeroseq++;
                else oneseq++;
                v.push_back(temp);
                temp = 1;
            }
        }        
        if(s[n-1]=='0') zeroseq++;
        else oneseq++;
        v.push_back(temp);
        // for(auto a : v) cout << a << " ";
        // cout << "\n";
        if(abs(ones-zeros)>2){
            cout << -1 << "\n";
            continue;
        }
        
        ll toremoveone = ones - oneseq;
        ll toremovezero = zeros - zeroseq;
        if(abs(toremoveone-toremovezero)<=1){
            cout << toremoveone + toremovezero << "\n";
            continue;
        }

        ll end1 = 0, end0 = 0;
        if(oneseq>zeroseq) end1 = 2;
        else if(zeroseq>oneseq) end0 = 2;
        else end1 = 1;
        if(end1==1) end0 = 1;

        if(toremoveone>toremovezero){
            ll diff = toremoveone - toremovezero - 1;
            if(diff>end0){
                cout << -1 << "\n";
            }else{
                cout << 2*toremoveone-1 << "\n";
            }
        }else{
            ll diff = toremovezero - toremoveone - 1;
            if(diff>end1){
                cout << -1 << "\n";
            }else{
                cout << 2*toremovezero-1 << "\n";
            }
        }

    }
}