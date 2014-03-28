/*
 * Copyright (C) 2010 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WServer>
#include <Wt/WBootstrapTheme>

#include <Wt/Auth/AuthModel>
#include <Wt/Auth/AuthWidget>
#include <Wt/Auth/PasswordService>

#include "DbSession.h"
#include "AuthManager.h"
#include "AuthWidget.h"

#include "../../0/WServer.h"

using namespace Wt;
using namespace Wt::Auth;
using Wt::Auth::Identity;
//using Ma::WRun;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//class MyAuthWidget : public AuthWidget
//{
//public:
//  MyAuthWidget (const AuthService& baseAuth, AbstractUserDatabase& users,
//              Login& login, WContainerWidget* parent=0)
//             :AuthWidget(baseAuth, users, login, parent)
//  {
//    model()->addPasswordAuth(AuthManager::passwordAuth());
//    model()->addOAuth(AuthManager::oAuth());
//    setRegistrationEnabled(true);
//    processEnvironment();
//  }

//  MyAuthWidget (const AuthManager& am, WContainerWidget* parent=0)
//             :AuthWidget(am.auth(), am.users(), am.login(), parent)
//  {
//    model()->addPasswordAuth(am.passwordAuth());
//    model()->addOAuth(am.oAuth());
//    setRegistrationEnabled(true);
//    processEnvironment();
//  }
//};

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

    //pass an auth object
    //new MyAuthWidget(AuthManager::auth(), auth.Users(), auth.getLogin(), root());
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
