// Q Link -> https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    
    unordered_map<int,int> mp;
    unordered_map<int,int> cnt;
    queue<int> l_acc;
    int cap;
    LRUCache(int capacity)
    {
        cap=capacity;
    }
    
    int get(int key) 
    {
        auto x=mp.find(key);
        if(x==mp.end()) return -1;
        int val=x->second;
        l_acc.push(key);
        cnt[key]++;
        return val;
    }
    
    void put(int key, int value)
    {
        if(mp.size()<cap)
        {
            mp[key]=value;
            cnt[key]++;
            l_acc.push(key);
            return ;
        }
        
       auto x=mp.find(key);
        if(x!=mp.end())
        {
            mp[key]=value;
            cnt[key]++;
            l_acc.push(key);
            return ;
        }
        
      while(true)
      {
          int f=l_acc.front();
          l_acc.pop();
          cnt[f]--;
          if(cnt[f]==0)
          {
              mp.erase(mp.find(f));
              break;
          }
      
          
      }
        
   mp[key]=value;
        cnt[key]++;
        l_acc.push(key);
        
        return ;
        
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj
