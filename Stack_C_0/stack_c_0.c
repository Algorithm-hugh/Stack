#include "h_stack.h"
void test();
void test_array();
void test_error();

void main(){
    test();
    test_array();
    test_error();
}

void test(){
    Stack stack;
    push(&stack, 5);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);
    pop(&stack);
    push(&stack, 10);

    print(&stack);

    return;
}

void test_array(){
    Stack stack;
    int array[16] = {1,2,3,4,5,6,7,8,9,10};

    push_array(&stack, array, 10);
    print(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    print(&stack);
}

void test_error(){
    Stack stack;
    int array[MAXSIZE],i;
    int num=1;

    //在未初始化情况下出栈
    if (!pop(&stack)){
        printf("（未初始化情况下）出栈失败！\n");
    }
    //获得一个大小为栈长度最大值的整型数组
    for ( i = 0; i < MAXSIZE; i++) {
        array[i]=i;
    }
    //将这个数组压栈，打印栈长度（大小）
    push_array(&stack, array, 1024);
    printf("Stack Size: %d\n",stack.size);

    //在栈充满之后入栈一个数
    if(!push(&stack, num)){
        printf("（压栈操作会导致数据溢出）压栈失败\n");
    }

    //栈中数据全部出栈,打印栈长度（大小）
    for (i = stack.size; i >0; i--) {
        pop(&stack);
    }
    printf("Stack Size: %d\n",stack.size);

    //数据全部出栈后再次执行出栈
    if (!pop(&stack)){
        printf("（栈中没有数据时出栈）出栈失败！\n");
    }
}