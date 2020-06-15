#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

using namespace std;

class Time{
    int hours;
    int minutes;
    int seconds;
public:
    Time(){
        hours = minutes = seconds = 0;
    }
    Time(int hours, int minutes, int seconds){
        setHours(hours);
        setMinutes(minutes);
        setSeconds(seconds);
    }
    void setHours(int hours){
        if(hours > 23){
            cout << "Invalid value for hours. Keep the value within 0 to 23.\n";
            cin >> hours;
        }
        this->hours = hours;
    }
    void setMinutes(int minutes){
        if(minutes > 59){
            cout << "Invalid value for minutes. Keep the value within 0 to 59.\n";
            cin >> minutes;
        }
       this->minutes = minutes;
    }
    void setSeconds(int seconds){
        if(seconds > 59){
            cout << "Invalid value for seconds. Keep the value within 0 to 59.\n";
            cin >> seconds;
        }
        this->seconds = seconds;
    }

    void displayWatch(){
        system("clear");
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    void getTime(){
        for(int i=0; i<=25332514525; i++){
            seconds++;
            if(seconds > 59){
                seconds = 0;
                minutes++;
            }
            if (minutes > 59)
            {
                minutes = 0;
                hours++;
            }
            if (hours > 23)
            {
                seconds = 0;
                minutes = 0;
                hours = 0;
            }
            sleep(1);
            displayWatch();
        }
    }

    int getHours(){
        return hours;
    }
    int getMinutes(){
        return minutes;
    }
    int getSeconds(){
        return seconds;
    }

};

int main()
{
    int hours, minutes, seconds;
    cout << "Enter time in HH:MM:SS format.\n";
    cin >> hours >> minutes >> seconds;
    Time dobj(hours, minutes, seconds);
    dobj.getTime();
}