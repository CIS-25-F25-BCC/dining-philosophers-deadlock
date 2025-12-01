# Dining Philosophers - Deadlock Demo

This program demonstrates the classic **deadlock** scenario using the Dining Philosophers problem.

## The Setup

- 5 philosophers sit at a round table
- 5 chopsticks, one between each pair of philosophers
- To eat, a philosopher needs BOTH adjacent chopsticks
- Each philosopher: thinks, gets hungry, tries to eat, repeats

## The Bug

Each philosopher:
1. Picks up their LEFT chopstick first
2. Then tries to pick up their RIGHT chopstick

If all 5 philosophers pick up their left chopstick at the same time:
- Philosopher 0 has C0, wants C1
- Philosopher 1 has C1, wants C2
- Philosopher 2 has C2, wants C3
- Philosopher 3 has C3, wants C4
- Philosopher 4 has C4, wants C0

**Circular wait = DEADLOCK!**

## Building

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Running

```bash
./philosophers
```

Watch the output - you'll see all philosophers pick up their left chopstick, then the program freezes!

Press Ctrl+C to kill the deadlocked program.

## Your Task

In the mini-lab, you'll fix this deadlock using one of several strategies:
- Lock ordering
- `std::lock()` to acquire both at once
- Limiting concurrent diners
