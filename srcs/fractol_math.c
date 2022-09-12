/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:07:37 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 20:16:28 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_fractol *frac)
{
	int		n;
	double	temp;
	double	va_z;

	va_z = 0;
	n = 0;
	frac->zmax = frac->cmax;
	frac->zmin = frac->cmin;
	while (n < frac->max_iterations && va_z < 4)
	{
		temp = pow(frac->zmax, 2) - pow(frac->zmin, 2) + frac->cmax;
		frac->zmin = (2 * frac->zmax * frac->zmin) + frac->cmin;
		frac->zmax = temp;
		va_z = pow(frac->zmax, 2) + pow(frac->zmin, 2);
		n++;
	}
	return (n);
}

int	julia(t_fractol *frac)
{
	int		n;
	double	temp;
	double	va_z;

	n = 0;
	va_z = 0;
	frac->zmax = frac->cmax;
	frac->zmin = frac->cmin;
	while (n < frac->max_iterations && va_z < 4)
	{
		temp = pow(frac->zmax, 2) - pow(frac->zmin, 2) + frac->kmax;
		frac->zmin = (2 * frac->zmax * frac->zmin) + frac->kmin;
		frac->zmax = temp;
		va_z = pow(frac->zmax, 2) + pow(frac->zmin, 2);
		n++;
	}
	return (n);
}