// Q Link -> https://leetcode.com/problems/lru-cache/

class LRUCache 
{
public:
    unordered_map<int,pair<int,list<int>::iterator>> mp;
    int capacity;
    int currSize;
    list<int> dll;
    LRUCache(int capacity) 
    {
        this->capacity=capacity;
        currSize=0;
        dll.clear();
        
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            dll.erase(mp[key].second);
            dll.push_front(key);
            mp[key].second=dll.begin();
            return mp[key].first;
        }
       
        return -1;
    
    }
    
    void put(int key, int value) 
    {
        
      if(mp.find(key)!=mp.end())
      {
          
          
          dll.erase(mp[key].second);
          dll.push_front(key);
          mp[key]={value,dll.begin()};
          
          
      }
        else
        {
            
            
            if(currSize>=capacity)
            {
       
                mp.erase(dll.back());
                     dll.pop_back();
        
            }
              dll.push_front(key);
          mp[key]={value,dll.begin()};
            currSize++;
    
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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
