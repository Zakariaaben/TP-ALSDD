#include <stdio.h>
#include <stdlib.h>

#include "LibFunctions.c"
#include "menu.c"

#include <stdbool.h>


int main()
{


    // Initialistion part

    bool listcreated = false;
    bool queuecreated = false;

    NodeVehicle *VehicleList=NULL;
    NodeItem *ItemList=NULL;

    queue VanQ;
    queue MotoQ;


    //End of innitialisation part



    int choix;
    choix = 0;
    hide_cursor();
mainmenu:
    menuprinci(&choix);

    switch (choix)
    {

    case 1: //
    sousmenu_1:
        menulistmanagement(&choix); // LIST AND FILE MANAGEMENT MENU
        switch (choix)
        {
        case 1: // lOAD LISTS FROM FILE
            if ( listcreated == false)
                {

                loadVehicleListFromfile(&VehicleList, "vehicles.txt");

                loadItemListFromfile(&ItemList, "items.txt");

                printf("\n\t\tLists Loaded successfully from the file ! Press enter to go back to the previous menu.");
                listcreated = true;
                getchar();
            } else {
                printf("\n\t\t\t\t\tThe lists are already loaded");
                getchar();
            }
            goto sousmenu_1;





        case 2 :  // CREATE VANQ AND MOTOQ

            if (listcreated == true){
                createQueuesFromList(VehicleList,&MotoQ,&VanQ);
                printf("\n\t\t\t\t\t Queues Created Successfully");
                queuecreated = true;
                getchar();
            } else {
                printf("\n\t\t\t\t\t You have to load The lists Before ! ");
                getchar();
            }
            goto sousmenu_1;


        case 3: // printItemList
        if (listcreated == true){
            clrscr();
            printItemList(ItemList);
            getchar();
            
            }else {
                printf("\n\t\t\t\t    * Please load the list from the file first * \n");
                getchar();
            }
            system("cls");
            goto sousmenu_1;


        case 4:// PrintVehicleList
            if (listcreated == true){
            clrscr();
            printVehicleList(VehicleList);
            getchar();
            system("cls");
            }else {
                printf("\n\t\t\t\t    * Please load the list from the file first * \n");
                getchar();
            }
            goto sousmenu_1;

        case 5: // Add new Item
            if (listcreated == true){
            Item item ;
            createItem(&item); // * a finir *
            addNewItem(&ItemList,item);
            printf("\n\t\t\t\t\t\t    Item Added successfully\n");
            getchar();
            }else{
                printf("\n\t\t\t\t    * Please load the list from the file first * \n");
                getchar();
            }
            goto sousmenu_1;

        case 6: // Add new Vehicle

            if (queuecreated == true){
            Vehicle vehicle;
            createVehicle(&vehicle);
            addVehicleAndUpdateQueue(&VehicleList,vehicle, &MotoQ, &VanQ);
            printf("\n\t\t\t\t\t\t    Vehicle Added successfully\n");
            getchar();
            }else{
                printf("\n\t\t\t\t    * Please create the queues first * \n");
                getchar();
            }

            goto sousmenu_1;


        case 7: // delete Vehicle

           if (listcreated == true){
                int ID;
                printVehicleList(VehicleList);
                printf("\nEnter the ID of the vehicle you want to delete : ");
                scanf("%d",&ID);
                deleteVehicleByID(&VehicleList,ID);

                if (queuecreated== true){createQueuesFromList(VehicleList,&MotoQ,&VanQ);}

           }else{
                printf("\n\t\t\t\t    * Please load the list from the file first * \n");
                getchar();
           }
           goto sousmenu_1;

        case 8: //Print Van Queue

            if (queuecreated == true){
            system("cls");
            printVehicleQueue(VanQ);
            getchar();
            system("cls");
            }else {
                printf("\n\t\t\t\t    * Please load the queue from the list first * \n");
                getchar();
            }
            goto sousmenu_1;

        case 9: // print Moto Queue
        if (queuecreated == true){
            system("cls");
            printVehicleQueue(MotoQ);
            getchar();
            system("cls");
            }else {
                printf("\n\t\t\t\t    * Please load the queue from the list first * \n");
                getchar();
            }
            goto sousmenu_1;

        case 10: // return to main menu
            goto mainmenu;
        }



    case 2: // Assign items and launch Delivery

        if(queuecreated==true){

            system("cls"); // Waiting screen
            gotoxy(marginleft+5, 5);
            printf("-----------------------------------------\n");
            gotoxy(marginleft+5, 11);
            printf("-----------------------------------------");
            gotoxy(marginleft+5, 7);
            printf("    Items Are being assigned");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            assignItemsToVehicleQueue(ItemList,MotoQ,VanQ);
            gotoxy(marginleft+5, 9);
            printf("\tItems assigned Successfully !\n");
            Sleep(1500);

            menureturn(&choix);
            system("cls");
            switch (choix)
            {

            case 1:// Yes
                printf("\tVan Queue : \n\n");
                printVehicleQueue(VanQ);
                printf("\tMoto Queue : \n\n");
                printVehicleQueue(MotoQ);
          GiveID:printf("\nGive the ID of the Item Returned (Based on the ID of an Item linked to the queues) :");
                int ID;
          readID:scanf( "%d", &ID );

                if(setReturn(ItemList,ID)==1){
                    printf("Invalid ID Please try again  : ");
                    goto readID;
                }

                printf("\n\t\tItem Set to returned ! \n ");
                printf("Is there another returned  item ? (Y/N)\n");
                char ans ;
                ans= getch();
                if (ans ==  'y' || ans == 'Y'){
                    goto GiveID;
                }
                system("cls");
                break;


            case 2:// No
                break;
            }

            updateItemlist(&ItemList);
            
        }
        else {
            printf("\n\t\t\t\t    * Please load the queue from the list first * \n");
            getchar();
        }
    
    goto mainmenu;
    case 3: // set return and delivery cancellation ( delete Items from list )
        if (listcreated ==true)
        {
            printItemList(ItemList);
            int ID;
            printf("\nEnter the ID of the Item you want to Remove / Cancel :  ");
            scanf("%d",&ID);
            if (deleteItemByID(&ItemList,ID)==1){
                printf("\n\t\tThis ID does not exist !");
            }
            Sleep(1);
            getch();
        }else{
            printf("\n\t\t\t\t    * Please load the list from the file first * \n");
        }


            goto mainmenu;
    case 4: // simulate end of the day and Update files and create report file

    goto mainmenu;
    case 5: // exit application
    system("cls");
    printf("See you soon\n");
    }
}




