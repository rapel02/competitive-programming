#include<bits/stdc++.h>
#define EPS 1e-20
using namespace std;

long long sector[5];
const long long MOD = 7340033;
const long long root = 3;
long long fact[100005],inv_fact[100005];

const long long N = 1<<20;

long long A[N],B[N],ANS[N],w[N],temp[N];
long long h_val,h_pow;
long long ans[N];

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

void NTT(long long *P,int depth,int inv)
{
	if(depth == h_pow) return ;
	long long mv = 1 << depth;
	NTT(P,depth+1,inv);
	NTT(P + mv,depth+1,inv);
	long long num = 1 << (h_pow - depth);
	long long pos = 0;
	long long half = num/2;
	long long t1,t2;
	for(int a=0;a<half;a++)
	{
		t1 = P[pos];
		t2 = P[pos + mv];
		t2 = t2 * w[(a<<depth)];
		temp[a] = (t1 + t2)%MOD;
		temp[a + half] = ((t1 - t2)%MOD + MOD)%MOD;
		pos = pos + 2*mv;
	}
	for(int a=0 ; a < num;a++) P[a*mv] = temp[a];
	return ;
}

int main()
{
	precom();
	int ntc;
	scanf("%d",&ntc);
	long long v = (MOD-1)/N;
	long long rr = fast(root,v);
	w[0] = 1;
	for(int a=1;a<=N;a++) w[a] = w[a-1] * rr %MOD;
		
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		scanf("%d",&n);
		memset(sector,0,sizeof(sector));
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
		//FFT PART
		long long len1 = n/2;
		h_val = 1, h_pow = 0;
		while(len1 *2 > h_val) h_val *=2, h_pow++;
		for(int a=0;a<=len1;a++)
		{
			long long tep = 0;
			tep = combine(sector[0],a)*combine(sector[2],a)%MOD;
			//cout<<a<<" "<<tep<<endl;
			A[a] = tep;
		}
		for(int a=len1 + 1;a<h_val;a++) A[a] = 0;
		for(int a=0;a<=len1;a++)
		{
			long long tep = 0;
			tep = combine(sector[1],a)*combine(sector[3],a)%MOD;
			//cout<<a<<" "<<tep<<endl;
			B[a] = tep;
		}
		for(int a=len1 + 1;a<h_val;a++) B[a] = 0;

		NTT(A,0,0);
		NTT(B,0,0);
		for(int a=0;a<h_val;a++) ANS[a] = A[a] * B[a];
		NTT(ANS,0,1);
		reverse(ANS+1,ANS+h_val);
		long long revv = fast(h_val,MOD-2);
		for(int a=0;a<h_val;a++)
		{
			long long num = (long long)ANS[a] * revv;
			cout<<a<<" "<<num%MOD<<endl;
			ans[a] = num % MOD;
		}
		//END OF FFT
		printf("Case %d:\n",tc);
		for(int a=1;a<=n;a++)
		{
			if(a!=1) printf(" ");
			long long tot = 0;
			if(a%2==0) tot = (ans[a/2])%MOD;
			cout<<tot;
		}
		printf("\n");
	}
}
