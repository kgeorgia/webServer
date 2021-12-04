/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:08:41 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/11/21 19:22:26 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "../../includes/web_server.hpp"

class Response
{
private:
    std::string header;
    std::string body;
public:
    Response(const char *filepath);
    ~Response();

    const char *response();
};

#endif