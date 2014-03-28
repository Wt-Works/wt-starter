// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include "Wt/Auth/HashFunction"

#include "Wt/Auth/PasswordStrengthValidator"
#include "Wt/Auth/PasswordVerifier"
#include "Wt/Auth/GoogleService"
#include "Wt/Auth/FacebookService"
#include "Wt/Auth/Dbo/AuthInfo"
#include "Wt/Auth/Dbo/UserDatabase"

#include "AuthManager.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

using namespace std;
using namespace Wt;

namespace {

  class MyOAuth : public vector<const Auth::OAuthService *>
  {
  public:
    ~MyOAuth()
    {
      for (unsigned i = 0; i < size(); ++i)
        delete (*this)[i];
    }
  };

  static Auth::AuthService baseService;
  static Auth::PasswordService pwdService(baseService);
  static MyOAuth oAuthServices;

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

AuthManager::AuthManager(Dbo::Session& _db)
  :db(_db)
{
  users = new UserDatabase(db);
}

void AuthManager::configureAuth()
{

  baseService.setAuthTokensEnabled(true, "logincookie");
  baseService.setEmailVerificationEnabled(true);

  Auth::PasswordVerifier *verifier = new Auth::PasswordVerifier();
  verifier->addHashFunction(new Auth::BCryptHashFunction(7));
  pwdService.setVerifier(verifier);
  pwdService.setAttemptThrottlingEnabled(true);
  pwdService.setStrengthValidator(new Auth::PasswordStrengthValidator());

  if (Auth::GoogleService::configured()) {
    oAuthServices.push_back(new Auth::GoogleService(baseService));
  }

  if (Auth::FacebookService::configured()) {
    oAuthServices.push_back(new Auth::FacebookService(baseService));
  }
}

AuthManager::~AuthManager()
{
  delete users;
}

Dbo::ptr<User> AuthManager::getUser() const
{
  if (login.loggedIn()) {
    Dbo::ptr<AuthInfo> authInfo = users->find(login.user());
    return authInfo->user();
  }
  else {
    return Dbo::ptr<User>();
  }
}

const Auth::AuthService& AuthManager::base()
{
  return baseService;
}

const Auth::PasswordService* AuthManager::passwordAuth()
{
  return &pwdService;
}

const vector<const Auth::OAuthService *>& AuthManager::oAuth()
{
  return oAuthServices;
}

Auth::AbstractUserDatabase& AuthManager::Users()
{
  return *users;
}







