#include <stdio.h>
#include <stdlib.h>
#include "./Libraries/LibFunctions.c"
#include "./Libraries/menu.c"


int main()
{
    hide_cursor();
    page_acceuil();


    // Initialistion part

    bool listcreated = false;
    bool queuecreated = false;

    NodeVehicle *VehicleList=NULL;
    NodeItem *ItemList=NULL;
    
    queue VanQ;
    queue MotoQ;


    report report ={.cancelledItems=0,.ItemsDelivered=0,.newItems=0,.returnedItems=0, .initialItemsNumber = 0, .finalItemsNumber=12};
    //End of innitialisation part



    int choix;
    choix = 0;
    
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
                report.initialItemsNumber = lengthofItemList(ItemList);
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
                
                    if (queuecreated == false){
                    createQueuesFromList(VehicleList,&MotoQ,&VanQ);
                    printf("\n\t\t\t\t\t Queues Created Successfully");
                    queuecreated = true;
                    getchar();
                    }
                    else {
                        printf("\n\t\t\t\t\t    The Queues are already created !");
                        getchar();  
                    }
            } else {
                printf("\n\t\t\t\t\t You have to load The lists Before ! ");
                getchar();
            }
            goto sousmenu_1;


        case 3: // printItemList
        if (listcreated == true){
            clrscr();
            printItemList(ItemList);
            Sleep(1);
            getchar();
            
            }else {
                printf("\n\t\t\t\t    * Please load the list from the file first * \n");
                Sleep(1);
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
            report.newItems++;
            Item item ;
            createItem(&item,ItemList); // * a finir *
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
            createVehicle(&vehicle,VehicleList);
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
            if (areItemsRemaining(ItemList)){
                

                if (assignItemsToVehicleQueue(ItemList,MotoQ,VanQ)==true){
                animation();
                menureturn(&choix);
                system("cls");
                switch (choix)
                {

                case 1:// Yes
                    printf("\tVan Queue : \n\n");
                    printQueueContent(VanQ);
                    printf("\tMoto Queue : \n\n");
                    printQueueContent(MotoQ);
            GiveID:printf("\nGive the ID of the Item Returned (Based on the ID of an Item linked to the queues) :");
                    int ID;
            readID:scanf( "%d", &ID );

                    if(setReturn(ItemList,ID)==1){
                        printf("Invalid ID Please try again  : ");
                        goto readID;
                    }
                    report.returnedItems++;
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
                updateQueuesAfterDelivery(&VanQ,&MotoQ);
                }
                else{
                    animation2();
                }
            }else{
                printf("\n\t\t\t    * There is no Items Left To Deliver Please save and close * \n");
                getchar();
            }
            
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
            report.cancelledItems++;
            Sleep(1);
            getch();
        }else{
            printf("\n\t\t\t\t    * Please load the list from the file first * \n");
            Sleep(1);
            getch();
        }
        goto mainmenu;

    case 4: // simulate end of the day and Update files and create report file
    
    if (listcreated== true){
        report.finalItemsNumber = lengthofItemList(ItemList); 
        report.ItemsDelivered= report.initialItemsNumber + report.newItems-report.cancelledItems-report.finalItemsNumber;
        createReportFile(report);
        loadfilefromvehiclelist(VehicleList);
        loadfilefromItemlist(ItemList);
        getch();
        }
        else{
            printf("\n\t\t\t\t    * Please load the list from the file first * \n");
            getchar();
        }
    goto mainmenu;
    case 5: // exit application
    system("cls");
    printf("See you soon\n");
    }
}




