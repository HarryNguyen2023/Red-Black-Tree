# Red-Black-Tree
## Author Harry Nguyen (Created 07/11/2023)

Red Black Tree is a type of balanced binray search tree, which ensure the time complexity for basic tree opreations such as search, insert, delete to be O(logn).

Instead of containing only the key value, each node in the red black tree also has a color variable, that must satisfy those following conditions:
- Root node is always black.
- Leaf nodes are called NIL and are also black.
- The black depth (the number of black nodes from root to leaf) of all the path must be the same.
- No two consecutive nodes are red.
Thus, the depth of each path is ensured that there is no path whose depth is more than 2 times larger than other path's depth.

To maintain the color property, the red black tree uses recoloring and rotation during insertion and deletion. However, compare to AVL tree, the red black tree requires less rotation, which makes it more suitable for database that have more insertion and deletion operations than search one.

Red black tree has many practical applications:
- Implementation for some data structure such as map, multiset, ... in Cpp or Jave packages.
- Virtual memory manager in Linux kernel.
- Index tables in MySQL.

### My updates:
Even though, most of the tutorial both in books and online only use the integer as the data type of the red-black tree, I have tried to create a more general red-black tree that can utilizes most of the basic data types in Cpp, even structure and union.

### References:
[1]. Red-Black Tree, https://www.programiz.com/dsa/red-black-tree.

[2]. Introduction to Red-Black Tree, https://www.geeksforgeeks.org/introduction-to-red-black-tree/.

  
