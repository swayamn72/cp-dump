#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi l(n), m(n), w(n);
        for(ll i=0; i<n; i++){
            cin >> l[i] >> m[i] >> w[i];
        }
        ll mid = n/2;
        vector<vi> seta, uniquea;

        auto dfs1 = [&](auto &&self, ll i, ll end, ll L, ll M, ll W, ll mask)->void{
            if(i==end){
                seta.push_back({L-M,M-W,L,mask});
                return;
            }
            self(self,i+1,end,L+l[i],M+m[i],W,mask*3+0);
            self(self,i+1,end,L+l[i],M,W+w[i],mask*3+1);
            self(self,i+1,end,L,M+m[i],W+w[i],mask*3+2);
        };
        dfs1(dfs1,0,mid,0,0,0,0);

        sort(seta.begin(),seta.end(),[](const vi &a, const vi &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            if(a[1]!=b[1]) return a[1]<b[1];
            return a[2]>b[2];
        });
        for(ll i=0; i<seta.size(); i++){
            if(i==0 || seta[i][0] != seta[i-1][0] || seta[i][1]!=seta[i-1][1]){
                uniquea.push_back(seta[i]);
            }
        }
        ll maxl = LLONG_MIN;
        ll bestmask1 = -1, bestmask2 = -1;
        bool flag = false;

        auto dfs2 = [&](auto &&self, ll i, ll end, ll L, ll M, ll W, ll mask)->void{
            if(i==end){
                ll req1 = M-L;
                ll req2 = W-M;

                vi temp = {req1,req2,0,0};
                auto it = lower_bound(uniquea.begin(), uniquea.end(), temp, [](const vi &a, const vi &b){
                    if(a[0]!=b[0]) return a[0]<b[0];
                    return a[1]<b[1];
                });

                if(it!=uniquea.end() && (*it)[0]==req1 && (*it)[1]==req2){
                    if(!flag || (*it)[2] + L > maxl){
                        flag = true;
                        maxl = (*it)[2] + L;
                        bestmask1 = (*it)[3];
                        bestmask2 = mask;
                    }
                }
                return;
            }
            self(self,i+1,end,L+l[i],M+m[i],W,mask*3+0);
            self(self,i+1,end,L+l[i],M,W+w[i],mask*3+1);
            self(self,i+1,end,L,M+m[i],W+w[i],mask*3+2);
        };
        dfs2(dfs2,mid,n,0,0,0,0);
        if(!flag){
            cout << "Impossible";
            continue;
        }
        auto decode = [](ll mask, ll len)->vi{
            vi res(len);
            for(ll i=len-1; i>=0; i--){
                res[i] = mask%3;
                mask/=3;
            }
            return res;
        };
        vi ans1 = decode(bestmask1,mid);
        vi ans2 = decode(bestmask2,n-mid);

        for(auto x : ans1) cout << (x == 0 ? "LM\n" : (x == 1 ? "LW\n" : "MW\n"));
        for(auto x : ans2) cout << (x == 0 ? "LM\n" : (x == 1 ? "LW\n" : "MW\n"));
    }
} 