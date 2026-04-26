// filter odd and even number using lambda function
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int num;
	cin>>num;
	vector<int> nums(num),odds,evens;
	for (int i = 0; i < num; i++) {
        cin >> nums[i];
    }

	//lambda functions 
	auto even=[](int a){return a%2==0;};
	auto odd=[](int a){return a%2!=0;};
    
    // applying filters
	copy_if(nums.begin(),nums.end(),back_inserter(evens),even);

	copy_if(nums.begin(),nums.end(),back_inserter(odds),odd);

    //printing values
	cout<<"even values from array\n";
    for(auto a:evens)cout<<a<<" ";
    cout<<"\nodd values from array\n";
    for(auto a:odds)cout<<a<<" ";
    cout<<"\n";
	return 0;
}