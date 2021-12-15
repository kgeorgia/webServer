/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:08:41 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/12/04 16:18:16 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "../../includes/webServer.hpp"
# include "../request/Request.hpp"

class Response
{
private:
	std::string	protocol;
	std::string statusCode;
	std::string statusText;
	std::map<std::string, std::string> headers;
	std::string body;

	static std::map<std::string, void (Response::*)(const Request&)> allowMethods;
	static std::map<int, std::string> possibleErrors;
public:
	Response(const char *filepath);
	Response(const Request &request);
	~Response();

	std::map<std::string, void (Response::*)(const Request&)>	initAllowMethods(void);
	void	HandlerGetMethod(const Request &request);
	void	HandlerPostMethod(const Request &request);
	void	HandlerHeadMethod(const Request &request);
	void	HandlerPutMethod(const Request &request);
	void	HandlerDeleteMethod(const Request &request);
	void	HandlerOptionsMethod(const Request &request);
	void	HandlerTraceMethod(const Request &request);

	std::map<int, std::string> initPossibleErrors(void);

	const char *response();
};

#endif