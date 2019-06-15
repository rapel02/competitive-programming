#include<bits/stdc++.h>
using namespace std;

struct stt{
	int w;
	int h;
}s[20005];

pair<int,int> ss[20005];
int n;
int tc;
bool cmp(struct stt a,struct stt b)
{
	if(a.w<b.w) return true;
	else if(a.w==b.w) return a.h<b.h;
	return false;
}

int compute()
{
	int tot = 0;
	int k = 0;
	ss[0].first = s[0].w,ss[0].second = s[0].h;
	k++;
	for(int a=1;a<n;a++)
	{
		
		int lo = 0;
		int hi = k-1;
		int rem = -1;
		while(lo<=hi)
		{
			int mid = (lo+hi)/2;
			if(ss[mid].first>s[a].w&&ss[mid].second>s[a].h)
			{
				rem = mid;lo = mid+1;
			}
			else hi = mid-1;
		}
		if(rem!=-1) ss[rem].first = s[a].w,ss[rem].second = s[a].h;
		else{
			if(ss[k-1].first<s[a].w &&ss[k-1].second<s[a].h)
			{
			ss[k].first = s[a].w , ss[k].second = s[a].h;
			k++;
		}
		}
	}
	return k-1;
}

int main()
{
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		for(int a = 0;a<n;a++) scanf("%d %d",&s[a].w,&s[a].h);
		sort(s,s+n,cmp);
		printf("%lld\n",n-compute());
	}
}
