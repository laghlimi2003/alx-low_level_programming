#!/bin/bash

# Compile each .c file into a corresponding .o file
for file in *.c
do
  gcc -c "$file"
done

# Create the static library liball.a from the .o files
ar rc liball.a *.o

# Index the library for faster symbol lookup
ranlib liball.a

# Clean up the .o files
rm -f *.o

