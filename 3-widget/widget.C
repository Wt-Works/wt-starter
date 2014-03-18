// simple user interaction, simple reusable widget
// Author: I. Lazaridis info@lazaridis.com

#include <Wt/WApplication>

#include "../0/WServer.h"

#include "SayWidget.h"


using namespace Wt;
using Ex::SayWidget;
using Ma::WRun;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class SayApplication : public WApplication
{
public:
  SayApplication(const WEnvironment& env) : WApplication(env)
  {
    setTitle("Say!");
    new SayWidget(root());
  }

  static WApplication* create(const WEnvironment& env)
  {
    return new SayApplication(env);
  }
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char **argv)
{
  return WRun(argc, argv, SayApplication::create, "./wthttpd");
}
