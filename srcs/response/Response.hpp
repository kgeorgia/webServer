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

class Response;

typedef int (Response::*methods)(const Request& request);
typedef std::map<std::string, methods> mapMethods;
typedef std::map<int, std::string> mapErrors;

class Response
{
	public:
		Response(const Request &request);
		~Response();

		static mapMethods	InitAllowMethods();
		int		HandlerGetMethod(const Request &request);
		int		HandlerPostMethod(const Request &request);
		int		HandlerHeadMethod(const Request &request);
		int		HandlerPutMethod(const Request &request);
		int		HandlerDeleteMethod(const Request &request);
		int		HandlerOptionsMethod(const Request &request);
		int		HandlerTraceMethod(const Request &request);

		void				InitHeaders();
		static mapErrors	InitPossibleErrors();

		void		SetHeaders(const Request &request);
		const char	*ResponseCall();

	private:
		std::string	protocol;
		std::string	statusCode;
		std::string	statusText;
		std::map<std::string, std::string>	headers;
		std::string	body;

		static mapMethods allowMethods;
		static mapErrors possibleErrors;
};

#endif