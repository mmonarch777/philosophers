/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:56:28 by mmonarch          #+#    #+#             */
/*   Updated: 2021/11/04 19:47:32 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINI_H
# define LIBMINI_H
# include <unistd.h>

void	ft_putendl(char *str);
void	ft_error(char *str);
int		ft_isdigit(char c);
int		ft_atoi(const char *str);

#endif
