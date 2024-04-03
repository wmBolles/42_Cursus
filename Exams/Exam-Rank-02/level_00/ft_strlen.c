#include <stddef.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
int	ft_strlen(char *str)
<%
	short	_;
	short	__;

	_ = NULL;
	__ = ~(-0x00001);
	while(!(*(str + _) == '\0'))<% _ += (2 >> 1); __++; %>
	return (_ == __) ? _ : __;
%>
#pragma GCC diagnostic pop
