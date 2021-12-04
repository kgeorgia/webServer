#ifndef SERVER_HPP
# define SERVER_HPP

# include "../../includes/web_server.hpp"
# include "../response/Response.hpp"

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