#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <string>
#include <list>
#include <unordered_map>
#include <iostream>


using namespace std;

// A pair to store the contact name (key) and message count (value)
using CacheEntry = pair<string, int>;
// A list of these pairs will be our cache
using CacheList = list<CacheEntry>;

class LRUCache {
public:
    // Constructor: Initializes the cache with a given capacity
    LRUCache(size_t capacity);

    // Get the number of messages for a contact. Returns -1 if not found.
    int get(const string& contact);

    // Add or update a contact's message count in the cache.
    void put(const string& contact, int messages);

    // Prints the current state of the cache from most to least recent.
    void printCache() const;

private:
    // The maximum number of entries the cache can hold
    size_t capacity_;
    
    // The list storing the cache entries. Front is most recent.
    CacheList cache_list_;

    // The map for O(1) lookup. Maps a contact name to an iterator in the list.
    unordered_map<string, CacheList::iterator> map_;

    // Helper function to move an accessed entry to the front of the list.
    void moveToFront(CacheList::iterator it);

    // Helper function to remove the least recently used entry.
    void removeLRU();
};

#endif // LRU_CACHE_H
