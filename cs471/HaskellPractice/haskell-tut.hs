listTimes2 = [x * 2 | x <- [1..10]]
multOfList = foldl (*) 3 [2,3,4,5]

fact1 :: Int -> Int

fact1 n = if n == 0 then 1 else n * fact1 (n-1)


fact2 :: Integer -> Integer
fact2 n = if n == 0 then 1 else n * fact2 (n-1)



factPattern :: Integer -> Integer

factPattern 0 = 1
factPattern n = n * factPattern(n-1)


factGuards :: Integer -> Integer
factGuards x
  | x < 0 = error "neg x"
  | x == 0 = 1
  | otherwise = x * factGuards(x-1)

factGuards2 :: Integer -> Integer
factGuards2 x
    | x < 0 = error "neg x"
    | x == 0 = 1
    | otherwise = x * factGuards2 x - 1



prodT (a, b, c) = a * b * c

prodC a b c = a * b * c


prodCx :: Num a => a -> (a -> (a->a))
prodCx a b c = a * b * c


prodC1 = prodC 1
prodC2 = prodC1 2
prodC12 = prodC 1 2

{- not valid
prodT1 = prodT 1
prodT2 = prodT(1)

prodT4 = prodT(1,2) //not allowed
prodT3 = prodT(1,x,y) //not allowed

-}

{- HW 1 -}

{- problem 1-}
sumALL :: Num a => [a] -> a

sumAll [0] = 0
sumALL [] = 0
sumALL (x:xs) = x + sumALL(xs)



{-problem 2-}
binOpALL :: Num a => (a -> a -> a) -> [a] -> a
binOpALL op [] = 0
binOpALL op [x] = x
binOpALL op (x : xs) = op x (binOpALL op xs)


{-problem 3-}
insertAt :: (Eq a, Num a) => b -> a -> [b] -> [b]

insertAt val indx [] = [val]
insertAt val 0 (x : xs) = val : x : xs
insertAt val indx (x : xs) = x : insertAt val (indx - 1) xs

{-problem 4-}















{-study guide
More Problems
1) -}
iterates :: (a -> a) -> a -> [a]
iterates f x = x : iterates f (f x)

{-
take 6 (iterate (\(a,b) ->  (b,a+b)) (0,1))

[(0,1),(1,1),(1,2),(2,3),(3,5),(5,8)]


take 4 (iterate (\x -> (head x * 2):x) [1])

[[1], [2,1], [4,2,1], [8,4,2,1]]

take 4 (iterate (\x -> (length x):x) [])
[[], [0], [1,0], [2,1,0]]



2) Consider the following definition:  ( ~> is the symbol between each step in the evaluation!)
> mys8 c (v:vs)
> 	| [] == vs = c  v
> 	| otherwise = mys8 (\x -> c (2*x)) vs


Show each step in the evaluation of mys8 (1 -) [10, 9]
~> mys8 (\x -> (1-) (2*x)) [9]
~> (\x -> (1-) (2 * x))9
~> (\x -> (1-) (18))
~> (\x -> -17)

Show each step in the evaluation of mys8 (1 -) [3,5,9]
~> mys8 (\x -> (1-) (2 * x)) [5,9]
~> mys8(\y -> (\x -> (1-)(2*x)) (2*y))[9]
~> mys8(\y -> (\x -> (1-)(2*x)) (2*y)) 9
~>.....

3)
Given the following types:
	map        :: (a → b) → [a] → [b]
	mysB      :: a -> b -> a
	uncurry :: (a -> b -> c) -> (a, b) -> c
	( .)     ::   (b -> c) -> (a -> b) -> a -> c



What is the most general inferred type of
map mysB::
map        :: (x → y) → [x] → [y]
mysB      :: a -> b -> a
So (x->y) === (a->b->a)  therefore x== a and y == (b->a)
Therefore map mysB :: [a] -> [b->a]

    a) uncurry map ::_______________________________________________

    b) (.) map mysB ::______________________________________________

    c) mysB map  :: _____________________________________________

   You will have to show your work to get full credit.



4)What is the inferred type of fp given the following definition.
         fp g = g (fp g)  ?


-}
fp g = g (fp g)
