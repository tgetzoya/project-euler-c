# Project settings
PROG	=	project-euler
SRCS	!=	find src -name '*.c'


# Build flags
CFLAGS?	=	-O2 -pipe
CFLAGS	+=	-Wall -Wextra -flto -I/usr/local/include
LDFLAGS	+=	-flto -L/usr/local/lib -lgmp
MK_MAN	=	no

# Include FreeBSD build framework
.include <bsd.prog.mk>
