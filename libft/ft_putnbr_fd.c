/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:40:37 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/18 12:13:42 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

static	void	num_write(int i, int fd)
{
	int		count;
	char	num[12];

	count = 0;
	while (0 < i)
	{
		num[count] = i % 10 + '0';
		i /= 10;
		count++;
	}
	while (0 < count)
	{
		count--;
		write(fd, &num[count], 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
	}
	else if (n == 0)
		write (fd, "0", 1);
	num_write(n, fd);
}
