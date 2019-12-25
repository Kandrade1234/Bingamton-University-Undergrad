To Compile the program:
  -Unzip all files
  -run the "make" command
To Run:
  Prompt> ./BestFirstSearch <input.txt> <output.txt>

Data Structures Used:
  For branch and bound a priority Queue is used for the next node. There are also Vectors that are used

Classes:
  Node.cpp
    represents a node that contains items
  Item.cpp
    represents the item object that holds info about each object
  BestFirstSearch.cpp
    contains the algorithm for branch and bound.
  Main.cpp
    the driver of the project.


Runtime:
  worst: O(2^n)
  best: O(N)
