#include <stdio.h>
#include "../crc64.h"

#include "test_help.h"

extern uint64_t _crc64(uint_fast64_t crc, const void *in_data, const uint64_t len);
extern uint64_t crc64(uint64_t crc, const unsigned char *s, uint64_t l);

int test_crc64(int argc, char **argv, int flags) {
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(flags);
    crc64_init();

    unsigned char numbers[] = "123456789";
    TEST_ASSERT_MESSAGE("[calcula]: CRC64 '123456789'", (uint64_t)_crc64(0, numbers, 9) == 16845390139448941002ull);
    TEST_ASSERT_MESSAGE("[calcula]: CRC64 '123456789'", (uint64_t)crc64(0, numbers, 9) == 16845390139448941002ull);

    unsigned char li[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed "
                         "do eiusmod tempor incididunt ut labore et dolore magna "
                         "aliqua. Ut enim ad minim veniam, quis nostrud exercitation "
                         "ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis "
                         "aute irure dolor in reprehenderit in voluptate velit esse "
                         "cillum dolore eu fugiat nulla pariatur. Excepteur sint "
                         "occaecat cupidatat non proident, sunt in culpa qui officia "
                         "deserunt mollit anim id est laborum.";

    TEST_ASSERT_MESSAGE("[calcula]: CRC64 TEXT'", (uint64_t)_crc64(0, li, sizeof(li)) == 14373597793578550195ull);
    TEST_ASSERT_MESSAGE("[calcula]: CRC64 TEXT", (uint64_t)crc64(0, li, sizeof(li)) == 14373597793578550195ull);
    return 0;
}

int test_aradz(int argc, char **argv, int flags) {
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(flags);
    crc64_init();
    uint64_t res = 0;
    char* s = "jK9fLmQx3nPwZsAb2cVdEgHiYuOp7aBcDeFgHiJkLmNoPqRsTuVwXyZ0123456789!@#$^&*()_+{}|:<>?`~-=[];',./ABCDEFGHIJKLMNOPjK9fLmQx3nPwZsAb2cVdEgHiYuOp7aBcDeFgHiJkLmNoPqRsTuVwXyZ0123456789!@#$^&*()_+{}|:<>?`~-=[];',./ABCDEFGHIJKLMNOPjK9fLmQx3nPwZsAb2cVdEgHiYuOp7aBcDeFgHiJkLmNoPqRsTuVwXyZ0123456789!@#$^&*()_+{}|:<>?`~-=[];',./ABCDEFGHIJKLMNOPjK9fLmQx3nPwZsAb2cVdEgHiYuOp7aBcDeFgHiJkLmNoPqRsTuVwXyZ0123456789!@#$^&*()_+{}|:<>?`~-=[];',./ABCDEFGHIJKLMNOP";

    res = crc64(res, s, 400);
    printf("aradzz1: res0 :(%llx) \n", res);

    uint64_t res2 = 0;
    int index = 0; 
    for (int i=0; i <40; i++){
        res2 = crc64(res2, s+index, 10);
        index +=10;
    }
    printf("aradzz2: res2 :(%llx) \n", res);
    int a = (res == res2);
    printf("aradzz 3 (%d)",a );
    TEST_ASSERT_MESSAGE("aradzz 4 compering res == res", res == res2);
    return 0 ;


}
