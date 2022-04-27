#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		int size = nums.size();
		if (size < 3) return {};
		sort(nums.begin(), nums.end());
		vector<vector<int> > res;
		int pt = 0;
		while (pt <= size - 3) {
			int pl = pt + 1;
			int pr = size - 1;
			int target = nums[pt];
			while (pl < pr) {
				int left = nums[pl], right = nums[pr];
				if (left + right == -target) {
					res.push_back({ target, left,right });
					for (pl++; nums[pl] == left && pl < size - 1; pl++);
				}
				else if (left + right < -target) {
					for (pl++; nums[pl] == left && pl < size - 1; pl++);
				}
				else {
					for (pr--; nums[pr] == right && pt > 0; pr--);
				}
			}
			for (pt++; nums[pt] == target && pt <= size - 3; pt++);
		}
		return res;
	}
};

int main() {
	vector<int> nums = { 0,0,0 };
	Solution solu;
	auto res = solu.threeSum(nums);
	for(int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}