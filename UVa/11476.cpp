#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int k =0;
int num[1000005];
int prime[1000005];

int l = 0;

inline void compute_prime()
{
	num[1] = 1;
	for(int a=2;a<=40000;a++)
	{
		if(num[a]==0)
		{
			prime[l] = a;
			l++;
			long long b = a;
			while(b*a<=40000)
			{
				num[b*a] = a;
				b++;
			}
		}
	}
}

inline long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

inline long long mulmod(long long a,long long b,long long mod)
{
	long long ans = 0;
	long long c = a % mod;
	while(b!=0)
	{
		if(b%2==1) ans = (ans+c) % mod;
		c = (c*2) % mod;
		b/=2; 
	}
	return ans % mod;
}

inline long long fast_exp (long long a,long long b,long long mod)
{
	long long c = a%mod;
	long long ans = 1;
	while(b!=0)
	{
		if(b%2==1) ans = mulmod(ans,c,mod);
		c = mulmod(c,c,mod);
		b/=2;
	}
	return ans % mod;
}

inline bool millerTest(long long p,int iteration)
{
	srand(time(NULL));
    if(p<2){
    return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1;
		long long temp=s;
        long long mod=fast_exp(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

inline long long factorize(long long num,vector<long long> &vec)
{
	for(int a=0;a<l;a++)
	{
		if(prime[a]*prime[a]>num) break;
		while(num%prime[a]==0)
		{
			vec.push_back(prime[a]);
			num/=prime[a];
		}
	}
	if(num!=1) vec.push_back(num);
}

long long maxn = 1e+9;

inline long long pollard_rho(long long n,int stat,vector<long long> &vec)
{
	//Checking prime
	srand(time(NULL));	//for miller rabin and pollard rho
	if(n==1) return 0;
	else if(n<=maxn)
	{
		return factorize(n,vec);
	}
	else if(n%2==0)
	{
		vec.push_back(2);
		return pollard_rho(n/2,0,vec);
	}
	else if(stat == 0 && millerTest(n,5)==true)
	{
		vec.push_back(n);
		return 0;
	}
	else
	{
		//Real Pollard Rho
		long long d = n;
		for(int c = 2; d==n ;c++)
		{
			long long x = 2 ;
			long long y = x ;
			do
			{
			//	printf("%lld %lld %lld\n",x,y,d);
				x = (mulmod(x,x,n) + c ) % n;
				y = (mulmod(y,y,n) + c ) % n;
				y = (mulmod(y,y,n) + c ) % n;
				d = gcd(abs(x-y),n);
				if (d>1) break;
			}while(true);
		}	
		pollard_rho(d,0,vec);
		pollard_rho(n/d,0,vec);
		return 0;
	}
}
//983160949277722
int main()
{
	int tc;
	scanf("%d",&tc);
	compute_prime();
	while(tc--)
	{
		k = 0;
		long long n;
		scanf("%lld",&n);
		map<long long,int> mmap;
		vector<long long > vec;
		pollard_rho(n,0,vec);
		long long sz = vec.size();
		for(long long x = 0; x<sz;x++) mmap[vec[x]]++;
		printf("%lld =",n);
		for (map<long long,int>::iterator it = mmap.begin(); it != mmap.end(); it++) {
            if (it != mmap.begin())
                printf(" *");
            printf(" %lld", it->first);
            if (it->second > 1)
                printf("^%d", it->second);
        }
		printf("\n");
	}
}
