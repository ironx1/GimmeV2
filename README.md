# GimmeV2
Sort words, numbers, letters.
Gimme is a c application that sorts letters, words and numbers using binary search tree. The application takes data as arguments or reads it from a file. Gimme can write the arguments to a file or output directly to the screen.

# Usage

Print to screen: gimmev2 -p arg1 arg2 arg3 -type <br />
Write to a file: gimmev2 -w filename.txt arg1 arg2 arg3 -type <br />
Read and Write: gimmev2 -r readfile.txt -w writefile.txt -type <br />

# Type
Use  <br />-int for integers,  <br />-flt for floating point numbers, <br /> -srt for strings.

# Exlampes
gimmev2 -p 10 3 44 1 9 122 11 10 33 0 -4 -int <br />
gimmev2 -w inordered.txt kaan can ali kerem kaan -str <br />
