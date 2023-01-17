
#ifndef MINITALK_H
# define MINITALK_H

# define LOG    printf("%s:%d %s()\n", __FILE__,__LINE__, __FUNCTION__);
# define DEBUG 1
# define PAUSE    if (DEBUG) {getchar();};

# include <unistd.h>
# include "../Libft/libft.h"
# include <signal.h>
# include <sys/types.h>

#endif