#include <stdio.h>
#include <stdlib.h>
#include "LibStructures.c"
#include <stdbool.h>
#include "LibFunctions.h"
#include <string.h>
#include <conio.h>
#include <windows.h>


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

bool ItemIdexists(NodeItem * head, int ID){ // verifies if The ID of the Item is in the Item list
    NodeItem * p = head;
    while (p!=NULL)
    {
        if (valueItem(p).ID==ID)
        {
            return true;
        }   
        p=nextItem(p);
    }
    return false;
    
}


void createItem(Item * item,NodeItem * ItemList){ // creates a new Item
    printf("\n\t - Insert the Item ID: ");
    scanf("%d",&(*item).ID);
    while (ItemIdexists(ItemList,(*item).ID)==true)
    {
        printf("\n\tThis ID already exists, try again : ");
        scanf("%d",&(*item).ID);

    }
    

    printf("\n\t - Insert the Item Date of the Item (Format: DD-MM-YY): ");
    scanf("%s",(*item).Date);

wilaya:printf("\n\t - Insert the wilaya  {1..58}: ");
    scanf("%d",&(*item).wilaya);
    if ((*item).wilaya<1 || (*item).wilaya>58 )
    {
        goto wilaya;
    }
    
    printf("\t - Insert the weight: ");
    scanf("%d",&(*item).ID);

    (*item).Status = 'A';

}




void addNewItem(NodeItem **head, Item Item) // adds the Item to the End of the ItemList
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


void printItem(Item item){  // Prints one Item
            printf("\t\t\t- ID: %d\n", item.ID);
            printf("\t\t\t- Date: %s\n", item.Date);
            printf("\t\t\t- Wilaya: %d\n", item.wilaya);
            printf("\t\t\t- Weight: %d\n", item.weight);
            printf("\t\t\t- Status: %c\n", item.Status);
            
}



void printItemList(NodeItem *head) // Prints the whole Item List
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



int deleteItemByID(NodeItem **head, int ID) // Deletes an Item from the Item list by his ID
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




int lengthofItemList(NodeItem *head) // returns the Number of Items in the Item List
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


void loadItemListFromfile(NodeItem **head, char *filename) // Loads the Item List
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

void loadfilefromItemlist(NodeItem *head) // Creates the End of the day Item new List
{
    FILE *file;
    file = fopen("./Reports/ItemReport.txt", "w"); // Open the file for writing

    if (file == NULL) // Check if the file opening was successful
    {
        printf("Error opening file for writing.\n");
        return;
    }

    NodeItem *current = head; // Start from the head of the list

    while (current != NULL) // Traverse the linked list
    {
        // Write vehicle data to the file in the desired format
        fprintf(file, "(%d, %s, %02d, %02d, %c)\n", valueItem(current).ID, valueItem(current).Date, valueItem(current).wilaya,valueItem(current).weight,valueItem(current).Status);
        current = nextItem(current); // Move to the next node
    }

    fclose(file); // Close the file
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


bool VehicleIdexists(NodeVehicle * head, int ID){ // verifies if the vehicle exists
    NodeVehicle * p = head;
    while (p!=NULL)
    {
        if (valueVehicle(p).ID==ID)
        {
            return true;
        }   
        p= nextVehicle(p);
    }
    return false;
    
}



void createVehicle(Vehicle * vehicle,NodeVehicle * VehicleList){ // creates a new Vehicle
   
type:printf("\n\tGive the type of the Vehicle (M for Moto and V for Van) :  ");
    scanf("%c", &(*vehicle).Type);
    if ((*vehicle).Type!='M' && (*vehicle).Type!='m' && (*vehicle).Type!='V' && (*vehicle).Type!='v')
    {
        goto type;
    }

    printf("\n\tGive the ID of the Vehicle  :  ");
    scanf("%d", &(*vehicle).ID);
    while (VehicleIdexists(VehicleList,(*vehicle).ID)==true)
    {
        printf("\n\tThis ID already exists, try again : ");
        scanf("%d",&(*vehicle).ID);
    }
    


maxcap:printf("\n\tGive the Maximum capacity of the Vehicle ( <=2 For Moto) :  ");
    scanf("%d", &(*vehicle).capacity); 
    if ((*vehicle).capacity>2 && (*vehicle).Type=='M')
    {
        goto maxcap;
    }
    
}

void addNewVehicle(NodeVehicle **head, Vehicle Vehicle) // adds the vehicle to the list
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



void printVehicle(Vehicle vehicle){
    printf("\t- Type: %c\n", vehicle.Type);
    printf("\t- ID: %d\n", vehicle.ID);
    printf("\t- Max Capacity: %d\n", vehicle.capacity);
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
            printf("\t- Max Capacity: %d\n", tempVehicle.capacity);
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



void loadfilefromvehiclelist(NodeVehicle *head) // creates the end of the day Vehicle File
{
    FILE *file;
    file = fopen("./Reports/VehicleReport.txt", "w"); // Open the file for writing

    if (file == NULL) // Check if the file opening was successful
    {
        printf("Error opening file for writing.\n");
        return;
    }

    NodeVehicle *current = head; // Start from the head of the list

    while (current != NULL) // Traverse the linked list
    {
        // Write vehicle data to the file in the desired format
        fprintf(file, "(%c, %d, %d)\n", valueVehicle(current).Type, valueVehicle(current).ID, valueVehicle(current).capacity);
        current = nextVehicle(current); // Move to the next node
    }

    fclose(file); // Close the file
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

void enqueueVehicle(queue *queue, NodeQueue * newNode) // adds a node at the end of the queue
{
    newNode->head = NULL;
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
}



NodeQueue * dequeueVehicle(queue *queue) 
{
    if ((*queue).head == NULL)
    {
        return NULL; // RETURN ERROR IF THE QUEUE IS EMPTY
    }
    else {
        NodeQueue *temp = (*queue).head ;
        if ((*queue).tail == (*queue).head)
        {
            (*queue).head = NULL;
            (*queue).tail = NULL;
        }

    else
        {
            (*queue).head = nextVQueue((*queue).head);
        }

        return temp; // RETURN SUCCESS
    }
}

void printVehicleQueue(queue queue) // prints the vehicles of the queue
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
            printf("\t- Max capapcity: %d\n", tempVehicle.capacity);  
            printf("\t- Trips Done : %d\n\n",p->Trips);
            printf("\n\n");  
            p = nextVQueue(p);
            maillon++;
        }
    }
}


void printQueueContent(queue queue){ // prints the vehicle  of the queue containing at least one item
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
            if (p->head != NULL)
            {
            printf("  Vehicle %d :\n", maillon);
            printf("\t- ID: %d\n", tempVehicle.ID);
            printf("\t- Max capapcity: %d\n", tempVehicle.capacity);  
            printf("\t- Trips Done : %d\n\n",p->Trips);
            printItemList(p->head);
            printf("\n\n");  
            }
            
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
    NodeQueue *NewNode;
    while (pList != NULL) // CREATING THE QUEUES
    {
        allocateVQueue(&NewNode);
        ass_valVQueue(NewNode,valueVehicle(pList));
        if (valueVehicle(pList).Type == 'V')
        {
            enqueueVehicle(VanQ, NewNode);
        }
        else if (valueVehicle(pList).Type == 'M')
        {

            
            enqueueVehicle(MotoQ, NewNode);
        }

        NewNode->Trips = 0;
        pList = nextVehicle(pList);
        
    }
}


void addVehicleAndUpdateQueue(NodeVehicle **head, Vehicle vehicle, queue *MotoQ, queue *VanQ) // Updates the vehicle queue and the vehicle list at the same time
{
    addNewVehicle(head, vehicle);
    NodeQueue* NewNode;
    allocateVQueue(&NewNode);
    ass_valVQueue(NewNode,vehicle);
    if (vehicle.Type == 'M')
    {
        enqueueVehicle(MotoQ, NewNode);
    }
    else if (vehicle.Type == 'V')
    {
        
        enqueueVehicle(VanQ, NewNode);
    }
}

//--------------------------------- END OF FUNCTION LOADING QUEUE ---------------------------------------------

// ------------------------ FUNCTIONS OF PART OF ASSIGNING ITEMS TO VEHICLES ---------------------------------

int min_date(char *date1, char *date2) // returns the minimum date between two dates 
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
    char *mindate = "99-99-99"; // initialises the date at the highest date possible
    NodeItem *q=NULL;
    while (p != NULL)
    {
        if( min_date(mindate, valueItem(p).Date) == 2 && valueItem(p).studied == 0 && valueItem(p).Status == 'A'){
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


bool assignItemsToVehicleQueue(NodeItem *headlist, queue MotoQ, queue VanQ) // this is the main function of the program :
//  IT assigns each Item of the Item list to the corresponding vehicle 
{
    bool isThereAssignedItem= false;
    NodeItem *currentItem = priorItem(headlist);
    
     while (currentItem != NULL)
    {

        if (valueItem(currentItem).weight > 3 || valueItem(currentItem).wilaya != 16) // CASE 01 : THE ITEM GOES TO VanQ
        {
            NodeQueue *pVanQ = VanQ.head; 
                while (pVanQ != NULL && pVanQ->Trips<3)
                {   
                        if (lengthofItemList(pVanQ->head) == 0 || (lengthofItemList(pVanQ->head) < valueVQueue(pVanQ).capacity && valueItem(pVanQ->head).wilaya == valueItem(currentItem).wilaya))
                    {
                         // We assign it to the vehicle if the van is empty or if the current capacity is less then the max cap and that the item goes to the same wilaya
                        (*currentItem).Item.Status = 'D'; // for delivered
                        addNewItem(&pVanQ->head, valueItem(currentItem));
                        pVanQ = NULL;
                        isThereAssignedItem = true;
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
            while (pMotoQ != NULL && pMotoQ->Trips<3)
            {
                if (lengthofItemList(pMotoQ->head) < 2)
                { // We assign it to the vehicle if the Moto is empty or if the current capacity is less then the max cap and that the item goes to the same wilaya
                    (*currentItem).Item.Status = 'D'; // for delivered
                    addNewItem(&pMotoQ->head, valueItem(currentItem));
                    pMotoQ = NULL;
                    isThereAssignedItem = true;
                }
                else
                {
                    pMotoQ = nextVQueue(pMotoQ);
                }
            }

            if (valueItem(currentItem).Status == 'A') // IF THE ITEM CANNOT BE DELIVERED IN MOTO THEN WE TRY IN THE VanQ
            {
                NodeQueue *pVanQ = VanQ.head;
                while (pVanQ != NULL && pVanQ->Trips<3)
                {
                    if (lengthofItemList(pVanQ->head) == 0 || (lengthofItemList(pVanQ->head) < valueVQueue(pVanQ).capacity && valueItem(pVanQ->head).wilaya == valueItem(currentItem).wilaya))
                    { // We assign it to the vehicle if the van is empty or if the current capacity is less then the max cap and that the item goes to the same wilaya
                        (*currentItem).Item.Status = 'D'; // for delivered
                        addNewItem(&pVanQ->head, valueItem(currentItem));
                        pVanQ = NULL;
                        isThereAssignedItem = true;
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
    
    
    NodeItem * p =headlist;
    while (p!= NULL)
    {
        p->Item.studied = 0;
        p=nextItem(p);
    }
    return isThereAssignedItem;

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


void removeItemByadress(NodeItem ** head, NodeItem * p){ // It removes the Item according to  a pointer of the node It is used in the updateItemList Function
    if (p == *head){
        *head = nextItem(p);
        free(p);

    }else{
        NodeItem* q  = * head;
        while(q!= NULL){

        if (nextItem(q) == p) {

            ass_adrItem(q,nextItem(p));
            free(p);
            break;
        }

        q = nextItem(q);

        }
    }
}



void updateItemlist(NodeItem ** head){ // removes items with delivered status after finishing assigning thet Items to the vehicle
    NodeItem * p,*q ;
    p = *head;
    q = NULL;
    

    while (p!=NULL)
    {
        if (valueItem(p).Status=='D')
        {
           removeItemByadress(head,p);
        }
        p =nextItem(p);
    }
    

}





void createReportFile(report report) { // creates a report file at the end of the program
    // Open the file in write mode
    FILE *file = fopen("./Reports/report.txt", "w");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    

    // Print the data into the file in tabular format
    fprintf(file,"\n\n\t\t_____________________________________________________________\n");
    fprintf(file,"\t\t|                                                           |\n");
    fprintf(file,"\t\t|   Initial Items number : %02d Item                          |\n", report.initialItemsNumber);
    fprintf(file,"\t\t|                                                           |\n");
    fprintf(file,"\t\t|   New Items number : %02d Item                              |\n", report.newItems);
    fprintf(file,"\t\t|                                                           |\n");
    fprintf(file,"\t\t|   Total number of Delivered Items : %02d Item               |\n", report.ItemsDelivered);
    fprintf(file,"\t\t|                                                           |\n");
    fprintf(file,"\t\t|   Total number of Returned Items : %02d Item                |\n", report.returnedItems);
    fprintf(file,"\t\t|                                                           |\n");
    fprintf(file,"\t\t|   Total number of cancelled Items : %02d Item               |\n", report.cancelledItems);
    fprintf(file,"\t\t|                                                           |\n");
    fprintf(file,"\t\t|   Final number of Items in the List : %02d Item             |\n", report.finalItemsNumber);
    fprintf(file,"\t\t|                                                           |\n");
    fprintf(file,"\t\t-------------------------------------------------------------\n");
    

    // Close the file
    fclose(file);

    printf("\n\t\t\t\t\t* Report file created successfully! * \n");
}
        
        
        
void updateQueuesAfterDelivery(queue *VanQ, queue * MotoQ){ // Resets the item list of the queues and increments the trips

    Vehicle vehicle;

    NodeQueue * pMoto= (*MotoQ).head;
    NodeQueue * pVan= (*VanQ).head;
    while (lengthofItemList(pMoto->head)>0)
    {
        
        if (lengthofItemList(pMoto->head)>0)
        {
          pMoto->Trips++;
          pMoto =nextVQueue(pMoto);
          enqueueVehicle(MotoQ,dequeueVehicle(MotoQ));
          
        }
        else{
            break;
        }
    }

    while (lengthofItemList(pVan->head)>0)
    {
        
        if (lengthofItemList(pVan->head)>0)
        {
          pVan->Trips++;
          pVan = nextVQueue(pVan);
          enqueueVehicle(VanQ,dequeueVehicle(VanQ)); 
          
        }
        else{
            break;
        }
    }
    
}


bool areItemsRemaining(NodeItem* ItemList){ // verifies if there is still Items to deliver
    NodeItem * p = ItemList;
    while (p!= NULL)
    {
        if (valueItem(p).Status == 'A'){
            return true;
            break;
        }
        p = nextItem(p);
    }
    
    return false;
}

    
 
void page_acceuil() { // Function of the initial Display of the Program 
    system("Cls"); // Effacer l'ecran
    int k ;
    for (k = 0 ; k<10 ; k++ ) {  // Afficher 10 fois le logo de ESI
        if (k % 2 == 0) // Les iterations paires s'afficherent en vert
        system("color 0A");
        if (k % 2 == 1) // Les iterations impaires s'afficherent en cian
        system("color 0B");

        printf("\n\n\n\n\n\n"); // imprimer le logo de ESI
        printf(
            "\t\t\t\t                                              iiii\n"
            "\t\t\t\t                                             i::::i\n"
            "\t\t\t\t                                              iiii\n\n"
            "\t\t\t\t        eeeeeeeeeeee          ssssssssss    iiiiiii\n"
            "\t\t\t\t      ee::::::::::::ee      ss::::::::::s   i:::::i\n"
            "\t\t\t\t     e::::::eeeee:::::ee  ss:::::::::::::s   i::::i\n"
            "\t\t\t\t    e::::::e     e:::::e  s::::::ssss:::::s  i::::i\n"
            "\t\t\t\t    e:::::::eeeee::::::e   s:::::s  ssssss   i::::i\n"
            "\t\t\t\t    e:::::::::::::::::e      s::::::s        i::::i\n"
            "\t\t\t\t    e::::::eeeeeeeeeee          s::::::s     i::::i\n"
            "\t\t\t\t    e:::::::e             ssssss   s:::::s   i::::i\n"
            "\t\t\t\t    e::::::::e            s:::::ssss::::::s i::::::i\n"
            "\t\t\t\t     e::::::::eeeeeeee    s::::::::::::::s  i::::::i\n"
            "\t\t\t\t      ee:::::::::::::e     s:::::::::::ss   i::::::i\n"
            "\t\t\t\t        eeeeeeeeeeeeee      sssssssssss     iiiiiiii\n"
        );

        Sleep(200);     // Attendre 200 ms (0,2 s) a chaque iteration
        system("cls");
    }

    system("cls");  // effacer l'ecran
    printf("\n\t\t\t\033[96m           R%cpublique Alg%crienne D%cmocratique et Populaire           \033[0m\n", 130, 130, 130);
    printf("\t\t\t\033[96m  Minist%cre de l'Enseignement Sup%crieur et de la Recherche Scientifique\033[0m\n", 130, 130);
    printf("\t\t\t      \033[96m _______________________________________________________\n");
    printf("\t\t\t      \033[96m|        \033[92m_______\033[0m    \033[91m _______\033[0m    \033[97m _\033[0m                      \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|  _____|\033[0m   \033[91m|  _____|\033[0m   \033[97m| |\033[0m  \033[92m%ccole nationale\033[0m    \033[96m|\n", 130);
    printf("\t\t\t      \033[96m|       \033[92m| |_____\033[0m    \033[91m| |_____\033[0m    \033[97m| |\033[0m                     \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|  _____|\033[0m   \033[91m|_____  |\033[0m   \033[97m| |\033[0m  \033[91msup%crieure\033[0m         \033[96m|\n", 130);
    printf("\t\t\t      \033[96m|       \033[92m| |_____\033[0m    \033[91m _____| |\033[0m   \033[97m| |\033[0m                     \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|_______|\033[0m   \033[91m|_______|\033[0m   \033[97m|_|\033[0m  \033[97md'informatique\033[0m     \033[96m|\n");
    printf("\t\t\t      \033[96m|_______________________________________________________|\033[0m\n\n");

    printf("\t\t\t\t\033[96m  CPI - 1%cre Ann%ce - Ann%ce Universitaire 2023/2024 \n", 138, 130, 130);
    printf("\t\t\t\033[96m ___________________________________________________________________\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|          REALISED BY:  \033[97mZakaria Benhamiche  && Bouba Yacin\033[96m         |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|               SECTION :  \033[97mB\033[96m          GROUP: \033[97m06\033[96m                     |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|             TP1 :  \033[97mLes listes lin%caires chain%ces\033[96m                  |\n", 130, 130);
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|              <  \033[97mLogiciel de gestion de Livraison\033[96m >                |\n");
    printf("\t\t\t\033[96m|___________________________________________________________________|\n\n\n");


    printf("\t\t\t                            \033[91mS'il vous plait                                 \n");
    printf("\t\t\t          Appuyez sur n'importe quelle touche pour continuer...\033[0m               ");
    getch();

    system("cls");
}

