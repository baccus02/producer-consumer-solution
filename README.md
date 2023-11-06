# Producer-Consumer Problem Solution

## Overview

This C++ implementation tackles the classic synchronization challenge known as the producer-consumer problem. It employs semaphores for synchronization and pthreads for multithreading within a POSIX environment.

## Problem Description

The producer-consumer scenario involves a producer placing items onto a buffer, referred to as a table, and a consumer removing these items. The table has a limited capacity, set to two items concurrently. The producer waits when the table is full, and the consumer waits when it is empty. Semaphores ensure that the producer and consumer access the table in a synchronized manner, preventing race conditions.

## Files Included

- `producer.cpp`: Implementation of the producer, responsible for generating items and adding them to the buffer.
- `consumer.cpp`: Implementation of the consumer, responsible for removing items from the buffer.

## Compilation Instructions

Use the following commands in the terminal to compile the producer and consumer programs:


g++ -std=c++11 -pthread producer.cpp -o producer
g++ -std=c++11 -pthread consumer.cpp -o consumer

Execution Instructions
After compilation, run the programs concurrently with the following commands:
./producer &
./consumer &

Example Output
The output illustrates the producer creating items and the consumer removing them:
Produced: 0
Consumed: 0
Produced: 1
Consumed: 1
...

Design Decisions
Buffer Size: Defined with a #define directive, the buffer size is limited to two items, as specified in the assignment.
Synchronization: Semaphores synchronize access to the buffer, ensuring mutual exclusion and signaling buffer availability.
Concurrency: POSIX threads (pthreads) enable the producer and consumer to execute concurrently, facilitating an efficient flow of operations.

Author
Deanna Baccus