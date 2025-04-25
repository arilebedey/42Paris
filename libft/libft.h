/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:15:53 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/09 11:15:55 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** #### size_t ####
**
** Using size_t ensures code behaves consistently across different platforms.
** An int might be 2 bytes on one system and 4 bytes on another, potentially
** causing overflow issues.
** 
** On 32-bit systems: size_t is typically 4 bytes (0 to ~4.3 billion)
** On 64-bit systems: size_t is typically 8 bytes (0 to ~18.4 quintillion)
**
** size_t is specifically designed for memory addressing and counting. Memory
** addressing refers to the process of identifying and accessing specific
** locations in computer memory. Each byte in memory has a unique address,
** and size_t is guaranteed to be large enough to represent any valid memory
** address or offset on the target system.
**
** This makes size_t ideal for:
** - Array indexing and offsets
** - Pointer arithmetic
** - Memory allocation sizes
** - String lengths and buffer sizes
**
** This larger range is essential for functions like strlen() that need to
** handle potentially very large memory sizes safely.
**
** To avoid potential issues with different compiler implementations,
** include <stddef.h>
*/

#ifndef LIBFT_H
# define LIBFT_H

// # include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h> 
// # include <stdint.h>

/* libc functions */
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *d, const void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *d, const char *s, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

/* additional functions */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/* Bonus */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
