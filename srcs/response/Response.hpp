/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:08:41 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/12/16 16:54:56 by kgeorgia         ###   ########.fr       */
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
	std::string	statusCode;
	std::string	statusText;
	std::map<std::string, std::string>	headers;
	std::string	body;

	static mapMethods allowMethods;
	static std::map<int, std::string> possibleErrors;

public:
	typedef std::map<std::string, void (Response::*)(const Request&)> mapMethods;

	Response(const char *filepath);
	Response(const Request &request);
	~Response();

	mapMethods	InitAllowMethods(void);
	void	HandlerGetMethod(const Request &request);
	void	HandlerPostMethod(const Request &request);
	void	HandlerHeadMethod(const Request &request);
	void	HandlerPutMethod(const Request &request);
	void	HandlerDeleteMethod(const Request &request);
	void	HandlerOptionsMethod(const Request &request);
	void	HandlerTraceMethod(const Request &request);

	void	InitHeaders(void);
	std::map<int, std::string> InitPossibleErrors(void);

	void	SetHeaders(const Request &request);
	const char *Response();
};

#endif