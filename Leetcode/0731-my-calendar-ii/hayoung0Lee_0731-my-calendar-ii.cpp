// https://leetcode.com/problems/my-calendar-ii/discuss/323479/Simple-C%2B%2B-Solution-using-built-in-map-(Same-as-253.-Meeting-Rooms-II)

class MyCalendarTwo {
public:
    map<int, int> m;
    
    MyCalendarTwo() {
        
    }
    
    
    bool book(int start, int end) {
        // [5, [7, [10, 15], 20], 40] // 괄호 갯수를 생각하는 방식으로 풀수가 있음. 
        m[start]++;
        m[end]--;
        int booked = 0;
        
        for(auto it = m.begin(); it != m.end(); it++){
            booked += it->second;
            
            if(booked == 3){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
        
    }
};


// class MyCalendarTwo {
// public:
//     set<pair<int, int>> s;
    
//     MyCalendarTwo() {
        
//     }
    
//     bool book(int start, int end) {
//         auto it = s.lower_bound({start, end});
//         // (10, 20), (10, 40) / (50, 60), (50, 70) 일때
//         // (25, 40) 이런게 들어오면 50, 60을 반환해줌
        
//         std::cout << "=====" << std::endl;
//         for (auto it = s.begin(); it != s.end(); ++it) {
//             std::cout << it->first << ", " << it->second << std::endl;
//         }
//         std::cout << "!!!!!" << std::endl;

//         std::cout << "current it: " << it->first << ", " << it->second << std::endl; 
//         if(it != s.end() && next(it) != s.end() && !(next(it)->first >= end)){ 
//             // 마지막 값도 아니고, 그다음 값도 있을때 => 그다음 두개의 값에 대해서 테스트
//             std::cout << "next: " << next(it)->first << std::endl;
//             return false;
//         }else if(it != s.begin() && prev(it) != s.begin() && !(prev(prev(it))->second <= start)){ 
//             // 첫번째 값도 아니고, 그앞의 값도 있을때, 이전 두개의 값에 대해서 테스트
//             std::cout << "prev: " << prev(it)->second << std::endl;
//             return false; 
//         }
//         else if(it != s.begin() && it != s.end() && (prev(it)->second > start && it->first < end && it->first <= prev(it)->second)){
//             std::cout << "both: " << prev(it)->second << std::endl;
//             return false;
//         }
        
//         // std::cout << start << ", " << end << std::endl;
        
//         s.insert({start, end - 1}); 
//         return true;
//     }
// };

// /**
//  * Your MyCalendarTwo object will be instantiated and called as such:
//  * MyCalendarTwo* obj = new MyCalendarTwo();
//  * bool param_1 = obj->book(start,end);
//  */
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */