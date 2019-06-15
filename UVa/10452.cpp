#include<bits/stdc++.h>
using namespace std;

int r,c;
char f[10][10];
char name[]={"@IEHOVA"};

int px[]={1,-1,0};
int py[]={0,0,1};

bool recursive(int y,int x,int id)
{
	if(id==-1) return true;
	for(int a=0;a<3;a++)
	{
		int yy = py[a] + y;
		int xx = px[a] + x;
		if(yy<0 ||xx<0 || yy>=r ||xx>=c) continue;
		if(f[yy][xx]==name[id] && recursive(yy,xx,id-1)==true)
		{
			if(id!=0) printf(" ");
			if(a==0) printf("left");
			if(a==1) printf("right");
			if(a==2) printf("forth");
			return true;
		}
	}
	return false;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&r,&c);
		int sx=0 ,sy = 0;
		for(int a=0;a<r;a++)
		{
			scanf("%s",f[a]);
			for(int b=0;b<c;b++)
				if(f[a][b]=='#') sy = a,sx = b;
		}
		if(recursive(sy,sx,6)==true) ;
		printf("\n");
	}
}
