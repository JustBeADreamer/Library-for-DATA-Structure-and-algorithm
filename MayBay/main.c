#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>


typedef struct plane {
    char FlightNumber[10];
    int WaitingTime, ServingTime, gate;
    struct plane * next;
} Plane;

typedef struct {
    Plane * front, * rear;
    int totalWaitingTime;
    //bool free;
} Queue;


//bai 1
void Initialize(Queue * q) {
    q->front = q->rear = NULL;
    q->totalWaitingTime = 0;
    //q->free = true;
}

int isEmpty(Queue * q) {
    return (q->rear == NULL) && (q->front == NULL);
}

void push(Queue * q, char * FlightNumber, int ServingTime) {    //push each flight to right terminal and increase total waiting time
    if(isEmpty(q)) {
        q->front = q->rear = (Plane *) malloc(sizeof(Plane));

        strcpy(q->front->FlightNumber, FlightNumber);
        q->front->WaitingTime = 0;      
        q->totalWaitingTime = ServingTime;      //next plane will have to wait for q->totalWaitingTime
        q->front->next = NULL;

        q->rear = q->front;
    }
    else {
        q->rear->next = (Plane *) malloc(sizeof(Plane));
        q->rear = q->rear->next;
        
        strcpy(q->rear->FlightNumber, FlightNumber);
        q->rear->ServingTime = ServingTime;
        q->rear->WaitingTime = q->totalWaitingTime;

        q->totalWaitingTime = q->rear->WaitingTime + ServingTime;   //next plane will have to wait for q->totalWaitingTime
    }
}



int getMinimumTimeToObtainTrueGate(Queue Terminal[]) {
    int priorityPos = 0;
    int min = INT_MAX;
    
    for(int i = 0; i < 3; i++) {
        if(Terminal[i].totalWaitingTime < min) {
            min = Terminal[i].totalWaitingTime;
            priorityPos = i;
        }
    }
    return priorityPos;
}

//bai 2

Plane * AddNewFlight(Plane * firstFlight, char * FlightNumber, int WaitingTime, int ServingTime, int gate) {
    Plane * newNode = (Plane *) malloc(sizeof(Plane));
    strcpy(newNode->FlightNumber, FlightNumber);
    newNode->WaitingTime = WaitingTime;
    newNode->ServingTime = ServingTime;
    newNode->gate = gate;
    newNode->next = NULL;

    if(firstFlight == NULL) {
        firstFlight = newNode;
    }
    else {
        Plane * currentFlight = firstFlight;
        while(currentFlight->next != NULL) {
            currentFlight = currentFlight->next;
        }
        currentFlight->next = newNode;
    }
    return firstFlight;
}

void PrintInformationOfPlanes(Plane * firstFlight) {
    if(firstFlight == NULL) {
        printf("NO INFORMATION TO BE PRINTED\n");
    }
    else {
        Plane * currentFlight = firstFlight;
        printf("Flight No.\tGate\tWaiting time\tServing time\n");
        while(currentFlight != NULL) {
            printf("%s\t\t%d\t%d\t\t%d\n", currentFlight->FlightNumber, currentFlight->gate, currentFlight->WaitingTime, currentFlight->ServingTime);
            currentFlight = currentFlight->next;
        }
    }
}

//ex 3
Plane * SearchForFlight(Plane * firstFlight) {
    char search_code[10];
    printf("Input searched number: ");
    scanf("%s", search_code);

    Plane * current = firstFlight;
    for(current = firstFlight; current != NULL; current = current->next) {
        if(strcmp(current->FlightNumber, search_code) == 0) {
            return current;
        }
    }
}

//ex4
void CountingMinuteForTakingLuggage(Plane * firstFlight) {
    // 5 * (n - X);
    Plane * FlightNeededForTakingPassage = NULL;

    do {
        FlightNeededForTakingPassage = SearchForFlight(firstFlight);
    } while(FlightNeededForTakingPassage == NULL);

    int numberOfLuggages;
    printf("Number of luggages: ");
    scanf("%d", &numberOfLuggages);

    int passenger;
    do {
        printf("\nInput the code of passenger: ");
        scanf("%d", &passenger);
    } while(passenger <= 0 || passenger > numberOfLuggages);

    printf("Time need = %d\n", 5 * (numberOfLuggages - passenger));
}


int main ()
{
    Queue Terminal[3];
    for(int i = 0; i < 3; i++) {
        Initialize(&(Terminal[i]));
        printf("%d\n", Terminal[i].totalWaitingTime);
    }
    Plane * firstFlight = NULL;


    int choice;
    do {
        do {
            printf("\n\n\tMENU\n");
            printf("1. Print out information\n");
            printf("2. Print information of each plane\n");
            printf("3. Search flight number\n");
            printf("4. Counting time for taking luggages\n");
            printf("0. Quit\n");
            
            printf("Your choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                char FlightNumber[10];
                int ServingTime;

                FILE * a = fopen("gaterequest.txt", "r");

                if(a != NULL) {
                    int gate = -1;
                    firstFlight = NULL; 

                    while(fscanf(a, "%s %d", FlightNumber, &ServingTime) != EOF) {
                        if(ServingTime > 30) {
                            printf("Please re-input the waiting time of flight %s\n", FlightNumber);
                            return 0;
                        }
                        printf("%s %d\n", FlightNumber, ServingTime);
                        
                        gate = getMinimumTimeToObtainTrueGate(Terminal);        //get the right gate
                        push(&Terminal[gate], FlightNumber, ServingTime);

                        //after pushing to terminal, create a linked list in data type Plane to store the information, used for ex.2
                        firstFlight = AddNewFlight(firstFlight, FlightNumber, Terminal[gate].rear->WaitingTime, ServingTime, gate + 1);
                    }
                }
                else {
                    printf("Can not open file to read");
                }
                fclose(a);
            }
            else if(choice == 2) {
                //traverse the linked list
                PrintInformationOfPlanes(firstFlight);
            }
            else if(choice == 3) {
                Plane * searchFlight = SearchForFlight(firstFlight);
                if(searchFlight == NULL) {
                    printf("NO RESULT FOUND\n");
                }
                else {
                    printf("Flight No.\tGate\tWaiting time\tServing time\n");
                    printf("%s\t\t%d\t%d\t\t%d\n", searchFlight->FlightNumber, searchFlight->gate, searchFlight->WaitingTime, searchFlight->ServingTime);
                }
            }
            else if(choice == 4) {
                CountingMinuteForTakingLuggage(firstFlight);
            }
        } while(choice != 0);
    } while(choice < 0 && choice > 4);  

    return 0;  
}

