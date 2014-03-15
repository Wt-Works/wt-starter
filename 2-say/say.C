// simple user interaction, simple reusable widget
// Author: I. Lazaridis info@lazaridis.com

#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget> // http://redmine.webtoolkit.eu/issues/2822
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>

#include "../0/WServer.h"


using namespace Wt;
using Ma::WRun;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class SayApplication : public WApplication
{
public:
  SayApplication(const WEnvironment& env);

  static WApplication* create(const WEnvironment& env)
  {
    return new SayApplication(env);
  }

private:
  WLineEdit* input;
  WText* output;
  void say();
};


SayApplication::SayApplication(const WEnvironment& env) : WApplication(env)
{
  setTitle("Say!");

  WContainerWidget* rootWidget = this->root();

  new WText ("What to say? ", rootWidget);

  input = new WLineEdit("hi", rootWidget);
  input->setFocus();

  WPushButton *button = new WPushButton("Say", rootWidget);
  button->setMargin(5, Left);
  button->clicked().connect(this, &SayApplication::say);

  new WBreak(rootWidget);

  output = new WText(rootWidget);

}


void SayApplication::say()
{
  output->setText("Saying: " + input->text());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char **argv)
{
  return WRun(argc, argv, SayApplication::create, "./wthttpd");
}
