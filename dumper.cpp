/*
    Author: Khanh Nguyen
    Description: dumper app that receive an input of an app name, then create a logger
        class then store all of the log messages into a vector of string, then print it out
    Date: Oct 2, 2022
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <signal.h>
using namespace std;
#include "logger.h"
#include "log_message.h"

/*
    Name: main
    Description: retrieve message from the database by creating a logger and then print the log messages with its timestamp
    Parameters: number of arguments and the name of the app to retrieve data
    Return: none
*/
int main(int argc, char *argv[]) {
    vector<log_message> allLog;

    string appName = argv[1];
    logger retrieve(appName);
    allLog = retrieve.read_all();
    

    for (int i=0; i<allLog.size(); i++){
        cout << allLog[i].get_timestamp() << ": " << allLog[i].get_message() << endl;
    }


}