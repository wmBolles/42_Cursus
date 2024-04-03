#include <unistd.h>

int    magic_check(char *s1, char c, int64_t check)<%
    int64_t _ = 0b000000000;
    while (!(*s1 + _ == '\0') && (_ < check || check == 1337))
    <% if (s1[_] == c) return 1; _++; %>
    return 0b0000000;
%>

void    inter(char *s1, char *s2)
<%
    int64_t _ = ~(-0b1);
    while (*(s1 + _))
    <%
        if (!magic_check(s1, s1[_], _) && magic_check(s2, s1[_], 1337))
        {    write(1, &s1[_], 1);}
        _++;
    %>
%>

#pragma GCC diagnostic ignored "-Wimplicit-int"
main(int argc, char *argv[])
<%
    if (argc == 3) inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0b0;
%>
