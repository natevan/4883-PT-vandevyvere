## Tree Summing (112)
### Nathan Van De Vyvere

### Description: 
LISP was one of the earliest high-level programming languages
and, with FORTRAN, is one of the oldest languages currently
being used. Lists, which are the fundamental data structures in
LISP, can easily be adapted to represent other important data
structures such as trees.
This problem deals with determining whether binary trees
represented as LISP S-expressions possess a certain property.
Given a binary tree of integers, you are to write a program
that determines whether there exists a root-to-leaf path whose
nodes sum to a specified integer.
For example, in the tree shown on the right there are exactly
four root-to-leaf paths. The sums of the paths are 27, 22, 26, and 18. Binary trees are represented in
the input file as LISP S-expressions having the following form.

empty tree ::= ()
tree ::= empty tree | (integer tree tree)

The tree diagrammed above is represented by the expression

(5 (4 (11 (7 () ()) (2 () ()) ) ()) (8 (13 () ()) (4 () (1 () ()) ) ) )

Note that with this formulation all leaves of a tree are of the form

(integer () () )

Since an empty tree has no root-to-leaf paths, any query as to whether a path exists whose sum is
a specified integer in an empty tree must be answered negatively.


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|1|[TreeSumming.cpp](TreeSumming.cpp)|source code|
|2|[input 1](in1)|Test input 1|
|3|[input 2](in2)|Test input 2|
|4|[P112](112.pdf)|Online Judge problem 112 pdf|

### Sources

- uDebug https://www.udebug.com/UVa/112

Source of the input files used.
