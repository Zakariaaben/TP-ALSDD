#include <stdio.h>
#include <stdlib.h>
#include "LibStructures.c"

void allocateItem(NodeItem **);
NodeItem *nextItem(NodeItem *);
void ass_adrItem(NodeItem *, NodeItem *);
void ass_valItem(NodeItem *, Item);
Item valueItem(NodeItem *);
void addNewItem(NodeItem **, Item);
void printItemList(NodeItem *);
void loadItemListFromfile(NodeItem **, char *);
void allocateVehicle(NodeVehicle **);
NodeVehicle *nextVehicle(NodeVehicle *);
void ass_adrVehicle(NodeVehicle *, NodeVehicle *);
void ass_valVehicle(NodeVehicle *, Vehicle);
Vehicle valueVehicle(NodeVehicle *);
void printVehicleList(NodeVehicle *);
void loadVehicleListFromfile(NodeVehicle **, char *);
void createQueuesFromList(NodeVehicle *, queue *, queue *);






//----------------------------------------------------- PART FUNCTIONS OF ITEMS --------------------------------

const char* READ_FORMAT_ITEM = "(%d, %[^,], %d, %d, %c)\n";//(1, 05-01-22, 23, 150, A)

void allocateItem(NodeItem **p)
{
    *p = malloc(sizeof(NodeItem));
}

NodeItem *nextItem(NodeItem *p)
{
    return p->link;
}

void ass_adrItem(NodeItem *p, NodeItem *q)
{
    p->link = q;
}

void ass_valItem(NodeItem *p, Item Item)
{
    p->Item = Item;
}

Item valueItem(NodeItem *p)
{
    return p->Item;
}

void addNewItem(NodeItem **head, Item Item)
{
    if (*head == NULL)
    {
        allocateItem(head);
        ass_valItem(*head, Item);
        ass_adrItem(*head, NULL);
    }
    else
    {
        NodeItem *ptr = *head;

        while (nextItem(ptr) != NULL)
        {
            ptr = nextItem(ptr);
        }
        NodeItem *q;
        allocateItem(&q);
        ass_adrItem(ptr, q);
        ptr = nextItem(ptr);
        ass_adrItem(ptr, NULL);
        ass_valItem(ptr, Item);
    }
}

void printItemList(NodeItem *head)
{
    if (head == NULL)
    {
        printf("\n\t/* La liste est vide */\n");
    }
    else
    {
        NodeItem *p = head;
        int maillon = 1;
        while (p != NULL)
        {
            Item tempItem = valueItem(p);
            printf("  Item %d :\n", maillon);
            printf("\t- ID: %d\n", tempItem.ID);
            printf("\t- Date: %s\n", tempItem.Date);
            printf("\t- Wilaya: %d\n", tempItem.wilaya);
            printf("\t- Weight: %d\n", tempItem.weight);
            printf("\t- Status: %c\n", tempItem.Status);
            p = nextItem(p);
            maillon++;
        }
    }
}


void loadItemListFromfile(NodeItem **head, char *filename)
{
    char line[100]; // ceci contiendra chaque ligne
    FILE * file;
    
    file  = fopen(filename,"a+"); // opening of the file
    Item Item;
    
    while (fgets(line, sizeof(line), file) != NULL) // READS EACH LINE OF THE FILE
    {
        if (sscanf(line, READ_FORMAT_ITEM, &(Item.ID), (Item.Date), &(Item.wilaya), &(Item.weight), &(Item.Status))==5) // TAKES  THE DATA FROM A LINE AND PUT IT IN LIST
        {   
            addNewItem(head,Item);// ADDS THE ITEM TO THE LIST
        }
    }
    fclose(file); // closing the file
}

//----------------------------------------------------- END PART FUNCTIONS OF ITEMS ----------------------------

//---------------------------------------------------- PART FUNCTINOS OF VEHICLE -------------------------------

const char* READ_FORMAT_VEHICLE = "(%c, %d, %d)\n";//(1, 05-01-22, 23, 150, A)

void allocateVehicle(NodeVehicle **p)
{
    *p = malloc(sizeof(NodeVehicle));
}

NodeVehicle *nextVehicle(NodeVehicle *p)
{
    return p->link;
}

void ass_adrVehicle(NodeVehicle *p, NodeVehicle *q)
{
    p->link = q;
}

void ass_valVehicle(NodeVehicle *p, Vehicle Vehicle)
{
    p->Vehicle = Vehicle;
}

Vehicle valueVehicle(NodeVehicle *p)
{
    return p->Vehicle;
}

void addNewVehicle(NodeVehicle **head, Vehicle Vehicle)
{
    if (*head == NULL)
    {
        allocateVehicle(head);
        ass_valVehicle(*head, Vehicle);
        ass_adrVehicle(*head, NULL);
    }
    else
    {
        NodeVehicle *ptr = *head;

        while (nextVehicle(ptr) != NULL)
        {
            ptr = nextVehicle(ptr);
        }
        NodeVehicle *q;
        allocateVehicle(&q);
        ass_adrVehicle(ptr, q);
        ptr = nextVehicle(ptr);
        ass_adrVehicle(ptr, NULL);
        ass_valVehicle(ptr, Vehicle);
    }  
        
}

void printVehicleList(NodeVehicle *head)
{
    if (head == NULL)
    {
        printf("\n\t/* La liste de ces vehicule est vide */\n");
    }
    else
    {
        NodeVehicle *p = head;
        int maillon = 1;
        while (p != NULL)
        {
            Vehicle tempVehicle = valueVehicle(p);
            printf("  Vehicle %d :\n", maillon);
            printf("\t- Type: %c\n", tempVehicle.Type);
            printf("\t- ID: %d\n", tempVehicle.ID);
            printf("\t- Wilaya: %d\n", tempVehicle.capacity);
            p = nextVehicle(p);
            maillon++;
        }
    }
}



void loadVehicleListFromfile(NodeVehicle **head, char *filename)
{
    char line[100]; // ceci contiendra chaque ligne
    FILE * file;
    
    file  = fopen(filename,"a+"); // opening of the file
    Vehicle Vehicle;
    
    while (fgets(line, sizeof(line), file) != NULL) // READS EACH LINE OF THE FILE
    {
        if (sscanf(line, READ_FORMAT_VEHICLE, &(Vehicle.Type), &(Vehicle.ID), &(Vehicle.capacity))==3) // TAKES  THE DATA FROM A LINE AND PUT IT IN LIST
        {   
            addNewVehicle(head,Vehicle);// ADDS THE Vehicle TO THE LIST
        }
    }
    fclose(file); // closing the file
}

// ---------------------------------------------- END PART OF VEHICLE FUNCTIONS ----------------------------------------




// ---------------------------------- LOAD MOTO/VAN QUEUE FROM VEHICLE LIST ---------------------------------


void createQueuesFromList(NodeVehicle *headList, queue * MotoQ, queue * VanQ){

    NodeVehicle *pList = headList;
    (*MotoQ).head =(*MotoQ).tail = (*VanQ).head = (*VanQ).tail =  NULL;
    
    NodeVehicle * tailMoto=NULL , *tailVan =NULL;

    while (pList!=NULL)     // CREATING THE QUEUES
    {
        if (valueVehicle(pList).Type=='V'){

            addNewVehicle(&(*VanQ).head ,valueVehicle(pList));

            if (tailVan == NULL)
            {
               tailVan= (*VanQ).head;
            }else if (nextVehicle(tailVan)!=NULL){
                tailVan = nextVehicle(tailVan);
            }
            
        }else if (valueVehicle(pList).Type == 'M'){

            addNewVehicle(&(*MotoQ).head ,valueVehicle(pList));

            if (tailMoto == NULL)
            {
               tailMoto= (*MotoQ).head;
            }else if (nextVehicle(tailMoto)!=NULL){
                tailMoto = nextVehicle(tailMoto);
            }

        }
        pList=nextVehicle(pList);
    }

    // INITIALIZING THE TAIL
    (*MotoQ).tail = tailMoto ;
    (*VanQ).tail = tailVan  ;

}



void addVehicleAndUpdateQueue(NodeVehicle ** head,Vehicle vehicle,queue* MotoQ,queue* VanQ){
    addNewVehicle(head,vehicle);
    NodeVehicle * p;
    allocateVehicle(&p);
    ass_valVehicle(p,vehicle);
    ass_adrVehicle(p,NULL);
    if (vehicle.Type == 'M')
    {
        ass_adrVehicle((*MotoQ).tail, p);
        (*MotoQ).tail = p;
    }else if (vehicle.Type == 'V' ){
        ass_adrVehicle((*VanQ).tail, p);
        (*VanQ).tail = p;
    }
}

//--------------------------------- END OF FUNCTION LOADING QUEUE ---------------------------------------------



