#include<bits/stdc++.h>
using namespace std;

int arr[150000];
int bit[150000];
int n;

pair<int,int> p[150000];

void update(int a)
{
	for(int b=a;b<=n;b+= b&(-b)) bit[b]++;
}

int query(int a)
{
	int tot = 0;
	for(int b=a;b>0;b -= b&(-b)) tot += bit[b];
	return tot;
}

int main()
{
	while(scanf("%d",&n),n)
	{
		memset(bit,0,sizeof(bit));
		for(int a=1;a<=n;a++)
		{
			scanf("%d",&arr[a]);
			p[a].first = arr[a];
			p[a].second = a;
		}
		sort(p+1,p+n+1);
		long long tot = 0;
		for(int a=1;a<=n;a++)
		{
			tot = tot + query(n) - query(p[a].second);
			update(p[a].second);
		}
		if(tot%2==1) printf("Marcelo\n");
		else printf("Carlos\n");
		//printf("%lld\n",tot);
	}
}
