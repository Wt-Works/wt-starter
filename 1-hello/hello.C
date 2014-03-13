/*
 * Author: I. Lazaridis (info@lazaridis.com)
 *
 */


#include <Wt/WApplication>
#include <Wt/WContainerWidget> //ISSUE: WText does not include this header
#include <Wt/WText>
#include "../0/WServer.h"

using Wt::WApplication;
using Wt::WEnvironment;
using Wt::WContainerWidget;
using Wt::WText;

using Ma::WRun;


class HelloApplication : public WApplication
{
public:
  HelloApplication(const WEnvironment& env) : WApplication(env)
  {
    setTitle("Hello world");
    root()->addWidget(new WText("Hello World"));
  }

  static WApplication* create(const WEnvironment& env)
  {
    return new HelloApplication(env);
  }
};

int main(int argc, char **argv)
{
  return WRun(argc, argv, HelloApplication::create, "./wthttpd");
}

