/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:55:17 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/20 12:19:13 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <errno.h>

int		ft_printf(const char *s, ...);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putptr(uintptr_t n);
int		ft_putnbr_hex(int nbr, char flag);
int		ft_putnbr_hex_uintptr(uintptr_t nbr);

#endif