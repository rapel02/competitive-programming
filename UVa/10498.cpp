#include<bits/stdc++.h>
#define INF 1e+9
using namespace std;

int n,m;

double arr[100][100];
double price[25];

double compute()
{
	double lz = 0;
	while(1)
	{
		for(int a=0;a<=m;a++)
		{
			for(int b=0;b<=n;b++) printf("%lf ",arr[a][b]);
			printf("\n");
		}
		printf("\n");
		lz = 0.000;
		int piv = -1;
		for(int a=0;a<n;a++)
		{
			if(arr[m][a]<lz)
			{
				lz = arr[m][a];
				piv = a;
			}
		}
		if(piv==-1) break;
		int n_piv = 0;
		double mini= 1000000;
		for(int a=0;a<m;a++)
		{
			if(arr[a][piv]==0.0000) continue;
			if(mini > arr[a][n]/arr[a][piv])
			{
				mini = arr[a][n] / arr[a][piv];
				n_piv = a;
			}
		}
		double rem = arr[n_piv][piv];
		for(int a=0;a<=n;a++) arr[n_piv][a] /= rem;
		//for(int a=0;a<=n;a++) cout<<" "<<arr[n_piv][a];
		//cout<<endl;
		for(int a=0;a<=m;a++)
		{
			if(a==n_piv) continue;
			double multi = -arr[a][piv]/arr[n_piv][piv];
			for(int b=0;b<=n;b++) arr[a][b]+=multi*arr[n_piv][b];
		}
	}
	return arr[m][n];
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int a=0;a<n;a++) scanf("%lf",&price[a]);
		for(int a=0;a<m;a++)
		{
			for(int b=0;b<n;b++) scanf("%lf",&arr[a][b]);
			scanf("%lf",&arr[a][n]);
			//printf("%lf\n",arr[a][n]);
		}
		for(int a=0;a<n;a++) arr[m][a] = -price[a];
		arr[m][n] = 0;
		printf("Nasa can spend %.0lf taka.\n",compute());
	}
}
