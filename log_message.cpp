/*
    Author: Khanh Nguyen
    Description: Implementation file for log message class that contains functions, constructor and destructor
    Date: Oct 2, 2022
*/

#include <iostream>
#include <ctime>
using namespace std;
#include "log_message.h"
#include "logger.h"

/*
    Name: log_message
    Description: constructor, set timestamp and message passed 
    Parameters: Time and Message 
    Return: none
*/
log_message::log_message(string inpTime, string inpMess){
    timestamp = inpTime;
    message = inpMess;
}

/*
    Name: ~log_message
    Description: Destructor, tear down the object
    Parameters: noen
    Return: none
*/
log_message::~log_message(){

}

/*
    Name: get_message
    Description: function to retrieve message of the object
    Parameters:none
    Return: message of the object
*/
string log_message::get_message(){
    return message;
}

/*
    Name: get_timestamp
    Description: function to retrieve timestamp of the object
    Parameters: none
    Return: timestamp of the object
*/
string log_message::get_timestamp(){
    return timestamp;
}


