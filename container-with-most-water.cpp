#include <cstdio>
#include <vector>

using namespace std;

int max_area(vector<int>& height)
{
    size_t left = 0;
    size_t right = height.size() - 1;
    int area = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            int cur_area = height[left] * (right - left);
            if (cur_area > area) {
                area = cur_area;
            }
            left++;
        } else {
            int cur_area = height[right] * (right - left);
            if (cur_area > area) {
                area = cur_area;
            }
            right--;
        }
    }
    return area;
}

int main(int argc, char* argv[])
{
    //vector<int> height = {1,8,6,2,5,4,8,3,7};
    vector<int> height = {1,4,9,1};
    printf("%d\n", max_area(height));
    return 0;
}

