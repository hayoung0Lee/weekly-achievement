class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size() < k){
            return 0;
        }
        
        int answer = 0;
        int sum = 0;
        
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        
        for(int i = 0; i <= arr.size() - k; i++){
            if(sum / k >= threshold){
                answer++;
            }
            sum -= arr[i];
            if(i + k < arr.size()){
                sum += arr[i + k];            
            }
        }
        
        return answer;
    }
};