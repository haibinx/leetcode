#include <iostream>
#include <vector>

using namespace std;

int shortestsub(const vector<int>& nums) {
  if (nums.size() < 2) return 0;
  int start = nums.size();
  int end = -1;
  int max = nums[0];
  int min = nums.back();

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] >= max) {
      max = nums[i];
    } else {
      end = i;
    }
  }
  if (end == -1) return 0;

  for (int i = nums.size() -1; i >=0; i--) {
    if (nums[i] <= min) {
      min = nums[i];
    } else {
      start = i;
    }
  }

  return end -start +1;
}

int main() {
  cout << shortestsub({1,2,3,5,4,2}) << endl;
  cout << shortestsub({1,2,3,4,5}) << endl;
  cout << shortestsub({5,4,3,2,1}) << endl;
  return 0;
}
