/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache
{
    list<pair<int, int>> order;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int n = 0;
    void update_order(list<pair<int, int>>::iterator it)
    {
        order.splice(order.begin(), order, it);
        cache[it->first] = order.begin();
    }

public:
    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            update_order(it->second);
            return it->second->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            it->second->second = value;
            update_order(it->second);
        }
        else
        {
            if (order.size() == n)
            {
                cache.erase(order.back().first);
                order.pop_back();
            }
            order.emplace_front(key, value);
            cache[key] = order.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
