/*
 * Author: I. Lazaridis (info@lazaridis.com)
 *
 */

#include <Wt/WApplication>
#include <Wt/WText>



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
  return WRun(argc, argv, HelloApplication::create);
}

