*This project has been created as part of the 42 curriculum by mobouifr.*

<div align="center">

# push_swap

### Cost-driven stack sorting with constrained operations and move-aware rotations

<img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C badge" />
<img src="https://img.shields.io/badge/Type-Algorithmic%20Project-1f6feb?style=for-the-badge" alt="Algorithm badge" />
<img src="https://img.shields.io/badge/42-Norm%20Ready-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 badge" />

</div>

## What Is This?

`push_swap` takes a list of integers and prints a sequence of stack operations that sorts them in ascending order. It works with two linked-list stacks (`a` and `b`) and emits only the allowed push/swap/rotate instructions.

What makes this code interesting is that it does not just move numbers around blindly. For larger inputs, it computes a target node and a movement price for each candidate, then chooses the cheapest move path while reusing combined rotations when possible (`rr` / `rrr`).

This project is a practical lesson in algorithmic trade-offs: parsing under strict validation, constrained instruction sets, linked-list manipulation, and operation-count optimization.

> Sort with fewer moves, not just correct moves.

## How It Works

For small stacks, the program uses dedicated routines:
- size 2 → `sort_two`
- size 3 → `sort_three`

For larger stacks, it uses a cost-based two-phase strategy:

```text
Input numbers
   |
   v
Stack A (linked list) -------------------------------.
   |                                                 |
   | push two nodes to B                             |
   v                                                 |
Repeat while A has more than 3 nodes:               |
  1) For each node in A, find its target in B        |
  2) Compute move price (index/median aware)         |
  3) Pick cheapest node                              |
  4) Position A and B (rr / rrr when possible)       |
  5) pb                                               |
                                                     |
Sort remaining 3 in A                                |
                                                     |
Repeat until B is empty:                             |
  1) For each node in B, find its target in A        |
  2) Compute move price                              |
  3) Pick cheapest node                              |
  4) Position stacks (rr / rrr when possible)        |
  5) pa                                              |
                                                     |
Rotate A so min node is on top ----------------------'
```

## Features

| Feature | Status | Notes |
|---|---|---|
| Program `push_swap` | ✓ | Builds a single binary named `push_swap`. |
| Argument parsing from multiple argv tokens | ✓ | Supports both `./push_swap 3 2 1` and `./push_swap "3 2 1"` via split on `' '`. |
| Integer validation | ✓ | Rejects non-digits, invalid sign usage, and out-of-range values (`INT_MIN..INT_MAX`) in `ft_atoi`. |
| Duplicate detection | ✓ | `check_doubles` scans parsed numbers and exits on duplicates with `Error`. |
| Empty/invalid text arguments | ✓ | Empty strings and tab-only/tab-containing whitespace paths are rejected (`string_isempty`). |
| Stack operations (`sa sb ss pa pb ra rb rr rra rrb rrr`) | ✓ | All operation emitters are implemented and print instruction lines. |
| Small-input specialized sort | ✓ | Dedicated sort for 2 and 3 elements. |
| Cost-based general sort | ✓ | Uses target selection + pricing + cheapest-node moves with combined rotations. |
| Final normalization | ✓ | Rotates stack A until the minimum value is on top. |
| Bonus `checker` program | — | Not present in repository. |

<details>
<summary><strong>Verified Parser Notes</strong></summary>

- Separator used by parsing split: space character `' '`.
- A quoted argument with spaces is accepted.
- A quoted argument containing tabs (example: `"3\t2 1"`) is rejected with `Error`.
- On parse/validation failure, program writes `Error\n` to stderr and exits with non-zero status.

</details>

## Project Structure

```text
.
├── Makefile ← Builds push_swap directly from project sources
├── push_swap.h ← Main structs and function prototypes
├── push_swap.c ← Entry point, parse pipeline, sort dispatch
├── parse.c ← Input splitting, empty checks, duplicates checks
├── libft/
│   ├── Makefile ← Builds libft.a (not used by root Makefile)
│   ├── libft.h ← Libft prototypes, including project-specific ft_atoi signature
│   ├── ft_atoi.c ← Number conversion + validation + error exit path
│   ├── ft_bzero.c ← Zero-fill memory helper
│   ├── ft_calloc.c ← Allocating + zeroing helper
│   ├── ft_isalnum.c ← Alphanumeric test
│   ├── ft_isalpha.c ← Alphabetic test
│   ├── ft_isascii.c ← ASCII-range test
│   ├── ft_isdigit.c ← Digit test
│   ├── ft_isprint.c ← Printable-char test
│   ├── ft_itoa.c ← Integer to string conversion
│   ├── ft_memchr.c ← Search byte in memory block
│   ├── ft_memcmp.c ← Compare memory blocks
│   ├── ft_memcpy.c ← Memory copy helper
│   ├── ft_memmove.c ← Overlap-safe memory move
│   ├── ft_memset.c ← Memory set helper
│   ├── ft_putchar_fd.c ← Write char to fd
│   ├── ft_putendl_fd.c ← Write string + newline to fd
│   ├── ft_putnbr_fd.c ← Write integer to fd
│   ├── ft_putstr_fd.c ← Write string to fd
│   ├── ft_split.c ← String split by delimiter
│   ├── ft_strchr.c ← Find first char occurrence
│   ├── ft_strdup.c ← String duplication
│   ├── ft_striteri.c ← In-place mapped iteration on string
│   ├── ft_strjoin.c ← Concatenate two strings
│   ├── ft_strlcat.c ← Bounded concatenation
│   ├── ft_strlcpy.c ← Bounded copy
│   ├── ft_strlen.c ← String length
│   ├── ft_strmapi.c ← New string by mapped function
│   ├── ft_strncmp.c ← Bounded string comparison
│   ├── ft_strnstr.c ← Bounded substring search
│   ├── ft_strrchr.c ← Find last char occurrence
│   ├── ft_strtrim.c ← Trim charset from ends
│   ├── ft_substr.c ← Substring extraction
│   ├── ft_tolower.c ← Lowercase conversion
│   └── ft_toupper.c ← Uppercase conversion
├── linked_list_functions/
│   ├── ft_lstnew.c ← Create stack node (content/index/price/target)
│   ├── ft_lstaddback.c ← Append node to list tail
│   ├── ft_lstaddfront.c ← Insert node at list head
│   ├── ft_lstsize.c ← Return list size counter
│   ├── ft_lstmax.c ← Find max-content node
│   ├── ft_lstmin.c ← Find min-content node
│   ├── ft_lstlast.c ← Return last node helper
│   ├── ft_lstdisplay.c ← Traversal debug helper
│   └── ft_lstclear.c ← Free full list
├── operations/
│   ├── push_operations.c ← `pa` / `pb`
│   ├── swap_operations.c ← `sa` / `sb` / `ss`
│   ├── rotate_operations.c ← `ra` / `rb` / `rr`
│   └── reverse_rotate_operations.c ← `rra` / `rrb` / `rrr`
└── push_swap_functions/
    ├── sorting_functions.c ← `not_sorted`, `sort_two`, `sort_three`, `sort_all`
    ├── find_target.c ← Target-node selection in opposite stack
    ├── find_price.c ← Move cost calculation logic
    ├── find_price_extn.c ← Price pass, median checks, cheapest lookup
    ├── node_positioning_a.c ← Move selected node from A to B efficiently
    ├── node_positioning_b.c ← Move selected node from B to A efficiently
    ├── update_index.c ← Re-index nodes after each operation
    ├── fill_stack_a.c ← Build initial stack from parsed numbers
    └── check_lowestnum.c ← Final rotate to bring minimum to top
```

## Getting Started

Build:

```bash
make
```

Run:

```bash
./push_swap 2 1 3 6 5 8
./push_swap "3 2 1"
```

Error case example:

```bash
./push_swap 0 one 2 3
```

<div align="center">

| Make Rule | Effect |
|---|---|
| `make` / `make all` | Build `push_swap` |
| `make clean` | Remove object files |
| `make fclean` | Remove objects and binary |
| `make re` | Rebuild from scratch |

</div>

<details>
<summary><strong>Build Details (Verified)</strong></summary>

```text
Compiler: cc
Flags: -Wall -Wextra -Werror
Output binary: push_swap
```

Root Makefile compiles project sources directly, including the three used libft files (`ft_atoi`, `ft_split`, `ft_isdigit`) as source files.

</details>

## Limitations

> This repository currently implements only the mandatory `push_swap` binary.

| Area | Current State |
|---|---|
| Bonus checker | Not implemented in this repository |
| Input separators | Parsing is based on space splitting; tab-separated values are rejected |
| Embedded libft usage | Root build does not link `libft.a`; it compiles selected libft `.c` files directly |

## Authors

| Source | Identity |
|---|---|
| 42 headers across source files | `mobouifr` |
| Git history (unique author identities) | `mobouifr`, `montassir` |

## Resources

- 42 push_swap subject and evaluation benchmark (intra resources)
- Big-O Cheat Sheet: https://www.bigocheatsheet.com/
- Sorting and stability overview: https://en.wikipedia.org/wiki/Sorting_algorithm
- Linked list reference (C): https://en.cppreference.com/w/c/container
