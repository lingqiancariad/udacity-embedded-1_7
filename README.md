# Sorted Linked List In-Place Merger

A C++ implementation of a Singly Linked List (SLL) merging algorithm. This project demonstrates a specific logic where nodes from a source list (`l1`) are iteratively inserted into a pre-sorted target list (`l2`).

## 🚀 Overview

The algorithm takes two lists and merges them by traversing the first list and finding the appropriate insertion point in the second. Unlike standard "Merge Sorted Lists" problems where both lists are sorted, this implementation assumes **only the target list (`l2`) is sorted**, while the source list (`l1`) can be in any order.

### Key Logic & Features:
* **In-Place Insertion:** Directly modifies the pointers of existing nodes to minimize memory overhead.
* **Flexible Input:** The source list (`l1`) does not require pre-sorting.
* **Step-by-Step Debugging:** Includes a `printList` helper that visualizes the state of the target list after every node insertion.
* **Precondition:** The target list (`l2`) must be sorted in ascending order for the logic to function correctly.

---

## 🛠️ How the Algorithm Works

The function `mergeTwoLists(l1, l2)` follows these insertion rules for each node in `l1`:

1.  **Head Insertion:** If the node is smaller than the current head of `l2`, it becomes the new head.
2.  **Tail Insertion:** If the node is larger than the last element of `l2`, it is appended to the end.
3.  **Middle Insertion:** If the node's value falls between two existing nodes in `l2`, it is inserted between them.
4.  **Traversal:** If the current `l1` node is larger than the current `l2` window, the pointer moves forward in `l2` to find the correct spot.


---

## 💻 Usage

### Prerequisites
* A C++ compiler (GCC, Clang, or MSVC) supporting C++11 or later.

### Compilation
```bash
g++ -o merge_slls merge_slls.cpp
```

### Running the Program
```bash
./merge_slls
```

### Example Input
* **List 1 (Unsorted):** `30 -> 25 -> 8 -> 40`
* **List 2 (Sorted):** `10 -> 11 -> 12 -> 13`
* **Final Merged Output:** `8 -> 10 -> 11 -> 12 -> 13 -> 25 -> 30 -> 40`
<img width="792" height="363" alt="image" src="https://github.com/user-attachments/assets/ebe20261-8b7a-4499-9676-f799f952ff43" />

---

## 📝 Author
* **LiMe**
* **Date:** March 17, 2026

---
MIT License
Copyright (c) 2026 LiMe

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
