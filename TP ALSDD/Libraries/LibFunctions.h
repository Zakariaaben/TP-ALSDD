#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H

void allocateItem(NodeItem **);
NodeItem *nextItem(NodeItem *);
void ass_adrItem(NodeItem *, NodeItem *);
void ass_valItem(NodeItem *, Item);
Item valueItem(NodeItem *);
bool ItemIdexists(NodeItem *, int);
void createItem(Item *, NodeItem *);
void addNewItem(NodeItem **, Item);
void printItem(Item);
void printItemList(NodeItem *);
int deleteItemByID(NodeItem **, int);
int lengthofItemList(NodeItem *);
void loadItemListFromfile(NodeItem **, char *);
void loadfilefromItemlist(NodeItem *);
void allocateVehicle(NodeVehicle **);
NodeVehicle *nextVehicle(NodeVehicle *);
void ass_adrVehicle(NodeVehicle *, NodeVehicle *);
void ass_valVehicle(NodeVehicle *, Vehicle);
Vehicle valueVehicle(NodeVehicle *);
bool VehicleIdexists(NodeVehicle *, int);
void createVehicle(Vehicle *, NodeVehicle *);
void addNewVehicle(NodeVehicle **, Vehicle);
int deleteVehicleByID(NodeVehicle **, int);
void printVehicle(Vehicle);
void printVehicleList(NodeVehicle *);
void loadVehicleListFromfile(NodeVehicle **, char *);
void loadfilefromvehiclelist(NodeVehicle *);
void allocateVQueue(NodeQueue **);
NodeQueue *nextVQueue(NodeQueue *);
void ass_adrVQueue(NodeQueue *, NodeQueue *);
void ass_valVQueue(NodeQueue *, Vehicle);
Vehicle valueVQueue(NodeQueue *);
void enqueueVehicle(queue *, NodeQueue *);
NodeQueue * dequeueVehicle(queue *);
void printVehicleQueue(queue);
void printQueueContent(queue);
void createQueuesFromList(NodeVehicle *, queue *, queue *);
void addVehicleAndUpdateQueue(NodeVehicle **, Vehicle, queue *, queue *);
int min_date(char *, char *);
NodeItem *priorItem(NodeItem *);
bool assignItemsToVehicleQueue(NodeItem *, queue, queue);
int setReturn(NodeItem *, int);
void removeItemByadress(NodeItem **, NodeItem *);
void updateItemlist(NodeItem **);
void createReportFile(report);
void updateQueuesAfterDelivery(queue *, queue *);
bool areItemsRemaining(NodeItem *);
void page_acceuil();

#endif //LIBFUNCTIONS_H