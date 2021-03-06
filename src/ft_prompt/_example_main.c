#include "ft_sh.h"

int			main(int argc, char **argv)
{
	char		*line;

	ft_printf("%s", "Hello 42sh!\n- - - - - - - - - -\n\nUse [ exit ] to quit echo_sh.\n\n");

/*	This function must be called to enable history.
**	Sets the max length of the history log.	*/
	ft_prompt_history_set_len(200);

	while (1)
	{
/*		ft_prompt returns [ NULL ] on error.
**		and a pointer to a fresh string on success. */
		line = ft_prompt("echo_sh $> ");

/*		This function adds a string to the history log.
**		ft_prompt does NOT keep track of history internally. */
		ft_prompt_history_add(line);

		ft_putendl(line);
		if (!ft_strcmp(line, "exit"))
		{
/*			[ line ] has been malloc'd by ft_prompt and must be freed.
**			History is freed by ft_prompt on program exit. */
			free(line);
			break ;
		}
		free(line);
	}

	argc = 0;
	argv = 0;
	return (0);
}
