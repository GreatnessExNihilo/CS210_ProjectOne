/*
CS-210
Omar Raymond
January 26, 2024
Dr. Adamo
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Clock {
private:
    // variable to store the hours
    int hours; 
    // variable to store the minutes
    int minutes;
    // variable to store the seconds 
    int seconds;
    // variable to check whether to appened AM or PM 
    bool isMorning; 
    
public:
    Clock() {

        //Get current time
        time_t currentTime = time(0);
        tm *localTime = localtime(&currentTime); 

        hours = localTime-> tm_hour; 
        minutes = localTime-> tm_min;
        seconds = localTime-> tm_sec; 
        isMorning = true; 
    }

    //Add hour
    void addHour() {
        // increment the hours, but keep it within 0-23 range
        hours = (hours + 1) % 24; 
        if(hours == 0) {
            if(isMorning) {
                isMorning = false;
            }
            else {
                isMorning = true; 
            }
        }
    }

    // Add minute 
    void addMinute() {
        // increment the minutes, but keep it within 0-59 range
        minutes = (minutes + 1) % 60; 
        
        // increment hour if minute equals 0
        if (minutes == 0) {
            addHour(); 
        }
    }

    // Add second
    void addSecond() {
        // increment the seconds, but keep it within 0-59 range
        seconds = (seconds + 1) % 60; 
        // increment minute if second equals 0
        if (seconds == 0) {
            addMinute(); 
        }
    }

    void displayClocks() {
        string extraSpace;
        
        string prependHourWithZero = "";
        string minuteSeparator;
        string secondSeparator;

        if (hours >= 0 && hours <= 9) {
            prependHourWithZero = "0";
        }
        //Prepend 0 to minute section of clock if greater than or equal to 0 and less that or equal to 9
        if(minutes >= 0 && minutes <= 9) {
            minuteSeparator = ":0";
        } 
        else {
            minuteSeparator = ":";
        }
        
        //Prepend 0 to second section of clock if greater than or equal to 0 and less that or equal to 9 
        if(seconds >= 0 && seconds <= 9) {
            secondSeparator = ":0";
        } 
        else {
            secondSeparator = ":";
        }
        
        //Adds white space between AM and PM when hours >= 10 and <= 12 to keep * format
        if (hours >= 10 && hours <= 12) {
            extraSpace = "";
        }
        else {
            extraSpace = " ";
        }

        //12 hour clock display
        cout << "\n****************************    **************************\n";
        cout << "*        12hr Clock        *    *        24hr Clock      *               \n";
        cout << "*        ";
        int hour = (hours % 12 == 0) ? 12 : hours % 12; 
        cout << hour << minuteSeparator << minutes << secondSeparator << seconds;

        //Append AM or PM depending on time of day
         if(isMorning) { 
                cout << extraSpace << "AM";
        }
        else {
                cout << extraSpace << "PM";
        }
        cout << "        *";

        //24 hour clock display
        cout << "\t";
        cout << "*        ";
        cout << prependHourWithZero << hours << minuteSeparator << minutes << secondSeparator << seconds;

        cout << "        *";
        cout << "\n****************************    **************************\n";
    }
};

//Display user selection menu
void displayMenuOptions() {
        cout << "\n*************************\n";
        cout << "* 1 - Add One Hour\t*\n";
        cout << "* 2 - Add One Minute\t*\n";
        cout << "* 3 - Add One Second\t*\n";
        cout << "* 4 - Exit Program\t*\n";
        cout << "*************************\n";
    }

int main() {
    Clock clock;

    while (true) {
    
        clock.displayClocks();

        displayMenuOptions();

        cout << "What is your selection? "; 
        int userSelection;
        cin >> userSelection;

        if (userSelection == 1) { 
            //Increment hour when user enters 1
            clock.addHour();
            cout << "You entered " << userSelection <<" and added 1 hour to the clock." << endl;
        }
        else if (userSelection == 2) {
            //Increment minute when user enters 2
            clock.addMinute();
            cout << "You entered " << userSelection <<" and added 1 mintue to the clock." << endl;

        }
        else if (userSelection == 3) {
            //Increment second when user enters 3
            clock.addSecond();
            cout << "You entered " << userSelection <<" and added 1 second to the clock." << endl;

        }
        else if (userSelection == 4) {
            //Quit program if user enters 4
            return 0;
        }
        else {
            // Tell user input is invalid and clear and ignore value entered to stop unending loop.
            cout << "\nInvalid Input. Enter a value between 1 and 4!" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return 0;
}
