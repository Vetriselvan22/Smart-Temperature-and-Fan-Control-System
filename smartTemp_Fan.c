#include "smartTemp_Fan.h"

//This function is to read the temperature
void read_temperature(struct address *Temperature)
{
    float tempervery_temp;
    int tempervery_speed;

    printf("Enter the temperature : ");
    scanf("%f",&tempervery_temp);
    getchar();

    if((tempervery_temp > -50) && (tempervery_temp < 150))
    {
        tempervery_speed = calculate_fan_speed(tempervery_temp);
        control_Fan(tempervery_speed,Temperature);

        Temperature->temperature = tempervery_temp;
        Temperature->speed = tempervery_speed;
        temp_save_history(Temperature);

        if(tempervery_speed == 100)
        {
            Temperature->overheating++;
        }
    }
    else
    {
        printf("Temperacter should be above -50 C  and below 150 C\n");
        return;
    }
}

//This function  for display the status
void Display_status(struct address *current_status)
{
    if(current_status->history_count > 0 )
    {
    printf("====SYSTEM CURRENT STATUS====\n");
    printf("Temperature   :%g C\n",current_status->temperature);
    printf("Fan Status    :%s\n",current_status->status);
    printf("Fan Speed     :%d%%\n",current_status->speed);
    printf("Alarm         :%s\n",current_status->alarm);
    }
    else
    {
        printf("====No ANY CURRENT STATUS====\n");
    }

    if(current_status->speed >= 100)
    {
        printf("WARNING: HIGH TEMPERATURE!\n");
    }
}

//This Function for calculate the speed
int calculate_fan_speed(float temperature)
{
    int speed_moniter;

    if(temperature < 25)
    {
        speed_moniter = 0;
    }
    else if(temperature >= 25 && temperature <= 34)
    {
        speed_moniter = 30;
    }
    else if(temperature >= 35 && temperature <= 44)
    {
        speed_moniter = 60;
    }
    else if(temperature >=45 && temperature <= 54 )
    {
        speed_moniter = 80;
    }
    else
    {
        speed_moniter = 100;
    }

    return speed_moniter;
}

//This function for control fan (ON or OFF ) to alarm and fan 
void control_Fan(int speed,struct address *control_fan_status)
{
    if(speed == 0)
    {
        strcpy(control_fan_status->status,"OFF");
        strcpy(control_fan_status->alarm,"OFF");
    }
    else if(speed == 30 || speed == 60 || speed == 80)
    {
        strcpy(control_fan_status->status,"ON");
        strcpy(control_fan_status->alarm,"OFF");       
    }
    else if(speed > 60)
    {
        strcpy(control_fan_status->status,"ON");
        strcpy(control_fan_status->alarm,"ON");
    }
}

//This function for store the history of temperature
void temp_save_history(struct address *temperature)
{
    int i,j;

    for(i = temperature->history_count ; i == temperature->history_count ; i++)
    {
        if(temperature->history_count >= 5)
        {
            for(j = 0 ; j < 4 ; j++)
            {
             temperature->history[j] = temperature->history[j+1];               
            }
            temperature->history[4] = temperature->temperature;
        }
        else
        {
            temperature->history[i] = temperature->temperature;
        }
    }
    temperature->history_count++;
}

//This function for display the previous search history of temperature
void temperature_history(struct address *History)
{
    History->history_count == 0?printf("===NO PREVIOUS TEMPERATURE HISTORY===\n"):printf("==== Temperature History ====\n");
    for(int i = 0 ; i < History->history_count ; i++)
    {
        if(i == 5)
        {
            break;
        }
        else
        {
             printf("%d  %g C\n",i+1,History->history[i]);
        }
    }
}

//This function for display the Maximum temperature in search history
void  Max_temperature(struct address *Max_temp)
{
    Max_temp->maximum_temp = Max_temp->history[0];;

    for(int i = 0; i < Max_temp->history_count ;i++)
    {
        if(i == 5)
        {
            break;
        }
        else if(Max_temp->maximum_temp < Max_temp->history[i])
        {
            Max_temp->maximum_temp = Max_temp->history[i];
        }
    }

    Max_temp->maximum_temp == 0 ?printf("===NO PREVIOUS TEMPERATURE HISTORY===\n"):printf("--> Viewing Maximum Temperature = %g C\n",Max_temp->maximum_temp);
}

//This function for display the minimum temperature in search history
void Min_temperature(struct address *Min_temp)
{
    Min_temp->minimum_temp = Min_temp->history[0];;

    for(int i = 0; i < Min_temp->history_count ;i++)
    {
        if(i == 5)
        {
            break;
        }
        else if(Min_temp->minimum_temp > Min_temp->history[i])
        {
            Min_temp->minimum_temp = Min_temp->history[i];
        }
    }

    Min_temp->minimum_temp == 0?printf("===NO PREVIOUS TEMPERATURE HISTORY===\n"):printf("--> Viewing Minimum Temperature = %g C\n",Min_temp->minimum_temp);
}

//This function for display the average temperature in search history
void Aver_temperature(struct address *Aver_temp)
{
    float sum_temp=0;
    int i;
    for( i = 0; i < Aver_temp->history_count ;i++)
    {
        if(i == 5)
        {
            break;
        }
        else
        {
            sum_temp += Aver_temp->history[i];
        }
    }

    if(i >= 5)
    Aver_temp->average_temp = (sum_temp/5.0);
    else
    Aver_temp->average_temp = (sum_temp/(i));

    Aver_temp->average_temp == 0 ?printf("===NO PREVIOUS TEMPERATURE HISTORY===\n"):printf("--> Viewing Average Temperature = %g C\n",Aver_temp->average_temp);
}

//This function for display the overheating events
void Overheating_event(struct address *Events)
{
    Events->overheating == 0?printf("===THERE IS NO OVER HEATING EVENTS===\n"):printf("===OVERHEATING EVENTS IN HISTORY===\n");

    if(Events->overheating > 0)
    {
    printf("Overheating Events  : %d\n",Events->overheating);
    printf("Current Temperature : %g C\n",Events->temperature);
    printf("Fan Speed           : %d%%\n",Events->speed);
    printf("Alarm Status        : %s\n",Events->alarm);
    }
}

void Reset_system(struct address *System_reset)
{
    int reset,i;
    printf("Are you sure you want to reset the system?\n");
    printf("1. YES\n2. NO\nEnter the number : ");
    scanf("%d",&reset);
    getchar();

    if(reset == 1)
    {
        System_reset->temperature = 0; 
        System_reset->maximum_temp = 0; 
        System_reset->minimum_temp = 0;
        System_reset->average_temp = 0;
        System_reset->speed =0 ;
        System_reset->history_count = 0;
        System_reset->overheating =0;
        System_reset->status[0] = '\0'; 
        System_reset->alarm[0] = '\0';
        for(i=0 ;i < 5 ;i++)
        {
            System_reset->history[i] = 0 ;
        }

        printf("System reset completed successfully.\n");
    }
    else
    {
        printf("The system reset process has been terminated\n");
    }
}

void Save_Exit(struct address *save)
{
    FILE *fp = fopen("database.csv","w");

    fprintf(fp,"%f,%d,%d,%d,%s,%s\n",save->temperature,save->speed,save->history_count,save->overheating,save->status,save->alarm);

    for(int i=0;i<save->history_count;i++)
    {
        fprintf(fp,"%f,",save->history[i]);
    }

    fclose(fp);
}

void load_detials(struct address *load)
{
    FILE *fp=fopen("database.csv","r");

    if(fp == NULL)
    {
        return;
    }
    fscanf(fp,"%f,%d,%d,%d,%[^,],%[^\n]\n",&load->temperature,&load->speed,&load->history_count,&load->overheating,load->status,load->alarm);

    for(int i=0;i<load->history_count;i++)
    {
        fscanf(fp,"%f,",&load->history[i]);
    }

    fclose(fp);
}