/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:32:59 by pevtimov          #+#    #+#             */
/*   Updated: 2024/03/27 19:35:38 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"
# define DEC "0123456789"

int				ft_printf(char const *str, ...);
int				ft_putchar_and_count(char c);
int				ft_find_type(char var_type, va_list args);
int				ft_putstr_and_count(char *s);
unsigned int	ft_strlen_pf(const char *s); //
unsigned int	ft_get_lenght(unsigned long long num, unsigned int size_base);
char			*ft_convert_num_to_base(unsigned long long num, char *base);//
int				ft_putstring_ptr(unsigned long long ptr_address, char *base);
int				ft_putstring_base(unsigned int num, char *base);
void			*ft_calloc_printf(int nmemb, size_t size);
void			ft_bzero_printf(void *s, int n);
int				ft_putstring_int(int num, char *base);

#endif