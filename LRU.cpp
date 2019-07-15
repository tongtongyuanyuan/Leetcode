//
// Created by Tong Xue on 7/15/19.
//

class LRUCache {
public:

    LRUCache(int capacity): capacity(capacity) {}

    int get(int key) {
        if(kv.find(key) == kv.end()){ //没有找到
            return -1;
        }
        else{
            //Update LRU and others;
            lru.erase(kl[key]);
            lru.push_front(key);
            kl[key] = lru.begin();
            return kv[key];
        }

    }

    void put(int key, int value) {
        if(kv.size() == capacity && kv.find(key) == kv.end()){
            //Delete the final one, put in the first one.
            kv.erase(lru.back());
            kl.erase(lru.back());
            lru.pop_back();
        }
        //Update Lru and others
        if(kv.find(key) != kv.end()){
            lru.erase(kl[key]);
        }
        lru.push_front(key);
        kl[key] = lru.begin();
        kv[key] = value;
    }


private:
    int capacity;
    list<int> lru;                              // key list. Save by time;
    unordered_map<int, list<int>::iterator> kl; // key - iterator in list
    unordered_map<int ,int> kv;                 // key-value
};
int mian() {

}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
     * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

