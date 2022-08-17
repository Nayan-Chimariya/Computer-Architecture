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

void nBitAdder(int *p, int *q, int n)
{
    int res[120], i, carry_in=0;
    printf ("\nSum = ");
    for(i=n-1; i>=0; i--)
    {
        res[i] = sum(*(p+i),*(q+i),carry_in);
        carry_in = carry(*(p+i),*(q+i),carry_in);
    }

    for(i=0; i<n; i++)
        printf("%d ",res[i]);

    printf("\nCarry = %d\n",carry_in);
}

int main()
{
    int logic_1[128], logic_2[128];
    int *p , *q, i, n;

    p = logic_1;
    q = logic_2;

    printf("Enter number of bits : ");
    scanf("%d",&n);

    printf("Enter %d bits for A : ",n);
    for (i=0; i<n; i++)
        scanf("%d",p+i);

    printf("Enter %d bits for B : ",n);
    for (i=0; i<n; i++)
        scanf("%d",q+i);

    nBitAdder(p,q,n);

    return 0;
}
