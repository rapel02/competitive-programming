#include<bits/stdc++.h>
using namespace std;

const long long MAXN = 1e+6;

long long BIT[100000];
long long arr[100000];
long long par[100000];
long long num[MAXN + 5];
long long prime[MAXN + 5];
long long k = 1;

map<long long,int> mmap;

long long find(long long x)
{
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

long long factor(int nu)
{
	int ans = 0;
	while(nu%10==0)
	{
		ans += 2;
		nu/=10;
	}
	while(num[nu]!=0)
	{
		ans++;
		nu = nu/num[nu];
	}
	ans++;
	return ans;
}

void update(int x,long long num)
{
	for(int a = x;a < k;a = a + (a&(-a))) BIT[a] += num;
}

void setvalue(int x,long long num)
{
	for(int a=x;a < k;a = a + (a&(-a))) par[a] += num;
}

long long getvalue(int x)
{
	long long ans = 0;
	for(int a = x;a>0;a = a-(a&(-a))) ans += par[a];
	return ans;
}

long long query(int x)
{
	long long ans = 0;
	for(int a= x;a>0;a= a-(a&(-a))) ans += BIT[a];
	return ans;
}

void sieve()
{
	for(long long a=2;a<=MAXN;a++)
	{
		if(num[a] == 0)
		{
			prime[k] = a;
			long long temp = a;
			queue<long long> s;
			while(temp)
			{
				s.push(temp%10);
				temp/=10;
			}
			long long nums = 0;
			while(!s.empty())
			{
				nums = nums*10 + s.front();
				s.pop();
			}
			while(nums < 1000000) nums*=10;
			arr[k] = nums;
			k++;
			for(long long b=a*a;b<=MAXN;b+=a) num[b] = a;
		}
	}
	sort(arr + 1,arr+k);
	for(int a=1;a<k;a++)
	{
		setvalue(a,1);
		mmap[arr[a]] = a;
		long long ct = factor(arr[a]);
		update(a,ct);
	}
}

int main()
{
	string in;
	int t;
	sieve();
	while(cin>>in>>t)
	{
		if(in=="q")
		{
			int lo = 1;
			int hi = k-1;
			int ans = -1;
			t++;
			while(lo <= hi)
			{
				int mid = (lo + hi)/2;
				long long ck = getvalue(mid);
			//	printf("%d %lld\n",mid,ck);
				if(ck >= t)
				{
					ans = mid;
					hi = mid-1;
				}
				else lo = mid+1;
			}
			printf("%lld\n",query(ans));
		}
		else
		{
			int idx = mmap[t];
			setvalue(idx,-1);
			update(idx,-factor(t));
		}
	}
}
