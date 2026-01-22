*This project has been created as part of the 42 curriculum by nadoho*

# Push_swap

Because Swap_push doesn’t feel as natural

## Description

This project asks you to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you'll have to manipulate various types of algorithms and choose the most appropriate solution for optimized data sorting.

This implementation uses **Turk’s algorithm**.

---

## Instructions

### Compilation
```bash
make
```

### Usage
```bash
./push_swap 2 1 3 6 5 8
```

Check number of instructions:
```bash
./push_swap 2 1 3 6 5 8 | wc -l
```

---
### Rules

The game is composed of 2 stacks named **a** and **b**.

-   At the beginning:
    -   The stack **a** contains a random amount of negative and/or positive numbers which cannot be duplicated.
    -   The stack **b** is empty.
-   The goal is to sort the numbers in stack **a** in ascending order.
-   To do so, we have the following instructions at your disposal:

| Command | Description |
| :--- | :--- |
| `sa` | **swap a** - swap the first 2 elements at the top of stack a. |
| `sb` | **swap b** - swap the first 2 elements at the top of stack b. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` | **push a** - take the first element at the top of b and put it at the top of a. |
| `pb` | **push b** - take the first element at the top of a and put it at the top of b. |
| `ra` | **rotate a** - shift up all elements of stack a by 1. The first element becomes the last one. |
| `rb` | **rotate b** - shift up all elements of stack b by 1. The first element becomes the last one. |
| `rr` | `ra` and `rb` at the same time. |
| `rra` | **reverse rotate a** - shift down all elements of stack a by 1. The last element becomes the first one. |
| `rrb` | **reverse rotate b** - shift down all elements of stack b by 1. The last element becomes the first one. |
| `rrr` | `rra` and `rrb` at the same time. |

### Functionnement

There to many function is this program, so I won't list all of them.
I will only evelop the the program's functionnemet.

- Fistly, take all of the arguments semd to the program and stock them in a `t_stack`
- Verify if the stack is already sorted. If yes, it will do nothing.
- Otherwise:
    - If size is 2 -> `sa`
    - If size is 3 -> `sort_three`
    - Else → use **Turk’s algorithm** (You can see video link's on it bellow)

### Turk's algorithm (by me)

The Turk algorithm is a greedy strategy designed to minimize 
the number of operations by always choosing the cheapest move.

#### Global idea

The goal is to push elements from stack a to stack b in an optimized way, then push them back to a in the correct order.

#### Step 1 — Push elements to stack b

Keep only 3 elements in stack a.
All other elements are pushed to b.


#### Step 2 — Sort remaining elements

Once only 3 elements remain in a, a simple `sort_three` is applied.

#### Step 3 - Cost caluclation
- Each number is is assigned by a index in the sorted array (**0: smallest, N-1 :biggest**). This simplifies comparisons and avoids dealing with large values.
For each node in **stack_b**:

- Define a **target node** in **stack_a**
  - Smallest value greater than the node
- Compute rotation cost

#### Cost rules

If index ≤ size / 2:
```
cost = index        (ra / rb)
```

Else:
```
cost = size - index (rra / rrb)
```

Total cost:
```
cost_a + cost_b
```

#### Optimizations
- Use `rr` if both rotate up
- Use `rrr` if both rotate down

Choose the node with the **lowest cost**.

### Step 4 — Push Back to A
- Repeat cost calculation
- Push until **b** is empty

### Step 5 — Final Rotation
- Rotate **a** so smallest value is on top

---

#### Why this algorithm?

- Efficient for large inputs
- Scales well with input size
- Produces a low number of instructions
- Easy to optimize with rotation merging

## Bonus

The bonus specify to do a `checker` program's that your `push_swap` program correctly works.
For that, we use the `get_next_line` project to read the instruction.
- Taking the list of argument, the execute the list of instruction.
- After that, we check that the stack is sorted.

***(Yes, it's all)***
 
## Ressources 

To help me, I use that :
- [This medium article wrote by Yutong Deng on the turk algorythm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Thuggonaut's tutorial to do Push_swap](https://www.youtube.com/watch?v=wRvipSG4Mmk&t=1s)
- [Push_Swap Tester by](run.sh)
- [A site-web to generate random suit of number](https://stattrek.com/statistics/random-number-generator)

## Author

- **nadoho** aka [Ynvers](https://github.com/Ynvers)
