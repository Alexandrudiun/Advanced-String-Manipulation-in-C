# Advanced-String-Manipulation-in-C

##This program uses the POSIX regular expression library to match a regular expression pattern against a given string. If the match is successful, it prints "Matched", otherwise it prints "No match".

##It also uses the sprintf function to format a string with a floating-point value and print it to the console.

##Finally, it uses the SHA-256 algorithm to hash a given string and print the hash to the console.

##Please note that the example above use openssl library for the SHA256 hash function, you need to install openssl library and include <openssl/sha.h> for it to work.
To run this prgram I used: gcc program.c -o program -lssl -lcrypto
./program
