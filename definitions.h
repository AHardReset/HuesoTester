#include <CD74HC4067.h>
#define en_a 8
#define sig_a A0
#define s0a 3
#define s1a 4
#define s2a 5
#define s3a 6

#define en_b 7
#define sig_b A1
#define s0b 6
#define s1b 5
#define s2b 4
#define s3b 3

#define relay 9
#define led 13

#define max_shortV 5
#define min_continuityV 1013
CD74HC4067 mux_a(s0a, s1a, s2a, s3a);
CD74HC4067 mux_b(s0b, s1b, s2b, s3b);