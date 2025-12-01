# Mini-Lab: Concurrency Basics

**CIS-25: Data Structures | December 1, 2025**

## Overview

In this lab, you'll experience one of the most dangerous bugs in concurrent programming: **deadlock**. You'll observe the bug in action and explain why it happens.

**Collaboration:** Submit individually, but you're welcome to help each other and share code as much as you like. Please don't copy-paste someone else's answers, but feel free to work through this together and discuss with others.

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

## Your Task (15 points)

1. Run the dining philosophers demo: `./philosophers`
2. Watch for deadlock (program stops producing output but doesn't exit)
3. You may need to run it several times - deadlock doesn't always happen immediately
4. Press Ctrl+C to kill the program when it deadlocks

**Questions:**

a) What was the last output you saw before the program stopped? (Copy the last few lines)

b) In your own words, explain why deadlock occurs. What is each philosopher waiting for?

c) Describe ONE strategy that could prevent this deadlock:

---

## Deliverables

Submit individually on Canvas:
- Answers to all three questions above

## Grading Rubric (15 points)

- **Question a** (5 points): Recorded the last output before deadlock
- **Question b** (5 points): Correctly explained why deadlock occurs
- **Question c** (5 points): Described a valid strategy to prevent deadlock
