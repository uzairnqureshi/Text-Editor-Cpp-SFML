# Text Editor with Undo/Redo

![C++](https://img.shields.io/badge/Language-C++17-blue)
![SFML](https://img.shields.io/badge/Library-SFML%203.0-green)
![Status](https://img.shields.io/badge/Status-Completed-success)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

> A Problem-Based Learning (PBL) project demonstrating **Stack Data Structures** (LIFO) to implement **Undo**, **Redo**, and **History Management** in a graphical text editor.

---

## 🚀 Features

* **Typed Input:** Real-time text rendering.
* **Undo (`Ctrl+Z`):** Reverts the last action using a **History Stack**.
* **Redo (`Ctrl+Y`):** Restores undone actions using a **Redo Stack**.
* **Backspace Support:** Deletes characters (functionally identical to undo).
* **Visual Feedback:** Hover effects on buttons and a blinking cursor.

---

## 🛠️ Technical Implementation

This project uses an **Array-Based Stack** to achieve $O(1)$ time complexity for all critical operations.

### Data Structure: `CharStack`
* **Underlying Container:** Fixed-size Array (`char stack[MAX]`).
* **Operations:**
    * `push(char)`: Adds character to top.
    * `pop()`: Removes character from top.

### Logic Flow
1.  **Typing:** Pushes to `MainStack`. **Clears** `RedoStack` (new path invalidates old future).
2.  **Undo:** Pops from `MainStack` → Pushes to `RedoStack`.
3.  **Redo:** Pops from `RedoStack` → Pushes to `MainStack`.

---

## 📦 Dependencies

* **C++ Compiler** (supporting C++17 or later)
* **SFML 3.0** (Simple and Fast Multimedia Library)

---
## 👨‍💻 Author
* Uzair Qureshi
* Course: Data Structures & Algorithms
---

## 🔧 Installation & Build

### 1. Clone the Repository
```bash
git clone [https://github.com/YourUsername/Text-Editor-Undo-PBL.git](https://github.com/YourUsername/Text-Editor-Undo-PBL.git)
cd Text-Editor-Undo-PBL
