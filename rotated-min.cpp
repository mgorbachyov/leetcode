#include <cstdio>
#include <vector>

using namespace std;

int min_range(const vector<int>& nums, size_t first, size_t last)
{
	if (first == last) {
		return nums[first];
	}

	size_t pos = first + ((last - first) >> 1);
	if (nums[pos] < nums[last]) {
		return min_range(nums, first, pos);
	}
	return min_range(nums, pos + 1, last);
}

int findMin(vector<int>& nums)
{
	return min_range(nums, 0, nums.size() - 1);
}

int main(int argc, char** argv)
{
	//vector<int> nums { 4,5,6,7,0,1,2 };
	vector<int> nums { 11,13,15,17 };

	printf("%d\n", findMin(nums));
	return 0;
}

