#include<bits/stdc++.h>
using namespace std;

int tot[800005];
int num[200000];
char in[1000];

int build(int idx,int ll,int rr)
{
	if(ll==rr) return tot[idx]=num[ll];
	else
	{
		tot[idx]=build(2*idx,ll,(ll+rr)/2)+build(2*idx+1,(ll+rr)/2+1,rr);
		return tot[idx];
	}
}

void query(int idx,int ll,int rr,int nm,int chg)
{
	//printf("%d %d %d %d %d\n",idx,ll,rr,nm,chg);
	if(ll>nm || rr< nm) 
	{
		//printf("finish\n");
		return;
	}
	else if(ll==rr) tot[idx]+=chg;
	else
	{
		tot[idx]=tot[idx] + chg;
		query(2*idx,ll,(ll+rr)/2,nm,chg);
		query(2*idx+1,(ll+rr)/2+1,rr,nm,chg);
	}
}

int show(int idx,int ll,int rr,int sl,int sr)
{
	//printf("%d %d %d %d %d\n",idx,ll,rr,sl,sr);
	if(ll>sr || rr<sl) return 0;
	else if(sl<=ll && rr<=sr) return tot[idx];
	else
	{
		return show(2*idx,ll,(ll+rr)/2,sl,sr) + show(2*idx+1,(ll+rr)/2+1,rr,sl,sr);
	}
}

int main()
{
	int k=1,r;		
	scanf("%d",&r);getchar();
	do
	{
		memset(tot,0,sizeof(tot));
		if(r==0) break;
		for(int a=1;a<=r;a++)
		{
			scanf("%d",&num[a]); getchar();
		}
		build(1,1,r);
		printf("Case %d:\n",k);
		while(1)
		{
			scanf("%[^\n]",in); getchar();
			int len=strlen(in);
			if(len==3 && in[0]=='E') break;
			else
			{
				bool sp1=false;
				int n1=0,n2=0;
				for(int a=2;a<len;a++)
				{
					if(in[a]==' ') sp1=true;
					else if(sp1==false)
					{
						n1=n1*10+(in[a]-'0');
					}
					else n2=n2*10+(in[a]-'0');
				}
				//printf("%d %d %c\n",n1,n2,in[0]);
				if(in[0]=='M')
				{
					printf("%d\n",show(1,1,r,n1,n2));
				}
				else if(in[0]=='S')
				{
					query(1,1,r,n1,n2-num[n1]);
					num[n1]=n2;
					//printf("hooray\n");
				}
			}
		}		
		scanf("%d",&r);getchar();
		if(r!=0)printf("\n");
		k++;
	}while(r!=0);
}
