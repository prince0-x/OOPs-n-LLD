#include<iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//lambda without parameter
	auto hello =[](){cout<<"hello prince!"<<endl;};
    // function call
    hello();
    hello();
	return 0;
}