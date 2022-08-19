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

int * ones (int a[], int n)
{
    int res[16], i;
    int *p = res;

    printf("\nOne's Complement = ");
    for(i=0; i<n; i++)
    {
        res[i] = not(a[i]);
        printf("%d ",res[i]);
    }

    return p;
}

void twos (int *p, int n)
{
    int res[16], i, carry_in = 1;

    printf("\nTwo's Complement = ");

    //check for pointer
    for(i=0; i<n; i++)
        printf("%d ",*(p+i));

    //error in index -2;
    /*for(i=n-1; i>=0; i--)
    {
        res[i] = sum(*(p+i),0,carry_in);
        carry_in = carry(*(p+i),0,carry_in);
    }

    for(i=0; i<n; i++)
        printf("%d ",res[i]);*/
}

int main()
{

    int a[16], n, i, *p;

    printf("Enter number of bit: ");
    scanf("%d",&n);

    printf("Enter %d bits for A: ",n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    p = ones(a,n);
    twos(p, n);

    return 0;
}
