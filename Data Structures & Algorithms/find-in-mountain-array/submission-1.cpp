/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int find_peak(MountainArray &mountainArr){
        int n = mountainArr.length();
        int lo = 0;
        int hi = n-1;
        // check if mid is peak
        // if on inc slope -> go right
        // go left including mid
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
    int binary_search(int start, int end, MountainArray &mountainArr, int target, int dir){
        int lo = start;
        int hi = end;
        if(dir==1){
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(mountainArr.get(mid)==target){
                    return mid;
                }
                else if(mountainArr.get(mid)>target){
                    hi = mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
        }
        else{
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(mountainArr.get(mid)==target){
                    return mid;
                }
                else if(mountainArr.get(mid)>target){
                    lo=mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak_index = find_peak(mountainArr);
        int left = binary_search(0,peak_index,mountainArr,target,1);
        int right = binary_search(peak_index+1,n-1,mountainArr,target,-1);
        if(left==-1 && right==-1) return -1;
        if(left==-1) return right;
        return left;
    }
};