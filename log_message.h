/*
    Author: Khanh Nguyen
    Description: header file for log message objects that includes data members and functions 
    Date: Oct 2, 2022
*/

#ifndef LOGMESSAGE_H// include guard
#define LOGMESSAGE_H


class log_message{
    private:
        string message;
        string timestamp;

    public:
        log_message(string inpTime, string inpMess);
 
        ~log_message();

        string get_message();

        string get_timestamp();
};

#endif