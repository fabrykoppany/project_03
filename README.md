# Structure Tester

The implementation of Structure Tester, our third project during the DSA lab in Sapientia.

Team members:
- Fábry Koppány
- Derzsi Dániel

# What is Structure Tester?

Structure Tester is a simple project that aims to test the performance of various data structures.

We implement the following data structures:
1. IntArrays (`array.c` and `array.h`)
2. Dynamic Lists (`list.c` and `list.h`)
3. Binary Trees (`btree.c` and `btree.h`)
4. Heaps (`heap.c` and `heap.h`)
5. Hash Tables (`hashtable.c` and `hashtable.h`)

Compile the program using CMake (in IntelliJ) and run the executable in Windows Command Prompt. Using IntelliJ to run the program itself is unadvisable as its console support is abysmal.

# Runtime System

Our program creates test files automatically. These test files contain either numbers, either strings or both strings and numbers. Our runtime system makes it possible to store numbers and strings at the same time using the same data structures. This has a memory overhead of 1 byte for each element, as the type of the element must be stored at all times.

Check out `runtime_type.c` and `runtime_type.h` for more information.

# Test Cases

We've implemented best case, worst case and average case tests for all data structures. Best cases, worst cases and average cases are all determined beforehand for each data structure. For example, the best case of a binary tree is the root of the tree, the worst case is any of the deepest leafs, and the average case is any of the leafs that are of an equal distance to both the root and the deepest leaf.
