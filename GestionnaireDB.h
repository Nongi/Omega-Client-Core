#ifndef __GESTIONNAIREDB_H__
#define __GESTIONNAIREDB_H__

#include <string>
#include <vector>
#include "sqlite3.h"

using namespace std;

class GestionnaireDB
{
    public:
        GestionnaireDB();
        GestionnaireDB(string filename);
        ~GestionnaireDB();

	    bool open(char* filename);
	    vector<vector<string> > query(string request);
	    void close();

        time_t timeDate;

	private:
	    sqlite3 *database;
};

#endif
