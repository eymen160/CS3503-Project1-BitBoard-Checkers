# CS 3503  Project 1: BitBoard Checkers

 **Student:** Eymen Keyvan  
 **Course:** CS 3503 – Computer Organization & Architecture  
 **Semester:** Fall 2025

---

## 🧩 About the Project

This project implements a simple 2-player checkers game using a **bitboard** system in C.  
The goal was to use bitwise operations to represent and manipulate the board without arrays.  

The board is stored in 64 bits (`unsigned long long`) where each bit represents a square on the 8×8 board.  
Red and black pieces are moved using bitwise shifts and masks.

---

## ▶️ How to Run

Compile and run in terminal:

```bash
gcc main.c -o bitcheck
./bitcheck
