#include<bits/stdc++.h>
using namespace std;

long long sector[5];
const long long MOD = 7340033;
long long fact[100005],inv_fact[100005];
const long long root = 5;

const long long N = 1<<20;

vector<long long > A,B,ANS;

long long h_val,h_pow;
long long ans[N + 5];
long long ww[N + 5];
long long fast(long long a,long long b)
{
	long long ans = 1;
	while(b!=0)
	{
		if(b%2==1) ans = (ans * a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}

void precom()
{
	fact[0] = 1;
	for(int a=1;a<=100000;a++) fact[a] = (fact[a-1] * a)%MOD;
	for(int a=0;a<=100000;a++)
	{
		inv_fact[a] = fast(fact[a],MOD-2);
	}
}

long long combine(long long n,long long r)
{
	if(n < r) return 0;
	long long mr = n-r;
	return (fact[n]*inv_fact[r])%MOD*inv_fact[mr]%MOD;
}

void NTT(vector<long long> &a, int sign = 1) {
	int n = a.size(); // n should be a power of two
	int theta = N / n;
  	for (int m = n ; m>= 2; m >>= 1) 
	{
    	int mh = m >> 1;
    	for (int i = 0; i < mh; i ++) 
		{
			long long w;
			w = ww[i*theta % N];
			for (int j = i; j < n ; j+=m) 
			{
				int k = j + mh;
				long long x = (a[j] - a[k] + MOD)%MOD;
				if(x<0) x+=MOD;
				a[j] += a[k];
				a[j]%=MOD; 
				a[k] = (w * x)%MOD;
			}
		}
		theta = (theta * 2) % N;
	}
	
	for (int i = 0, j = 1; j < n - 1; ++j) 
	{
		for (int k = n >> 1; k > (i ^= k); k >>= 1);
		if (j < i) swap(a[i], a[j]);
	}
	
	if(sign==-1) reverse(a.begin() + 1,a.end());
}

int main()
{
	precom();
	int ntc;
	ww[0] = 1;
	long long v = (MOD-1)/N;
	long long rr = fast(root,v);
	for(int a=1;a<=N;a++) ww[a] = ww[a-1] * rr %MOD;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		scanf("%d",&n);
		memset(sector,0,sizeof(sector));
		A.clear(),B.clear(),ANS.clear();
		for(int a=0;a<n;a++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if(x>0 && y>0) sector[0]++;
			if(x<0 && y>0) sector[1]++;
			if(x<0 && y<0) sector[2]++;
			if(x>0 && y<0) sector[3]++;
		}
		memset(ans,0,sizeof(ans));
		//NTT PART
		long long len1 = n;
		h_val = 1, h_pow = 0;
		while(len1 *2 > h_val) h_val *=2, h_pow++;
		for(int a=0;a<=len1;a++)
		{
			long long tep = 0;
			if(a%2==0) tep = combine(sector[0],a/2)*combine(sector[2],a/2)%MOD;
			//cout<<a<<" "<<tep<<endl;
			A.push_back(tep);
			//cout<<a<<" "<<A[a]<<endl;
		}
		for(int a=len1 + 1;a<h_val;a++) A.push_back(0);
		for(int a=0;a<=len1;a++)
		{
			long long tep = 0;
			if(a%2==0) tep = combine(sector[1],a/2)*combine(sector[3],a/2)%MOD;
			//cout<<a<<" "<<tep<<endl;
			B.push_back(tep);
			//cout<<a<<" "<<B[a]<<endl;
		}
		for(int a=len1 + 1;a<h_val;a++) B.push_back(0);
		//printf("MO NTT\n");
		NTT(A,1);
		NTT(B,1);
		//printf("FIN NTT\n");
		for(int a=0;a<h_val;a++) ANS.push_back((A[a] * B[a])%MOD);
		//printf("MOREV NTT\n");
		NTT(ANS,-1);
		//printf("REV NTT\n");
		long long revv = fast(h_val,MOD-2);
		for(int a=0;a<h_val;a++)
		{
			long long num = ANS[a] * revv % MOD;
		//	cout<<ANS[a]<<" "<<a<<" "<<num%MOD<<endl;
			ans[a] = num;
		}
		//END OF NTT
		printf("Case %d:\n",tc);
		for(int a=1;a<=n;a++)
		{
			if(a!=1) printf(" ");
			long long tot = (ans[a] % MOD + MOD )%MOD;
			printf("%lld",tot);
		}
		printf("\n");
	}
}
