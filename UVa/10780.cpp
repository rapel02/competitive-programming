#include<bits/stdc++.h>
using namespace std;

int num[10005];
int prime[10005];
int k=0;

void pre()
{
	for(int a=2;a<=10000;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			for(int b=a*a;b<=10000;b+=a) num[b] = a;
		}
	}
}

int main()
{
	int ntc;
	pre();
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int m,n;
		printf("Case %d:\n",tc);
		scanf("%d %d",&m,&n);
		map<int,int> mmap;
		int te = m;
		while(num[te] != 0)
		{
			mmap[num[te]]++;
			te/=num[te];
		}
		mmap[te]++;
		int mini = 150000;
		for(map<int,int>::iterator it = mmap.begin();it!=mmap.end();it++)
		{
			int di = it->first;
			int to = it->second;
			te = n;
			int tot = 0;
			while(te != 0)
			{
				tot += te/di;
				te/=di;
			}
			mini = min(mini,tot/to);
		}
		if(mini == 0) printf("Impossible to divide\n");
		else printf("%d\n",mini);
	}
}
