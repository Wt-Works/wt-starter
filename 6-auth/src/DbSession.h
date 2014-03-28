// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2009 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#ifndef DBSESSION_H_
#define DBSESSION_H_

#include <Wt/Auth/Login>

#include <Wt/Dbo/Session>
#include <Wt/Dbo/ptr>
#include <Wt/Dbo/backend/Sqlite3>

#include "User.h"

namespace dbo = Wt::Dbo;
  using namespace std; using namespace Wt;

typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> UserDatabase;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class DbSession : public dbo::Session
{
public:

  DbSession(const string& sqliteDb);
  ~DbSession();

private:
  Dbo::backend::Sqlite3 connection;

};

#endif // DBSESSION_H_
