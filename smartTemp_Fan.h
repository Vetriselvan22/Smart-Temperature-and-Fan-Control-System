#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>

struct  address
{
    float history[5];
    float temperature , maximum_temp , minimum_temp , average_temp;
    int speed , history_count, overheating;
    char status[5] , alarm[5];
};

void read_temperature(struct address *temperature);
void Display_status(struct address *current_status);
int calculate_fan_speed(float temperature);
void control_Fan(int speed,struct address *control_fan_status);
void temperature_history(struct address *History);
void temp_save_history(struct address *temperature);
void Aver_temperature(struct address *Aver_temp);
void Min_temperature(struct address *Min_temp);
void  Max_temperature(struct address *Max_temp);
void Overheating_event(struct address *Events);
void Reset_system(struct address *System_reset);
void Save_Exit(struct address *save);
void load_detials(struct address *load);

#endif