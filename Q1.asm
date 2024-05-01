.data
A:        .word 1, 2, 3, -4, 5           # Initialize array A
sum:      .word 0                        # Initialize sum variable
newline:   .asciiz "\n"                  # Newline character
sum_msg:   .asciiz "The sum value is: "  # Message for sum

.text
.globl main

main:
    # Initialize variables
    addi $t0, $zero, 0             # $t0 = i (loop counter)
    la $t1, A                      # $t1 = address of A
    la $t2, sum                    # $t2 = sum

    # Print original array A (first for loop in main function)
print_A_loop:
    beq $t0, 5, summation_3_call   # if i == 5, jump to summation_3_call
    lw $a0, ($t1)                  # load A[i] into $a0
    li $v0, 1                      # syscall code for printing an integer
    syscall
    li $v0, 4                      # syscall code for printing a string
    la $a0, newline                # load address of newline into $a0
    syscall
    addi $t0, $t0, 1               # i++
    addi $t1, $t1, 4               # iterate pointer to next element of A
    j print_A_loop                 # repeat loop

summation_3_call:
    # Reset the loop counter and array pointer
    addi $t0, $zero, 0             # $t0 = i (loop counter)
    la $t1, A                      # $t1 = address of A

summation_3_loop:
    beq $t0, 5, print_updated_A    # if i == 5, jump to print_updated_A
    lw $t3, ($t1)                  # load A[i] into $t3
    addi $t3, $t3, 3               # A[i] += 3
    sw $t3, ($t1)                  # store updated A[i] back into A
    lw $t4, sum                    # load sum into $t4
    addi $t4, $t4, 3               # sum += 3
    sw $t4, sum                    # store updated sum back into sum
    addi $t0, $t0, 1               # i++
    addi $t1, $t1, 4               # advance pointer to next element of A
    j summation_3_loop             # repeat loop

print_updated_A:
    # Reset loop counter and array pointer
    addi $t0, $zero, 0             # $t0 = i (loop counter)
    la $t1, A                      # $t1 = address of A

    # Print updated array A
print_updated_A_loop:
    beq $t0, 5, print_sum          # if i == 5, jump to print_sum
    lw $a0, ($t1)                  # load A[i] into $a0
    li $v0, 1                      # syscall code for printing an integer
    syscall
    li $v0, 4                      # syscall code for printing a string
    la $a0, newline                # load address of newline into $a0
    syscall
    addi $t0, $t0, 1               # i++
    addi $t1, $t1, 4               # advance pointer to next element of A
    j print_updated_A_loop         # repeat loop

print_sum:
    # Print sum message
    li $v0, 4                      # syscall code for printing a string
    la $a0, sum_msg                # load address of sum_msg into $a0
    syscall
    
    # Print sum
    lw $a0, sum                    # load sum into $a0
    li $v0, 1                      # syscall code for printing an integer
    syscall
    li $v0, 4                      # syscall code for printing a string
    la $a0, newline                # load address of newline into $a0
    syscall

    # Exit program
    li $v0, 10                     # syscall code for exiting program
    syscall
