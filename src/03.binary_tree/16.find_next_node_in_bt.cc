#include <stack>

#include "03.binary_tree/16.find_next_node_in_bt.h"

namespace coding_interview_guide::binary_tree::find_next_node_in_bt {

namespace {
const NewNode<int>* in_order_traverse(const NewNode<int>* root, const NewNode<int>* node) {
    std::stack<const NewNode<int>*> stack;
    const NewNode<int>* curr = root;
    const NewNode<int>* top = nullptr;
    while (stack.size() || curr != nullptr) {
        if (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        } else {
            top = stack.top();
            stack.pop();
            if (top == node) {
                if (top->right == nullptr) {
                    return stack.size() ? stack.top() : nullptr;
                } else {
                    curr = top->right;
                    while (curr->left != nullptr) {
                        curr = curr->left;
                    }
                    return curr;
                }
            }
            curr = top->right;
        }
    }
    return nullptr;
}
}  // namespace

const NewNode<int>* FindNextNode::find_node(const NewNode<int>* node) {
    if (node == nullptr) {
        return nullptr;
    }
    const NewNode<int>* node_ = node;
    while (node->parent != nullptr) {
        node = node->parent;
    }
    return in_order_traverse(node, node_);
}

const NewNode<int>* FindNextNode::find_node_opt(const NewNode<int>* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right != nullptr) {
        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    while (node->parent != nullptr) {
        if (node->parent->left == node) {
            return node->parent;
        } else {
            node = node->parent;
        }
    }
    return nullptr;
}

}  // namespace coding_interview_guide::binary_tree::find_next_node_in_bt
