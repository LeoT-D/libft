/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 01:52:34 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/08 07:01:35 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			append_substr(char **dst, char *src, size_t len)
{
	char		*sub;
	char		*tmp;

	tmp = *dst;
	sub = ft_strsub(src, 0, len);
	*dst = ft_strjoin(*dst, sub);
	free(tmp);
	free(sub);
}

void			append_cursor_pos(char **dst, char *num)
{
	char		esc[64];
	int			numlen;

	numlen = ft_strlen(num);
	ft_strncpy(esc, "\r\033[", 64);
	ft_strncpy(esc + 3, num, numlen + 1);
	ft_strncpy(esc + 3 + numlen, "C", 2);
	free(num);
	append_substr(dst, esc, numlen + 4);
}

void			print_line(t_prompt *p)
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
	{
		tmp.len--;
	}
	append_substr(&line, "\r", 1);
	append_substr(&line, p->pstr, p->plen);
	append_substr(&line, tmp.buf, tmp.len);
	append_substr(&line, DEL_END_SEQ, 4);
	append_cursor_pos(&line, ft_itoa((int)(tmp.pos + p->plen)));
	write(p->ofd, line, ft_strlen(line));
	free(line);
}
