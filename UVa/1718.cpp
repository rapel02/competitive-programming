#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

const int N = 1<<20; 
typedef complex<double> C;

string t1,t2;

C A[N],B[N],ANS[N],w[N],temp[N];
int h_val, h_pow;

void FFT(C *P,int depth,int inv) // 1 for inverse
{
	if(depth == h_pow) return ;
	int mv = 1 << depth;
	FFT(P,depth+1,inv);
	FFT(P + mv,depth+1,inv);
	int num = 1 << (h_pow - depth);
	int pos = 0;
	int half = num/2;
	C t1,t2;
	for(int a=0;a<half;a++)
	{
		t1 = P[pos];
		t2 = P[pos + mv];
		if(inv==0) t2 = t2 * w[(a<<depth)];
		else t2 = t2 / w[(a<<depth)];
		temp[a] = t1 + t2;
		temp[a + half] = t1 - t2;
		pos = pos + 2*mv;
	}
	for(int a=0 ; a < num;a++) P[a*mv] = temp[a];
	return ;
}

int d[500005];
int ans[500005];

void compute()
{
	for(int a=1;a<=500000;a++)
		for(int b=a;b<=500000;b+=a) d[b]++;
}

int segment[2500000];

void build(int idx,int l,int r)
{
	if(l==r)
	{
		segment[idx] = l;
		return ;
	}
	int mid = (l+r)/2;
	build(2*idx,l,mid);
	build(2*idx + 1,mid+1,r);
	if(ans[segment[2*idx]] >= ans[segment[2*idx+1]]) segment[idx] = segment[2*idx];
	else segment[idx] = segment[2*idx+1];
}

int query(int idx,int l,int r,int ll,int rr)
{
	if(ll <= l && r <= rr) return segment[idx];
	if(rr < l || ll > r) return -1;
	int mid = (l+r)/2;
	int lf = query(2*idx,l,mid,ll,rr);
	int rf = query(2*idx+1,mid+1,r,ll,rr);
	if(lf==-1) return rf;
	if(rf==-1) return lf;
	if(ans[lf] >= ans[rf]) return lf;
	return rf;
}

int main()
{
	int tc;
	compute();
	int len1 = 500000;
	h_val = 1, h_pow = 0;
	while(len1 * 2 > h_val) h_val *=2, h_pow++;
	for(int a=0;a<h_val;a++) w[a] = C(cos(2 * pi * a / h_val) , sin(2 * pi *a / h_val));
	for(int a=0;a<=len1;a++) A[a] = C(d[a],0);
	for(int a = len1 + 1;a<h_val;a++) A[a] = C(0,0);
	FFT(A,0,0);
	for(int a=0;a<h_val;a++) ANS[a] = A[a] * A[a];
	FFT(ANS,0,1);
	for(int a=0;a<len1;a++)
	{
		ans[a] = (int)round(ANS[a].real() / h_val);
	}
	build(1,1,len1);
	while(scanf("%d",&tc)!=EOF)
	{
		while(tc--)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			int maxi = query(1,1,len1,l,r);   
			printf("%d %d\n",maxi,ans[maxi]);
		}
	}
}
