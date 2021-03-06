## Counting inversions [SPOJ-SWAPS](http://www.spoj.com/ranks/SWAPS/) 

You are given a sequence A of N (N≤250000) integers between 1 and 50000. On this sequence you have to apply M (M≤10000) operations of the form: modify the i-th element in the sequence and then say how many inversions are there in the sequence. The number of inversions in a sequence is given by the number of pairs (i,j) with i < j and Ai > Aj.

### Input

The first line of input contains the number N and the next line contains the numbers that form the sequence. After that follows the number M and then M lines, each containig 2 integers X and Y, meaning that new value of the X-th element of the sequence is Y and that you should count the number of inversions in the modified sequence.

### Output

Output must contain M lines, the i-th line of output containg the number of inversions in the sequence after the first i operations.

### Example

### Input:

10

2 6 6 4 7 6 3 5 9 1 

7

8 8

5 1

5 6

10 5

7 1

10 10

4 6

### Output:

17

18

16

13

14

8

6

### 分析

翻译下这道题，输入 n 个数的序列，随后更改第 x 个元素的值为 y，计算逆序的个数对，即对于 i < j 有 A[i] > A[j] 的对数。 一般这种题目要求的效率肯定不能是 n^m 的。
