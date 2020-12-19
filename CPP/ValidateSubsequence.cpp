#include<iostream>
#include<vector>

using namespace std;

bool IsValidSubsequence(vector<int> array, vector<int> sequence) {
	
	return false;
}

int main(){

	//Test case 1
	vector<int> A1 {1, 2, 3, 4, 5};
	vector<int> S1 {1, 2};
	cout<<"Test 1 : "<<((IsValidSubsequence(A1, S1) == true) ? "PASS" : "FAIL")<<endl;
	return 0;
}
