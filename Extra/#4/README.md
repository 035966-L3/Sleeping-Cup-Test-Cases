### About this problem

This is the hard version of problem D (in Main/#4), which is not used in the contest.

### General instructions

The generators `gen_more.cpp` and `gen_extra.cpp` generate rather slowly, so you should be patient.

(In fact, it is highly recommended to copy the corresponding testcases directly as they generate fixed testcases.)

Below are the details:

| Generator | Expected execution time |
| :-: | :-: |
| `gen_default.cpp` | less than a second |
| `gen_more.cpp` | one or two hours |
| `gen_extra.cpp` | several minutes |
| `gen_20.cpp` | less than a second |

### Tests 1-14

These tests are identical to the original problem, so they meet the original constraints.

Everything about these tests, including the generators, are directly copied here.

### Tests 15-20

These are dedicated tests for this problem (the hard version).

However, you may find many parts of the generator code never executed, since they are adapted from the original generators.

### Generator dependencies

The generator `gen_20.cpp` may read the previously generated tests `12.in`, `13.in` and `14.in` as databases.

As a result, please make sure those three files exist in the working directory of `gen_20.cpp`.

