/*
*   作者：silverHugh
*   时间：2015年1月29日
*   内容：栈的实现
*   语言：C语言
* */
#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 1024

struct Stack{
    int top;
    int data[MAXSIZE];

    int size;
    bool initialled;
};

typedef struct Stack Stack;

void init(Stack *stack);                    //初始化队列
bool push(Stack *stack, int push_data);     //入队一个整型数
bool push_array(Stack *stack,
        int en_data[],int array_size);      //入队一个整型数组
bool pop(Stack *stack);                     //出队
void print(Stack *stack);                   //格式化输出队列

/*
* stack         需要操作的栈指针
* */
void init(Stack *stack){
    stack->top= 0;
    stack->size = 0;
    stack->initialled = true;

    return;
}
/*
* stack         需要操作的栈指针
* push          需要入栈的整型数
* 返回值         入栈成功返回true，失败返回false
* */
bool push(Stack *stack, int push_data){
    if (!stack->initialled){
            init(stack);
        }
    if (stack->size >= MAXSIZE){
        return false;
    }

    stack->data[stack->top++] = push_data;
    stack->size++;

    return true;
}
/*
* stack         需要操作的栈指针
* push_data     需要入栈的整型数组
* array_size    入栈整型数组的大小
* 返回值         数组入栈成功返回true，失败返回false
* */
bool push_array(Stack *stack,
        int push_data[],int array_size){
    int i;

    if (array_size < 0){
        return false;
    }
    if (!stack->initialled){
        init(stack);
    }
    if (stack->size + array_size  > MAXSIZE){
        return false;
    }

    for (i = 0; i <array_size; ++i) {
        push(stack, push_data[i]);
    }

    return true;
}
/*
* stack     需要操作的栈指针
* 返回值     出栈成功返回true，失败返回false
* */
bool pop(Stack *stack){
    if((!stack->initialled)||stack->size==0){
        return false;
    }

    stack->top--;
    stack->size--;

    return true;
}
/*
* stack     需要操作的栈指针
* */
void print(Stack *stack){
    int serial_num;
    if(!stack->initialled){
        init(stack);
    }

    printf("Stack Print\n=================\n");
    printf("Stack Size: %d\n-----------------\n",
            stack->size);
    printf("Stack Data:\n");
    if (stack->size==0){
        printf("Data empty.\n");
    }else{
        for (serial_num=1;serial_num<=stack->size;serial_num++){
            printf("%4d\t",stack->data[stack->top-serial_num]);
            if (serial_num==1){
                printf("Top\n");
            }else if (serial_num==stack->size){
                printf("Bottom\n");
            }else{
                printf("\n");
            }
        }
    }
    printf("=================\nEND\n");

    return;
}

