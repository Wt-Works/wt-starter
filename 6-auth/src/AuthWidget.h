// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef AUTHWIDGET_H_
#define AUTHWIDGET_H_

#include <Wt/Auth/AuthWidget>
//#include <Wt/Auth/AuthModel>
//#include <Wt/Auth/AuthService>
#include <Wt/Auth/Dbo/UserDatabase>

#include "User.h"
#include "AuthManager.h"


using namespace std;
using namespace Wt;
using namespace Wt::Auth;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class MyAuthWidget : public AuthWidget
{
public:

  MyAuthWidget (AuthManager& am, WContainerWidget* parent=0)
             :AuthWidget(am.base(), am.Users(), am.getLogin(), parent)
  {
    model()->addPasswordAuth(am.passwordAuth());
    model()->addOAuth(am.oAuth());
    setRegistrationEnabled(true);
    processEnvironment();
  }
};


#endif
