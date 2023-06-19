# push_swap

The "push_swap" repository contains the C implementation of an algorithm for sorting a stack of numeric values. This project is part of the curriculum at 42School and has achieved a score of 125 out of 100.

The project focuses on implementing an efficient sorting algorithm using a combination of stack operations, such as push, swap, and rotate, along with the use of an auxiliary stack. The goal is to sort the stack in the fewest number of moves possible.

## Features

The "push_swap" program includes the following features:

- Stack operations: push, swap, rotate, reverse rotate
- Sorting algorithm implementation
- Optimized moves calculation
- Chunk division and cost

## Usage

1. Clone the repository to your local system
	```shell
	git clone https://github.com/stenterello/push_swap.git

2. Navigate to the main directory of the repository:
	```shell
	cd push_swap

3. Compile the program using the provided Makefile:
	```shell
	make

4. Execute the program by providing a list of numeric values to sort:
	```shell
	./push_swap 5 3 1 4 2

5. Optionally, you can check if the instructions are valid by piping them into the "checker" program:
	```shell
	./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2

In this last case, you have to compile with the "make bonus" rule, to get the checker executable.


## Algorithm Description

The push_swap algorithm is primarily based on the division of the stack into chunks and the calculation of move costs to determine the best move. Although there is a suboptimal implementation of the Longest Increasing Subsequence (LIS) algorithm, the focus is on chunk division and cost calculation.

The algorithm aims to minimize the number of moves required to sort the stack efficiently. It analyzes the stack's current state, divides it into chunks based on a proportional range, and calculates the move costs for different possible moves. The algorithm then chooses the move with the lowest cost, repeating the process until the stack is sorted.