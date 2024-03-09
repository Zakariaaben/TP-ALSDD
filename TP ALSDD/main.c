#include <stdio.h>
#include <stdlib.h>
#include "LibFunctions.c"


int main(){
    NodeVehicle *listVehicle = NULL;

    loadVehicleListFromfile(&listVehicle, "./Vehicles.txt");
    printVehicleList(listVehicle);
    printf("\n\n");

    queue MotoQ, VanQ;
    createQueuesFromList(listVehicle, &MotoQ, &VanQ);

    printVehicleList(MotoQ.head);
    printf("\n\n");
    printVehicleList(VanQ.head);
    printf("\n\n");
    Vehicle vehicle = {.ID = 15, .Type = 'V', .capacity = 12345 };
    addVehicleAndUpdateQueue(&listVehicle,vehicle,&MotoQ,&VanQ);
    printVehicleList(MotoQ.head);
    printf("\n\n");
    printVehicleList(VanQ.head);
    return 0;
}