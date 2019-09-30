#ifndef HASH_NODE_H
#define HASH_NODE_H

template <class K, class V>
class HashNode {
   public:
    HashNode(const K &key, const V &value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    K getKey() const { return key; }

    V getValue() const { return value; }

    void setValue(V value) { this->value = value; }

    HashNode *getNext() const { return next; }

    void setNext(HashNode *next) { this->next = next; }

   private:
    K key;
    V value;
    HashNode *next;
};

#endif  // HASH_NODE_H
