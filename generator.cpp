/*
    Author: Khanh Nguyen
    Description: generator app that takes log messages and then create a logger class, store 
        log messages randomly into database, go to sleep and then repeat until there's no message left
    Date: Oct 2, 2022
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <signal.h>
#include <regex>
using namespace std;
#include "logger.h"
#include "log_message.h"

/*
    Name: signalHandler
    Description: helps to terminate the program when the user input Ctrl+c
    Parameters: signum
    Return: none
*/
void signalHanler(int signum) {
    cout << "Program terminating" << endl;
    exit(signum);
}

/*
    Name: main
    Description: Take log messages, store them into the database
    Parameters: number of arguments and strings of log messages
    Return: none
*/
int main(int argc, char *argv[]) {
    //cout << "You input " << argc-1 << " messages:" << endl;
    string appName = argv[0];
    appName = regex_replace( appName,regex("./|\\r\\n|\\r|\\n"),"");
    //store messages from input
    vector<string> messages;
    for (int i = 1; i < argc; ++i) {
        messages.push_back(argv[i]);
    }
    
    //if every message has been read, terminate
    signal(SIGABRT, signalHanler);
    while (!messages.empty()){
        //get random message
        int randomInt = rand() % messages.size();
        //create logger object
        logger store(appName);
        store.write(messages[randomInt]);
        //remove the message after having been stored
        messages.erase(messages.begin()+randomInt);
        sleep(2);
    }
}