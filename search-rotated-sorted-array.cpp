#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
	if (nums.empty()) {
		return -1;
	}
	size_t first = 0;
	size_t last = nums.size() - 1;
	while (first != last) {
		printf("%d %d\n", first, last);
		size_t pos = first + ((last - first) >> 1);
		if (nums[first] < nums[pos]) {
			if ((target < nums[first]) || (target > nums[pos])) {
				first = pos + 1;
			} else {
				last = pos;
			}
		} else {
			if ((target < nums[pos + 1]) || (target > nums[last])) {
				last = pos;
			} else {
				first = pos + 1;
			}
		}
	}

	if (nums[first] == target) {
		return first;
	}
	return -1;
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		assert(!"usage: %s target");
	}

	//vector<int> nums { 4,5,6,7,0,1,2 };
	vector<int> nums { 9,1,2,3,4,5,6,7,8 };

	for (const auto& i : nums) {
		printf(" %d", i);
	}
	printf("\n");

	int target;
	if (sscanf(argv[1], "%d", &target) != 1) {
		assert(!"invalid input");
	}

	printf("res: %d\n", search(nums, target));
	return 0;
}

