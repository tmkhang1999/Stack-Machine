# Project Description

<p>In this project you will implement a stack machine in C. A stack machine is a simple model of computation in which the primary memory construct is a stack. There is a set of instructions which allow adding/removing integers from the stack, as well as performing various mathematical operations. Stack machine programs are lists of these instructions. Instructions are executed one after another, except for branching instructions which allow jumping to a specific instruction number in the program. </p>

<p>You must implement a stack of integers as a linked data structure (think linked list). Be sure you implement this yourself and don&#8217;t use code from the internet &#8212; it&#8217;s not hard and is a useful task. Be careful to properly allocate memory when you need to push and to free memory when you pop. Stack machine programs will be read from a file &#8212; you may either provide an argument or have your program ask for a file name. The files will begin with the number of instructions, followed by the list of instructions. You should store the instructions in some data structure for easy access by index. </p>

<p>To execute your program, you will need some sort of counter to keep track of where you are in the list of instructions. Decode and execute instructions one after another until you&#8217;ve reached the end of the program. </p>

<h3>Instruction Set</h3>

`1. Input / Output`
> - IN   -- Reads the next integer from the input stream, and pushes it on the stack.
> - OUT  -- Pops the top integer from the stack, and prints it.

`2. Stack operations`
> - LIT [NUMBER] -- Pushes NUMBER on the stack.
> - DROP         -- Pops the top element of the stack.
> - DUP [N]      -- Duplicates the top N elements of the stack, in order (DUP 2: ... A B becomes ... A B A B).
> - SWAP         -- Swaps the top two elements of the stack (SWAP: ... A B becomes ... B A).

`3. Integer operations`
> - ADD/SUB/MUL/DIV/MOD -- Pops the top two integers from the stack, Adds/.../Mods them, and pushes the result.
> - AND/OR              -- Pops the top two integers from the stack, ANDs/ORs them, and pushes the result.

`4. Branching`
> - IFEQ [INSTRUCTION] -- checks if the two elements at the top of the stack are equal. If so, jump to the given instruction.
> - IFLT [INSTRUCTION] -- checks if the first element of the stack is less than the second element. If so, jump to the given instruction.
> - JUMP [INSTRUCTION] -- jumps to the given instruction.