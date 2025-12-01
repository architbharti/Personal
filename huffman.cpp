#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    } };

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }  };

// Generate Huffman Codes (recursive traversal)
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    // If it's a leaf node
    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode); }

int main() {
    unordered_map<char, int> freq = {
        {'a', 26}, {'e', 18}, {'o', 20}, {'s', 14}, {'t', 10}, {'n', 12}    };

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes and push into heap
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));  }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Merge nodes
        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " -> " << pair.second << "\n";
    }

    vector<string> words = {"stone", "sea", "tea"};
    cout << "\nEncoded Strings:\n";
    for (string word : words) {
        string encoded = "";
        for (char c : word)
            encoded += huffmanCode[c];
        cout << word << " -> " << encoded << "\n";
    }
    return 0; }
