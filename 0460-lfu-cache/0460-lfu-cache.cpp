class LFUCache {
public:
    int cap; 
    int size; 
    unordered_map<int, list<vector<int>>::iterator> mp; 
    map<int, list<vector<int>>> freq; 

    LFUCache(int capacity) {
        cap = capacity; 
        size = 0; 
    }

    void makeMostFrequentlyUsed(int key){
        auto &vec = (*(mp[key])); //list in which the item exist
        int value = vec[1]; //its value
 
        int f = vec[2]; //its frequency counter

        freq[f].erase(mp[key]); //remove that item from list

        if(freq[f].empty()){ //if that list gets empty
            freq.erase(f); //remove its entry from map as list emoty now
        }

        f++; //as not empty increase counter

        freq[f].push_front(vector<int>({key, value, f})); //push new item to freq map
        mp[key] = freq[f].begin(); //update cache map with new address

    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){ //if key not present return -1 
            return -1; 
        }

        auto &vec = (*(mp[key])); //list in which the item exists
        int value = vec[1]; //its valie

        makeMostFrequentlyUsed(key); //mark
        return value; 
    }
    
    void put(int key, int value) {
        if(cap == 0){
            return;
        }

        if(mp.find(key) != mp.end()){ //key already present
            auto &vec = (*(mp[key])); // the list in which the item exists
            vec[1] = value; //update with new value; 
            makeMostFrequentlyUsed(key); 
        } else if(size < cap){
            size++; 
            freq[1].push_front(vector<int>({key, value, 1})); //new item push with count as 1
            mp[key] = freq[1].begin(); 
        } else { //remove from LRU list as same freq tie
            auto &listToRemove = freq.begin()->second; //gives the list
            int itemToRemove = (listToRemove.back())[0]; //gives the key of item to be removed 
            listToRemove.pop_back(); //remove from LRU list from back. 
            if(listToRemove.empty()){
                freq.erase(freq.begin()->first); //remote enrty from freq map
            }

            freq[1].push_front(vector<int>({key, value, 1})); //new item

            mp.erase(itemToRemove); //remove from cache map
            mp[key] = freq[1].begin(); // update new added item 

        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */