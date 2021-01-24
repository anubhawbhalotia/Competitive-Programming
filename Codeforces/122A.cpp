#include<bits/stdc++.h>
using namespace std;
bool isLuckyNumber(int n) {
	int digit;
	while(n) {
		digit = n % 10;
		n /= 10;
		if(digit != 4 && digit != 7) {
			return 0;
		}
	}
	return 1;
}
vector<int> getAllLuckyNumberFromOneToN(int n) {
	vector<int> luckyNumbersList;
	for(int i = 1; i <= n; i++) {
		if(isLuckyNumber(i)) {
			luckyNumbersList.push_back(i);
		}
	}
	return luckyNumbersList;
}
int main() {
	int n;
	cin>>n;
	vector<int> luckyNumbersList = getAllLuckyNumberFromOneToN(n);
	for(int i : luckyNumbersList) {
		if(n % i == 0) {
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}