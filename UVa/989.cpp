#include<bits/stdc++.h>
using namespace std;

int n;

int arr[15][15],temp[15][15],rem[15][15];

bool ans;

int row[15][20],col[15][20],area[15][20];


void compute(int r,int c)
{
	//printf("%d %d %d\n",r,c,n*n);
	if(c>=n*n)
	{
		compute(r+1,0);
		return ;
	} 
	if(r>=n*n)
	{
		//printf("in\n");
//		for(int a=0;a<n*n;a++)
//		{
//			for(int b=0;b<n*n;b++) printf("%d ",temp[a][b]);
//			printf("\n");
//		}
		ans = true;
		int mark = 0;
		for(int a=0;a<n*n;a++)
		{
			for(int b=0;b<n*n;b++)
			{
				if(rem[a][b]>temp[a][b])
				{
					mark = 1;
					break;
				}
				else if(rem[a][b]<temp[a][b])
				{
					mark = -1;
					break;
				}
			}
			if(mark!=0) break;
		}
		if(mark==1)
		{
			for(int a=0;a<n*n;a++)
				for(int b=0;b<n*n;b++) rem[a][b] = temp[a][b];
		}
		return ;
	}
	if(arr[r][c]!=0) 
	{
		compute(r,c+1);
		return ;
	}
	for(int a=1;a<=9;a++)
	{
		if(row[r][a]==0 && col[c][a]==0 && area[r/n*n + c/n][a]==0)
		{
			temp[r][c] = a;
			row[r][a] = 1;
			col[c][a] = 1;
			area[r/n*n + c/n][a] = 1;
			compute(r,c+1);
			row[r][a]--;
			col[c][a]--;
			area[r/n*n + c/n][a]--;
			temp[r][c] = 0;
		}
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		ans = false;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(area,0,sizeof(area));
		for(int a=0;a<n*n;a++) 
			for(int b=0;b<n*n;b++) 
			{
				rem[a][b] = 99;
				scanf("%d",&arr[a][b]);
				row[a][arr[a][b]]++;
				col[b][arr[a][b]]++;
				area[a/n*n + b/n][arr[a][b]]++;
				temp[a][b] = arr[a][b];
			}
		compute(0,0);
		if(ans==false) printf("NO SOLUTION\n");
		else
		{
			for(int a=0;a<n*n;a++)
			{
				for(int b=0;b<n*n;b++)
				{
					if(b!=0) printf(" ");
					printf("%d",rem[a][b]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
}
