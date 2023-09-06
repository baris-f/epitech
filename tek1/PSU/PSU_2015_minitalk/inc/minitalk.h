#ifndef PLAT_H_
# define PLAT_H_

# define _POSIX_C_SOURCE 199309L

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

# define ABS(Value) ((Value < 0) ? (Value * -1) : (Value))



#endif /* !PLAT_H_ */
