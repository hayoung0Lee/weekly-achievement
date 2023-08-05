class MyCalendar {
public:
    std::set<pair<int, int>> s;
    
    MyCalendar() {
    
    }
    
    bool book(int start, int end) {  
        if(s.empty()){
            s.insert(make_pair(start, end-1));
            return true;
        }
        
        for(auto elem : s) {
            if(!((end - 1) < elem.first || (elem.second < start))){
                return false;
            }     
        }       
        
        s.insert(make_pair(start, end-1));
        return true;
        
//         for(int i = start; i < end; i++){
//             auto itr  = s.find(i);
//             if (itr != s.end()){
//                 return false;
//             }
//         }
        
//         for(int i = start; i < end; i++){
//             s.insert(i);
//         }
//         return true;   
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */