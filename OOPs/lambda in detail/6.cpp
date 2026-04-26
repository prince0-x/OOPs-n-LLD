#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	cin>> a>> b;
	// mutable lambda 
	auto test =[a]()mutable{
		a+=7;
		cout<<"inside lambda :"<<a<<endl;
	};
	test();
    cout<<"outside lambda :"<<a<<endl;
	return 0;
}