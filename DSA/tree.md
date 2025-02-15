# Tree

A type of structure where there are nodes connected with edges and there is a way to go from the sole root node to every other node
and each node has exactly one parent. Root node is parentless

Tree is a kind of directed graph, so you can go from parent to any child but not in reverse!

### Some Maths

In a tree with `N` nodes, there are exactly `N-1` edges.

$$ E = N - 1 $$

Depth of node X is length of path from ROOT to X OR Number of Edges from ROOT to X
Height of node X is number of edges in longest path from X to Leaf

Height of Leaf nodes is 0
Height of tree is height of root node

### Applications:

1. Storing naturally hierarchical data (e.g. file system)
2. organized data (e.g. BST)
3. Trie -> fast dictionary
4. Network Routing Algorithm

# Binary Tree

We had a look at the Tree, but it had too many children. Let's consider a Tree where each node has atmost 2 children.
It's a BINARY TREE. Each node can have atmost two children

a. Strict/Proper Binary Tree
Each node can have either 0 or two children

b. Complete Binary Tree
all levels except the last are completely filled and all nodes are as left as possible (fill from left)

Maximum no. of nodes at level i is given by $$ 2^i $$

c. Perfect Binary Tree
All levels are completely filled

Maximum no. of nodes in a binary tree with height h
$$ = 2^0 + 2^1 + 2^2 + 2^3 + .... + 2^h $$
$$ = 2^(h+1) - 1 $$
$$ = 2^(no\.of\.levels) - 1 $$

Height of Perfect Binary Tree with n nodes
$$ Let n = 2^(h+1) - 1 $$
$$ h = log(n+1, 2) - 1 $$

Height of Complete Binary Tree with n nodes
$$ h = log(n, 2) $$

### Creation

Making them with Pointers and Nodes is easy

```c
struct Node {
  int val;
  Node* left;
  Node* right;
}
```

But making them with arrays is kindof interetsing and challenging

[2, 4, 1, 5, 8, 7, 9]
0 1 2 3 4 5 6

For a Node at Index `i`,
Left Child-index = `2i + 1`
Right Child-index = `2i + 2`

## Traversal

1. Pre Order
   First the data, then the left subtree and then the right subtree

2. Post Oder
   First the left subtree, then right subtree and then the data

3. In Oder
   First the left subtree, then the data, and lastly the right subtree

### Height of tree

$$ Height of tree = height of the root Node. $$
Height of tree is the max(height of left subtree, height of right subtree) + 1
base case is root == NULL then return -1 (to account for the extra 1 travel to get to the leaf node)

# Binary Search Tree

A binary tree in which for each node the values of nodes in the left subtree is less (or equal in some cases)
than the the value of the node
and the value of nodes in the right subtress is more than the value of node

Implemented using Linked List or Arrays

## Binary Tree Traversal

1. Breadth-First-Search (BFS)

It is Level ordered. It means we first need to traverse a whole level before moving to any child nodes.
Level Order Traversal.

2. Depth-First-Search (DFS)

If we visit a node, we go through it's entire subtree first child's subtree before going to the next child

- We can Do Inorder, preorder and postorder in DFS
