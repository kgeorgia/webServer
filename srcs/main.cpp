/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:02:21 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/11/19 18:58:02 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/web_server.hpp"
#include "server/Server.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    Server serv;

    serv.start();
    serv.process();
    return (0);
}
