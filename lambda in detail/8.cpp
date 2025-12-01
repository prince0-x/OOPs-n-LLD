#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	cin>> a>> b;
	// reusable  lambda 
	function<int(int,int)> add =[](int a, int b){return a+b;};

	cout<<"sum :"<<add(a,b)<<endl;
	return 0;
}