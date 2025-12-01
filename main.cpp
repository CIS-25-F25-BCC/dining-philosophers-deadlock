// Dining Philosophers - Naive Implementation (DEADLOCKS!)
//
// This program demonstrates the classic deadlock scenario.
// Run it and watch it freeze when all philosophers pick up their left chopstick.
//
// The deadlock happens because:
// 1. Each philosopher picks up their LEFT chopstick first
// 2. Then tries to pick up their RIGHT chopstick
// 3. If all 5 do this simultaneously, each has their left but needs their right
// 4. Each right chopstick is someone else's left - circular wait!

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex chopsticks[5];

void philosopher(int id) {
    int left = id;
    int right = (id + 1) % 5;

    while (true) {
        // Think
        std::cout << "Philosopher " << id << " thinking\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Get hungry, pick up LEFT chopstick first
        chopsticks[left].lock();
        std::cout << "Philosopher " << id << " picked up left chopstick (C" << left << ")\n";

        // Small delay makes deadlock more likely to occur
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        // Try to pick up RIGHT chopstick - THIS IS WHERE WE GET STUCK
        chopsticks[right].lock();
        std::cout << "Philosopher " << id << " picked up right chopstick (C" << right << ")\n";

        // Eat
        std::cout << "Philosopher " << id << " eating\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Put down chopsticks
        chopsticks[right].unlock();
        chopsticks[left].unlock();
    }
}

int main() {
    std::cout << "=== Dining Philosophers (Deadlock Demo) ===\n";
    std::cout << "Watch for all philosophers to pick up their left chopstick...\n";
    std::cout << "Then the program will freeze (deadlock)!\n\n";

    std::thread philosophers[5];

    // Start all philosophers
    for (int i = 0; i < 5; i++) {
        philosophers[i] = std::thread(philosopher, i);
    }

    // Wait for all (will never finish - deadlock!)
    for (int i = 0; i < 5; i++) {
        philosophers[i].join();
    }

    return 0;
}
