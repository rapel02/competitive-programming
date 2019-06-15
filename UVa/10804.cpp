	#include<bits/stdc++.h>
	#define EPS 1e-14
	using namespace std;
	
	int m,n,k;
	
	double ans;
	
	struct Point{
		double x,y;
	}gop[555],hole[555];
	
	double dist[555][555];
	
	int val[555];
	bool vis[555];
	
	double mid;
	
	double sqr(double x)
	{
		return x*x;
	}
	
	double calc(int a,int b)
	{
		return sqrt(sqr(gop[a].x - hole[b].x) + sqr(gop[a].y - hole[b].y));
	}
	
	bool matching(int idx)
	{
		if(vis[idx]==true) return false;
		vis[idx] = true;
		for(int a=0;a<n;a++)
		{
			if(dist[idx][a]< mid && (val[a]==-1 || matching(val[a]) ) )
			{
				val[a] = idx;
				return true;
			}
		}
		return false;
	}
	
	int mcbm()
	{
		memset(val,-1,sizeof(val));
		int tot = 0;
		for(int a=0;a<m;a++)
		{
			memset(vis,false,sizeof(vis));
			if(matching(a)==true) tot++;
		}
		return tot;
	}
	
	bool process()
	{
		scanf("%d %d %d",&m,&n,&k);
		if(m-k>n) return false;
		for(int a=0;a<m;a++) scanf("%lf %lf",&gop[a].x,&gop[a].y);
		for(int a=0;a<n;a++) scanf("%lf %lf",&hole[a].x,&hole[a].y);
		double maxii = -1;
		for(int a=0;a<m;a++)
			for(int b=0;b<n;b++)
			{
				dist[a][b] = calc(a,b);
				maxii = max(maxii,dist[a][b]);
			}
		double lo = 0.000;
		double hi = maxii;
		ans = -1.0000;
		for(int a=0;a<=500;a++)
		{
			mid = (lo+hi)/2.00;
			int ret = mcbm();
			if(m-k <= ret)
			{
				hi = mid;
				ans = mid;
			}
			else lo = mid;
		}
		return true;
	}
	
	double dabs(double x)
	{
		if(x<-0.000000001) return -x;
		return x;
	}
	
	double formula(double s)
	{
		double w = abs(s*1000 - floor(s*1000) - 0.5);
		cout<<s<<" "<<w<<endl;
		return w;
	}
	
	int main()
	{
		int ntc;
		scanf("%d",&ntc);
		for(int tc=1;tc<=ntc;tc++)
		{
			bool ada = process();
			printf("Case #%d:\n",tc);
			if(m==0 && n==0 || (m==k) || m==0) printf("0.000\n");
			else if(ada==false) printf("Too bad.\n");
			else printf("%.3lf\n",ans + EPS);
			printf("\n");
		}
	}
