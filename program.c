#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>
#include <openssl/sha.h>

int main() {
    // Regular expression matching
    char *string = "Hello, world!";
    regex_t regex;
    int reti;
    char msgbuf[100];

    reti = regcomp(&regex, "^H.*!", 0);
    if(reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    reti = regexec(&regex, string, 0, NULL, 0);
    if(!reti) {
        puts("Matched");
    } else if(reti == REG_NOMATCH) {
        puts("No match");
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    // String formatting
    char buffer[100];
    int n = sprintf(buffer, "The value of pi is %f", 3.14159);
    printf("Formatted string: %s\n", buffer);

    // String hashing
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(digest, &sha256);

    printf("SHA256 hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    puts("");

    return 0;
}
