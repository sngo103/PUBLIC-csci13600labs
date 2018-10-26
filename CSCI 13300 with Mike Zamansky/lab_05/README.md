## lab_05
#### Samantha Ngo | CSCI 133 | 2018 October 11 | Hunter Daedalus Honors

##### This lab is a modified version of CSCI 136's lab_05, but practices implementing and using Catch2, Makefiles, and writing helper functions.

Notes:
- Some function tests are limited by memory, such as ones that count up to 100. Such cases(2 in tests.cpp) have been commented out because they resulted in a pause in compiling similar to that caused by a hidden infinite loop.
- All the functions assume that parameters are given in integer format. However, any decimals will be automatically truncated and the function will proceed as normal.
- Any functions that use a range for the parameter(countPrimes() and largestTwinPrime()) returns a -1 if the lower bound is numerically greater than the upper bound.
- nextTwinPrime() assumes that any number n given as the parameter does not need to be a twin prime number in order to find the next twin prime number greater than n.
- isPrime() and any functions that depend on isPrime() don't consider any negative(non-natural) numbers as prime and are automatically rejected as a prime number.
