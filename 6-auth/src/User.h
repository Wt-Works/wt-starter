// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef USER_H_
#define USER_H_

#include <Wt/Dbo/Types>
#include <Wt/WGlobal>
#include <Wt/Auth/Dbo/UserDatabase>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class User
{
public:

  template<class Action>
  void persist(Action& a)
  {
  }

  typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
  typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> AuthDatabase;

};


DBO_EXTERN_TEMPLATES(User);

#endif // USER_H_
