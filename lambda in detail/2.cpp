#include<iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//lambda with parameter
	auto sum =[](int a, int b){return a+b;};
    // function call
    int a, b;
    cin >> a >> b;
    cout<<sum(a,b)<<endl;
    cout<<sum(a,b)<<endl;
	return 0;
}