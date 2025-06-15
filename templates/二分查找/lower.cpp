int lower_bound(vector<int> &nums, int target) {
int l = 0, r = nums.size(), mid;
while (l < r) {
mid = l + (r - l) / 2;
if (nums[mid] >= target) {
r = mid;
} else {
l = mid + 1;
}
}
return l;
}