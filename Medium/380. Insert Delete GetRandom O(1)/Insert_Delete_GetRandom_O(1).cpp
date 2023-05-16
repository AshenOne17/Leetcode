/*
* Implement the RandomizedSet class:

  - RandomizedSet() Initializes the RandomizedSet object.
  - bool insert(int val) Inserts an item val into the set if not present. 
    Returns true if the item was not present, false otherwise.
  - bool remove(int val) Removes an item val from the set if present. 
    Returns true if the item was present, false otherwise.
  - int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). 
    Each element must have the same probability of being returned.

  You must implement the functions of the class such that each function works in average O(1) time complexity.

  -----
  Example 1:

  Input:
  ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
  [[], [1], [2], [2], [], [1], [2], []]

  Output:
  [null, true, false, true, 2, true, false, 2]

  Explanation:
  RandomizedSet randomizedSet = new RandomizedSet();
  randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
  randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
  randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
  randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
  randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
  randomizedSet.insert(2); // 2 was already in the set, so return false.
  randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 
  -----
  Constraints:

  -231 <= val <= 231 - 1

  At most 2 * 105 calls will be made to insert, remove, and getRandom.

  There will be at least one element in the data structure when getRandom is called.
*/

#include <unordered_set>
#include <vector>
#include <random>

class RandomizedSet {
private:
    std::unordered_set<int> set_;
    std::vector<int> vec_;
    std::random_device rd_;
    std::mt19937 gen_;
public:
    RandomizedSet() : gen_(rd_()) {}

    bool insert(int val) {
        if (set_.count(val))
            return false;

        set_.insert(val);
        vec_.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!set_.count(val))
            return false;

        set_.erase(val);
        vec_.erase(std::find(vec_.begin(), vec_.end(), val));
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<> dist(0, vec_.size() - 1);
        return vec_[dist(gen_)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Code for testing 
// Should produce result [true] (inserting value 1), [false] (removing value 2), 1

/*
int main() {

    RandomizedSet* obj = new RandomizedSet();

    int val_1 = 1;

    bool param_1 = obj->insert(val_1);

    std::cout << "[" << std::boolalpha << param_1 << "] (inserting value " << val_1 << "), ";

    int val_2 = 2;

    bool param_2 = obj->remove(val_2);

    std::cout << "[" << std::boolalpha << param_2 << "] (removing value " << val_2 << "), ";

    int param_3 = obj->getRandom();

    std::cout << param_3;

    return 0;
}
*/