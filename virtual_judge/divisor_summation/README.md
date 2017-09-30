### A - Divisor Summation

Give a natural number n (1 <= n <= 500000), please tell the summation of all its proper divisors.
Definition: A proper divisor of a natural number is the divisor that is strictly less than the number.

e.g. number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.

#### Input

An integer stating the number of test cases, and that many lines follow each containing one integer between 1 and 500000.


#### Output

One integer each line: the divisor summation of the integer given respectively.


#### Sample Input

3

2

10

20


#### Sample Output

1

8

22

---

### 相关知识

- 约数和定理

- 素数分解

然而以上并没有用到

更类似于找规律。

利用类似素数表的方式快速求得约数和.

没明白证明原理，但是能知道规律...
