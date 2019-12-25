> module Hw13
>     where

> hlen :: (Num u, Eq t) => ([t] -> u) -> [t] -> u
> hlen = (\f x -> if x == [] then 0 else 1 + (f (tail x)))
> myLength ls = if ls == [] then 0 else 1 + myLength (tail ls)

PART B
1) Look at hlen --
        1. Why is hlen recursive? Why or why not.
                A: hlen itself is not necesarly recursive. All it does is apply a function to the tail of the list. the function that is applied may be recursive, such as myLength.
        2. It is a higher order function because it is a lambda expression.
        3.a 12
        3.b 6

        hlen has nothing to do with them.
2) 3
3) they both return the size of the listen
PART C


1)

> factorial :: Integral a => a -> a
> factorial n = if n ==0 then 1 else n * (factorial (n - 1))

> hFact = (\f x -> if x == 0 then 1 else x * (f (x - 1)))

hFact has type (Integer -> Integer) -> Integer -> Integer  because its lambda expression takes a func. that takes an int, and returns an int.

2) 36

3) value of hFact factorial is 5. same as 5!.

PART D


> factorial' = hFact factorial'

1) Integer -> Integer because it expands the lambda to take an int and returns an int.
2.a) type of fix is (f->f) -> f. this is because it takes a function and passes it to the same call. eventually ends with a single function
2.b) not possible. It will try to evaluate f passing in fix, later calling f again withh no args.

3a) 720
3b) 720
3c) 720
3d) 720
