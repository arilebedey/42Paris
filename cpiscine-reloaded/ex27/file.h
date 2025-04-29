/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:44:08 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/24 16:44:09 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H

# define FILE_H

# include <unistd.h>
# include <fcntl.h>

// Arg Errors
void	err_too_many_args(void);
void	err_no_arg(void);
void	err_not_file(void);

#endif
