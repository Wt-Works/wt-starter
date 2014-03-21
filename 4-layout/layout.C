// A basic layout of a web application
// Author: I. Lazaridis info@lazaridis.com

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WBorderLayout>
#include <Wt/WText>

#include "../0/WServer.h"


using namespace Wt;
using Ma::WRun;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class MyLayout : public WContainerWidget
{
public:
  MyLayout(WContainerWidget* parent);
  WContainerWidget* top()     {return _top;}
  WContainerWidget* buttom()  {return _buttom;}
  WContainerWidget* left()    {return _left;}
  WContainerWidget* right()   {return _right;}
  WContainerWidget* center()  {return _center;}

private:
  WBorderLayout* layout;
  WContainerWidget* _top;
  WContainerWidget* _buttom;
  WContainerWidget* _left;
  WContainerWidget* _right;
  WContainerWidget* _center;

};

MyLayout::MyLayout(WContainerWidget* parent=0) : WContainerWidget(parent)
{
  setHeight(400);
  setStyleClass("green-box");

  layout = new WBorderLayout();
  setLayout(layout);

  _top = new WContainerWidget();
  layout->addWidget(_top, WBorderLayout::North);

  _buttom = new WContainerWidget();
  layout->addWidget(_buttom, WBorderLayout::South);

  _left = new WContainerWidget();
  _left->setWidth(200);
  layout->addWidget(_left, WBorderLayout::West);

  _right = new WContainerWidget();
  layout->addWidget(_right, WBorderLayout::East);

  _center = new WContainerWidget();
  layout->addWidget(_center, WBorderLayout::Center);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class LayoutApp : public WApplication
{
public:
  LayoutApp(const WEnvironment& env);

  static WApplication* create(const WEnvironment& env)
  {
    return new LayoutApp(env);
  }

};

LayoutApp::LayoutApp(const WEnvironment& env) : WApplication(env)
{
  setTitle("Layout, Basic Example");
  MyLayout* lay = new MyLayout();

  lay->top()->addWidget(new WText("Top"));
  lay->buttom()->addWidget(new WText("Buttom"));
  lay->left()->addWidget(new WText("Left"));      // e.g. navigation menu
  lay->right()->addWidget(new WText("Right"));
  lay->center()->addWidget(new WText("Center"));  // e.g. content area

  root()->addWidget(lay);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char* argv[])
{
  return WRun(argc, argv, LayoutApp::create, "./wthttpd");
}
