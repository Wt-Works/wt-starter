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

namespace Wt {
namespace Auth {

class OAuthServices : public vector<const Auth::OAuthService *>
{
public:
  ~OAuthServices()
  {
    for (unsigned i = 0; i < size(); ++i)
      delete (*this)[i];
  }
};

}}//ns Wt::Auth

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class AuthManager
{
public:
  AuthManager(Dbo::Session& _db);
  ~AuthManager();
  static const Auth::AuthService& base();
  static const Auth::PasswordService* passwordAuth();
  static const vector<const Auth::OAuthService*>& oAuth();

  static void configureAuth();

  Dbo::ptr<User> getUser() const;

  Auth::AbstractUserDatabase& Users();
  Auth::Login& getLogin() { return login; }

private:
  UserDatabase* users;
  Auth::Login login;
  Dbo::Session& db;

  static Auth::AuthService baseService;
  static Auth::PasswordService pwdService;
  static Auth::OAuthServices AuthManager::oAuthServices;
};

#endif
