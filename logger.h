/*
    Author: Khanh Nguyen
    Description: Header file for logger class including data members and functions
    Date: Oct 2, 2022
*/

#ifndef LOGGER_H// include guard
#define LOGGER_H
#include <vector>
#include <sqlite3.h>    //check these 2 if can be deleted
#include "log_message.h"

class logger{
    private:
        string app;
        vector<log_message> result;
        sqlite3* db;

    public:
        logger(string appName);
 
        ~logger();

        void write(string mess);
        
        vector<log_message> read_all();
};

#endif  