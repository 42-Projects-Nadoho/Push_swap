*The very first line must be italicized and read: This project has been created as part
of the 42 curriculum by nadoho*

# Push_swap

This project asks you to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you'll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## Description

make
```

This will generate the `push_swap` executable.

## 🚀 Usage

Run the program with a list of integers as arguments:

./push_swap 2 1 3 6 5 8
pa
pa
```

You can verify the number of instructions with `wc -l`:

```bash
./push_swap 2 1 3 6 5 8 | wc -l
```

## 📋 Rules

The game is composed of 2 stacks named **a** and **b**.

-   At the beginning:
    -   The stack **a** contains a random amount of negative and/or positive numbers which cannot be duplicated.
    -   The stack **b** is empty.
-   The goal is to sort the numbers in stack **a** in ascending order.
-   To do so, you have the following instructions at your disposal:

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

## 👤 Author

-   **nadoho** (Luzolo)
