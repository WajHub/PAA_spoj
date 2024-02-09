# Base Conversion

Every integer number \( n \) is represented in a positional number system of base \( r \) by a sequence of digits \( 0  d_i < r \), so the value is equal to:

\[ n = d_0  + r*d_1 + r^2*d_2 + r^3*d_3 + ...\]

Your task is to convert a given number in \( r \) - base representation into \( s \) - base representation, for example: decimal 231 into binary 11100111. Assume that \( r &le; 36 \) and the digits are \( 0,1,2,3,4,5,6,7,8,9, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z \).

## Input
\[ N \] [the number of series ≤ 1000]  
\[ n r s \] [\( n &le; 10^1000, r,s &le; 36 \)]

## Output
\[ n \] [\( s \)-base representation of number \( n \)]


### Example
#### Input:
\[ 3 \]  
\[ 231  10 2 \]  
\[ ABC  15 10 \]  
\[ XYZ 36 2 \]

#### Output:
\[ 11100111 \]  
\[ 2427 \]  
\[ 1010101111111011 \]

# Graph Search

Searching the Graph
For a given list of adjacent vertices of a graph and a chosen vertex \( v \), write down in the Depth First Search (DFS) or Breadth First Search (BFS) order all the vertices from the connected component of the graph containing \( v \). Assume that the number of vertices of the graph is at most 1000.

## Input

\[ t \] [the number of graphs ≤ 100]  
**Graph:**  
\[ n \] [\( 1 &le;  n &le; 1000 \) the number of graph vertices]  
\[ i m a b c  \] [the list of \( m \) adjacent vertices to vertex \( i \)]  
Any query is as follows: [not more than \( n \) queries]  
\[ v i \]  
where \( 1 &le; v &le; n \) is the beginning vertex and \( i = 0 \) for DFS order and \( i = 1 \) for BFS order.  
\[ 0 0 \] [at the end of the series]

The list for isolated vertex \( a \) is \( a 0 \).

## Output

\[ graph i \] [test case, word graph is necessary]  
\[ a b c ... \] [the DFS or BFS order of all vertices]

### Example

#### Input:
\[ 3 \]  
\[ 6 \]  
\[ 1 2 3 4 \]  
\[ 2 2 3 6 \]  
\[ 3 2 1 2 \]  
\[ 4 1 1 \]  
\[ 5 0 \]  
\[ 6 1 2 \]  
\[ 5 1 \]  
\[ 1 0 \]  
\[ 1 0 \]  
\[ 0 0 \]  
\[ 10 \]  
\[ 1 6 3 5 6 7 8 9 \]  
\[ 2 1 9 \]  
\[ 3 2 1 5 \]  
\[ 4 5 6 7 8 9 10 \]  
\[ 5 4 1 3 7 8 \]  
\[ 6 3 1 4 7 \]  
\[ 7 5 1 4 5 6 8 \]  
\[ 8 5 1 4 5 7 10 \]  
\[ 9 3 1 2 4 \]  
\[ 10 2 4 8 \]  
\[ 7 1 \]  
\[ 1 0 \]  
\[ 2 1 \]  
\[ 4 1 \]  
\[ 7 1 \]  
\[ 0 0 \]  
\[ 2 \]  
\[ 1 0 \]  
\[ 2 0 \]  
\[ 1 1 \]  
\[ 0 0 \]

#### Output:
\[ graph 1 \]  
\[ 5 \]  
\[ 1 3 2 6 4 \]  
\[ 1 3 2 6 4 \]  
\[ graph 2 \]  
\[ 7 1 4 5 6 8 3 9 10 2 \]  
\[ 1 3 5 7 4 6 8 10 9 2 \]  
\[ 2 9 1 4 3 5 6 7 8 10 \]  
\[ 4 6 7 8 9 10 1 5 2 3 \]  
\[ 7 1 4 5 6 8 3 9 10 2 \]  
\[ graph 3 \]  
\[ 1 \]

# Longest Common Subsequence

## Problem Description

For a given two words \( x = x_1 x_2...x_n \) and \( y = y_1 y_2... y_m \), find the longest common subsequence, i.e. \( z = z_1z_2... z_k \) such that every two consecutive elements of \( z \) are equal to some two elements of \( x \): \( xa \), \( xb \), and \( y \): \( yc \), \( yd \) where \( a < b \) and \( c < d \). Assume that elements of words are letters 'a' - 'z' and \( m, n &le; 1000 \).

## Input

\[ N \] [the number of series ≤ 1000]  
\[ n  x \]  
\[ m  y \]  
...

## Output

\[ case  1  Y \] [or N when no answer to this case]  
\[ d \] [the length of the LCS]  
\[ z_j  p  q \] [position of \( z_j \) in \( x \) and in \( y \), respectively]  
...


### Example

#### Input:
\[ 3 \]  
\[ 5  ddacc \]  
\[ 3  cac \]  
\[ 7  cbbccbc \]  
\[ 4  aaca \]  
\[ 4  cbeb \]  
\[ 5  fdceb \]  

#### Output:
\[ case  1  Y \]  
\[ 2 \]  
\[ a  3  2 \]  
\[ c  4  3 \]  
\[ case  2  N \]  
\[ case  3  Y \]  
\[ 3 \]  
\[ c  1  3 \]  
\[ e  3  4 \]  
\[ b  4  5 \]  


# Wlasne porzadki

Jaś, who was a true bookworm, decided to introduce his own order in his rich book collection consisting of \( n &le; 500000 \) books. "Every book must be in its place!" - thought resolute Jaś, smiling to himself...

Jaś assigned a unique number (0 <= number <= 10^9) to each book and arranged them on the shelf in random order. Then, Jaś exchanged the \( k_1 \)-th numbered book in non-increasing order with the last book on the shelf. Next, Jaś chose the \( k_2 \)-th numbered book in non-increasing order from the remaining books (except the last one) and exchanged it with the second-to-last book on the shelf, and so on... To avoid mistakes, Jaś occasionally writes down the consecutive book numbers on the shelf. "Nobody will guess my own order" - Jaś was pleased. Try to decipher Jaś's order! We will assume that \( 1 &le; k_i &le; n - i + 1 \).

Input data consists of 15 tests, divided into three groups:

tests 1-5: number of books \( n &le; 10000 \), \( 1 &le; k_i &le; 2 \),
tests 6-10: number of books \( n &le; 10000 \), \( 1 &le; k_i &le; n - i + 1 \),
tests 11-15: number of books \( n &le; 500000 \), \( 1 &le; k_i &le; n - i + 1 \).

## Input

The first line of the input will contain the number of books \( n \). The second line will contain the numbers of books separated by spaces (in random order), the third line will contain the values \( k_1, k_2, \ldots, k_n \). Finally, the fourth line will contain the numbers of steps (rearrangements of one book) after which Jaś records the state on the shelf. We assume that the last value in the fourth line will be \( n \).

## Output

The output should contain all the shelf states noted by Jaś in consecutive lines.

### Example 

#### Input:
\[ 10 \]  
\[ 318 428 564 190 369 272 551 620 98 517 \]  
\[ 1 2 1 2 2 2 2 2 1 1\]  
\[ 2 7 8 9 10\]  
 

#### Output:

\[ 318 428 564 190 369 272 98 517 551 620\]  
\[ 190 98 517 272 318 369 428 564 551 620\]  
\[ 517 98 190 272 318 369 428 564 551 620\]  
\[98 517 190 272 318 369 428 564 551 620\]  
\[98 517 190 272 318 369 428 564 551 620\] 

# Quadratic Equation Roots

For the given integer coefficients \( a \), \( b \), \( c \) (ranging from -1000000 to 1000000) of the quadratic equation in canonical form \( a \cdot x^2 + b \cdot x + c = 0 \), determine the approximate real solutions \( x'_1 \) and \( x'_2 \) of the equation (if they exist) such that \( |x_1 - x'_1| &le;10^{-k} \) and \( |x_2 - x'_2| &le;10^{-k} \), where \( x_1 \) and \( x_2 \) are the exact solutions.

Input data consists of 10 test sets, divided into two groups:

tests 1-5: \( 1 &le;k &le;2 \),
tests 6-10: \( 1 &le;k &le;100 \).

## Input

The first line contains the number of test sets \( t &le;10 \). Each of the next \( t \) lines contains four integers \( a \), \( b \), \( c \), and \( k \).

## Output

For each set of integers \( a \), \( b \), \( c \), and \( k \), determine the real roots of the quadratic equation \( a * x^2 + b * x + c = 0 \) with precision up to \( 10^{-k} \). Print the number of different real roots of the equation. If real solutions exist, after a space, print the roots in ascending order (separated by space). The number of decimal places is not limited.

### Example

#### Input:

5 \
1 0 1 1 \
1 2 1 1 \
1 -2 1 1 \
1 0 -1 2 \
1 0 -2 2 

#### Output:

0 \
1 -1 \
1 1 [could be: 1 0.9 or 1 1.1] \
2 -1 1 \
2 -1.41 1.42 [could be: -1.423 1.4142]