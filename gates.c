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

int main()
{
    int logic_1, logic_2;
    printf("Enter two logic values: ");
    scanf("%d %d",&logic_1, &logic_2);

    printf("\nNOT %d -> %d\n",logic_1,not(logic_1));
    printf("NOT %d -> %d\n",logic_2,not(logic_2));

    printf("\n%d AND %d-> %d\n",logic_1,logic_2,and(logic_1,logic_2));

    printf("\n%d OR %d-> %d\n",logic_1,logic_2,or(logic_1,logic_2));

    printf("\n%d X-OR %d-> %d\n",logic_1,logic_2,xor(logic_1,logic_2));
    return 0;
}
