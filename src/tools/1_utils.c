/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   1_utils.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mkulikov <mkulikov@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/19 15:42:38 by mkulikov		  #+#	#+#			 */
/*   Updated: 2025/01/12 16:12:02 by mkulikov		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(-1, "open", NULL);
	return (fd);
}

bool	in_range_int(int i, int left, int right)
{
	return ((left <= i) && (i <= right));
}

bool	in_range_float(float i, float left, float right)
{
	return ((left <= i) && (i <= right));
}

bool	is_upper(char i)
{
	return (('A'<= i) && (i <= 'Z'));
}
