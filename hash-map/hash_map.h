#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "hash_node.h"
#include "key_hash.h"

template <class K, class V, class F = KeyHash<K>>
class HashMap {
   public:
    HashMap() { table = new HashNode<K, V> *[TABLE_SIZE](); }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode<K, V> *entry = table[i];
            while (entry) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
        }
        delete[] table;
    }

    V get(const K &key) {
        const unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = table[hashValue];
        while (entry) {
            if (entry->getKey() == key) {
                return entry->getValue();
            }
            entry = entry->getNext();
        }
        return 0;
    }

    void put(const K &key, const V &value) {
        const unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *entry = table[hashValue];
        while (entry && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }
        if (!entry) {
            entry = new HashNode<K, V>(key, value);
            if (!prev)
                table[hashValue] = entry;
            else
                prev->setNext(entry);
        } else {
            entry->setValue(value);
        }
    }

    void remove(const K &key) {
        const unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *entry = table[hashValue];
        while (entry && entry->getKey() != key) {
            prev = entry;
            entry = entry->next;
        }
        if (!entry) return;
        if (!prev) {
            table[hashValue] = entry->getNext();
        } else {
            prev->setNext(entry->getNext());
        }
        delete entry;
    }

   private:
    F hashFunc;
    HashNode<K, V> **table;
};

#endif  // HASH_MAP_H
