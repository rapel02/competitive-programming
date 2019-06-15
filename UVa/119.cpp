#include<bits/stdc++.h>
using namespace std;

string in[15];
map<string,int> mmap;
int total[15];


int main()
{
	int n;
	ios_base::sync_with_stdio(false);
	bool isf = true;
	while(cin>>n)
	{
		mmap.clear();
		if(!isf) cout<<endl;
		isf = false;
		for(int a=0;a<n;a++) 
		{
			total[a] = 0;
			cin>>in[a];
			mmap[in[a]] = a;
		}
		for(int a=0;a<n;a++)
		{
			string nm;
			int dt,m;
			cin>>nm>>dt>>m;
			int idx = mmap[nm];
			if(m!=0)
			{
				total[idx] -= dt;
				total[idx] += (dt - (dt/m*m) );
				for(int b=0;b<m;b++)
				{
					string mn;
					cin>>mn;
					int tar = mmap[mn];
					total[tar] += dt/m;
				}
			}
		}
		for(int a=0;a<n;a++) cout<<in[a]<<" "<<total[a]<<endl;
	}
}
