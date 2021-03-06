/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 01:52:34 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/10 15:37:21 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int				append_substr(char **dst, char *src, size_t len)
{
	char		*sub;
	char		*tmp;

	tmp = *dst;
	MALL_CHECK(sub = ft_strsub(src, 0, len));
	MALL_CHECK(*dst = ft_strjoin(*dst, sub));
	free(tmp);
	free(sub);
	return (0);
}

int				append_cursor_pos(char **dst, int n)
{
	char		esc[64];
	int			numlen;
	char		*num;

	MALL_CHECK(num = ft_itoa(n));
	numlen = ft_strlen(num);
	ft_strncpy(esc, "\r\033[", 64);
	ft_strncpy(esc + 3, num, numlen + 1);
	ft_strncpy(esc + 3 + numlen, "C", 2);
	free(num);
	ERR_CHECK(append_substr(dst, esc, numlen + 4));
	return (0);
}

int				prev_newline_check(t_prompt *p)
{
	char		buf[16];
	char		*b2;
	int			x;
	int			y;

	write(1, CUR_SEQ, 4);
	read(0, buf, 16);
	x = ft_atoi(buf + 2);
	b2 = ft_strchr(buf, ';');
	b2++;
	y = ft_atoi(b2);
	if (y != 1)
		write(p->ofd, "\033[30;47m%\033[0m\n\r", 15);
	return (0);
}

int				print_line(t_prompt *p)
{
	char		esc[64];
	char		*line;
	t_prompt	tmp;

	ft_bzero(esc, 64);
	tmp.buf = p->buf;
	tmp.len = p->len;
	tmp.pos = p->pos;
	line = ft_strnew(0);
	while (p->plen + tmp.pos >= p->cols)
	{
		tmp.buf++;
		tmp.len--;
		tmp.pos--;
	}
	while ((p->plen + tmp.len) > p->cols)
		tmp.len--;
	ERR_CHECK(append_substr(&line, "\r", 1));
	ERR_CHECK(append_substr(&line, p->pstr, p->plen));
	ERR_CHECK(append_substr(&line, tmp.buf, tmp.len));
	ERR_CHECK(append_substr(&line, DEL_END_SEQ, 4));
	ERR_CHECK(append_cursor_pos(&line, tmp.pos + p->plen));
	write(p->ofd, line, ft_strlen(line));
	free(line);
	return (0);
}
