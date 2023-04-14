/*
    Author: Khanh Nguyen
    Description: Implementation file for header class containing functions of the class logger
    Date: Oct 2, 2022
*/

#include <iostream>
using namespace std;
#include <sqlite3.h> 
#include <ctime>
#include <regex>
#include "logger.h"
#include "log_message.h"




/*
    Name: logger
    Description: Constructor, initialize the object, set name of the app and open database
    Parameters: none
    Return: none
*/
logger::logger(string appName){
    //set the app
    app = appName;
    //open database
    int checkOpen =0;
    checkOpen = sqlite3_open("database", &db);
    //check if db can be opened
    if (checkOpen == 1) {
        cout << "Can't open database" << endl;
    }
}

/*
    Name: ~logger
    Description: Destructor, tear down when logging is done, close db
    Parameters:none
    Return: none
*/
logger::~logger(){
    sqlite3_close(db);
}

/*
    Name: write
    Description: create table if not exist, insert message from parameter along with its timestamp
    Parameters: message to be logged
    Return: none
*/
void logger::write(string mess){
    //current time from the system
    time_t cur = time(0);
    //convert to string
    string currTime = ctime(&cur);
    //remove new line from current time
    currTime = regex_replace( currTime,regex("\\r\\n|\\r|\\n"),"");

    //create table query  
    string sqlCreateTable = "create table if not exists " + app +" (timestamp varchar(255), message varchar(255));";
    //insert query
    string sqlInsert = "insert into " + app +" values (\"" + currTime + "\", \""+ mess +"\");";

    //int to indicate if the operation is successful
    int checkQuery = 0;
    char* errMessage;

    //create table
    checkQuery = sqlite3_exec(db, sqlCreateTable.c_str(), NULL, 0, &errMessage);
    //ouput if table is created successfully
    if (checkQuery == 1) {
        cout << "Can't create table" << endl;
    }
    else{
        sqlite3_free(errMessage);
    }

    //insert data
    checkQuery = sqlite3_exec(db, sqlInsert.c_str(), NULL, 0, &errMessage);    
    //check if insert is successful
    if (checkQuery == 1) {
        cout << "Can't insert data" << endl;
    }
    else{
        sqlite3_free(errMessage);
    }    
}


/*
    Name: read_all
    Description: retrieve log messages and timestamps from the database 
    Parameters: none
    Return: vector containing log_message object that has message and timestamp
*/
vector<log_message> logger::read_all(){
    int checkQuery = 0;
    //prepare statement
    sqlite3_stmt *stmt;
    //select query
    string sqlSelect = "select * from " + app +";";
    checkQuery = sqlite3_prepare_v2(db, sqlSelect.c_str(), -1, &stmt, NULL);
    //check if the query succeeded
    if (checkQuery == 1) {
        cout << "Can't get data" << endl;
    }
    while ((checkQuery = sqlite3_step(stmt)) == SQLITE_ROW){
        //retrieve time
        string retrievedTime = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        //retrieve message
        string retrievedMess = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        //put into vector
        result.push_back(log_message(retrievedTime,retrievedMess));
    }
    if (checkQuery != SQLITE_DONE) {
        cout << "error: " << sqlite3_errmsg(db);
    }   
    sqlite3_finalize(stmt);
    return result;
}











