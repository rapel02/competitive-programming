#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll ol[63];
ll arr[1005];
ll pascal[1005][1005], pref[1005][1005];

void change(ll x,int v) {
    for(int i = 62;i >= 0;i--) {
        if(x & (1LL<<i)){
            ol[i] += v;
            break;
        }
    }
}

void pre() {
    for(int i = 0;i <= 1000;i++) {
        for(int j = 0;j <= i;j++) {
            if(j == 0 || i == j) pascal[i][j] = 1;
            else {
                pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
            }
            if(j >= 2) pref[i][j] = (pref[i][j - 2] + pascal[i][j]) % MOD;
            else pref[i][j] = pascal[i][j];
        }
    }
}

ll calc(ll x) {
    ll ctr = 0;
    ll res = 1;
    for(int i = 62;i >= 0;i--) {
        ctr += ol[i];
        int dec = 0;
        if(x & (1LL<<i)) dec = 1;
        if(ctr < dec) return 0;
        res = res * pref[ctr][ctr - dec] % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pre();
    cout<<"PREF "<<pref[2][2]<<endl;
    int n;
    cin>>n;
    ll xo = 0;
    for(int i = 0;i < n;i++) {
        cin>>arr[i];
        xo ^= arr[i];
    }
    for(int i = 0;i < n;i++) {
        change(arr[i], 1);
    }
    ll tot = 0;
    tot = (tot + calc(xo)) % MOD;
    xo = 0;
    for(int i = 0;i < n;i++) {
    	change(arr[i], -1);
    	change(arr[i] - 1,1);
    	xo ^= (arr[i] - 1);
	}
	cout<<"TOT "<<tot<<endl;
	cout<<"CALC "<<calc(xo)<<endl;
	tot = (tot + (MOD - calc(xo)) ) % MOD;
    ll val = 0;
    for(int j = 0;j < n;j++) {
        change(arr[j] - 1, -1);
        change(arr[j],  1);
        val = (xo ^ arr[j] ^ (arr[j] - 1) );
        val = (val + calc(xo)) % MOD;
        change(arr[j], - 1);
        change(arr[j] - 1, 1);
    }
    cout<<"VAL "<<val<<endl;
    tot = (tot + (MOD - val) % MOD) % MOD;
    cout<<tot<<endl;
}
