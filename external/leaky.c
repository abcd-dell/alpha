#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()
int main() {
  int packets[5], b_size, o_rate, p_sz_rm = 0;
  for (int i = 0; i < 5; i++) {
    packets[i] = rand() % 10 + 1; // Ensure non-zero packet size
  }
  printf("Enter output rate: ");
  scanf("%d", &o_rate);
  printf("Enter bucket size: ");
  scanf("%d", &b_size);
  for (int i = 0; i < 5; i++) {
    if (packets[i] + p_sz_rm > b_size) {
      printf("\nIncoming packet size %d exceeds bucket capacity!\n", packets[i]);
    } else {
      p_sz_rm += packets[i];
      printf("\nIncoming packet: %d\n", packets[i]);
      printf("Bytes in bucket: %d\n", p_sz_rm);
      while (p_sz_rm > 0) {
        sleep(1);
        if (p_sz_rm < o_rate) {
          printf("Transmitting %d bytes\n", p_sz_rm);
          p_sz_rm = 0;
        } else {
          printf("Transmitting %d bytes\n", o_rate);
          p_sz_rm -= o_rate;
        }
        printf("Bytes remaining: %d\n", p_sz_rm);
      }
    }
  }
  return 0;
}
