#include "GestionnaireDB.h"
#include "sqlite3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>

/*
    ofstream fluxOut("Log\\logBddInternal.txt", ios::app);
    if(fluxOut)
    {
        time (&timeDate);
        string timeDateString = ctime(&timeDate);
        timeDateString.resize(timeDateString.size()-1);
        fluxOut<<"["<<timeDateString<<"] => openning : internal.db"<<endl;
    }
*/


GestionnaireDB::GestionnaireDB()
{
    string filenameIn="Database.db";
    char * filename;
    filename = new char [filenameIn.size()+1];
    strcpy (filename, filenameIn.c_str());
    database = NULL;
    open(filename);
}

GestionnaireDB::GestionnaireDB(string filenameIn)
{
    char * filename;
    filename = new char [filenameIn.size()+1];
    strcpy (filename, filenameIn.c_str());
    database = NULL;
    if(open(filename))
    {
        ofstream fluxOut("Log\\logGestionnaireDBB.txt", ios::app);
        if(fluxOut)
        {
            time (&timeDate);
            string timeDateString = ctime(&timeDate);
            timeDateString.resize(timeDateString.size()-1);
            fluxOut<<"["<<timeDateString<<"] => openning : "<<filenameIn<<endl;
        }
    }
}

GestionnaireDB::~GestionnaireDB()
{
    close();
}

bool GestionnaireDB::open(char* filename)
{
    if(sqlite3_open(filename, &database) == SQLITE_OK)
        return true;
    else
	    return false;
}

vector<vector<string> > GestionnaireDB::query(string request)
{
    sqlite3_stmt *statement;
    vector<vector<string> > results;

    char * query;

    /*
    ofstream fluxOut("Log\\logGestionnaireDBB.txt", ios::app);
    if(fluxOut)
    {
            time (&timeDate);
            string timeDateString = ctime(&timeDate);
            timeDateString.resize(timeDateString.size()-1);
            fluxOut<<"["<<timeDateString<<"] => request : "<<request<<endl;
    }*/

    query = new char [request.size()+1];
    strcpy (query, request.c_str());

    if(sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(statement);
        int result = 0;
        while(true)
        {
            result = sqlite3_step(statement);

            if(result == SQLITE_ROW)
            {
                vector<string> values;
                for(int col = 0; col < cols; col++)
                {
                    values.push_back((char*)sqlite3_column_text(statement, col));
                }
                results.push_back(values);
                }
            else
            {
                break;
            }
        }

        sqlite3_finalize(statement);
    }

    string error = sqlite3_errmsg(database);
    if(error != "not an error") cout << query << " " << error << endl;

    return results;
}

void GestionnaireDB::close()
{
    sqlite3_close(database);
}
