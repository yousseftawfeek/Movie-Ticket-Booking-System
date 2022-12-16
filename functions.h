#include "STD_TYPES.h"
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
void insert_movie(u32 *code , f32 *economy_price , f32 *vip_price)
{
    f32 vip , economy;
    label:
    printf("enter the vip ticket price: ");
    scanf("%f" , &vip);
    if(vip<=0)
        {
            printf("cannot put a price equals or below 0\n");
            goto label;
        }
    *vip_price=vip;
    label2:
    printf("enter the economy ticket price: ");
    scanf("%f" , &economy);
    if(economy<=0)
    {
        printf("cannot put a price equals or below 0\n");
        goto label2;
    }
    else if(economy>=vip)
    {
        printf("cannot put a price of economy seats equals or more than the price of the VIP price\n");
        goto label2;
    }
    *economy_price=economy;
    printf("the movie code is: %d\nthe vip ticket price is: %.2f\nthe economy ticket price is: %.2f\n" , code , *vip_price , *economy_price);
    printf("====================================================================================== \n");
}
void book_ticket(u32 code , f32 vip_price , f32 economy_price , u32 *economy_seats , u32 *vip_seats)
{
    if(economy_price>0)
    {
        u8 name[50];
    u32 number , type;
    printf("enter your name without spaces: ");
    scanf("%s" , &name);
    printf("enter the number of tickets: ");
    scanf("%d" , &number);
    label:
    printf("enter (1) for VIP tickets and press (2) for economy tickets: ");
    scanf("%d" , &type);
    if(type!=1&&type!=2)
        {
            printf("incorrect choice\n");
            goto label;
        }
    if(type==1)
    {
        if(*vip_seats<number)
        {
            printf("\nthere is no enough seats for this number of tickets\n");
            printf("=============================================================\n");
        }
        else
        {
            printf("========================================================\n");
            printf("name: %s\n" , name);
            printf("total seats: %d\n" , number);
            printf("the cost per ticket is: %.1f\n" , vip_price);
            printf("the total cost is: %.1f\n" , vip_price*number);
            printf("=======================================================\n");
            *vip_seats-=number;
        }
    }
    if(type==2)
    {
        if(*economy_seats<number)
        {
            printf("\nthere is no enough seats for this number of tickets\n");
            printf("=========================================================\n");
        }
        else
        {
            printf("======================================================\n");
            printf("name: %s\n" , name);
            printf("total seats: %d\n" , number);
            printf("the cost per ticket is: %.1f\n" , economy_price);
            printf("the total cost is: %.1f\n" , economy_price*number);
            printf("=======================================================\n");
            *economy_seats-=number;
        }
    }

    }
    else
    {
        printf("there is no movie with that code\n");
        printf("=================================\n");
    }

}
void view_records(u32 vip[] , u32 economy[] , f32 vip_price[] , f32 economy_price[])
{
    printf("=====================================================================\n");
    for(int i=0 ; i<5 ; i++)
    {
        if(vip_price[i]>0)
        {
            printf("the code of the film is: %d\n" , i+1);
            printf("the number of economy tickets available is: %d\n" , economy[i]);
            printf("the number of economy tickets reserved is: %d\n" , 20-economy[i]);
            printf("the number of VIP tickets available is: %d\n" , vip[i]);
            printf("the number of VIP tickets reserved is: %d\n" , 20-vip[i]);
            printf("============================================================\n");
        }
        else
            continue;

    }

}
void cancel_booking(u32 code , f32 vip_price , f32 economy_price , u32 *economy_seats , u32 *vip_seats)
{
    u32 type , number;
    if(economy_price>0)
    {
        printf("enter the number of tickets you want to cancel the booking of them: ");
        scanf("%d" , &number);
        printf("enter (1) for VIP tickets and press (2) for economy tickets: ");
        scanf("%d" , &type);
        label:
        if(type!=1 && type!=2)
        {
            printf("incorrect choise\n");
            goto label;
        }
        if(type==1)
        {
            if(number+*vip_seats<=20)
            {
                printf("the number of tickets is: %d\n" , number);
                printf("the quantity of money returned to the customer: %.1f\n" , number*vip_price);
                printf("========================================================================\n");
                *vip_seats+=number;
            }
            else
                {
                    printf("cannot return money for such a number of tickets\n");
                    printf("===================================================\n");
                }
        }
        else
            {
                if(number+*economy_seats<=20)
            {
                printf("the number of tickets is: %d\n" , number);
                printf("the quantity of money returned to the customer: %.1f" , number*economy_price);
                printf("========================================================================\n");
                *economy_seats+=number;
            }
            else
                {
                    printf("cannot return money for such a number of tickets\n");
                    printf("===================================================\n");
                }
            }

    }
}
#endif // FUNCTIONS_H_INCLUDED
