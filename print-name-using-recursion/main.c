#include<stdio.h>
void xyz(int n);
int main()
{
    int a;
    printf("Enter the no. of times you want to print your name: ");
scanf("%d",&a);
xyz(a);
}

void xyz(int n)
{
    if(n==0){
    printf("stop");
    }

    else{
        printf("xyz");
        xyz(n-1);
    }
}