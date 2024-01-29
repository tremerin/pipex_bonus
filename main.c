/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:45:55 by fgalan-r          #+#    #+#             */
/*   Updated: 2024/01/29 20:52:49 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        printf ("argv[1]len: %ld\n",ft_strlen(argv[1]));
    }

    return (0);
}