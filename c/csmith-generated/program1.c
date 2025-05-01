// Options:   --max-funcs 1 --max-expr-complexity 1 --max-block-size 1 --no-unions --concise --no-volatile-pointers --no-pointers
#include "csmith.h"


static long __undefined;



static int32_t g_3[7] = {0x166941FCL,0x6C74AA0DL,0x166941FCL,0x166941FCL,0x6C74AA0DL,0x166941FCL,0x166941FCL};
static int64_t g_4 = 0x6CE4A6F44401D1B9LL;



static int32_t  func_1(void);




static int32_t  func_1(void)
{ 
    uint64_t l_2[9] = {1UL,1UL,1UL,1UL,1UL,1UL,1UL,1UL,1UL};
    int i;
    for (g_3[2] = 8; (g_3[2] >= 3); g_3[2] -= 1)
    { 
        g_4 |= (-1L);
    }
    return g_3[2];
}





int main (int argc, char* argv[])
{
    int i;
    int print_hash_value = 0;
    if (argc == 2 && strcmp(argv[1], "1") == 0) print_hash_value = 1;
    platform_main_begin();
    crc32_gentab();
    func_1();
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_3[i], "g_3[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_4, "g_4", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
