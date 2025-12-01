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
	// reusable functional with reference valiable lambda 
	function<int()> add =[&a,&b](){return a+b;};

	cout<<"sum :"<<add()<<endl;
	return 0;
}