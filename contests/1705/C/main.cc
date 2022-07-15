#include <bits/stdc++.h>

#include "codeforces_multi.h"

struct Node {
  int length;
  int offset;
  Node *left, *right;
};

void Main() {
  ints(n, c, q);
  strings(s);
  Node* root = new Node;
  root->length = sz(s);
  root->offset = 0;
  root->left = nullptr;
  root->right = nullptr;
  rep(c) {
    ints(l, r);
    --l;
    Node* left = root;
    Node* right = new Node;
    right->length = r - l;
    right->offset = l;
    right->left = root->left;
    right->right = root->right;
    root = new Node;
    root->length = left->length + right->length;
    root->offset = 0;
    root->left = left;
    root->right = right;
  }
  rep(q) {
    ints(k);
    --k;
    Node* n = root;
    while (n->left) {
      if (k < n->left->length) {
        n = n->left;
        k += n->offset;
      } else {
        k -= n->left->length;
        n = n->right;
        k += n->offset;
      }
    }
    wt(s[k]);
  }
}
