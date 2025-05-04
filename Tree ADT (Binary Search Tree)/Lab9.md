# Lab 09 – Tree ADT – Binary Search Tree  

## Lab Details
- **Lab Number:** 07
- **Date:** 23/03/2025
- **Topic:** Tree ADT (Binary Search Tree)

---

## ** A: Increasing Sequence Game (K5)**  
Nene invented a game based on an increasing sequence of integers \(a_1, a_2, \ldots, a_k\). Players are lined up, and in each round:  
- The \(a_1\)-th, \(a_2\)-th, ..., \(a_k\)-th players are kicked out (if they exist).  
- The game ends when no players are kicked in a round; remaining players win.  

**Example:**  
For \(a = [3, 5]\) and \(n = 5\) (players A, B, C, D, E):  
- **Round 1:** C (3rd) and E (5th) are kicked → Remaining: A, B, D.  
- **Round 2:** D (3rd) is kicked → Remaining: A, B.  
- **Round 3:** No one kicked → Winners: A, B.  

**Question:**  
Given \(q\) integers \(n_1, n_2, \ldots, n_q\), determine the number of winners for each \(n_i\) independently.  

---

## ** B: Participant Strength Difference (K5)**  
**Problem:**  
For each participant \(i\) among \(n\) participants, compute the difference between their strength \(s_i\) and the maximum strength of any other participant.  

**Input:**  
- Multiple test cases. Each test case:  
  - \(n\) (number of participants).  
  - Strengths \(s_1, s_2, \ldots, s_n\).  

**Output:**  
For each test case, print \(n\) space-separated integers (differences for each participant).  


---

## ** C: Binary Search Tree ADT (K4)**  
**Task:**  
Write a C++ menu-driven program to implement Tree ADT (Binary Search Tree) with:  
1. Insert  
2. Preorder Traversal  
3. Inorder Traversal  
4. Postorder Traversal  
5. Search  
6. Exit  

---

## ** D: Expression Tree Construction (K4)**  
**Task:**  
Extend the BST program to:  
1. Construct an expression tree from a postfix expression (using STL stack).  
2. Support these operations:  
   - Postfix Expression Input  
   - Construct Expression Tree  
   - Preorder/Inorder/Postorder Traversals  
   - Exit  
