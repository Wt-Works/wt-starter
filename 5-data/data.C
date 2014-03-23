// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Content: Basic persistency with dbo
// Author : I. Lazaridis info@lazaridis.com
// License:
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Sqlite3>

#include "Player.h"

using namespace std;
using namespace Wt;
using Ex::Player;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class Session : public Dbo::Session
{
  Dbo::backend::Sqlite3* sqlite3;

public:
  Session(const string& dbname=":memory:") : Dbo::Session()
  {
    sqlite3 = new Dbo::backend::Sqlite3(dbname);
    sqlite3->setProperty("show-queries", "true");
    setConnection(*sqlite3);

    mapClass<Player>("player");

    try {
      createTables();
    }
    catch(...) {
      cerr << "Database already exists" << endl;
    }
  }

  ~Session()
  {
    delete sqlite3;
  }

};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class Demo
{
  Dbo::Session& db;

public:
  Demo(Dbo::Session& dbSession)
    :db(dbSession)
  {
    cerr << "Demo Init" << endl;
  }

  typedef Dbo::collection< Dbo::ptr<Player> > Players;

  Dbo::ptr<Player> add(const string& name, Player::Role role, int age)
  {
    Dbo::Transaction t(db);
    Player* player = new Player();
    player->name = name;
    player->role = role;
    player->age = age;

    Dbo::ptr<Player> pp = db.add(player);
    t.commit();
    return pp;
  }

  Dbo::ptr<Player> show(string name)
  {
    Dbo::Transaction t(db);

    Dbo::ptr<Player> p = db.find<Player>().where("name = ?").bind(name);
    cerr << "Player " << p->name << " age " << p->age << endl;
    return p;
  }

  Players players()
  {
    Dbo::Transaction t(db);

    Players players =  db.find<Player>();

    cerr << "We have " << players.size() << " players:" << endl;

    for (Players::const_iterator i = players.begin(); i != players.end(); ++i) {
      cerr << "Player " << (*i)->name << " age " << (*i)->age << endl;
    }

    return players;
  }

};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class DataApp
{
public:

  int run ()
  {
    Session db;

    Demo demo(db);

    demo.add( "John Doe", Player::Admin, 17);
    demo.add( "Pete Doe", Player::Editor, 16);
    demo.players();
    demo.show( "John Doe");
    demo.show("Pete Doe");

    return 0;
  }

};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char **argv)
{
  DataApp app;
  return app.run();
}
