#include <physics/physics.h>

int calculate_mass(int __force, int __gravity)
{
    /*
    * Formula:
    * F = m * a
    * m = F / a
    */

   return (__force / __gravity);
}

int calculate_force(int __mass, int __gravity)
{
    /*
    * Formula:
    * F = m * a
    */

   return (__mass * __gravity);
}

int calculate_gravity(int __force, int __mass)
{
    /*
    * Formula:
    * F = m * a
    * a = F / m
    */

   return (__force / __mass);
}