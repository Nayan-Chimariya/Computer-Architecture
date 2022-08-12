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
    int logic_1[4], logic_2[4], carry_in=0, res[4];
    int i;

    printf("Enter 4 bits for A : ");
    for (i=0; i<4; i++)
        scanf("%d",&logic_1[i]);

    printf("Enter 4 bits for B : ");
    for (i=0; i<4; i++)
        scanf("%d",&logic_2[i]);

    printf("Enter carry in bit : ");
    scanf("%d",&carry_in);

    printf ("\nSum = ");
    for(i=3; i>=0; i--)
    {
        res[i] = sum(logic_1[i],logic_2[i],carry_in);
        carry_in = carry(logic_1[i],logic_2[i],carry_in);
    }

    for(i=0; i<4; i++)
        printf("%d ",res[i]);

    printf("\nCarry = %d\n",carry_in);
    return 0;
}
