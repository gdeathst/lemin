/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:30:04 by anonimnus         #+#    #+#             */
/*   Updated: 2021/05/06 07:30:54 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define ERROR "ERROR\n"

typedef enum e_legend
{
	NUMBER_OF_ANTS,
	COPY,
	ROOM,
	START,
	END,
	LINK,
	NOT_VALID,
	DESCRIPTION
}					t_legend;

typedef struct s_bfs	t_bfs;
typedef struct s_coord	t_coord;
typedef struct s_room	t_room;
typedef struct s_path	t_path;
typedef struct s_link	t_link;
typedef struct s_map	t_map;

struct s_bfs
{
	int		is_visited;
	t_room	*prev;
	t_link	*link;
};

struct s_coord
{
	int	x;
	int	y;
};

struct s_path
{
	int		number_of_ant;
	int		length_of_way;
	t_room	*next;
};

struct s_room
{
	char		*name;
	int			is_copy;
	t_coord		coord;
	t_link		**links;
	t_path		path;
	t_bfs		bfs;
};

struct s_link
{
	t_room		*to;
	t_room		*from;
	int			from_to;
	int			to_from;
	int			weigth;
};

struct s_map
{
	int			number_of_ants;
	t_list		*start;
	t_list		*end;
	t_list		*rooms;
	t_list		*links;
};

/*
** MAIN FUNCTION
*/
t_list		*get_map_description(void);
t_map		*get_map(t_list	*description);
int			get_number_of_ants(t_list *description);
t_list		*get_rooms(t_list *description);
t_list		*get_links(t_list *description, t_list *rooms, t_map *map);
void		modify_map(t_map *map);
void		route_search_optimization(t_map *map);
int			bfs(t_room *start, t_room *goal, t_list *rooms);
void		edmonds_karp(t_room *start, t_room *end, t_list *rooms);
void		build_paths(t_room *start, t_room *end);
void		optimize_choice_of_path(t_room *start);
void		show_description(t_list *description);
void		show_paths(t_map *map);
/*
**	LEGEND
*/
int			is_comment(char *line);
int			is_room(char *line);
int			is_link(char *line);
int			is_start(char *line);
int			is_end(char *line);
/*
**	FREE_MEMMORY
*/
void		destroy_map(t_map *map);
void		destoy_description(t_list *description);
/*
**	UTILS
*/
void		terminate(char *error_message);
t_list		*wrap(void	*content, int type);
t_list		*find_room(t_list *rooms, char *name, int type);
t_room		*get_next_room(t_link *link, t_room *from);
void		*ememalloc(size_t size);

#endif
