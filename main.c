/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@students.42wolfsburg.de>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:21:07 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/28 07:34:11 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

void *function()
{
    int x = 0;
    x += 1;
    printf("This is a thread with the id %d\n", x);   
}

int main(void)
{
    pthread_t t1;
    int x;
    
    x = 0;
    while (x < 10)
    {
        if(pthread_create(&t1, NULL, &function, NULL) != 0)
            return (1);
        if (pthread_join(t1, NULL) != 0)
            return (1);
        x++;
    }
}