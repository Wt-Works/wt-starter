// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// A basic layout of a web application
// Author: I. Lazaridis info@lazaridis.com
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#pragma once

#include <Wt/Dbo/Dbo>
#include <string>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace Ex {
using std::string;

class Player
{
public:
  enum Role {
    Admin  = 1,
    Editor = 2,
    Simple = 3
  };

  string      name;
  string      password;
  Role        role;
  int         age;
  int         points;

  template<class Action>
  void persist(Action& a)
  {
    field(a, name,     "name");
    field(a, password, "password");
    field(a, role,     "role");
    field(a, age,      "age");
    field(a, points,   "points");
  }

  typedef Wt::Dbo::ptr<Player> dbp;
  Player();
};

DBO_EXTERN_TEMPLATES(Player);

}
