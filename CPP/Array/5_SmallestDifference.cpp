/*
AlgoExpert array smallest difference
Given two array, find out smallest difference between elements of two arrays.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
		vector<int> res;

		sort(arrayOne.begin(), arrayOne.end());
		sort(arrayTwo.begin(), arrayTwo.end());

		int numOne, numTwo;
		int minSoFar = INT_MAX;
		int currDiff = INT_MAX;
		int i = 0, j = 0;
		while (i < arrayOne.size() && j < arrayTwo.size()) {
			numOne = arrayOne[i];
			numTwo = arrayTwo[j];
			if (numOne < numTwo) {
				currDiff = numTwo - numOne;
				i++;
			}
			else if (numOne > numTwo) {
				currDiff = numOne - numTwo;
				j++;
			}
			else {
				res = { numOne, numTwo };
				return res;
			}

			if (currDiff < minSoFar) {
				minSoFar = currDiff;
				res = { numOne, numTwo };
			}
		}
		return res;
	}
};

void printVI(vector<int>& vi) {
    cout << "[";
    for (auto x : vi) {
        cout << x << ", ";
    }
	cout << "], " << endl;
}

void testSolution(vector<int> arrOne, vector<int> arrTwo) {
    cout << "Input: ";
    printVI(arrOne);
	printVI(arrTwo);

    Solution s;
    vector<int> res = s.smallestDifference(arrOne, arrTwo);
    cout << "\nres: ";
    printVI(res);
    cout << "--------------------------------\n";
}

int main() {
	testSolution({ -1, 0, 1, 2, -1, -4 }, {1, 2, 3, 4, 5, 6}); //Output:
	testSolution({ -3, 10, 8, 9, -3, -4 }, { 1, 2, 3, 4, 5, 6 }); //Output:

	return 0;
}
