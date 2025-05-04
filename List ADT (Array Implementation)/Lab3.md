# Lab 3: List ADT - Array Implementation  

## Lab Details  
- **Lab Number:** 03  
- **Date:** 02/02/2025  
- **Topic:** List ADT (Array Implementation)  

---

## Questions  

### List ADT Program  
Write a C++ menu-driven program to implement **List ADT** using an array of size 5. Include the following operations:  
1. **Insert Beginning**  
2. **Insert End**  
3. **Insert Position**  
4. **Delete Beginning**  
5. **Delete End**  
6. **Delete Position**  
7. **Search**  
8. **Display**  
9. **Rotate**  
10. **Exit**  

#### Rotate Requirement:  
- The `Rotate` option takes an input `k` and rotates the array right by `k` times.  
- Implement **at least 3 solutions**, including one that uses **O(1) extra space**.  

**Example:**  
- **Input:** `nums = [1,2,3,4,5]`, `k = 2`  
- **Output:** `[4,5,1,2,3]`  
- **Explanation:**  
  - Rotate 1 step: `[5,1,2,3,4]`  
  - Rotate 2 steps: `[4,5,1,2,3]`  