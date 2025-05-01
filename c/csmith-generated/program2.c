// Options:   --max-funcs 1 --max-expr-complexity 1 --max-block-size 1 --no-unions --concise --no-volatile-pointers --no-pointers
#include "csmith.h"


static long __undefined;



static int32_t g_2 = 0x1C0F8067L;



static uint8_t  func_1(void);




static uint8_t  func_1(void)
{ 
    int64_t l_3 = 0x9869EC4279C4185ALL;
    g_2 ^= 4L;
    return l_3;
}





int main (int argc, char* argv[])
{
    int print_hash_value = 0;
    if (argc == 2 && strcmp(argv[1], "1") == 0) print_hash_value = 1;
    platform_main_begin();
    crc32_gentab();
    func_1();
    transparent_crc(g_2, "g_2", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
