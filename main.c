#include "smartTemp_Fan.h"


int main()
{
    struct address smarttemp_fan;
    smarttemp_fan.history_count=0;
    smarttemp_fan.maximum_temp=0;
    smarttemp_fan.minimum_temp=0;
    smarttemp_fan.average_temp=0;
    smarttemp_fan.overheating=0;
    smarttemp_fan.speed=0;
    strcpy(smarttemp_fan.status,"OFF");
    strcpy(smarttemp_fan.alarm,"OFF");

    load_detials(&smarttemp_fan);
    int choice;

    printf("\n=== SMART TEMPERATURE AND FAN CONTROL SYSYTEM ===\n\n");
    printf("1. Enter Temperature(Automatic Mode)\n");
    printf("2. Display System Status\n");
    printf("3. View Temperature History\n");
    printf("4. Show Maximum Temperature\n");
    printf("5. Show Minimum Temperature\n");
    printf("6. Show Average Temperature\n");
    printf("7. Over Heating Events\n");
    printf("8. Reset The System\n");
    printf("9. Save and Exit \n");

    do
    {
       printf("Enter your choice : ");
       scanf("%d",&choice);
       getchar();

        switch(choice)
        {
            case 1:
            printf("Mode : AUTOMATIC\n");
            read_temperature(&smarttemp_fan);
            break;
            case 2:
            Display_status(&smarttemp_fan);
            break;
            case 3:
            temperature_history(&smarttemp_fan);
            break;
            case 4:
            Max_temperature(&smarttemp_fan);
            break;
            case 5:
            Min_temperature(&smarttemp_fan);
            break;
            case 6:
            Aver_temperature(&smarttemp_fan);
            break;
            case 7:
            Overheating_event(&smarttemp_fan);
            break;
            case 8:
            Reset_system(&smarttemp_fan);
            break;
            case 9:
            Save_Exit(&smarttemp_fan);
            printf("...Information Saved and Exited...\n");
            break;
            default:
            printf("Invalid Input\n");
        }

    }while(choice != 9);
}