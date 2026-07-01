# CSE221-assignment-4
CSE221: Data Structures | Fall 2024 | Assignment 4 | Student score Management System



A C++ student score management system, that combines hash tables and skip lists to support efficient storage, retrieval, ordering, and ranking of student records.

The system maintains consistency between unordered and ordered data structures while providing fast access by student ID and score.

## Features

* Hash table with separate chaining
* Skip list for ordered score management
* Efficient insertion, deletion, and lookup
* Score updates synchronized across structures
* Top-k student retrieval
* Score ranking
* Support for duplicate scores
* Custom exception handling

## Repository Structure

```text
.
├── Makefile                    # Build configuration
├── PA4 description_v1.2.pdf    # Assignment specification
├── README.md                   # Repository documentation
├── main.cpp                    # Test driver
├── student_map.cpp
├── student_map.h               # Hash table implementation
├── student_ordered_map.cpp
├── student_ordered_map.h       # Skip list implementation
├── student_database.cpp
└── student_database.h          # Combined database interface
```

## Components

### StudentMap

Implements an unordered map from student ID to score using a hash table.

Supported operations:

* `add_student()`
* `update_score()`
* `get_score()`
* `remove_student()`

Features:

* Hash table size: 1000
* Separate chaining collision handling
* Fast lookup by student ID

### StudentOrderedMap

Implements an ordered map from score to student ID using a skip list.

Supported operations:

* `add_student()`
* `update_score()`
* `get_student()`
* `remove_student()`

Features:

* Ordered traversal by score
* Duplicate score handling
* Lowest student ID priority for equal scores

### StudentDatabase

Combines both structures to maintain synchronized student records.

The supported operations:

* `add_student()`
* `update_score()`
* `get_score()`
* `get_student()`
* `remove_student()`
* `get_top_k_students()`
* `get_rank()`

## Exception Handling

Runtime exceptions are thrown when:

* Updating a non-existent student
* Removing a non-existent student
* Looking up a non-existent student ID
* Looking up a non-existent score
* Requesting the rank of a score that does not exist

## Building

Compile the project with:

```bash
make
```

This generates:

```text
main
```

## Main Source Files

### student_map.cpp

Implements:

* Hash table construction
* Separate chaining
* Student insertion, update, lookup, and removal

### student_ordered_map.cpp

Implements:

* Skip list operations
* Ordered insertion and deletion
* Score-based search

### student_database.cpp

Implements:

* Synchronization between both structures
* Top-k student retrieval
* Rank computation

## Course Information

**Course:** CSE221 Data Structures
**Semester:** Fall 2024
