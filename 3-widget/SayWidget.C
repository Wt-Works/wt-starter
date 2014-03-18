// a simple widget, which can be reused
// Author: I. Lazaridis info@lazaridis.com

#include <Wt/WBreak>
#include <Wt/WContainerWidget> // http://redmine.webtoolkit.eu/issues/2822
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>

#include "SayWidget.h"

using namespace Wt;
using namespace Ex;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

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

