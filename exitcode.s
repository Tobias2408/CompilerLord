.text
.align 2
.global _start

.extern _exit           // Declare the external _exit function

_start:
    mov x0, 5           // Set the initial value to 5
    add x0, x0, 12      // Add 12 to x0, making it 17
    bl _exit            // Call _exit from libc with x0 as the exit code
