#include "LRUCache.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Initializing Chat Activity Monitor with a capacity of 5 contacts." << endl;
    LRUCache cache(5);

    // 1. Fill the cache with initial contacts
    cout << "\nPutting initial contacts..." << endl;
    cache.put("Virendra", 15);
    cache.put("Jaimin", 25);
    cache.put("Karthik", 5);
    cache.put("Abhinav", 30);
    cache.put("Medhaj", 10);
    cache.printCache(); // Medhaj should be at the front

    // 2. Access an existing contact (Virendra), making him the most recent
    cout << "\nGetting Virendra's message count..." << endl;
    cache.get("Virendra");
    cout << "Cache state after accessing Virendra:" << endl;
    cache.printCache(); // Virendra should now be at the front

    // 3. Add a new contact (Rohan), which will evict the LRU contact (Jaimin)
    cout << "\nAdding Rohan. Cache is full, so Jaimin (LRU) will be evicted." << endl;
    cache.put("Rohan", 22);
    cache.printCache(); // Rohan at the front, Jaimin is gone

    // 4. Try to get the evicted contact
    cout << "\nTrying to get Jaimin's message count..." << endl;
    int jaimin_messages = cache.get("Jaimin");
    if (jaimin_messages == -1) {
        cout << "Jaimin is not in the cache, as expected." << endl;
    }
    
    // 5. Final cache state
    cout << "\nFinal cache state:" << endl;
    cache.printCache();

    return 0;
}
