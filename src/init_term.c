#include "ft_sh.h"

static int	ret_init(char *str)
{
	//(void)data;
	ft_printf("%s", str);
	return (1);
}

int			init_term(void)
{
	struct termios	term;
	char			*str_1;

	tcgetattr(0, &term);
	term.c_lflag ^= (ECHO | ICANON);
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (ret_init("Error tcsetattr\n"));
	if (!(str_1 = getenv("TERM")))
		return (ret_init("TERM variable not set correctly\n"));
	if (tgetent(NULL, str_1) != 1)
		return (ret_init("Error tgetent\n"));
	return (0);
}
