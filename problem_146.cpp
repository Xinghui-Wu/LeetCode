/**
 * 146. LRU Cache
 * 
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * Implement the LRUCache class:
 *   LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 *   int get(int key) Return the value of the key if the key exists, otherwise return -1.
 *   void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * Constraints:
 *   1 <= capacity <= 3000
 *   0 <= key <= 104
 *   0 <= value <= 105
 *   At most 2 * 10^5 calls will be made to get and put.
 * 
 * Difficulty: Medium
 * Related Topics: Hash Table, Linked List, Design, Doubly-Linked List
 */
#include <iostream>
#include <unordered_map>

using namespace std;


struct DNode
{
    int key;
    int value;
    DNode* previous;
    DNode* next;
    DNode() : key(0), value(0), previous(nullptr), next(nullptr) {}
    DNode(int key, int value) : key(key), value(value), previous(nullptr), next(nullptr) {}
    DNode(int key, int value, DNode* previous, DNode* next) : key(key), value(value), previous(previous), next(next) {}
};


class LRUCache
{
private:
    int capacity_;
    DNode* head_;
    DNode* tail_;
    unordered_map<int, DNode*> cache_;


    void add_to_head(DNode* node)
    {
        node->previous = head_;
        node->next = head_->next;
        head_->next->previous = node;
        head_->next = node;
    }


    void move_to_head(DNode* node)
    {
        node->previous->next = node->next;
        node->next->previous = node->previous;

        add_to_head(node);
    }


    DNode* remove_tail()
    {
        DNode* lru = tail_->previous;
        
        lru->previous->next = tail_;
        tail_->previous = lru->previous;

        return lru;
    }


public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
        head_ = new DNode();
        tail_ = new DNode();
        head_->next = tail_;
        tail_->previous = head_;
    }
    

    int get(int key)
    {
        if (cache_.count(key) == 0)
        {
            return -1;
        }
        
        DNode* node = cache_[key];
        move_to_head(node);

        return node->value;
    }
    

    void put(int key, int value)
    {
        if (cache_.count(key) > 0)
        {
            DNode* node = cache_[key];
            node->value = value;
            move_to_head(node);
        }
        else
        {
            DNode* node = new DNode(key, value);
            cache_[key] = node;
            add_to_head(node);

            if (cache_.size() > capacity_)
            {
                DNode* lru = remove_tail();
                cache_.erase(lru->key);
                delete lru;
            }
        }
    }
};
