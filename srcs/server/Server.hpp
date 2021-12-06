#ifndef SERVER_HPP
# define SERVER_HPP

# include "../../includes/webServer.hpp"
# include "../response/Response.hpp"
# include "../request/Request.hpp"

class Server
{
	private:
		int server_fd;
		struct sockaddr_in address;
		std::map<int, std::string> requests;

	public:
		Server();
		Server(Server &other);
		~Server();

		void	start(void);
		void	process(void);
		// void	close(void);
};

#endif