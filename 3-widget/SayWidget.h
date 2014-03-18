//#pragma once

#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WText>

namespace Ex {

using namespace Wt;

class SayWidget : public WContainerWidget
{
public:
  SayWidget(WContainerWidget* parent);

private:
  WLineEdit* input;
  WText* output;
  void say();
};

}
