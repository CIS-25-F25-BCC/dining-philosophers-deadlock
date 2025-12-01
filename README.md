# Mini-Lab: Concurrency Basics

**CIS-25: Data Structures | December 1, 2025**

## Overview

In this lab, you'll experience one of the most dangerous bugs in concurrent programming: **deadlock**. You'll observe the bug in action, explain why it happens, and then implement a fix.

**Collaboration:** Submit individually, but you're welcome to help each other and share code as much as you like. Please don't copy-paste someone else's code, but feel free to work through this together and discuss with others.

## Setup

Clone this repository:

```bash
git clone https://github.com/CIS-25-F25-BCC/dining-philosophers-deadlock
```

Build the project:
```bash
cd dining-philosophers-deadlock
mkdir build && cd build
cmake .. && cmake --build .
```

---

## The Dining Philosophers Problem

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

---

## Part 1: Observe the Deadlock (5 points)

1. Run the dining philosophers demo: `./philosophers`
2. Watch for deadlock (program stops producing output but doesn't exit)
3. You may need to run it several times - deadlock doesn't always happen immediately
4. Press Ctrl+C to kill the program when it deadlocks

**Question:** What was the last output you saw before the program stopped? (Copy the last few lines)

---

## Part 2: Explain the Deadlock (5 points)

**Question:** In your own words, explain why deadlock occurs. What is each philosopher waiting for, and why can't any of them proceed?

---

## Part 3: Fix the Deadlock (10 points)

Modify `main.cpp` to prevent deadlock. One common solution is **lock ordering**:

- Make ONE philosopher (e.g., philosopher 4) pick up chopsticks in the OPPOSITE order (right first, then left)
- This breaks the circular wait because not everyone is waiting in the same direction

**Hint:** In the `philosopher()` function, add a condition:
```cpp
if (id == 4) {
    // Pick up RIGHT first, then LEFT
} else {
    // Pick up LEFT first, then RIGHT (original code)
}
```

**Requirements:**
- Your fix must prevent deadlock
- The program should run continuously without freezing
- All philosophers should eventually eat

**Test your fix:**
1. Rebuild: `cmake --build .`
2. Run: `./philosophers`
3. Let it run for 30+ seconds - it should NOT freeze
4. Press Ctrl+C to stop when satisfied

---

## Deliverables

Submit on Canvas:
- Part 1: The last output before deadlock
- Part 2: Your explanation of why deadlock occurs
- Part 3: Your modified `philosopher()` function code

## Grading Rubric (20 points)

- **Part 1** (5 points): Recorded the last output before deadlock
- **Part 2** (5 points): Correctly explained why deadlock occurs
- **Part 3** (10 points): Implemented a working fix that prevents deadlock
