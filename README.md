push_swap is a 42 school project that challenges you to sort a stack of integers using two stacks and a limited set of instructions — all while minimizing the total number of moves.
For this implementation, I used the ButterFly (Non-Ideal) algorithm, which is an efficient and structured approach to handle medium and large input sizes while remaining within project benchmarks.

🎯 Objectives
Implement a fast and memory-safe sorting program in C.

Minimize the number of stack operations for:

100 numbers: under 700 moves (bonus target).

500 numbers: under 5500 moves (bonus target).

Handle errors gracefully (invalid integers, duplicates, overflows).

⚙️ How It Works
You start with:

Stack A: filled with unique integers (positive/negative, random order).

Stack B: empty.

Allowed operations:

Swap: sa, sb, ss

Push: pa, pb

Rotate: ra, rb, rr

Reverse Rotate: rra, rrb, rrr

Task: sort Stack A in ascending order using the fewest moves possible.

🖥️ Usage
```
git clone https://github.com/yourusername/push_swap.git
cd push_swap
make
./push_swap 4 67 3 87 23
```

🚀 Bonus Part – Checker
An optional checker program is included:

```
make bonus
./checker 3 2 1 0
pb
sa
pa
OK
```
It verifies if a sequence of instructions sorts the stack correctly.





Ask ChatGPT
