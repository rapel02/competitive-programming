#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

char field[10][10];
int stats[10][10];

void king(int y,int x,int val) {
	for(int i = -1;i <= 1;i++) {
		for(int j = -1;j <= 1;j++) {
			if(i == 0 && j == 0) continue;
			stats[y + i][x + j] |= (1<<val);
		}
	}
}

void rook(int y,int x,int val) {
	for(int i = y + 1; i <= 8;i++) {
		stats[i][x] |= (1<<val);
		if(field[i][x] != '.') break;
	}
	for(int i = y - 1; i >= 1;i--) {
		stats[i][x] |= (1<<val);
		if(field[i][x] != '.') break;
	}
	for(int i = x + 1;i <= 8;i++) {
		stats[y][i] |= (1<<val);
		if(field[y][i] != '.') break;
	}
	for(int i = x - 1;i >= 1;i--) {
		stats[y][i] |= (1<<val);
		if(field[y][i] != '.') break;
	}
}

void bishop(int y,int x,int val) {
	for(int i = y + 1, j = x + 1; i <= 8 && j <= 8;i++,j++) {
		stats[i][j] |= (1<<val);
		if(field[i][j] != '.') break;
	}
	for(int i = y + 1, j = x - 1; i <= 8 && j >= 1;i++,j--) {
		stats[i][j] |= (1<<val);
		if(field[i][j] != '.') break;
	}
	for(int i = y - 1, j = x + 1; i >= 1 && j <= 8;i--,j++) {
		stats[i][j] |= (1<<val);
		if(field[i][j] != '.') break;
	}
	for(int i = y - 1, j = x - 1; i >= 1 && j >= 1;i--,j--) {
		stats[i][j] |= (1<<val);
		if(field[i][j] != '.') break;
	}
}

void queen(int y,int x,int val) {
	rook(y,x,val);
	bishop(y,x,val);
}

void knight(int y,int x,int val) {
	for(int i = -2;i <= 2;i++) {
		for(int j = -2;j <= 2;j++) {
			if(i *i + j *j != 5) continue;
			int yy = i + y;
			int xx = j + x;
			if(yy < 1 || yy > 8 || xx < 1 || xx > 8) continue;
			stats[yy][xx] |= (1<<val);
		}
	}
}

void pawn(int y,int x,int val) {
	if(val == 1) {
		stats[y+1][x-1] |= (1<<val);
		stats[y+1][x+1] |= (1<<val);
	}
	else {
		stats[y-1][x-1] |= (1<<val);
		stats[y-1][x+1] |= (1<<val);		
	}
}

int main(){
	desperate_optimization(10);
	string in;
	int tc = 0;
	while(1) {
		tc++;
		int y = 1, x = 1;
		for(int i = 0;i < 10;i++) for(int j = 0;j < 10;j++) field[i][j] = '.', stats[i][j] = 0;
		int flag = 0;
		for(int i = 1;i <= 8;i++) for(int j = 1;j <= 8;j++) cin>>field[i][j];
		for(int i = 1;i <= 8;i++) {
			for(int j = 1; j <= 8;j++) {
				if(field[i][j] == '.') continue;
				flag = 1;
				if(tolower(field[i][j]) == 'k') king(i,j,field[i][j] == 'k');
				if(tolower(field[i][j]) == 'r') rook(i,j,field[i][j] == 'r');
				if(tolower(field[i][j]) == 'b') bishop(i,j,field[i][j] == 'b');
				if(tolower(field[i][j]) == 'q') queen(i,j,field[i][j] == 'q');
				if(tolower(field[i][j]) == 'n') knight(i,j,field[i][j] == 'n');
				if(tolower(field[i][j]) == 'p') pawn(i,j,field[i][j] == 'p');
			}
		}
		if(flag == 0) break;
		int tot = 0;
		for(int i = 1;i <= 8;i++) {
			for(int j = 1;j <= 8;j++) {
				if(field[i][j] == 'k' && (stats[i][j] & (1<<0))) tot += 1;
				if(field[i][j] == 'K' && (stats[i][j] & (1<<1))) tot += 2;
			}
		}
		string res = "no";
		if(tot == 1) res = "black";
		else if(tot == 2) res = "white";
		cout<<"Game #"<<tc<<": "<<res<<" king is in check."<<endl;
	}
	return 0;
}

