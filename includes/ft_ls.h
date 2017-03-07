/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:20:54 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/07 16:30:10 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int			lflag;
	int			Rflag;
	int			aflag;
	int			rflag;
	int			tflag;
}				t_flags;

typedef struct	s_data
{
	char		*path_name;
	int			notdir;
}				t_data;

void			get_flag(char *str, t_flags *flags);
t_list			*start_list(char *path, t_flags *flags, t_list *lst);
void			ft_error(int i, char *str);

#endif
