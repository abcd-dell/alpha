#include <stdio.h>
#include <string.h>

void performXOR(char *trans, const char *poly, int n, int m) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        if (trans[i] == '1') { // Check if the bit is '1'
            for (j = i, k = 0; k < m; k++, j++) {
                // Perform XOR
                trans[j] = (trans[j] == poly[k]) ? '0' : '1';
            }
        }
    }
}

int main() {
    int i;
    char poly[30], frame[30], trans[60], recv[60];
    
    // Input polynomial and frame
    printf("Enter the polynomial: ");
    scanf("%s", poly);
    printf("Enter the frame: ");
    scanf("%s", frame);
    
    int m = strlen(poly); // Length of the polynomial
    int n = strlen(frame); // Length of the frame

    // Step 1: Prepare the transmitted frame with appended zeros
    for (i = 0; i < n; i++) {
        trans[i] = frame[i];
    }
    for (i = n; i < n + m - 1; i++) {
        trans[i] = '0';
    }
    trans[i] = '\0'; // Null-terminate the string

    // Step 2: Perform XOR division to calculate the CRC
    performXOR(trans, poly, n, m);

    // Step 3: Append the CRC remainder to the frame
    for (i = 0; i < m - 1; i++) {
        frame[n + i] = trans[n + i];
    }
    frame[n + m - 1] = '\0';

    printf("\nThe transmitted message (frame + CRC): %s\n", frame);

    // Step 4: Simulate the receiver side
    printf("Enter the received message: ");
    scanf("%s", recv);

    // Perform XOR division on the received message
    performXOR(recv, poly, n, m);

    // Check if the remainder is all zeros
    int error = 0;
    for (i = n; i < n + m - 1; i++) {
        if (recv[i] != '0') {
            error = 1; // Error detected
            break;
        }
    }

    if (error) {
        printf("Error detected in the received message.\n");
    } else {
        printf("No error detected. The message is valid.\n");
    }

    return 0;
}
