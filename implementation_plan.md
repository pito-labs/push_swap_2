# Push Swap 2 - Ring Array Implementation Plan

## Goal Description
Implement `push_swap` using a **Ring Array (Circular Buffer)** data structure.
This approach optimizes all stack operations (`sa`, `pa`, [ra](file:///Users/macbookpro2019/42-home/push_swap/src/compress.c#15-27), [rra](file:///Users/macbookpro2019/42-home/push_swap/src/compress.c#15-27), etc.) to **O(1)** time complexity by manipulating head/tail indices instead of shifting array elements.

## User Review Required
> [!NOTE]
> This implementation will reside in the `push_swap_2` directory as requested.
> It requires a new [Makefile](file:///Users/macbookpro2019/42-home/push_swap/Makefile) and [main.c](file:///Users/macbookpro2019/42-home/push_swap/src/main.c).

## Proposed Changes

### Data Structure ([includes/push_swap.h](file:///Users/macbookpro2019/42-home/push_swap/includes/push_swap.h))
Define a `t_ring` (or `t_stack`) struct:
```c
typedef struct s_stack {
    int *data;      // Static array of size start_N (or slightly larger)
    int head;       // Index of the top element
    int size;       // Current number of elements
    int capacity;   // Total buffer size
    char id;        // 'a' or 'b' for printing
} t_stack;

typedef struct s_ps {
    t_stack a;
    t_stack b;
    int instructions_count;
} t_ps;
```

### Core Operations (`src/`)
Implement circular buffer logic:

1.  **Push (`pa`, `pb`)**
    *   Target stack: Decrement `head`, write value. Increment `size`.
    *   Source stack: Read value at `head`, increment `head`. Decrement `size`.
2.  **Swap (`sa`, `sb`)**
    *   Swap `data[head]` and `data[(head + 1) % cap]`.
3.  **Rotate ([ra](file:///Users/macbookpro2019/42-home/push_swap/src/compress.c#15-27), `rb`)**
    *   Read value at `head`.
    *   Write value to [(head + size) % cap](file:///Users/macbookpro2019/42-home/push_swap/src/main.c#29-51) (tail position).
    *   Increment `head`.
4.  **Reverse Rotate ([rra](file:///Users/macbookpro2019/42-home/push_swap/src/compress.c#15-27), `rrb`)**
    *   Read value at [(head + size - 1) % cap](file:///Users/macbookpro2019/42-home/push_swap/src/main.c#29-51) (tail position).
    *   Decrement `head`.
    *   Write value to new `head`.

### Files Structure
#### [NEW] `push_swap_2/Makefile`
#### [NEW] `push_swap_2/includes/push_swap.h`
#### [NEW] `push_swap_2/src/main.c`
#### [NEW] `push_swap_2/src/stack_init.c`
#### [NEW] `push_swap_2/src/ops_push.c`
#### [NEW] `push_swap_2/src/ops_swap.c`
#### [NEW] `push_swap_2/src/ops_rotate.c`
#### [NEW] `push_swap_2/src/ops_rev_rotate.c`
#### [NEW] `push_swap_2/src/sort.c` (Radix sort via ring ops)
#### [NEW] `push_swap_2/src/utils.c`

## Verification Plan

### Automated Tests
1.  **Compilation**
    *   Run `make` in `push_swap_2/`.
2.  **Correctness**
    *   Use the existing [checker](file:///Users/macbookpro2019/42-home/push_swap/checker) from the parent directory:
        ```bash
        ARG="4 67 3 87 23"; ./push_swap $ARG | ../push_swap/checker_Mac $ARG
        ```
    *   Verify output is "OK".
3.  **Memory Leaks**
    *   Run with valid inputs and check for leaks (manual or leaks command if available).
