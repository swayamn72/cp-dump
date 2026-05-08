#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        bool flag = true;
        ll n; cin >> n;
        string a,b; cin >> a >> b;
        stack<char> st1, st2;
        ll abuffer = 0, bbuffer = 0;
        for(ll i=0; i<n; i++){
            if(a[i]=='(') st1.push(a[i]);
            if(b[i]=='(') st2.push(b[i]);
            if(a[i]==')' && !st1.empty()){
                st1.pop();
            }else if(a[i]==')'){
                if(st2.size()<2 || b[i]==')'){
                    flag = false;
                    break;
                }
                st2.pop(); st2.pop();
            }
            if(b[i]==')' && !st2.empty()){
                st2.pop();
            }else if(b[i]==')'){
                if(st1.size()<2 || a[i]==')'){
                    flag = false;
                    break;
                }
                st1.pop(); st1.pop();
            }
        }
        if(!st1.empty() && !st2.empty()) flag = false;
        cout << (flag ? "YES" : "NO") << "\n";
    }
}