#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;

    // Front = Most Recently Used
    // Back  = Least Recently Used
    list<pair<int, int>> lst;

    // key -> iterator pointing to the corresponding list node
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key)
    {
        auto it = mp.find(key);

        // Key doesn't exist
        if (it == mp.end())
            return -1;

        // Iterator pointing to [key, value]
        auto node = it->second;

        // Save value
        int value = node->second;

        // Move existing node to front (MRU)
        lst.splice(lst.begin(), lst, node);

        return value;
    }

    void put(int key, int value)
    {
        auto it = mp.find(key);

        // Key already exists
        if (it != mp.end()) {

            // Update value
            it->second->second = value;

            // Move existing node to front
            lst.splice(lst.begin(), lst, it->second);
        }
        else {

            // Insert new node at front
            lst.push_front({key, value});

            // Store iterator to new node
            mp[key] = lst.begin();

            // Cache exceeded capacity
            if (lst.size() > capacity) {

                // Last node = LRU
                auto last = prev(lst.end());

                // Remove from map
                mp.erase(last->first);

                // Remove from list
                lst.pop_back();
            }
        }
    }
};

int main()
{
    LRUCache cache(3);

    cache.put(10, 100);
    cache.put(20, 200);
    cache.put(30, 300);

    cout << cache.get(10) << endl;

    cache.put(40, 400);

    cout << cache.get(20) << endl;
    cout << cache.get(30) << endl;
    cout << cache.get(40) << endl;

    return 0;
}
