/*
 * @lc app=leetcode id=1845 lang=cpp
 *
 * [1845] Seat Reservation Manager
 */

// @lc code=start
struct MinComparator
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
class SeatManager
{
public:
    unordered_map<int, int> c;
    int count = 1;
    priority_queue<int, std::vector<int>, MinComparator> q;
    SeatManager(int n)
    {
        c.reserve(n);
    }

    int reserve()
    {
        if (!q.empty())
        {
            int x = q.top();
            c[x] = 1;
            q.pop();
            return x;
        }
        else
        {
            int y = count;
            c[count] = 1;
            count++;
            return y;
        }
        return 0;
    }

    void unreserve(int seatNumber)
    {
        q.push(seatNumber);
        c[seatNumber] = 0;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end
