> module Hw12.lhs
>  where


Due After break

Problem 1: (Thompson 10.13)
  Find functions f1 and f2 so that

   s1 =  map f1 . filter f2

  has the same effect as


> p1 = filter (>0) . map (+1)


  ....> p1 [-4,4, -3,3,12,-12]
  [5,4,13]
  (99 reductions, 153 cells)
  ....> s1 [-4,4, -3,3,12,-12]
  [5,4,13]
  (90 reductions, 137 cells)


Problem 1 Answer:
> s1 =  map f1 . filter f2

> f1 :: Num a => a -> a
> f1 = (\x -> x + 1)

> f2 :: (Num a, Ord a) => a -> Bool
> f2 = (\x -> (x >= 0))

Problem 2.
Using higher order functions (map, fold or filter) and if necessary lambda
expressions. Write a definition for 'g1' and 'g2' so the following evaluation
is valid:  (hint: a lambda expressions could be useful).
(Note that  (77 reductions, 123 cells) is time and memory from Hugs, ghci will give time and

     g1 (g2 (*) [1,2,3,4]) 5  ~> [5,10,15,20]

     Main> g1 ( g2 (*) [1,2,3,4]) 5
     [5,10,15,20]
     (77 reductions, 123 cells)

Problem 2 Answer:

> g1 op argument = op argument
> g2 op list = (\x -> map (\y -> op x y) list)

Problem 3:  (Thompson 17.23 )
Define the list of numbers whose only prime factors are 2, 3, and 5, the
so-called Hamming numbers:


   ...> take 15 hamming
   [1,2,3,4,5,6,8,9,10,12,15,16,18,20,24]


 You may consider using any combination of the following techniques
       to express your solution  list comprehension notation, and/or
       explicit recursion, and/or local definitions .  You may define a
       merge function of two sorted lists.

(Hint: Apply the circular list idea demonstrated in fibSeq
  (http://bingweb.binghamton.edu/%7Ehead/CS471/NOTES/HASKELL/4hF02.html))


Problem 3 ANSWER:

> merge (h1:t1) (h2:t2)
>   | h1 == h2  = h1 : merge t1 t2
>   | h1 < h2   = h1 : merge t1 (h2:t2)
>   | h1 > h2   = h2 : merge (h1:t1) t2

> merge [] list2 = list2
> merge list1 []  = list1

> hamming = 1 : merge (map (2*) hamming) (merge (map (3*) hamming) (map (5*) hamming))

Problem 4.
Using an  HOF (map, fold and/or filter) define flattenT that returns a list of
values in each tuple. For this problem you can assume each tuple will be a
pair, e.g. (x,y).
The output should be in the same order as the values appear in the
original list, e.g.

   ...> flattenT  [(1,2), (3,4), (11,21),(-5,45)]
   [1,2,3,4,11,21,-5,45]

Your answer should define flattenT.

Problem 4 ANSWER:

> tuppleToL (x, y) = [x,y]
> flattenT list = fold1 (++) (map tuppleToL list)


Problem 5: flattenR is the same as 3, however, the values appear in the reverse order
   from the original list.
e.g.
   ...> flattenR  [(1,2), (3,4), (11,21),(-5,45)]
   [45,-5,21,11,4,3,2,1]

flattenR should also be defined using HOF (and lamda expressions).

Your answer should define flattenR.

Problem 5 ANSWER:

> flattenR list = foldl (\x y -> y:x) [] (flattenT list)


Problem 6:  Define 'prodLtoR nums', that given a non empty list of Nums, nums,
      the result  is a list of the prod of the numbers in nums  such that last
      value in the output is the product of all the number nums, the next to
      last value in the output is the product of all the numbers in nums
      except the last value in nums, etc.

   A) Use explicit recursion.
      You may assume the input contains at least one value.  i.e.

    ...> prodLtoR [3,4,1,2,3]
    [3,12,12,24,72]

   B)Redo the above by filling in the blanks below.

     > prodLtoRHOF  = (.) reverse (foldl op [] )
     >  where
     >   op  [] y = [y]
     >   op  (x:xs) y = (y*x):x:xs


Problem 6 Answer:
6b is up above

6a)
> prodLtoR (l:ls) = prods [l] ls
>   where
>    prods (a:as) (n:ns) = prods ((a+n):a:ns) as
>    prods as []  = as


Problem 7:  Define 'prodRtoL nums', that given a non empty list of Nums, nums,
      the result  is a list of the prod of the numbers in nums such that first
      value in the output is the product of all the number nums, the next to
      first value in the output is the product of all the numbers in nums
      except the first value in nums, etc.
      i.e.
     ...> prodRtoL [3,4,1,2,3]
     [72,24,6,6,3]

A) Use explicit recursion.


Problem 7A Answer:
> prodRtoL (l:ls) = prods [l] ls
>   where
>    prods (a:as) (n:ns) = prods ((a+n):a:as) ns
>    prods as []  = as

Redo part A but using only HOF by filling in the blanks below.

  .  > prodRtoLHOF  = foldr op []
  .  >    where
  .  >     op  y [] = ___________
  .  >     op  y (x:xs) = ___________


      ...>  prodRtoLHOF [2,3,4,5]
      [120,60,20,5]

Problem 7B ANSWER:
> prodRtoLHOF  = foldr op []
>    where
>     op  y [] = [y]
>     op  y (x:xs) = (x*y):x:xs




Problem 8:
In the last assignment, problem 8, you defined a function replicate' which given a list of numbers returns a
list with each number duplicated its value.  It used only primitive recursion in your definition.

   Example:
   ...> replicate' [2, 4, 1]
   [2,2,4,4,4,4,1]

Now, define a function replicate'' which given a list of numbers returns a
list with each number duplicated its value.  Use only fold, map and take, (++).


Problem 8 ANSWER:

> replicate xs = foldr dup [] xs
>    where
>     dup x y = x : x : y

Problem 9:
Given the following recursive polymorphic tree data type:

> data Tree a = Leaf | Branch a (Tree a) (Tree a) deriving Show
> tree = Branch 6 (Branch 3 Leaf Leaf) (Branch 9 Leaf Leaf)

Define toList :: Tree a -> [a], that converts a tree structure to a list
structure.
    > toList tree
    [3,6,9]

What kind of tree traversal did you use?  What is the time complexity
of your code.

Problem 9 ANSWER:

> toList :: Tree a -> [a]
> toList (Node v l r) = toList l ++ [v] ++ toList r

Problem 10:
Using the Tree data type above define toTree, which converts a list of
values to a binary tree of the values of the list.

You may assume the following behavior: Given list [1,2,3]

1. We take 1 as the current node.
2. We split the remaining list into a left and right sublist [2] and [3],
   and convert those sublists to the left and right subtrees of the current
   node respectively.

    > toTree [1,2,3]
    Branch 1 (Branch 2 Leaf Leaf) (Branch 3 Leaf Leaf)
    > toTree [1,2,3,4,5]
    Branch 1 (Branch 2 Leaf (Branch 3 Leaf Leaf)) (Branch 4 Leaf (Branch 5 Leaf Leaf))

    Yes, the tree need not be complete.

What is the most general type of the list input?   What is the most general type
of 'toTree'?

Problem 10 ANSWER:
toTree :: (Ord a) => [a] -> Tree a
toTree [] = Nil
toTree (h:t) = toTree (Node Nil h Nil) t
	where
		toTree tr [] = tr
		toTree tr (h:t) = toTree (insert tr h) t


Problem 11:
Implement a function which returns mirror of a Tree a.
 (http://codercareer.blogspot.com/2011/10/no-12-mirror-of-binary-trees.html)
i.e.

  ... > mirror tree1
  Branch 5 Leaf (Branch 10 (Branch 12 (Branch 15 Leaf Leaf) Leaf) Leaf)
  ... > mirror (Branch "abc" Leaf (Branch "x" Leaf Leaf))
  Branch "abc" (Branch "x" Leaf Leaf) Leaf

Problem 11 ANSWER:

> mirror :: BinTree a -> BinTree a
> mirror (Node x tl tr) = Node x (mirror tr) (mirror tl)

Problem 12:
Now make Tree an instance in the EQ class -- do not use deriving. Trees are
considered equal if they have the same structures and the leaves have are equal.
Therefore the parameterize type of the Tree must be in the Class EQ. Below are
some possible test cases. tree1 and tree2 should be equal but not tree3 and tree4.
You may find this helpful: https://en.wikibooks.org/wiki/Haskell/Classes_and_types

> tree3 = Branch 6 (Branch 3 Leaf Leaf) (Branch 9 Leaf Leaf)

Thanks to E. O. (team A) who found typos in my test examples below:

   > tree1 = Branch 6 (Branch 3 Leaf  (Branch 9 Leaf Leaf))
   > tree2 = Branch 6 (Branch 3 Leaf (Branch 9 Leaf Leaf))
   > tree4 = Branch 6 (Branch 3 (Branch 9 Leaf Leaf) Leaf)

Below is correct test cases:

> tree1 = Branch 6 (Branch 3 Leaf  (Branch 9 Leaf Leaf)) Leaf
> tree2 = Branch 6 (Branch 3 Leaf (Branch 9 Leaf Leaf))  Leaf
> tree4 = Branch 6 (Branch 3 (Branch 9 Leaf Leaf) Leaf) Leaf


Example results:
  .... > tree1 == tree1
  True
  .... > tree1 == tree2
  True
  .... > tree3 == tree1
  False
  ...> tree1 /= tree3
  True

Problem 12 ANSWER:

> equal :: Eq a => Tree a -> Tree a -> Bool
> equal Null Null = True
> equal (leaf a) (Leaf b) = a == b
> equal (Node a1 left1 right1) (Node a2 left2 right2) = a1 == a2 && equal left1 right2 && equal right1 left2
> equal _ _ = False

Problem 13: Make Tree an instance of the Functor class. Read this before your start:
https://en.wikibooks.org/wiki/Haskell/The_Functor_class


Problem 13 ANSWER:

data Tree a = Empty | Node a (Tree a) (Tree a)

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node a x y) =  Node (f a) (fmap f x) (fmap f y)


    stack overflow
    https://stackoverflow.com/questions/35829969/haskell-functor-for-data-binary-tree
