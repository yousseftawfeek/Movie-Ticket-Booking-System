#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    //there is only 20 VIP seats and 20 economy seats for each movie
    //there are only five movies
    u32 movie_counter=0 , choice , flag=0 ,vip_seats[5]={20,20,20,20,20} , economy_seats[5]={20,20,20,20,20};
    f32 vip_price[5]={0 ,0 ,0 , 0 , 0 } , economy_price[5]={0, 0 ,0,0,0};
    s32 code;
    printf("\t\t\t\t\t\t\t\t\t\t\twelcome to the movie ticket program\n");
    while(1)
    {
        printf("press (1) to insert a movie\npress (2) to book a ticket\npress (3) to view all records\npress (4) to cancel booking\npress (0) to exit\n");
        printf("\nChoice:");
        scanf("%d" , &choice);
        switch(choice)
        {
        case 0:
            {
                flag=1;
                break;
            }
        case 1:
            {
                if(movie_counter<5)
                {
                    insert_movie(movie_counter+1 , &economy_price[movie_counter] , &vip_price[movie_counter]);
                    movie_counter++;
                    break;
                }
                else
                {
                    printf("maximum number of movies can be added is 5\n=============================================\n");
                    break;
                }

            }
        case 2:
            {
                printf("enter the movie code: ");
                scanf("%d" , &code);
                if(code<=0 || code>5)
                {
                    printf("there is no movie with that code\n");
                    printf("=====================================\n");
                    break;
                }
                book_ticket(code , vip_price[code-1] , economy_price[code-1] , &economy_seats[code-1] , &vip_seats[code-1]);
                break;
            }
        case 3:
            {
                view_records(vip_seats , economy_seats , vip_price , economy_price);
                break;
            }
        case 4:
            {
                printf("enter the movie code: ");
                scanf("%d" , &code);
                if(code<=0 || code>5)
                {
                    printf("there is no movie with that code\n");
                    printf("=====================================\n");
                    break;
                }
                cancel_booking(code , vip_price[code-1] , economy_price[code-1] , &economy_seats[code-1] , &vip_seats[code-1]);
                break;
            }
        default:
            {
                printf("there is no choice like that\n");
                printf("==================================\n");
                break;
            }

        }
        if(flag==1)
            break;
    }
    printf("===============================================================\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tthank you\ndesigned by\nyoussef tawfeek\nmenna ghazy\n\n\n\n\n\n\n\n\n\n\n");
    return 0;
}

