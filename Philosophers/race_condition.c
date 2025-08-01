/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:34:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/01 19:21:09 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * This program showcases the race condition that emerges when two threads
 * read the same value. One thread will often read an outdated value.
 *
 * The solution is locking the variable by first declaring it as mutex.
 *
 **/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int				g_mails = 0;
pthread_mutex_t	g_mutex;

void	*routine(void)
{
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&g_mutex);
		g_mails++;
		pthread_mutex_unlock(&g_mutex);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t p1, p2;
	if (pthread_mutex_init(&g_mutex, NULL) != 0)
	{
		printf("Failed to initialize mutex\n");
		return (1);
	}
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
	{
		printf("Failed to create thread 1\n");
		return (1);
	}
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
	{
		printf("Failed to create thread 2\n");
		return (2);
	}
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_mutex_destroy(&g_mutex);
	printf("Final value of mails: %d\n", g_mails);
	return (0);
}
