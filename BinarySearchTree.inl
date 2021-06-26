#pragma once

#include "BinarySearchTree.h"

#include <stdexcept>

template <typename K, typename V>
BinarySearchTree<K, V>::Node::Node(const K& key, const V& value) {
    _key = key;
    _value = value;
    _left = nullptr;
    _right = nullptr;
}

template <typename K, typename V>
BinarySearchTree<K, V>::Node::~Node() {
    delete _left;
    delete _right;
}

template <typename K, typename V>
BinarySearchTree<K, V>::BinarySearchTree() {
    _head = nullptr;
}

template <typename K, typename V>
void BinarySearchTree<K, V>::add(const K& key, const V& value) {
    Node* node = _head;
    if (node != nullptr) {
        while (((node->_key >= key) && (node->_left != nullptr)) || ((node->_key <  key) && (node->_right != nullptr))) {
            if (node->_key < key) {
                node = node->_right;
            }
            else {
                node = node->_left;
            }
        }
        if (node->_key < key) {
            node->_right = new Node(key, value);
        }
        else {
            node->_left = new Node(key, value);
        }
    }
    else {
        _head = new Node(key, value);
    }
}

template <typename K, typename V>
V& BinarySearchTree<K, V>::find(const K& key) {
    Node* node = _head;
    if (node != nullptr) {
        while (((node->_key > key) && (node->_left != nullptr)) || ((node->_key < key) && (node->_right != nullptr))) {
            if (node->_key < key) {
                node = node->_right;
            }
            else {
                node = node->_left;
            }
        }
    }
    else {
        throw std::logic_error("find");
    }
    if (node->_key != key) {
        throw std::logic_error("find");
    }
    else {
        return node->_value;
    }
}

template <typename K, typename V>
void BinarySearchTree<K, V>::remove(const K& key) {
    Node* node = _head;
    Node* nodePARENT = nullptr;
    if (node != nullptr) {
        while (((node->_key > key) && (node->_left != nullptr)) || ((node->_key < key) && (node->_right != nullptr))) {
            nodePARENT = node;
            if (node->_key < key) {
                node = node->_right;
            }
            else {
                node = node->_left;
            }
        }
        if (!nodePARENT && node->_key == key) {
            if ((node->_left == nullptr) && (node->_right == nullptr)) {
                _head = nullptr;
                delete node;
            }
            else if ((node->_left != nullptr) && (node->_right != nullptr)) {
                Node* nodeRIGHT = node->_left;
                _head = node->_left;
                while (nodeRIGHT->_right != nullptr) {
                    nodeRIGHT = nodeRIGHT->_right;
                }
                nodeRIGHT->_right = node->_right;
                node->_left = nullptr;
                node->_right = nullptr;
                delete node;
            }
            else {
                if (node->_left != nullptr) {
                    _head = node->_left;
                    node->_left = nullptr;
                }
                else if (node->_right != nullptr) {
                    _head = node->_right;
                    node->_right = nullptr;
                }
                delete node;
            }
        }
        else if (node->_key == key) {
            if ((node->_left == nullptr) && (node->_right == nullptr)) {
                if (nodePARENT->_key < key) {
                    nodePARENT->_right = nullptr;
                }
                else {
                    nodePARENT->_left = nullptr;
                }
                delete node;
            }
            else if ((node->_left != nullptr) && (node->_right != nullptr)) {
                if (nodePARENT->_key < key) {
                    nodePARENT->_right = node->_left;
                }
                else {
                    nodePARENT->_left = node->_left;
                }
                Node* nodeRIGHT = node->_left;
                while (nodeRIGHT->_right != nullptr) {
                    nodeRIGHT = nodeRIGHT->_right;
                }
                nodeRIGHT->_right = node->_right;
                node->_left = nullptr;
                node->_right = nullptr;
                delete node;
            }
            else {
                if (node->_left != nullptr) {
                    if (nodePARENT->_key < key) {
                        nodePARENT->_right = node->_left;
                    }
                    else {
                        nodePARENT->_left = node->_left;
                    }
                    node->_left = nullptr;
                }
                else if (node->_right != nullptr) {
                    if (nodePARENT->_key < key) {
                        nodePARENT->_right = node->_right;
                    }
                    else {
                        nodePARENT->_left = node->_right;
                    }
                    node->_right = nullptr;
                }
                delete node;
            }
        }
    }
}

template <typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree() {
    delete _head;
}
