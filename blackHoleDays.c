/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackHoleDays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:52:03 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/06 21:47:26 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//hard coded values xD
//found in slack look up "black hole 42 deep dive"
double get_totalxp(int level)
{
    if (level < 1)
        return 0;
    else if (level < 2)
        return 462;
    else if (level < 3)
        return 2688;
    else if (level < 4)
        return 5885;
    else if (level < 5)
        return 11777;
    else if (level < 6)
        return 29217;
    else if (level < 7)
        return 46255;
    else if (level < 8)
        return 63559;
    else if (level < 9)
        return 74340;
    else if (level < 10)
        return 85483;
    else
        return 0;
}

double get_newxp(int level)
{
    level++;
     if (level < 1)
        return 0;
    else if (level < 2)
        return 462;
    else if (level < 3)
        return 2226;
    else if (level < 4)
        return 3197;
    else if (level < 5)
        return 5892;
    else if (level < 6)
        return 17440;
    else if (level < 7)
        return 17038;
    else if (level < 8)
        return 17304;
    else if (level < 9)
        return 10781;
    else if (level < 10)
        return 11143;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    double level;
    double xp;
    double grade;
    double intlevel;
    double perlevel;
    double total_xp;
    double new_xp;
    double myxp;
    double bbdays;
    
    if (argc == 4)
    {
        level = atof(argv[1]);
        xp = atof(argv[2]);
        grade = atof(argv[3]);
        xp = xp * (grade * 0.01);
        perlevel = modf(level, &intlevel);
        total_xp = get_totalxp(level);
        new_xp = get_newxp(level);
        myxp = (new_xp * perlevel) + total_xp;
        bbdays = (pow((xp + myxp)/49980,0.45) - pow(myxp/49980, 0.45)) * 483;
        printf("%0.2f Days\n", bbdays);
    }
    else
        printf("<exec> <level> <xp_project> <grade(from 100)\n");
    return (0);
}