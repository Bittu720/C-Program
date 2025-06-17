#include <stdio.h>
void binaryToDec(int n)
{
    int i = 1, sum = 0;
    while (n > 0)
    {
        int rem = n % 10;
        sum += rem * i;
        i = i << 1;
        n /= 10;
    }
    printf("%d", sum);
}
void decToBinary(int n)
{
    int sum;
    if (n % 2 == 0)
    {
        sum = 1;
        while (n > 1)
        {
            int rem = n % 2;
            sum = sum * 10 + rem;
            n /= 2;
        }
    }
    else
    {
        sum = 0;
        while (n > 0)
        {
            int rem = n % 2;
            sum = sum * 10 + rem;
            n /= 2;
        }
    }
printf("\n");
    printf("%d", sum);
}
int main()
{
    int n = 100;
     binaryToDec(n);
    decToBinary(7);
    return 0;
}