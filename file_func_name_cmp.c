/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_func_name_cmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:14:29 by shogura           #+#    #+#             */
/*   Updated: 2022/04/08 20:43:58 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int bool;
	int fd;
	int rc;
	char *tmp;
	char buf[5000];
	char filename[][100] = {
			"ft_isalpha.c",
			"ft_isdigit.c",
			"ft_isalnum.c",
			"ft_isascii.c",
			"ft_isprint.c",
			"ft_strlen.c",
			"ft_memset.c",
			"ft_bzero.c",
			"ft_memcpy.c",
			"ft_memmove.c",
			"ft_strlcpy.c",
			"ft_strlcat.c",
			"ft_toupper.c",
			"ft_tolower.c",
			"ft_strchr.c",
			"ft_strrchr.c",
			"ft_strncmp.c",
			"ft_memchr.c",
			"ft_memcmp.c",
			"ft_strnstr.c",
			"ft_atoi.c",
			"ft_calloc.c",
			"ft_strdup.c",
			"ft_substr.c",
			"ft_strjoin.c",
			"ft_strtrim.c",
			"ft_split.c",
			"ft_itoa.c",
			"ft_strmapi.c",
			"ft_striteri.c",
			"ft_putchar_fd.c",
			"ft_putstr_fd.c",
			"ft_putendl_fd.c",
			"ft_putnbr_fd.c",
			"ft_lstnew.c",
			"ft_lstadd_front.c",
			"ft_lstsize.c",
			"ft_lstadd_back.c",
			"ft_lstdelone.c",
			"ft_lstclear.c",
			"ft_lstiter.c",
			"ft_lstmap.c",
	};

	char func_name[][100] = {
			"ft_isalpha",
			"ft_isdigit",
			"ft_isalnum",
			"ft_isascii",
			"ft_isprint",
			"ft_strlen",
			"ft_memset",
			"ft_bzero",
			"ft_memcpy",
			"ft_memmove",
			"ft_strlcpy",
			"ft_strlcat",
			"ft_toupper",
			"ft_tolower",
			"ft_strchr",
			"ft_strrchr",
			"ft_strncmp",
			"ft_memchr",
			"ft_memcmp",
			"ft_strnstr",
			"ft_atoi",
			"ft_calloc",
			"ft_strdup",
			"ft_substr",
			"ft_strjoin",
			"ft_strtrim",
			"ft_split",
			"ft_itoa",
			"ft_strmapi",
			"ft_striteri",
			"ft_putchar_fd",
			"ft_putstr_fd",
			"ft_putendl_fd",
			"ft_putnbr_fd",
			"ft_lstnew",
			"ft_lstadd_front",
			"ft_lstsize",
			"ft_lstadd_back",
			"ft_lstdelone",
			"ft_lstclear",
			"ft_lstiter",
			"ft_lstmap",
	};

	fd = open("filename_user.txt", O_RDONLY);
	bzero(buf, 5000);
	rc = read(fd, buf, 5000);
	bool = 1;

	for (int i = 0; i < 42; i++)
	{
		tmp = buf;
		if (strstr(tmp, filename[i]) == NULL)
		{
			printf("%s\x1b[31m [KO] \x1b[0m\n", filename[i]);
			bool = 0;
		}
		printf("%s\x1b[32m [OK] \x1b[0m\n", filename[i]);
	}
	if (bool)
		printf("[[[------FILENAME IS ALL GOOD!!------]]]\n\n");
	else
		printf("[[[------There is a mistake!!------]]]\n\n");
	close(fd);

	bool = 1;
	for (int i = 0; i < 42; i++)
	{
		char buf[5000];
		fd = open(filename[i], O_RDONLY);
		rc = read(fd, buf, 5000);
		tmp = strstr(buf, func_name[i]);
		tmp += strlen(filename[i]);
		if (strstr(tmp, func_name[i]) == NULL)
		{
			printf("%s\x1b[31m [KO] \x1b[0m\n", func_name[i]);
			bool = 0;
		}
		printf("%s\x1b[32m [OK] \x1b[0m\n", func_name[i]);
		close(fd);
	}
	if (bool)
		printf("[[[------FUNCNAME IS ALL GOOD!!------]]]\n");
	else
		printf("[[[------There is a mistake!!------]]]\n");
	return 0;
}
