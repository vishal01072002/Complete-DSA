#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // CODE STUDIO sum of two array
    //       [4 1] 
    // + [1 2 3 4]
    //   [1 2 7 5]  Ans


    // =========== Optomal Approch ============
    // only in single traverse like merge sort

    int n = 4;
    int m = 4;
    // int nums[] = {2, 0, 1, 2, 1, 2, 0, 1, 0, 2, 0, 1};
    int a[] = {4,7,1,2};
    int b[] = {1,7,1,2};

    int carry = 0;
	int i = n-1; 
	int j = m-1;
	vector<int> ans;

	while(i>=0 && j>=0){
		int val1 = a[i--];
		int val2 = b[j--];

		int sum = val1 + val2 + carry;
		carry = sum/10;
		int digit = sum%10;

		ans.push_back(digit);
	}

	while(i>=0 ){
		int val1 = a[i--];

		int sum = val1 + carry;
		carry = sum/10;
		int digit = sum%10;

		ans.push_back(digit);
	}

	while(j>=0){
		int val2 = b[j--];

		int sum = val2 + carry;
		carry = sum/10;
		int digit = sum%10;

		ans.push_back(digit);
	}

    if(carry){
		ans.push_back(carry);
	}

	reverse(ans.begin(),ans.end());

    for (int l = 0; l < ans.size(); l++)
    {
        cout << ans[l] << " ";
    }
    cout << endl;
    return 1;
}