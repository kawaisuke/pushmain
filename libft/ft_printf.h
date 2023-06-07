/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:47:24 by ykawai            #+#    #+#             */
/*   Updated: 2023/04/13 19:41:13 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<stddef.h>

size_t	ft_strlen(const	char *str);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
int		ft_char( va_list ap);
int		ft_string( va_list ap);
int		ft_int( va_list ap);
int		ft_unint( va_list ap);
int		ft_sihex( va_list ap);
int		ft_slhex( va_list ap);
int		ft_percent(void);
int		ft_point( va_list ap);
char	*ft_hex(unsigned int temp);
char	*ft_unitoa(unsigned int n);
void	ft_swap(char *ans, int count);
int		ft_smallhex(unsigned int temp, char *ans);
char	*ft_hex(unsigned int temp);
void	ft_swap(char *ans, int count);
int		ft_print_hex(va_list ap, const char format);
void	ft_putchar_fd(char num, int fd);
int		ft_print_ptr(va_list ap);//unsigned long long ptr)

#endif
