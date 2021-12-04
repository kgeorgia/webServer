#include "Server.hpp"

Server::Server()
{
    server_fd = -1;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    memset(address.sin_zero, 0, sizeof(address.sin_zero));
}

Server::Server(Server &other)
{
    server_fd = other.server_fd;
    address.sin_family =AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    memset(address.sin_zero, 0, sizeof(address.sin_zero));
}

Server::~Server()
{
    ::close(server_fd);
}

void    Server::start(void)
{
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << RED << "Failed to create socket. errno: " << errno << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, reinterpret_cast<sockaddr *>(&address), sizeof(address)) < 0)
    {
        std::cerr << RED << "Failed to bind to port. errno: " << errno << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0)
    {
        std::cerr << RED << "Failed to listen on socket. errno" << errno << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
}

void    Server::process(void)
{
    int ret;
    int tmp_socket;
    int addr_len = sizeof(address);
    Response res("./test/index.html");

    // const char *hello = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 224\n\n<!DOCTYPE html><html><title>400 Danya Huesos</title><body><div><H1>400 Danya Huesos</H1><p>Server could not process request due to a client error (malformed syntax, invalid request message framing, etc)</p></div></body></html>";
    // const char *hello = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 156\n\n<!DOCTYPE html><HTML><HEAD><TITLE>Your Title Here</TITLE></HEAD><BODY BGCOLOR=\"5FAAFA\"><H1>This is new site</H1><P> This is a text!</P></BODY></HTML>";
    while(42)
    {
        std::cout << std::endl << "-------------| Waiting new connection |-------------" << std::endl;
        if ((tmp_socket = accept(server_fd, reinterpret_cast<sockaddr *>(&address),
            reinterpret_cast<socklen_t*>(&addr_len))) < 0)
        {
            std::cerr << "Error in accept" << std::endl;
            exit(EXIT_FAILURE);
        }

        while (42)
        {
            char buffer[1000] = {0};
            ret = recv( tmp_socket, buffer, sizeof(buffer), 0);
            if (ret > 0)
            {
                std::cout << "Client: " << buffer << std::endl;
                send(tmp_socket, res.response(), strlen(res.response()), 0);
            }
            if (ret == 0 || ret == -1)
                break;
        }
        ::close(tmp_socket);
    }
    ::close(server_fd);
}