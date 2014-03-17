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

class SayWidget : public WContainerWidget
{
public:
  SayWidget(WContainerWidget* parent);

private:
  WLineEdit* input;
  WText* output;
  void say();
};

SayWidget::SayWidget(WContainerWidget* parent) : WContainerWidget(parent)
{
  new WText ("What to say? ", parent);

  input = new WLineEdit("hi", parent);
  input->setFocus();

  WPushButton *button = new WPushButton ("Say", parent);
  button->setMargin(5, Left);
  button->clicked().connect(this, &SayWidget::say);

  new WBreak(parent);

  output = new WText(parent);

}

void SayWidget::say()
{
  output->setText("Saying: " + input->text());
}

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
