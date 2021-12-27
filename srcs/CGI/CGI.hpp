#include "../../includes/webServer.hpp"

typedef std::map<std::string, std::string> MapEnviroment;

class CGI {
	public:
		CGI(void);
		~CGI();

		std::string 	execute();
	private:
		MapEnviroment	enviroment;
		std::string		bodyRequest;
		std::string 	pathScript;

		void	initEnviroment();
};