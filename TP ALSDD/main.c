#include <stdio.h>
#include <stdlib.h>
#include "LibFunctions.c"


int main(){
    NodeVehicle *listVehicle = NULL;

    loadVehicleListFromfile(&listVehicle, "./Vehicles.txt");

    
    printVehicleList(listVehicle);
    printf("\n\n");

    int id;
    printf("\n Enter  the ID of a vehicle to delete it: ");
    scanf("%d", &id);

    if (deleteVehicleByID(&listVehicle, id) == 0){
        printVehicleList(listVehicle);
    }else{
        printf("This ID doesn't exist");
    }

    
    return 0;
}