## Project Organisation

Our overall plan was designed so that each week we could incrementally finish in the 4 week project span:

- Week 1 - 26/02/2024
- Week 2 - 04/03/2024
- Week 3 - 11/03/2024
- Week 4 - 18/03/2024

| Feature                        | Week Planned To Complete | Week Completed |
| :-------                       | :----------------------: |:--------------:|
|  single func no arguments      |             1            |       3        |
|  int variable type             |             1            |       3        |
|   local variables              |             1            |       3        |
| arithmetic & logical expr      |             1            |       4        |
| if-then-else statements        |             1            |       4        |
|      while loops               |             1            |       4        |
|      for loops                 |             2            |       4        |
|  array intialisation           |             2            |       4        |
|     global array               |             2            |       x        |
|     local array                |             2            |       4        |
| reading and writing array vals |             2            |       4        |
| recursive function calls       |             3            |       x        |
|    switch statements           |             3            |       4        |
|  break and continue keywords   |             3            |       4        |
|  advanced features...          |            3+4           |       x        |

Initially we had decided to distribute the workload across the four weeks evenly. However the first two weeks were mainly dedicated towards other modules and their courseworks, it was decided that it would be more effective to have a dedicated few weeks to the compiler project rather than overlap with other courseworks so that we could focus our attention entirely on the project.

Our [initial context structure](https://github.com/LangProc/langproc-2023-cw-Bitwise/commit/6dde6988d0b434e35cbe23f1d847f91d558241d5) was defined in week 2.

We began to dedicate our time to working on the project in week 3, creating most of the required compiler foundations [(e.g function definitions, parameters etc)](https://github.com/LangProc/langproc-2023-cw-Bitwise/commit/220350f681003c3dec51265cd171d8fdd8ab26a4) this would allow us to implement, functionality to the compiler modularly such as arithmetic and logical operation, conditional statements and loops.

Week 4 was entirely dedicated to the project, we managed to implement all basic compiler features and moved onto intermediate which we had partially completed.

One major oversight we had made was underestimating the complexity of compiler context and the overall compiler infrastructure (stack, symbol table etc). Its design was crucial in developing a robust system. Without an extensive understanding of context, it would have to be rewritten to accommodate for more complex features such as arrays, which we ran out of time for when trying to implement globally due to scope issues. a significant amount of time was spent revisiting the compiler context and revising its structure.

## Debugging

The debugging process involved the use of various methods:

- using [compiler explorer](https://godbolt.org/) to infer the content and structure of generated assembly code for each compiler feature and the provided test case.

- inserting cout lines into ast files during their code generation which could be used to track the compilation process of a test case. then analysing the cout logs generated from the compiler tests

- hand tracing and analysing generated assembly code from the compiler tests
