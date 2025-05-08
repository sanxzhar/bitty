# Test program for Bitty processor
# This program performs basic arithmetic operations

# Load immediate values
addi r0 42    # r0 = 42
addi r1 10    # r1 = 10

# Perform arithmetic operations
add r2 r0    # r2 = r2 + r0
sub r3 r0    # r3 = r3 - r0
and r4 r0    # r4 = r4 & r0
or  r5 r0    # r5 = r5 | r0
xor r6 r0    # r6 = r6 ^ r0

# Shift operations
shli r7 2     # r7 = r7 << 2 (using r0 as implicit first operand)
shri r0 1     # r0 = r0 >> 1 (using r7 as implicit first operand)

# Comparison
cmp r1 r0    # Compare r0 and r1, result in r1 