#include<bits/stdc++.h>
using namespace std;

int num[3000004];
int prime[3000005];
int k = 0;
int ans[15000005];

void comp()
{
	for(long long a=2;a<=3000001;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			for(long long b=a*a;b<=3000001;b+=a) num[b] = a;
		}
	}
	memset(ans,-1,sizeof(ans));
	int prev = 0;
	ans[prev] = 0;
	for(int a=2;prev<=10000001;a++)
	{
		int tot = 1;
		int rem = a;
		while(num[rem]!=0)
		{
			tot++;
			rem /=num[rem];
		}
		//if(a%100000==0)printf("%d %d %d\n",a,prev,tot+prev);
		ans[tot+prev] = a;
		prev += tot;
	}
}

int main()
{
	comp();
	//cout<<"yay"<<endl;
	int n;
	int tc = 0;
	while(1)
	{
		tc++;
		scanf("%d",&n);
		if(n<0) return 0;
//		int lo = 0;
//		int hi = 2800000;
//		int ans = -1;
//		while(lo<=hi && ans==-1)
//		{
//			int mid = (lo+hi)/2;
//			int tot = 0;
//			bool big = false;
//			for(int a=0;big==false && a<k&&prime[a]<=mid;a++)
//			{
//				int rem = mid;
//				while(rem!=0)
//				{
//					if(tot>n)
//					{
//						big = true;
//						break;
//					}
//					tot += rem/prime[a];
//					rem/=prime[a];
//				}
//			}
//			//printf("%d %d\n",n,tot);
//			if(tot>n||big==true) hi = mid-1;
//			else if(tot<n) lo = mid+1;
//			else
//			{
//				ans = mid;
//				hi = mid-1;
//				break;
//			}
//		}
		printf("Case %d: ",tc);
		if(ans[n]!=-1) printf("%d!\n",ans[n]);
		else printf("Not possible.\n");
	}
}
