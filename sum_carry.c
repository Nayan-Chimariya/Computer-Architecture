#include <stdio.h>

int not(int logic)
{
    if(logic == 1)
        return 0;
    else
        return 1;
}

int or(int logic_1, int logic_2)
{
    if(logic_1==0 && logic_2==0)
        return 0;
    else
        return 1;
}

int and(int logic_1, int logic_2)
{
    if(logic_1==1 && logic_2 == 1)
        return 1;
    else
        return 0;
}

int xor(int logic_1, int logic_2)
{
    return or(and(logic_1,not(logic_2)),and(not(logic_1),logic_2));
}

int sum(int logic_1, int logic_2, int carry_in)
{
    return xor(xor(logic_1,logic_2),carry_in);
}

int carry(int logic_1, int logic_2,int carry_in)
{
    return or(or(and(logic_1,logic_2),and(logic_2,carry_in)),and(logic_1,carry_in));
}

int main()
{
    int logic_1, logic_2, carry_in;

    printf("Enter logic value of A : ");
    scanf("%d",&logic_1);

    printf("Enter logic value of B : ");
    scanf("%d",&logic_2);

    printf("Enter Carry in : ");
    scanf("%d",&carry_in);

    printf("\nSum = %d",sum(logic_1,logic_2,carry_in));
    printf("\nCarry = %d",carry(logic_1,logic_2,carry_in));

    return 0;
}

