#include "ft_sh.h"

static int	ret_init(t_sh *data, char *str)
{
	(void)data;
	//close(data->fd);
	//free_all(data);
	ft_printf("%s", str);
	return (1);
}

int			init_term(t_sh *data)
{
	struct termios	term;
	char			*str_1;

	tcgetattr(0, &term);
	term.c_lflag ^= (ECHO | ICANON);
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (ret_init(data, "Error tcsetattr\n"));
	if (!(str_1 = getenv("TERM")))
		return (ret_init(data, "TERM variable not set correctly\n"));
	if (tgetent(NULL, str_1) != 1)
		return (ret_init(data, "Error tgetent\n"));
	return (0);
}
