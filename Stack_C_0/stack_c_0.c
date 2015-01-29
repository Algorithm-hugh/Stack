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

    //��δ��ʼ������³�ջ
    if (!pop(&stack)){
        printf("��δ��ʼ������£���ջʧ�ܣ�\n");
    }
    //���һ����СΪջ�������ֵ����������
    for ( i = 0; i < MAXSIZE; i++) {
        array[i]=i;
    }
    //���������ѹջ����ӡջ���ȣ���С��
    push_array(&stack, array, 1024);
    printf("Stack Size: %d\n",stack.size);

    //��ջ����֮����ջһ����
    if(!push(&stack, num)){
        printf("��ѹջ�����ᵼ�����������ѹջʧ��\n");
    }

    //ջ������ȫ����ջ,��ӡջ���ȣ���С��
    for (i = stack.size; i >0; i--) {
        pop(&stack);
    }
    printf("Stack Size: %d\n",stack.size);

    //����ȫ����ջ���ٴ�ִ�г�ջ
    if (!pop(&stack)){
        printf("��ջ��û������ʱ��ջ����ջʧ�ܣ�\n");
    }
}