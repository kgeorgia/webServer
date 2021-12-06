/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:02:21 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/12/04 16:18:41 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/webServer.hpp"
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
