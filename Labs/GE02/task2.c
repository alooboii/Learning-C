#include <stdio.h>
#include <string.h>

void safe_memcpy(void *dest, const void *src, size_t n) {
    //Implement this function
    if (src == NULL || dest == NULL) {  //if either is NULL do nothing
        return;
    }
    char* d = (char*)dest;
    const char* s = (const char*)src;
    // 1) (s > d && d < s + n) --> overlapping case BUT safe Forward Copying
    // 2) (s <= d && d >= s + n) --> non-overlapping case
    // 3) (s > d || d >= s + n) --> non-overlapping case 

    if (s > d || d >= s + n) { 
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    }
    // 4) (s <= d && d < s + n) --> overlapping case, dest is completely inside src (Backward Copying)
    else { 
        size_t i = n;
        while(i--) {
            d[i] = s[i];
        }
    }
}



//---------------------------------------------- TEST CASES - DO NOT EDIT ----------------------------------------------------

void test_safe_memcpy(){
    printf("\033[1m\033[36m\nTesting Safe Memcpy:\033[0m\n");
    int total = 0;

    printf("\n\033[35mTesting basic copy (non-overlap):\033[0m");
    char src1[] = "Hello, World!";
    char dest1[20];
    safe_memcpy(dest1, src1, strlen(src1) + 1);
    // printf("src1: %s\n", src1);
    // printf("dest1: %s\n", dest1);
    if(!strcmp(dest1, src1)){
        total += 1;
        printf(" \033[0;32m1/1\033[0m");
    }
    else{
        printf(" \033[0;31m0/1\033[0m");
    }

    printf("\n\n\033[35mTesting exact sized copy (non-overlap):\033[0m");
    char src2[] = "Test!";
    char dest2[6];
    safe_memcpy(dest2, src2, 6);
    // printf("src2: %s\n", src2);
    // printf("dest2: %s\n", dest2);
    if(!strcmp(dest2, src2)){
        total += 1;
        printf(" \033[0;32m1/1\033[0m");
    }
    else{
        printf(" \033[0;31m0/1\033[0m");
    }

    printf("\n\n\033[35mTesting overlap (backward):\033[0m");
    char src3[] = "123456789";
    // printf("src3 old: %s\n", src3);
    safe_memcpy(src3 + 4, src3, 5);
    // printf("src3 new: %s\n", src3);
    if(!strcmp(src3, "123412345")){
        total += 4;
        printf(" \033[0;32m4/4\033[0m");
    }
    else{
        printf(" \033[0;31m0/4\033[0m");
    }

    printf("\n\n\033[35mTesting overlap (forward):\033[0m");
    char src4[] = "ABCDEFGHI";
    // printf("src4 old: %s\n", src4);
    safe_memcpy(src4, src4 + 3, 6);  // Overlap: copy "DEFGHI" to "ABCDEF"
    // printf("src4 new: %s\n", src4);
    if(!strcmp(src4, "DEFGHIGHI")){
        total += 3;
        printf(" \033[0;32m3/3\033[0m");
    }
    else{
        printf(" \033[0;31m0/3\033[0m");
    }

    printf("\n\n\033[35mTesting zero sized copy:\033[0m");
    char src5[] = "No Change";
    char dest5[20] = "Initial";
    safe_memcpy(dest5, src5, 0);
    // printf("src5: %s\n", src5);
    // printf("dest5: %s\n", dest5);
    if(!strcmp(dest5, "Initial")){
        total += 2;
        printf(" \033[0;32m2/2\033[0m");
    }
    else{
        printf(" \033[0;31m0/2\033[0m");
    }

    printf("\n\n\033[35mTesting single byte copy:\033[0m");
    char src6[] = "X";
    char dest6[2];
    safe_memcpy(dest6, src6, 2);
    // printf("src6: %s\n", src6);
    // printf("dest6: %s\n", dest6);
    if(!strcmp(dest6, "X")){
        total += 2;
        printf(" \033[0;32m 2/2\033[0m");
    }
    else{
        printf(" \033[0;31m0/2\033[0m");
    }

    printf("\n\n\033[35mTesting self copy:\033[0m");
    char src7[] = "SelfCopy";
    // printf("src7 old: %s\n", src7);
    safe_memcpy(src7, src7, strlen(src7) + 1);
    // printf("src7 old: %s\n", src7);
    if(!strcmp(src7, "SelfCopy")){
        total += 1;
        printf(" \033[0;32m1/1\033[0m");
    }
    else{
        printf(" \033[0;31m0/1\033[0m");
    }

    printf("\n\n\033[35mTesting NULL src or dest:\033[0m");
    safe_memcpy(NULL, src7, 5);
    safe_memcpy(src7, NULL, 5);
    if(!strcmp(src7, "SelfCopy")){
        total += 1;
        printf(" \033[0;32m1/1\033[0m");
    }
    else{
        printf(" \033[0;31m0/1\033[0m");
    }

    printf("\n\n\033[1m\033[35mTotal: ");
    if(total == 15){
        printf("\033[0;32m%d/%d\033[0m\n\n", total, 15);
    }
    else{
        printf("\033[0;31m%d/%d\033[0m\n\n", total, 15);
    }
}

int main() {
    test_safe_memcpy();
    return 0;
}
