//this algotith is based on euclid algorith and uses less division than the previous one
#include<stdio.h>
unsigned long int mul_inv(unsigned long int n_mod,unsigned long int a){
unsigned long int ret;
asm volatile("mov %0, %%rax\nmov %1, %%rbx\nmov %%rsp, %%r8\nxor %%rcx, %%rcx\n"
".intel_syntax noprefix\nle_loop%=:\nxor rdx, rdx\ndiv rbx\ninc cl\npush rax\n"
"mov rax, rbx\nmov rbx, rdx\ncmp rdx, 1\njne le_loop%=\nmov rax, rdx\nxor r9, r9\nmov rbx, rcx\n"
"le_loop2%=:\nmov r10, rax\nmov rdx, [r8-8]\nmul rdx\nadd rax, r9\nmov r9, r10\nsub r8, 8\nloop le_loop2%=\n"
"test bl,1\njz le_end%=\n"
".att_syntax prefix\n mov %0, %%rcx\nsub %%rax, %%rcx\nmov %%rcx, %2\njmp le_ret%=\n"
"le_end%=:\nmov %%rax, %2\nle_ret%=:\nshl $3, %%bx\nadd %%rbx, %%rsp\n"
:"+m" (n_mod), "+m" (a), "=m" (ret)
:
:"rbx", "rax", "rcx", "rdx", "r8", "r9", "r10"
);
return ret;
}
int main(){
unsigned long int n,a;
printf("xa=1 (mod n)\nenter n:");
scanf("%lu",&n);
printf("enter a:");
scanf("%lu",&a);
printf("x=%lu (mod n)", mul_inv(n,a));
return 1;
}
