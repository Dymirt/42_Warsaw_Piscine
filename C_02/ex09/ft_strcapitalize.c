/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:45:22 by dkolida           #+#    #+#             */
/*   Updated: 2023/11/26 19:13:25 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
void	capitalize_letter(int *is_first_letter, char *letter);
void	transform_uppercase(int *is_first_letter, char *letter);
void	transform_lowercase(int *is_first_letter, char *letter);

char	*ft_strcapitalize(char *str)
{
	int	is_first_letter;
	int	i;

	i = 0;
	is_first_letter = 1;
	while (str[i] != '\0')
	{
		capitalize_letter(&is_first_letter, &str[i]);
		i++;
	}
	return (str);
}

void	capitalize_letter(int *is_first_letter, char *letter)
{
	if (*letter >= 'A' && *letter <= 'Z')
	{
		transform_uppercase(is_first_letter, letter);
	}
	else if (*letter >= 'a' && *letter <= 'z')
	{
		transform_lowercase(is_first_letter, letter);
	}
	else if (*letter >= '0' && *letter <= '9')
	{
		*is_first_letter = 0;
	}
	else
	{
		*is_first_letter = 1;
	}
}

void	transform_uppercase(int *is_first_letter, char *letter)
{
	if (*is_first_letter == 0)
	{
		*letter = *letter + 32;
	}
	else
	{
		*is_first_letter = 0;
	}
}

void	transform_lowercase(int *is_first_letter, char *letter)
{
	if (*is_first_letter == 1)
	{
		*letter = *letter - 32;
		*is_first_letter = 0;
	}
}
