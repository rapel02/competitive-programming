#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

map<string,pair<double,double> > mmap;
map<string,bool> mmab;

const double PI = acos(-1);

string s;

string s1,s2;

double gcDistance(double lat1,double long1, double lat2, double long2, double rad)
{
	lat1 *= PI/180.0;
	lat2 *= PI/180.0;
	long1 *= PI/180.0;
	long2 *= PI/180.0;
	return rad * acos(cos(lat1) * cos(long1) * cos(long2)*cos(lat2) + cos(lat1)*sin(long1)*cos(lat2)*sin(long2) + sin(lat1)*sin(lat2));
}

int main()
{
	double lat,lon;
	while(1)
	{
		cin>>s;
		if(s=="#") break;
		cin>>lat>>lon;
		mmap[s] = mp(lat,lon);
		mmab[s] = true;
	}
	while(1)
	{
		cin>>s1>>s2;
		if(s1=="#" && s2=="#") break;
		cout<<s1<<" - "<<s2<<endl;
		if(mmab[s1] ==false || mmab[s2]==false)
		{
			cout<<"Unknown"<<endl;
		}
		else if(s1==s2)
		{
			cout<<"0 km"<<endl;
		}
		else
		{
			double lat1,long1,lat2,long2;
			lat1 = mmap[s1].ff;
			lat2 = mmap[s2].ff;
			long1 = mmap[s1].ss;
			long2 = mmap[s2].ss;
			printf("%d km\n",(int)round(gcDistance(lat1,long1,lat2,long2,6378)));
		}
	}
}
