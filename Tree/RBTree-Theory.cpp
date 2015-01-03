Red-Black Trees 
A Red-Black tree is a binary search tree with one extra bit of storage per node: its color, 
which can be either RED or BLACK.By constraining the node colors on any simple path from the 
root to leaf, red-black trees ensure that no such path is more than twice as long as any other,
so that the tree is approximately balanced.
Each node of the tree now contains the attributes color, key, left, right, and p. 
If a child or the parent of a node does not exist, the corresponding pointer attribute of the
node contains the value NIL. 
We consider these NILs as being pointers to leaves (external nodes) of the binary search tree
and the normal, key-bearing nodes as being internal nodes of the tree.
A red-black tree is a binary tree that satisfies the following red-black properties:
Every node is either red or black.
The root is black.
Every leaf(NIL) is black.
If a node is red, then both its children are black.
For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
STL map is implemented using this RB-Tree.
