#include <stdio.h>
#include <stdlib.h>
#include "LibStructures.c"
#include "LibFunctions.h"
#include <string.h>


//----------------------------------------------------- PART FUNCTIONS OF ITEMS --------------------------------

const char *READ_FORMAT_ITEM = "(%d, %[^,], %d, %d, %c)\n"; //(1, 05-01-22, 23, 150, A)

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

void createItem(Item * item){
    printf("Insert the Item ID: ");
    scanf("%d",&(*item).ID);
    // to finish
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


void printItem(Item item){
            printf("\t\t\t- ID: %d\n", item.ID);
            printf("\t\t\t- Date: %s\n", item.Date);
            printf("\t\t\t- Wilaya: %d\n", item.wilaya);
            printf("\t\t\t- Weight: %d\n", item.weight);
            printf("\t\t\t- Status: %c\n", item.Status);
            
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
            printf("\t\tItem %d :\n", maillon);
            printItem(tempItem);
            printf("\n");
            p = nextItem(p);
            maillon++;
        }
    }
}



int deleteItemByID(NodeItem **head, int ID)
{
    if (*head == NULL)
    {
        printf("The Item list is already empty.\n");
        return 1;
    }
    else
    {
        NodeItem *p = *head, *q;
        while (p != NULL)
        {
            if (valueItem(p).ID != ID)
            {
                q = p;
                p = nextItem(p);
            }
            else if (valueItem(p).ID == ID)
            {
                break;
            }
        }
        if (p == NULL)
            return 1;

        if (p == *head)
        {
            q = *head;
            free(q);
            *head = nextItem(*head);
        }
        else
        {
            ass_adrItem(q, nextItem(p));
            free(p);
        }
        printf("\nItem Deleted from the list successfully ! ");
        return 0;
    }
}


int lengthofItemList(NodeItem *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        NodeItem *p = head;
        int counter = 0;
        while (p != NULL)
        {
            p = nextItem(p);
            counter++;
        }
        return counter;
    }
}


void loadItemListFromfile(NodeItem **head, char *filename)
{
    *head = NULL;
    char line[100]; // ceci contiendra chaque ligne
    FILE * file;
    
    file  = fopen(filename,"a+"); // opening of the file
    Item Item;
    
    while(fgets(line, sizeof(line), file) != NULL) // READS EACH LINE OF THE FILE
    {
        if (sscanf(line, READ_FORMAT_ITEM, &(Item.ID), (Item.Date), &(Item.wilaya), &(Item.weight), &(Item.Status))==5) // TAKES  THE DATA FROM A LINE AND PUT IT IN LIST
        {   
            Item.studied= 0;
            addNewItem(head,Item);// ADDS THE ITEM TO THE LIST
        }
    }
    fclose(file); // closing the file
}


//----------------------------------------------------- END PART FUNCTIONS OF ITEMS ----------------------------

//---------------------------------------------------- PART FUNCTINOS OF VEHICLE -------------------------------

const char *READ_FORMAT_VEHICLE = "(%c, %d, %d)\n"; //(1, 05-01-22, 23, 150, A)

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

void createVehicle(Vehicle * vehicle){
    printf("Give the type of the Vehicle (M for Moto and V for Van) :  ");
    scanf("%c", &(*vehicle).Type);
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

int deleteVehicleByID(NodeVehicle **head, int ID)
{
    if (*head == NULL)
    {
        printf("The list is already empty.\n");
        return 1;
    }
    else
    {
        NodeVehicle *p = *head, *q;
        while (p != NULL)
        {
            if (valueVehicle(p).ID != ID)
            {
                q = p;
                p = nextVehicle(p);
            }
            else if (valueVehicle(p).ID == ID)
            {
                break;
            }
        }
        if (p == NULL)
            return 1;

        if (p == *head)
        {
            q = *head;
            free(q);
            *head = nextVehicle(*head);
        }
        else
        {
            ass_adrVehicle(q, nextVehicle(p));
            free(p);
        }
        printf("Vehicle Deleted");
        return 0;
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
    FILE *file;
    *head = NULL;
    file = fopen(filename, "a+"); // opening of the file
    Vehicle Vehicle;

    while (fgets(line, sizeof(line), file) != NULL) // READS EACH LINE OF THE FILE
    {
        if (sscanf(line, READ_FORMAT_VEHICLE, &(Vehicle.Type), &(Vehicle.ID), &(Vehicle.capacity)) == 3) // TAKES  THE DATA FROM A LINE AND PUT IT IN LIST
        {
            addNewVehicle(head, Vehicle); // ADDS THE Vehicle TO THE LIST
        }
    }
    fclose(file); // closing the file
}

// ---------------------------------------------- END PART OF VEHICLE FUNCTIONS ----------------------------------------

// -B-------------------------------------------------  MACHINE ABSTRAITE QUEUES de Vehicules -----------------------------//

void allocateVQueue(NodeQueue **p) // alloue un espace memoire pour un noeud de la queue
{
    *p = malloc(sizeof(NodeQueue));
}

NodeQueue *nextVQueue(NodeQueue *p) // renvoie l'adresse du prochain maillon de la queue
{
    return p->next;
}

void ass_adrVQueue(NodeQueue *p, NodeQueue *q)
{
    p->next = q;
}

void ass_valVQueue(NodeQueue *p, Vehicle Vehicle)
{
    p->Vehicle = Vehicle;
}

Vehicle valueVQueue(NodeQueue *p) // renvoie la valeur du vehicule du maillon
{
    return p->Vehicle;
}

// -E--------------------------------------------------- FIN MACHINE ABSTRAITE QUEUES --------------------------//

// ---------------------------------- LOAD MOTO/VAN QUEUE FROM VEHICLE LIST ---------------------------------

NodeQueue * enqueueVehicle(queue *queue, Vehicle Vehicle)
{
    NodeQueue *newNode;
    allocateVQueue(&newNode);
    ass_valVQueue(newNode, Vehicle);
    ass_adrVQueue(newNode, NULL);
    (*newNode).head = NULL;
    (*newNode).next = NULL;

    if ((*queue).head == NULL)
    {
        (*queue).head = (*queue).tail = newNode;
    }

    else
    {
        ass_adrVQueue((*queue).tail, newNode);
        (*queue).tail = newNode;
    }
    return newNode;
}

int dequeueVehicle(queue *queue, Vehicle *Vehicle)
{
    if ((*queue).head == NULL)
    {
        return 1; // RETURN ERROR IF THE QUEUE IS EMPTY
    }
    else if ((*queue).tail == (*queue).head)
    {
        *Vehicle = valueVQueue((*queue).head);
        free((*queue).head);
        (*queue).head = NULL;
        (*queue).tail = NULL;
        return 0; // RETURN SUCCESS
    }

    else
    {
        *Vehicle = valueVQueue((*queue).head);
        NodeQueue *temp = (*queue).head;
        (*queue).head = nextVQueue((*queue).head);
        free(temp);
        return 0; // RETURN SUCCESS
    }
}

void printVehicleQueue(queue queue)
{
    if (queue.head == NULL)
    {
        printf("\n\t/* La Queue de ces vehicule est vide */\n");
    }
    else
    {
        NodeQueue *p = queue.head;
        int maillon = 1;
        while (p != NULL)
        {
            Vehicle tempVehicle = valueVQueue(p);
            
            printf("  Vehicle %d :\n", maillon);
            printf("\t- ID: %d\n", tempVehicle.ID);
            printf("\t- Max capapcity: %d\n\n", tempVehicle.capacity);  

            if (p->head != NULL)
            {
                printItemList(p->head);
            }
            printf("\n\n");  
            p = nextVQueue(p);
            maillon++;
        }
    }
}

void createQueuesFromList(NodeVehicle *headList, queue *MotoQ, queue *VanQ)
{

    NodeVehicle *pList = headList;
    (*MotoQ).head = (*MotoQ).tail = (*VanQ).head = (*VanQ).tail = NULL;

    NodeQueue *tailMoto = NULL, *tailVan = NULL;
    NodeQueue * NewNode;
    while (pList != NULL) // CREATING THE QUEUES
    {
        if (valueVehicle(pList).Type == 'V')
        {
            NewNode=enqueueVehicle(VanQ, valueVehicle(pList));
        }
        else if (valueVehicle(pList).Type == 'M')
        {

            NewNode= enqueueVehicle(MotoQ, valueVehicle(pList));
        }
        NewNode->Trips = 0;
        pList = nextVehicle(pList);
        
    }
}


void addVehicleAndUpdateQueue(NodeVehicle **head, Vehicle vehicle, queue *MotoQ, queue *VanQ)
{
    addNewVehicle(head, vehicle);
    if (vehicle.Type == 'M')
    {
        enqueueVehicle(MotoQ, vehicle);
    }
    else if (vehicle.Type == 'V')
    {
        enqueueVehicle(VanQ, vehicle);
    }
}

//--------------------------------- END OF FUNCTION LOADING QUEUE ---------------------------------------------

// ------------------------ FUNCTIONS OF PART OF ASSIGNING ITEMS TO VEHICLES ---------------------------------

int min_date(char *date1, char *date2)
{
    // Compare year
    if (strncmp(date1 + 6, date2 + 6, 2) < 0)
    {
        
        return  1;
    }
    else if (strncmp(date1 + 6, date2 + 6, 2) > 0)
    {
        return 2;
    }

    // Compare month
    if (strncmp(date1 + 3, date2 + 3, 2) < 0)
    {
        return 1;
    }
    else if (strncmp(date1 + 3, date2 + 3, 2) > 0)
    {
        return 2;
    }
    // Compare day
    if (strncmp(date1, date2, 2) < 0)
    {
        return 1;
    }
    else
    {

        return 2;
    }
}

NodeItem *priorItem(NodeItem *headlist) // Fetches the pointer of the item having the  smallest date from the list.
{
    if (headlist == NULL)
        printf("LA LISTE EST VIDE");
    NodeItem *p = headlist;
    char *mindate = "99-99-99";
    NodeItem *q=NULL;
    while (p != NULL)
    {
        if( min_date(mindate, valueItem(p).Date) == 2 && valueItem(p).studied == 0){
            q= p;
            mindate  = valueItem(p).Date;
        }
        p = nextItem(p);
    }

    if (q != NULL){    // There is still an item that needs to be assigned 
    (*q).Item.studied = 1;
    } // ELSE : ALL THE ITEMS HAVE BEEN STUDIED

    return q;
    
}


void assignItemsToVehicleQueue(NodeItem *headlist, queue MotoQ, queue VanQ)
{

    NodeItem *currentItem = priorItem(headlist);
    
     while (currentItem != NULL)
    {

        if (valueItem(currentItem).weight > 3 || valueItem(currentItem).wilaya != 16) // CASE 01 : THE ITEM GOES TO VanQ
        {
            NodeQueue *pVanQ = VanQ.head;
            while (pVanQ != NULL)
            {
                if (lengthofItemList(pVanQ->head) == 0 || (lengthofItemList(pVanQ->head) < valueVQueue(pVanQ).capacity && valueItem(pVanQ->head).wilaya == valueItem(currentItem).wilaya))
                { // We assign it to the vehicle if the van is empty or if the current capacity is less then the max cap and that the item goes to the same wilaya
                    (*currentItem).Item.Status = 'D'; // for delivered
                    addNewItem(&pVanQ->head, valueItem(currentItem));
                    pVanQ = NULL;
                
                }
                else
                {
                    pVanQ = nextVQueue(pVanQ);
                    
                }
                
            }
        }

        else // CASE 02 : THE ITEM WEIGHS LESS THAN 3 AND GOES TO ALGIERS
        {
            NodeQueue *pMotoQ = MotoQ.head;
            while (pMotoQ != NULL)
            {
                if (lengthofItemList(pMotoQ->head) < 2)
                { // We assign it to the vehicle if the Moto is empty or if the current capacity is less then the max cap and that the item goes to the same wilaya
                    (*currentItem).Item.Status = 'D'; // for delivered
                    addNewItem(&pMotoQ->head, valueItem(currentItem));
                    pMotoQ = NULL;

                }
                else
                {
                    pMotoQ = nextVQueue(pMotoQ);
                }
            }

            if (valueItem(currentItem).Status == 'A') // IF THE ITEM CANNOT BE DELIVERED IN MOTO THEN WE TRY IN THE VanQ
            {
                NodeQueue *pVanQ = VanQ.head;
                while (pVanQ != NULL)
                {
                    if (lengthofItemList(pVanQ->head) == 0 || (lengthofItemList(pVanQ->head) < valueVQueue(pVanQ).capacity && valueItem(pVanQ->head).wilaya == valueItem(currentItem).wilaya))
                    { // We assign it to the vehicle if the van is empty or if the current capacity is less then the max cap and that the item goes to the same wilaya
                        (*currentItem).Item.Status = 'D'; // for delivered
                        addNewItem(&pVanQ->head, valueItem(currentItem));
                        pVanQ = NULL;
                    }
                    else
                    {
                        pVanQ = nextVQueue(pVanQ);
                    }
                }
            }
        }
        currentItem = priorItem(headlist); // WE STOP WHEN ALL THE  ITEMS HAVE BEEN PROCESSED
    }
    

}


int setReturn(NodeItem * headlist, int ID){ // set the item to Returned if we tried to deliver it but decided that it has been returned
    NodeItem * pList = headlist;
    while (pList != NULL )
    {
        if (valueItem(pList).ID == ID && valueItem(pList).Status=='D')
        {
            pList->Item.Status = 'R';
            return 0;
        }
        pList=nextItem(pList);
    }

    return 1;
}


void updatelist(NodeItem ** head){
    NodeItem * p,*q ;
    p = *head;
    q = NULL;
    

    while (p!=NULL)
    {
        if (valueItem(p).Status=='D')
        {
           if (q == NULL)
           {
            *head = nextItem(p);
           }
           
        }
        q = p;
        p =nextItem(p);
    }
    
}







        
        
        
    
    



