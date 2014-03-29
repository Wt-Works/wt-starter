// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WBootstrapTheme>

//#include <Wt/Auth/AuthModel>
//#include <Wt/Auth/AuthWidget>
//#include <Wt/Auth/PasswordService>

#include "DbSession.h"
#include "AuthManager.h"
#include "AuthWidget.h"

#include "../../0/WServer.h"

using namespace Wt;
using namespace Wt::Auth;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class AuthApp : public WApplication
{
private:
  DbSession db;
  AuthManager auth;

public:
  AuthApp(const WEnvironment& env)
    :WApplication(env),
    db(appRoot() + "auth.db"),
    auth(db)
  {
    auth.getLogin().changed().connect(this, &AuthApp::authEvent);

    root()->addStyleClass("container");
    setTheme(new WBootstrapTheme());

    useStyleSheet("css/style.css");

    new MyAuthWidget(auth, root());
  }

  void authEvent()
  {
    if (auth.getLogin().loggedIn()) {
      const Auth::User& u = auth.getLogin().user();
      log("notice")
        << "User " << u.id() << " (" << u.identity(Identity::LoginName) << ")" << " logged in.";
    }
    else {
      log("notice") << "User logged out.";
    }
  }

  static WApplication* create(const WEnvironment& env)
  {
    return new AuthApp(env);
  }

};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char* argv[])
{
    AuthManager::configureAuth();
    return Ma::WRun(argc, argv, AuthApp::create, "./wthttpd");
}
