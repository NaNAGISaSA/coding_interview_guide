#ifndef _CODEING_INTERVIEW_GUIDE_LINKED_LIST_LINKED_LIST_UTILS_H_
#define _CODEING_INTERVIEW_GUIDE_LINKED_LIST_LINKED_LIST_UTILS_H_

#include <type_traits>
#include <utility>

namespace coding_interview_guide::linked_list {

template <typename T>
struct Node {
    Node(T& value) : val(value), next(nullptr) {
    }
    Node(T&& value) : val(std::move(value)), next(nullptr) {
    }
    T val;
    Node* next;
};

template <typename T>
struct DoubleNode {
    DoubleNode(T& value) : val(value), prev(nullptr), next(nullptr) {
    }
    DoubleNode(T&& value) : val(std::move(value)), prev(nullptr), next(nullptr) {
    }
    T val;
    DoubleNode* prev;
    DoubleNode* next;
};

template <typename T>
struct RandNode {
    template <typename TT, std::enable_if_t<std::is_same<std::decay_t<TT>, T>::value, bool> = true>
    RandNode(TT&& value) : val(std::forward<TT>(value)), rand(nullptr), next(nullptr) {
    }

    T val;
    RandNode* rand;
    RandNode* next;
};

template <typename T>
struct BST {
    template <typename TT, std::enable_if_t<std::is_same<std::decay_t<TT>, T>::value, bool> = true>
    BST(TT&& value) : val(std::forward<TT>(value)), lch(nullptr), rch(nullptr) {
    }

    template <typename TT, std::enable_if_t<std::is_same<std::decay_t<TT>, T>::value, bool> = true>
    BST(TT&& value, BST* left, BST* right) : val(std::forward<TT>(value)), lch(left), rch(right) {
    }

    T val;
    BST* lch;
    BST* rch;
};

}  // namespace coding_interview_guide::linked_list

#endif
