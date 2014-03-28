// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef AUTHMANAGER_H_
#define AUTHMANAGER_H_

#include "Wt/Auth/AuthService"
#include "Wt/Auth/PasswordService"
#include <Wt/Auth/Login>

#include <Wt/Dbo/Session>
#include <Wt/Dbo/ptr>

#include "User.h"


using namespace std;
using namespace Wt;

typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> UserDatabase;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class AuthManager
{
public:
  AuthManager(Dbo::Session& _db);
  ~AuthManager();
  static const Auth::AuthService& base();
  static const Auth::PasswordService *passwordAuth();
  static const vector<const Auth::OAuthService *>& oAuth();

  static void configureAuth();

  Dbo::ptr<User> getUser() const;

  Auth::AbstractUserDatabase& Users();
  Auth::Login& getLogin() { return login; }

private:
  UserDatabase* users;
  Auth::Login login;
  Dbo::Session& db;
};


#endif
