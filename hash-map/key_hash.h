#ifndef KEY_HASH_H
#define KEY_HASH_H

#define TABLE_SIZE 26

template <class K>
class KeyHash {
   public:
    unsigned long operator()(const K& key) const { return key[0] % TABLE_SIZE; }
};

#endif  // KEY_HASH_H
