#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H

void allocateItem(NodeItem **);
NodeItem *nextItem(NodeItem *);
void ass_adrItem(NodeItem *, NodeItem *);
void ass_valItem(NodeItem *, Item);
Item valueItem(NodeItem *);
void createItem(Item *);
void addNewItem(NodeItem **, Item);
void printItem(Item);
void printItemList(NodeItem *);
int deleteItemByID(NodeItem **, int);
int lengthofItemList(NodeItem *);
void loadItemListFromfile(NodeItem **, char *);
void allocateVehicle(NodeVehicle **);
NodeVehicle *nextVehicle(NodeVehicle *);
void ass_adrVehicle(NodeVehicle *, NodeVehicle *);
void ass_valVehicle(NodeVehicle *, Vehicle);
Vehicle valueVehicle(NodeVehicle *);
void createVehicle(Vehicle *);
void addNewVehicle(NodeVehicle **, Vehicle);
int deleteVehicleByID(NodeVehicle **, int);
void printVehicleList(NodeVehicle *);
void loadVehicleListFromfile(NodeVehicle **, char *);
void allocateVQueue(NodeQueue **);
NodeQueue *nextVQueue(NodeQueue *);
void ass_adrVQueue(NodeQueue *, NodeQueue *);
void ass_valVQueue(NodeQueue *, Vehicle);
Vehicle valueVQueue(NodeQueue *);
NodeQueue * enqueueVehicle(queue *, Vehicle);
int dequeueVehicle(queue *, Vehicle *);
void printVehicleQueue(queue);
void createQueuesFromList(NodeVehicle *, queue *, queue *);
void addVehicleAndUpdateQueue(NodeVehicle **, Vehicle, queue *, queue *);
int min_date(char *, char *);
NodeItem *priorItem(NodeItem *);
void assignItemsToVehicleQueue(NodeItem *, queue, queue);
int setReturn(NodeItem *, int);
void removeItemByadress(NodeItem **, NodeItem *);
void updateItemlist(NodeItem **);

// void assignItemsToVehicleQueue(NodeItem *, queue, queue);

#endif //LIBFUNCTIONS_H