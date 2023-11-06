# Producer-Consumer Problem Solution

## Overview

This repository contains the C++ implementation of the classic synchronization problem known as the producer-consumer (bounded-buffer) problem. The solution demonstrates the use of semaphores for synchronization and pthreads for multithreading in a POSIX environment.

## Problem Description

In the producer-consumer problem, a producer generates items and puts them onto a table (buffer), and a consumer picks up items from the table. The challenge is that the table can only hold a finite number of items - in this case, two items at the same time. If the table is full, the producer must wait until there is space available. Similarly, if the table is empty, the consumer must wait until an item is produced. The synchronization of the producer and consumer is managed using semaphores, ensuring that the producer and consumer do not access the buffer at the same time, thus avoiding race conditions.

## Files

- `producer.cpp`: Contains the implementation of the producer which generates items and places them into the buffer.
- `consumer.cpp`: Contains the implementation of the consumer which takes items from the buffer.

## Compilation Instructions

To compile the producer and consumer programs, use the following commands in your terminal:

```sh
g++ -std=c++11 -pthread producer.cpp -o producer
g++ -std=c++11 -pthread consumer.cpp -o consumer



//Execution Instructions
./producer &
./consumer &

//Example Output
Produced: 0
Consumed: 0
Produced: 1
Consumed: 1

//Design Decisions section
- **Buffer Size**: The buffer is intentionally set to a capacity of two items, conforming to the assignment's specifications. This limit is established using a `#define` directive for its simplicity and directness.

- **Synchronization**: Semaphores are employed to manage access to the buffer, ensuring that only one actor (producer or consumer) can modify the buffer at any given time, and to signal when the buffer is full or empty.

- **Concurrency**: The implementation uses POSIX threads (pthreads) to enable the producer and consumer to operate in parallel, ensuring a smooth and efficient workflow.

//Author
Deanna Baccus
