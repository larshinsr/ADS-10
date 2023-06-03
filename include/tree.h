// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> children;
    };

    Node* root = nullptr;
    std::vector<char> permutation;
    void buildPermutationTree(std::vector<char> elements, Node* node) {
        if (elements.empty()) {
            return;
        }

        for (auto element : elements) {
            Node* child = new Node;
            child->value = element;
            node->children.push_back(child);
            std::vector<char> remaining = elements;
            remaining.erase(
                std::remove(remaining.begin(), remaining.end(), element),
                remaining.end());

            buildPermutationTree(remaining, child);
        }
    }
    void generatePermutations(Node* node) {
        if (node->children.empty()) {
            permutation.push_back(node->value);
            permutations.push_back(permutation);
            permutation.pop_back();
        }       
        for (Node* child : node->children) {
            permutation.push_back(node->value);
            generatePermutations(child);
            permutation.pop_back();
        }
    }
 
 public:
    std::vector<std::vector<char>> permutations;
    Tree(std::vector<char> elements) {
        root = new Node;
        root->value = '*';
        buildPermutationTree(elements, root);
        generatePermutations(root);
    }
};
#endif  // INCLUDE_TREE_H_
