#include<bits/stdc++.h>
using namespace std;

bool ans = false;
bool final = false;
int soln = 0;

int row[10][10],col[10][10],sqr[10][10],temp[10][10];
int n = 3;

int arr[10][10];

void compute(int rr,int cc)
{
	if(rr==9)
	{
		soln++;
		return ;
	}
	if(cc==9)
	{
		compute(rr+1,0);
		return ;
	}
	if(arr[rr][cc]!=0)
	{
		compute(rr,cc+1);
		return ;
	}
	for(int a=1;a<=9;a++)
	{
		if(row[rr][a]==0 && col[cc][a]==0 && sqr[rr/3*3 + cc/3][a]==0)
		{
			row[rr][a]=1;
			col[cc][a]=1;
			sqr[rr/3*3 + cc/3][a]=1;
			compute(rr,cc+1);
			row[rr][a]=0;
			col[cc][a]=0;
			sqr[rr/3*3 + cc/3][a]=0;
		}
	}
	
}

int main()
{
	int tc = 0;
	while(scanf("%d",&arr[0][0])!=EOF)
	{
		ans = true;
		soln = 0;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(sqr,0,sizeof(sqr));
		temp[0][0] = arr[0][0];
		if(arr[0][0]!=0)
		{
			row[0][arr[0][0]]++;
			col[0][arr[0][0]]++;
			sqr[0][arr[0][0]]++;
		}
		tc++;
		for(int a=0;a<9;a++) for(int b=0;b<9;b++){
			if(a+b==0) continue;
			scanf("%d",&arr[a][b]);
			if(arr[a][b]!=0)
			{
				row[a][arr[a][b]]++;
				col[b][arr[a][b]]++;
				sqr[a/3*3 + b/3][arr[a][b]]++;
				if(row[a][arr[a][b]]>1 || col[b][arr[a][b]]>1 || sqr[a/3 * 3 + b/3][arr[a][b]]>1) ans = false;
			}
			temp[a][b] = arr[a][b];
		}
		printf("Case %d: ",tc);
		if(!ans)
		{
			printf("Illegal.\n");
			continue;
		}
		compute(0,0);
		if(soln==0) printf("Impossible.\n");
		else if(soln==1) printf("Unique.\n");
		else printf("Ambiguous.\n");
	}
}
