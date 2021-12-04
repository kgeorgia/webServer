/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   web_server.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:19:31 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/11/21 19:20:52 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEB_SERVER_HPP
# define WEB_SERVER_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <sstream>
# include <fstream>

# include <vector>
# include <map>
# include <iterator>
# include <set>
# include <algorithm>

# include <stdlib.h>
# include <netinet/in.h>
# include <sys/types.h>
# include <unistd.h>
# include <poll.h>
# include <sys/event.h>
# include <sys/socket.h>
# include <sys/select.h>

# define RED "\033[31m"
# define RESET "\033[0m"

typedef struct s_listener
{
    u_int64_t   host;
    int         port;    
} t_listener;

#endif