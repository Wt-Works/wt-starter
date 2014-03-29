// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef DBSESSION_H_
#define DBSESSION_H_

#include <Wt/Dbo/Session>
#include <Wt/Dbo/backend/Sqlite3>


using namespace std;
using namespace Wt;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class DbSession : public Dbo::Session
{
public:
  DbSession(const string& sqliteDb);
  ~DbSession();

private:
  Dbo::backend::Sqlite3 connection;

};

#endif // DBSESSION_H_
