// simple user interaction, simple widget
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

  WContainerWidget* parent = this->root();

  new WText ("What to say? ", parent);

  input = new WLineEdit("hi", parent);
  input->setFocus();

  WPushButton *button = new WPushButton("Say", parent);
  button->setMargin(5, Left);
  button->clicked().connect(this, &SayApplication::say);

  new WBreak(parent);

  output = new WText(parent);

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
