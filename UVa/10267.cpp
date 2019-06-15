#include<bits/stdc++.h>
using namespace std;

string in;

char arr[255][255];
char name[255];

int py[]={1,-1,0,0};
int px[]={0,0,1,-1};
int r,c;

void fill(int y,int x,char cc,char p)
{
	if(c == p) return ;
	arr[y][x] = cc;
	for(int a=-1;a<=1;a++)
	{
		for(int b=-1;b<=1;b++)
		{
			int yy = y + a;
			int xx = x + b;
			if(a == 0 && b == 0) continue;
			if(yy < 1 || xx < 1 || yy > r || xx > c) continue;
			if(arr[yy][xx] != p) continue;
			fill(yy,xx,cc,p);
		}
	}
	return ;
}

int main()
{
	while(cin>>in)
	{
		if(in=="I")
		{
			cin>>c>>r;
			for(int a=1;a<=r;a++) for(int b=1;b<=c;b++) arr[a][b] = 'O';
		}
		else if(in=="C")
		{
			for(int a=1;a<=r;a++) for(int b=1;b<=c;b++) arr[a][b] = 'O';
		}
		else if(in=="L")
		{
			int x,y;
			cin>>x>>y>>name;
			arr[y][x] = name[0];
		}
		else if(in=="V")
		{
			int x,y1,y2;
			cin>>x>>y1>>y2>>name;
			if(y1 > y2) swap(y1,y2);
			for(int a=y1;a<=y2;a++) arr[a][x] = name[0];
		}
		else if(in=="H")
		{
			int x1,x2,y;
			cin>>x1>>x2>>y>>name;
			if(x1 > x2) swap(x1,x2);
			for(int a=x1;a<=x2;a++) arr[y][a] = name[0];
		}
		else if(in=="K")
		{
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2>>name;
			if(y1 > y2) swap(y1,y2);
			if(x1 > x2) swap(x1,x2);
			for(int a=y1;a<=y2;a++) for(int b=x1;b<=x2;b++) arr[a][b] = name[0];
		}
		else if(in=="F")
		{
			int x,y;
			cin>>x>>y>>name;
			if(name[0] == arr[y][x]) continue;
			fill(y,x,name[0],arr[y][x]);
		}
		else if(in=="S")
		{
			scanf("%s",name);
			printf("%s\n",name);
			for(int a=1;a<=r;a++)
			{
				for(int b=1;b<=c;b++) printf("%c",arr[a][b]);
				printf("\n");
			}
		}
		else if(in=="X") break;
	}
}
