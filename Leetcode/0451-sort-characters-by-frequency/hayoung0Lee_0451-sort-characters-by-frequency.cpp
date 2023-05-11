class Solution {
public:
    string frequencySort(string s) {
        // unordered_map m, 
        // 몇개있는지 트랙킹
        struct LengthComparator {
            bool operator()(pair<char, int> a, pair<char, int> b) const {
                return a.second < b.second;
            }
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, LengthComparator> pq;
        unordered_map<char, int> hash;
        
        for(int i = 0; i < s.size(); i++){
            if(hash.find(s[i]) != hash.end()){
                hash[s[i]] = hash[s[i]] + 1; 
            }else{
                hash[s[i]] = 1;
            }
        }
        
        for(auto element : hash){
            pq.push(pair<char, int>(element.first, element.second));
        }
        
        string answer = "";
        
        while(!pq.empty()){
            pair<char, int> letter = pq.top(); pq.pop();
            for(int i = 0; i < letter.second; i++){
                answer += letter.first;
            }
        }
        
        return answer;
    }
};