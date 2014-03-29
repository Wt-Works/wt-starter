// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include "DbSession.h"

#include "User.h"
#include "AuthManager.h"

using namespace std;
using namespace Wt;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

DbSession::DbSession(const string& sqliteDb)
  : connection(sqliteDb)
{
  connection.setProperty("show-queries", "true");

  setConnection(connection);

  mapClass<User>("user");
  mapClass<AuthInfo>("auth_info");
  mapClass<AuthInfo::AuthIdentityType>("auth_identity");
  mapClass<AuthInfo::AuthTokenType>("auth_token");

  try {
    createTables();
    cerr << "Created database." << endl;
  }
  catch (exception& e) {
    cerr << e.what() << endl;
    cerr << "Using existing database";
  }

}

DbSession::~DbSession()
{
  ;
}



