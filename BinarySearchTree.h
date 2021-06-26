#pragma once

template <typename Key, typename Value>
class AssociativeArray {
public:
    virtual void add(const Key& key, const Value& value) = 0;
    virtual Value& find(const Key& key) = 0;
    virtual void remove(const Key& key) = 0;
};

template <typename Key, typename Value>
class BinarySearchTree : public AssociativeArray<Key, Value> {
    class Node {
        public:
            Node(const Key& key, const Value& value);
            ~Node();
            Node* _left;
            Node* _right;
            Key _key;
            Value _value;
    };
    Node* _head;
public:
    BinarySearchTree();

    void add(const Key& key, const Value& value) override;
    Value& find(const Key& key) override;
    void remove(const Key& key) override;

    ~BinarySearchTree();

};

#include "BinarySearchTree.inl"
