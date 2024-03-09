#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    int ID;
    char Date[10];
    int wilaya;
    int weight;
    char Status; // A for Awaiting and R for Returned
}Item;

typedef struct Vehicle{
    char Type; // V for Van and M for Motorcycle
    int ID;
    int capacity;
} Vehicle;



typedef struct NodeItem{ // Node of a  linked list containing Item data type
    Item Item;
    struct NodeItem *link;
} NodeItem;



typedef struct NodeVehicle{ // Node of a linked list containing Vehicle data type
    Vehicle Vehicle;
    int itemsCarried;
    int wilayaOfDeliver;
    struct NodeVehicle *link;
} NodeVehicle;



typedef struct queue{
    NodeVehicle *head;
    NodeVehicle *tail;
}queue;




