/*
Validate subsequence: Check whether an Array is Subarray of another Array.
Given two non-empty arrays of integers, write a function that determines where the seconds array is a subsequence of he first one.
Given two arrays A[] and B[] consisting of n and m integers. The task is to check whether the array B[] is a subarray of the array A[] or not.
*/

#include<iostream>
#include<vector>

using namespace std;

bool IsValidSubsequence( vector<int> A, vector<int> S ) {
	int n = A.size();
	int m = S.size();
	if( n == 0 ) return false;
	int i = 0, j = 0;
	for( i = 0; i < n; i++ ) {
		if( A[i] == S[j] ) {
			j++;
			if( j == m ) return true;
		}
	}

	return false;
}

int main(){

	cout<<"Test 1 : "<< ( ( IsValidSubsequence( { 1 }, { 1 } ) == true ) ? "PASS" : "FAIL" ) << endl;
	cout<<"Test 2 : "<< ( ( IsValidSubsequence( { 1 }, { 5 } ) == false ) ? "PASS" : "FAIL" ) << endl;
	cout<<"Test 3 : "<< ( ( IsValidSubsequence( { 1, 2 }, { 1, 2 } ) == true ) ? "PASS" : "FAIL" ) << endl;
	cout<<"Test 4 : "<< ( ( IsValidSubsequence( { 1, 2, 3, 4, 5 }, { 5, 6 } ) == false ) ? "PASS" : "FAIL" ) << endl;
	cout<<"Test 5 : "<< ( ( IsValidSubsequence( { 1, 2, 3, 4, 5 }, { 1, 3, 5 } ) == true ) ? "PASS" : "FAIL" ) << endl;
	cout<<"Test 6 : "<< ( ( IsValidSubsequence( { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5, 6 } ) == false ) ? "PASS" : "FAIL" ) << endl;
	cout<<"Test 7 : "<< ( ( IsValidSubsequence( { 2, 3, 0, 5, 1, 1, 2 }, { 3, 0, 5, 1 } ) == true ) ? "PASS" : "FAIL" ) << endl;
	cout<<"Test 8 : "<< ( ( IsValidSubsequence( { 2, 3, 11, -5, 34, 21, -2, 8 }, { 3, -5, -2, 8 } ) == true ) ? "PASS" : "FAIL" ) << endl;
	return 0;
}
