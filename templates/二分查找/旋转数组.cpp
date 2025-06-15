// 一个原本增序的数组被首尾相连后按某个位置断开（如 [1,2,2,3,4,5] → [2,3,4,5,1,2]，在第一
// 位和第二位断开），我们称其为旋转数组。给定一个值，判断这个值是否存在于这个旋转数组中

// 输入是一个数组和一个值，输出是一个布尔值，表示数组中是否存在该值。
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true


// 即使数组被旋转过，我们仍然可以利用这个数组的递增性，使用二分查找。对于当前的中点，
// 如果它指向的值小于等于右端，那么说明右区间是排好序的；反之，那么说明左区间是排好序的。
// 如果目标值位于排好序的区间内，我们可以对这个区间继续二分查找；反之，我们对于另一半区
// 间继续二分查找。
// 注意，因为数组存在重复数字，如果中点和左端的数字相同，我们并不能确定是左区间全部
// 相同，还是右区间完全相同。在这种情况下，我们可以简单地将左端点右移一位，然后继续进行
// 二分查找。



bool search(vector<int>& nums, int target) {
int l = 0, r = nums.size() - 1;
while (l <= r) {
int mid = l + (r - l) / 2;
if (nums[mid] == target) {
return true;
}
if (nums[l] == nums[mid]) {
// 无法判断哪个区间是增序的
++l;
} else if (nums[mid] <= nums[r]) {
// 右区间是增序的
if (target > nums[mid] && target <= nums[r]) {
l = mid + 1;
} else {
r = mid - 1;
}

} else {
// 左区间是增序的
if (target >= nums[l] && target < nums[mid]) {
r = mid - 1;
} else {
l = mid + 1;
}
}
}
return false;
}