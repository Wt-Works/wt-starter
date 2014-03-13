/*
 * Copyright (C) 2014 Ilias Lazaridis (info@lazaridis.com)
 *
 */
#ifndef MA_WSERVER_H_
#define MA_WSERVER_H_

#include <Wt/WServer>

namespace Ma {

class WServer : public Wt::WServer
{

public:
    WServer(int argc, char *argv[], const std::string& serverConfigurationFile = std::string())
        : Wt::WServer()
    {
        setServerConfiguration(argc, argv, serverConfigurationFile);
    }

    WServer(const std::string &wtApplicationPath=std::string(), const std::string &wtConfigurationFile=std::string())
        : Wt::WServer(wtApplicationPath, wtConfigurationFile)
    {

    }

    void run()
    {
        if (start()) {
          WServer::waitForShutdown();
          stop();
        }
    }

    void addApplication(Wt::ApplicationCreator callback,
                        const std::string& path = std::string(),
                                const std::string& favicon = std::string())
    {
        addEntryPoint(Wt::Application, callback, path);
    }


};


int  WRun(int argc, char** argv, Wt::ApplicationCreator createApplication = 0,
          const std::string& serverConfigurationFile = std::string())
{
  WServer server(argc, argv, serverConfigurationFile);
  server.addApplication(createApplication, "/");

  server.run();
  return 0;
}


}


#endif // MA_WSERVER_H_
