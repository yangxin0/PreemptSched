#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>

#define STACK 1024 * 1024

void coroutine()
{
    printf("coroutine here!\n");
}

int main(int argc, char *argv[]) 
{
    ucontext_t main_ucp, co_ucp;
    unsigned char costack[STACK];

    if (getcontext(&co_ucp) < 0) {
        fprintf(stderr, "getcontext error\n");
        return -1;
    }

    co_ucp.uc_link = &main_ucp;
    co_ucp.uc_stack.ss_sp = costack;
    co_ucp.uc_stack.ss_size = sizeof(costack);
    co_ucp.uc_link = &main_ucp;
    makecontext(&co_ucp, coroutine, 0);

    printf(">> swap context <<\n");
    if (swapcontext(&main_ucp, &co_ucp) < 0) {
        fprintf(stderr, "swap context error\n");
        return -1;
    }
    
    printf("back from main!\n");

    return 0;
}
