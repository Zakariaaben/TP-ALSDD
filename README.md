# Management System For Deliveries

This Program aims to do a realistic simulation of a System managing Deliveries, with restrictions and priorities to optimize the deliveries.

<br/><br/>

# How to start the program ?

#### You only have to download the folder, unzip it open the "main.c" file and run it from the IDE You like (VS-Code, CodeBlocks ...) !

<br/><br/>

# How It Works ?

## General Overview of the Data Structure


<table>
<tr>
<th style="font-size:24px">  Item and Vehicle Structure : </th>
<th style="font-size:24px"> Vehicle Queue:</th>
</tr>
<tr>
<td style="display:flex;justify-content:space-evenly;align-items:center;">

<div style="margin-bottom:57px">
  
  ```
      struct  Item{
        int  ID;
        int  studied;
        char  Date[10];
        int  wilaya;
        int  weight;
        char  Status;
      }Item;
  ```
</div>
<div >

```
      struct  Vehicle{
          char  Type;
          int ID;
          int  capacity;
      } Vehicle;
```
</div>

</td>
<td  >



<div style="display:flex;justify-content:center;margin-bottom:40px">

  ```
  struct NodeQueue{
    Vehicle  Vehicle
    int  Trips;
    NodeItem  *head;
    struct  NodeQueue  *  next;
  }NodeQueue;
  ```
</div>

<div style="width:80%; margin-left:100px">

>each node of this queue contains a vehicle and list of items assigned to this one
</div>


</td>
</tr>
</table>



  



## Functionnalities 
   - #### MAIN MENU
![](https://i.ibb.co/qmwCKhC/Screenshot-2024-04-11-203229.png)
> Main Menu

<br/>

- ### Manage List And Queues
![](https://i.ibb.co/8g6QfPh/Screenshot-2024-04-11-203543.png)
> Managing list and queues Sub-Menu
<br/>

- ### Assigning Items process
  - After Creating the list of Items and the vehicles **which are fetched from the files "Vehicles.txt" and "Items.txt"**, launching the delievries will try to assign the remaining Items to a vehicle, the vehicles according to a number of conditions. After that, the user decides if there will be some returns (Due to simulation).
<br/>
  -  Finally all the items that weren't returned will be delivered/removed from the list of the Items, and the other's status will be at  " **R** ".

<br/>

- ### Simulate end of the day 

At each use of this option three reports will be created following the current **state** (*advancement*) of the program

  > Report.txt: This file contains a general summarize of the program such as "Number of Items delivered", "Number of Returns" and more.

  > ItemReport.txt: This file contains the Items at the exact  moment simulating the end of the day
  
  > VehicleReport.txt: This file contains the Vehicles at the exact moment simulating the end of the day


<br/><br/><br/>


# ⚠️  **Warning:** Avoid any change in files 

<p style="text-align:end ;margin-right:20px; margin-top:100px"> 
&copy; Zakaria Benhamiche
</div>







