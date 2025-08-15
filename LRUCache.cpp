#include "LRUCache.h"


using namespace std;

// Constructor implementation
LRUCache::LRUCache(size_t capacity) : capacity_(capacity) {}

// Adds or updates a key-value pair
void LRUCache::put(const string& contact, int messages) {
    // Check if the contact is already in the cache
    auto it = map_.find(contact);

    if (it != map_.end()) {
        // Contact exists: update its message count and move it to the front
        it->second->second = messages;
        moveToFront(it->second);
    } else {
        // Contact is new
        // If the cache is full, remove the least recently used item
        if (cache_list_.size() == capacity_) {
            removeLRU();
        }
        // Add the new contact to the front of the list
        cache_list_.emplace_front(contact, messages);
        // Store an iterator to the new entry in the map
        map_[contact] = cache_list_.begin();
    }
}

// Retrieves the value for a given key
int LRUCache::get(const string& contact) {
    auto it = map_.find(contact);
    
    // If contact is not found, return -1
    if (it == map_.end()) {
        return -1; 
    }
    
    // Contact found: move it to the front to mark it as recently used
    moveToFront(it->second);
    // Return the message count
    return it->second->second;
}

// Helper to move an element to the front of the list
void LRUCache::moveToFront(CacheList::iterator it) {
    // std::list::splice is a highly efficient O(1) operation
    cache_list_.splice(cache_list_.begin(), cache_list_, it);
}

// Helper to remove the least recently used element
void LRUCache::removeLRU() {
    // The LRU item is at the back of the list
    CacheEntry& last = cache_list_.back();
    
    // Erase it from the map
    map_.erase(last.first);
    
    // Erase it from the list
    cache_list_.pop_back();
}

// Prints the cache's contents
void LRUCache::printCache() const {
    cout << "---- Cache Content (Most to Least Recent) ----" << endl;
    for (const auto& entry : cache_list_) {
        cout << entry.first << ": " << entry.second << " messages" << endl;
    }
    cout << "---------------------------------------------" << endl;
}
