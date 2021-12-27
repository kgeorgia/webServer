#include "CGI.hpp"

CGI::CGI() {
	this->initEnviroment();
}

CGI::~CGI() {}

std::string 	CGI::execute() {
	std::string ret;
	int dupStdin = dup(STDIN_FILENO);
	int	dupStdout = dup(STDOUT_FILENO);
	int fdIn = mkstemp("tempIn");
	int fdOut = mkstemp("tempOut");
	char	**env = new char*[enviroment.size() + 1];
	MapEnviroment::iterator envIt;
	int i = 0;

	for (envIt = enviroment.begin(); envIt != enviroment.end(); envIt++) {
		std::string elem = envIt->first + "=" + envIt->second;
		env[i] = new char[elem.size() + 1];
		strcpy(env[i++], elem.c_str());
	}
	env[i] = NULL;

	write(fdIn, bodyRequest.c_str(), bodyRequest.size());
	lseek(fdIn, 0, SEEK_SET);

	if (!fork()) {
		dup2(fdIn, STDIN_FILENO);
		dup2(fdOut, STDOUT_FILENO);
		execve(pathScript.c_str(), NULL, env);
		std::cerr << RED << "Execve crash!" << RESET << std::endl;
		exit(0);
	}
	else {
		waitpid(-1, NULL, 0);
		lseek(fdOut, 0, SEEK_SET);

		char c;
		while ((read(fdOut, &c, 1)) == 1)
			ret += c;
	}

	dup2(dupStdin, STDIN_FILENO);
	dup2(dupStdout, STDOUT_FILENO);
	close(fdIn);
	close(fdOut);
	close(dupStdin);
	close(dupStdout);

	for (i = 0; env[i]; i++)
		delete[] env[i];
	delete[] env;

	return ret;
}

void 	CGI::initEnviroment() {
	enviroment["AUTH_TYPE"] = "";
	enviroment["CONTENT_LENGTH"] = "";
	enviroment["CONTENT_TYPE"] = "";
	enviroment["DOCUMENT_ROOT"] = "";
	enviroment["GATEWAY_INTERFACE"] = "";
	enviroment["HTTP_ACCEPT"] = "";
	enviroment["HTTP_COOKIE"] = "";
	enviroment["HTTP_FROM"] = "";
	enviroment["HTTP_REFERER"] = "";
	enviroment["HTTP_USER_AGENT"] = "";
	enviroment["PATH_INFO"] = "";
	enviroment["PATH_TRANSLATED"] = "";
	enviroment["QUERY_STRING"] = "";
	enviroment["REMOTE_ADDR"] = "";
	enviroment["REMOTE_HOST"] = "";
	enviroment["REMOTE_IDENT"] = "";
	enviroment["REMOTE_USER"] = "";
	enviroment["REQUEST_METHOD"] = "";
	enviroment["SCRIPT_NAME"] = "";
	enviroment["SERVER_NAME"] = "";
	enviroment["SERVER_PORT"] = "";
	enviroment["SERVER_PROTOCOL"] = "";
	enviroment["SERVER_SOFTWARE"] = "";
}