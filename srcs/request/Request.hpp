/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:18:01 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/12/06 15:30:37 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP
# include "../../includes/webServer.hpp"

class Request
{
private:
	std::string method;
	std::string url;
	std::string protocol;
	std::map<std::string, std::string> headers;
	std::string	body;

public:
	Request(const std::string &input);
	~Request();

	void			initHeaders();
	void			parsing(const std::string &input);
	std::string		parseKey(const std::string &line);
	std::string		parseValue(const std::string &line);
	void			parseFirstLine(const std::string &line);
	std::string		nextLine(const std::string &input, size_t &idx);

	void			printAll();
};

#endif