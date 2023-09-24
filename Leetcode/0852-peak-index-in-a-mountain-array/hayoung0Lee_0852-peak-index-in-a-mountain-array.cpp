class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0; 
        int end  = arr.size() - 1; 
        int middle;
        
        // [0,1,0]
        // [0,2,1,0]
        // [0, 1, 4, 2]
        // [4, 5 , 4, 3, 2, 1]
        int answer = 0;
        while(start <= end){
            middle = (start + end) / 2; 
            if (arr[middle-1] <= arr[middle] && arr[middle] >= arr[middle+1]){
                answer = middle;
                break;
            }else if(arr[middle] <= arr[middle+1]){
                // 오른쪽으로 증가하는 방향일때 
                start = middle;
            }else {
                // 왼쪽으로 증가하는 방향일때
                end = middle;
            }
        }
        
        return answer;
    }
};