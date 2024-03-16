#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H

void allocateItem(NodeItem **);
NodeItem *nextItem(NodeItem *);
void ass_adrItem(NodeItem *, NodeItem *);
void ass_valItem(NodeItem *, Item);
Item valueItem(NodeItem *);
void addNewItem(NodeItem **, Item);
void printItem(Item);
void printItemList(NodeItem *);
int lengthofItemList(NodeItem *);
void loadItemListFromfile(NodeItem **, char *);
void allocateVehicle(NodeVehicle **);
NodeVehicle *nextVehicle(NodeVehicle *);
void ass_adrVehicle(NodeVehicle *, NodeVehicle *);
void ass_valVehicle(NodeVehicle *, Vehicle);
Vehicle valueVehicle(NodeVehicle *);
void addNewVehicle(NodeVehicle **, Vehicle);
int deleteVehicleByID(NodeVehicle **, int);
void printVehicleList(NodeVehicle *);
void loadVehicleListFromfile(NodeVehicle **, char *);
void allocateVQueue(NodeQueue **);
NodeQueue *nextVQueue(NodeQueue *);
void ass_adrVQueue(NodeQueue *, NodeQueue *);
void ass_valVQueue(NodeQueue *, Vehicle);
Vehicle valueVQueue(NodeQueue *);
void enqueueVehicle(queue *, Vehicle);
int dequeueVehicle(queue *, Vehicle *);
void printVehicleQueue(queue);
void createQueuesFromList(NodeVehicle *, queue *, queue *);
void addVehicleAndUpdateQueue(NodeVehicle **, Vehicle, queue *, queue *);
int min_date(char *, char *);
NodeItem *priorItem(NodeItem *);

// void assignItemsToVehicleQueue(NodeItem *, queue, queue);

#endif //LIBFUNCTIONS_H