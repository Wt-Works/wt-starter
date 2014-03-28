// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2009 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#ifndef USER_H_
#define USER_H_

#include <Wt/Dbo/Types>
#include <Wt/WGlobal>

//#include <Wt/Auth/AuthModel>
//#include <Wt/Auth/AuthService>
#include <Wt/Auth/Dbo/UserDatabase>

class User
{
public:
  /* You probably want to add other user information here */

  template<class Action>
  void persist(Action& a)
  {
  }

  typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
  typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> AuthDatabase;

};


DBO_EXTERN_TEMPLATES(User);

#endif // USER_H_
