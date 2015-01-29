/*
*   ���ߣ�silverHugh
*   ʱ�䣺2015��1��29��
*   ���ݣ�ջ��ʵ��
*   ���ԣ�C����
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

void init(Stack *stack);                    //��ʼ������
bool push(Stack *stack, int push_data);     //���һ��������
bool push_array(Stack *stack,
        int en_data[],int array_size);      //���һ����������
bool pop(Stack *stack);                     //����
void print(Stack *stack);                   //��ʽ���������

/*
* stack         ��Ҫ������ջָ��
* */
void init(Stack *stack){
    stack->top= 0;
    stack->size = 0;
    stack->initialled = true;

    return;
}
/*
* stack         ��Ҫ������ջָ��
* push          ��Ҫ��ջ��������
* ����ֵ         ��ջ�ɹ�����true��ʧ�ܷ���false
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
* stack         ��Ҫ������ջָ��
* push_data     ��Ҫ��ջ����������
* array_size    ��ջ��������Ĵ�С
* ����ֵ         ������ջ�ɹ�����true��ʧ�ܷ���false
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
* stack     ��Ҫ������ջָ��
* ����ֵ     ��ջ�ɹ�����true��ʧ�ܷ���false
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
* stack     ��Ҫ������ջָ��
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

